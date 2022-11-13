/* add.c - ldap backend add function */
/* $OpenLDAP: pkg/ldap/servers/slapd/back-ldap/add.c,v 1.38.2.11 2005/01/20 22:43:28 ando Exp $ */
/* This work is part of OpenLDAP Software <http://www.openldap.org/>.
 *
 * Copyright 1999-2005 The OpenLDAP Foundation.
 * Portions Copyright 2000-2003 Pierangelo Masarati.
 * Portions Copyright 1999-2003 Howard Chu.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted only as authorized by the OpenLDAP
 * Public License.
 *
 * A copy of this license is available in the file LICENSE in the
 * top-level directory of the distribution or, alternatively, at
 * <http://www.OpenLDAP.org/license.html>.
 */
/* ACKNOWLEDGEMENTS:
 * This work was initially developed by the Howard Chu for inclusion
 * in OpenLDAP Software and subsequently enhanced by Pierangelo
 * Masarati.
 */

#include "portable.h"

#include <stdio.h>

#include <ac/string.h>
#include <ac/socket.h>

#include "slap.h"
#include "back-ldap.h"

int
ldap_back_add(
    Operation	*op,
    SlapReply	*rs )
{
	struct ldapinfo	*li = (struct ldapinfo *) op->o_bd->be_private;
	struct ldapconn *lc;
	int i, j;
	Attribute *a;
	LDAPMod **attrs;
	struct berval mapped;
	struct berval mdn = BER_BVNULL;
	ber_int_t msgid;
	dncookie dc;
	int isupdate;
	int do_retry = 1;
	int rc = LDAP_SUCCESS;
#ifdef LDAP_BACK_PROXY_AUTHZ 
	LDAPControl **ctrls = NULL;
#endif /* LDAP_BACK_PROXY_AUTHZ */

#ifdef NEW_LOGGING
	LDAP_LOG( BACK_LDAP, ENTRY, "ldap_back_add: %s\n", op->o_req_dn.bv_val, 0, 0 );
#else /* !NEW_LOGGING */
	Debug(LDAP_DEBUG_ARGS, "==> ldap_back_add: %s\n", op->o_req_dn.bv_val, 0, 0);
#endif /* !NEW_LOGGING */
	
	lc = ldap_back_getconn(op, rs);
	if ( !lc || !ldap_back_dobind( lc, op, rs ) ) {
		return( -1 );
	}

	/*
	 * Rewrite the add dn, if needed
	 */
	dc.rwmap = &li->rwmap;
#ifdef ENABLE_REWRITE
	dc.conn = op->o_conn;
	dc.rs = rs;
	dc.ctx = "addDN";
#else
	dc.tofrom = 1;
	dc.normalized = 0;
#endif
	if ( ldap_back_dn_massage( &dc, &op->o_req_dn, &mdn ) ) {
		send_ldap_result( op, rs );
		return -1;
	}

	/* Count number of attributes in entry */
	for (i = 1, a = op->oq_add.rs_e->e_attrs; a; i++, a = a->a_next)
		;
	
	/* Create array of LDAPMods for ldap_add() */
	attrs = (LDAPMod **)ch_malloc(sizeof(LDAPMod *)*i);

#ifdef ENABLE_REWRITE
	dc.ctx = "addAttrDN";
#endif

	isupdate = be_shadow_update( op );
	for (i=0, a=op->oq_add.rs_e->e_attrs; a; a=a->a_next) {
		int	is_oc = 0;

		if ( !isupdate && a->a_desc->ad_type->sat_no_user_mod  ) {
			continue;
		}

		if ( a->a_desc == slap_schema.si_ad_objectClass
				|| a->a_desc == slap_schema.si_ad_structuralObjectClass )
		{
			is_oc = 1;
			mapped = a->a_desc->ad_cname;

		} else {
			ldap_back_map(&li->rwmap.rwm_at, &a->a_desc->ad_cname, &mapped,
					BACKLDAP_MAP);
			if (mapped.bv_val == NULL || mapped.bv_val[0] == '\0') {
				continue;
			}
		}

		attrs[i] = (LDAPMod *)ch_malloc(sizeof(LDAPMod));
		if (attrs[i] == NULL) {
			continue;
		}

		attrs[i]->mod_op = LDAP_MOD_BVALUES;
		attrs[i]->mod_type = mapped.bv_val;

		if ( is_oc ) {
			for ( j = 0; !BER_BVISNULL( &a->a_vals[ j ] ); j++ )
				;

			attrs[ i ]->mod_bvalues =
				(struct berval **)ch_malloc( ( j + 1 ) *
				sizeof( struct berval * ) );

			for ( j = 0; !BER_BVISNULL( &a->a_vals[ j ] ); ) {
				struct ldapmapping	*mapping;

				ldap_back_mapping( &li->rwmap.rwm_oc,
						&a->a_vals[ j ], &mapping, BACKLDAP_MAP );

				if ( mapping == NULL ) {
					if ( li->rwmap.rwm_oc.drop_missing ) {
						continue;
					}
					attrs[ i ]->mod_bvalues[ j ] = &a->a_vals[ j ];

				} else {
					attrs[ i ]->mod_bvalues[ j ] = &mapping->dst;
				}
				j++;
			}

			if ( j == 0 ) {
				ch_free( attrs[ i ]->mod_bvalues );
				continue;
			}

			attrs[ i ]->mod_bvalues[ j ] = NULL;

		} else {
			if ( a->a_desc->ad_type->sat_syntax ==
				slap_schema.si_syn_distinguishedName )
			{
				/*
				 * FIXME: rewrite could fail; in this case
				 * the operation should give up, right?
				 */
				(void)ldap_dnattr_rewrite( &dc, a->a_vals );
				if ( a->a_vals == NULL || BER_BVISNULL( &a->a_vals[0] ) ) {
					continue;
				}
			}

			for (j=0; a->a_vals[j].bv_val; j++);
			attrs[i]->mod_vals.modv_bvals = ch_malloc((j+1)*sizeof(struct berval *));
			for (j=0; a->a_vals[j].bv_val; j++)
				attrs[i]->mod_vals.modv_bvals[j] = &a->a_vals[j];
			attrs[i]->mod_vals.modv_bvals[j] = NULL;
		}
		i++;
	}
	attrs[i] = NULL;

#ifdef LDAP_BACK_PROXY_AUTHZ
	rc = ldap_back_proxy_authz_ctrl( lc, op, rs, &ctrls );
	if ( rc != LDAP_SUCCESS ) {
		send_ldap_result( op, rs );
		rc = -1;
		goto cleanup;
	}
#endif /* LDAP_BACK_PROXY_AUTHZ */

retry:
	rs->sr_err = ldap_add_ext(lc->ld, mdn.bv_val, attrs,
#ifdef LDAP_BACK_PROXY_AUTHZ
			ctrls,
#else /* ! LDAP_BACK_PROXY_AUTHZ */
			op->o_ctrls,
#endif /* ! LDAP_BACK_PROXY_AUTHZ */
			NULL, &msgid);
	rc = ldap_back_op_result( lc, op, rs, msgid, 1 );
	if ( rs->sr_err == LDAP_UNAVAILABLE && do_retry ) {
		do_retry = 0;
		if ( ldap_back_retry( lc, op, rs )) goto retry;
	}
#ifdef LDAP_BACK_PROXY_AUTHZ
cleanup:
	if ( ctrls && ctrls != op->o_ctrls ) {
		free( ctrls[ 0 ] );
		free( ctrls );
	} 
#endif /* LDAP_BACK_PROXY_AUTHZ */

	for (--i; i>= 0; --i) {
		ch_free(attrs[i]->mod_vals.modv_bvals);
		ch_free(attrs[i]);
	}
	ch_free(attrs);
	if ( mdn.bv_val != op->o_req_dn.bv_val ) {
		free( mdn.bv_val );
	}
	return rc;
}

