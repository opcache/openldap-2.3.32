/* modrdn.c - ldap backend modrdn function */
/* $OpenLDAP: pkg/ldap/servers/slapd/back-ldap/modrdn.c,v 1.28.2.7 2005/01/20 17:01:12 kurt Exp $ */
/* This work is part of OpenLDAP Software <http://www.openldap.org/>.
 *
 * Copyright 1999-2005 The OpenLDAP Foundation.
 * Portions Copyright 1999-2003 Howard Chu.
 * Portions Copyright 2000-2003 Pierangelo Masarati.
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

#include <ac/socket.h>
#include <ac/string.h>

#include "slap.h"
#include "back-ldap.h"

int
ldap_back_modrdn(
    Operation	*op,
    SlapReply	*rs )
{
	struct ldapinfo	*li = (struct ldapinfo *) op->o_bd->be_private;
	struct ldapconn *lc;
	ber_int_t msgid;
	dncookie dc;
	int do_retry = 1;
	int rc = LDAP_SUCCESS;
#ifdef LDAP_BACK_PROXY_AUTHZ 
	LDAPControl **ctrls = NULL;
#endif /* LDAP_BACK_PROXY_AUTHZ */

	struct berval mdn = BER_BVNULL, mnewSuperior = BER_BVNULL;

	lc = ldap_back_getconn( op, rs );
	if ( !lc || !ldap_back_dobind(lc, op, rs) ) {
		return( -1 );
	}

	dc.rwmap = &li->rwmap;
#ifdef ENABLE_REWRITE
	dc.conn = op->o_conn;
	dc.rs = rs;
#else
	dc.tofrom = 1;
	dc.normalized = 0;
#endif
	if (op->orr_newSup) {
		int version = LDAP_VERSION3;
		ldap_set_option( lc->ld, LDAP_OPT_PROTOCOL_VERSION, &version);
		
		/*
		 * Rewrite the new superior, if defined and required
	 	 */
#ifdef ENABLE_REWRITE
		dc.ctx = "newSuperiorDN";
#endif
		if ( ldap_back_dn_massage( &dc, op->orr_newSup,
			&mnewSuperior ) ) {
			send_ldap_result( op, rs );
			return -1;
		}
	}

	/*
	 * Rewrite the modrdn dn, if required
	 */
#ifdef ENABLE_REWRITE
	dc.ctx = "modrDN";
#endif
	if ( ldap_back_dn_massage( &dc, &op->o_req_ndn, &mdn ) ) {
		send_ldap_result( op, rs );
		return -1;
	}

#ifdef LDAP_BACK_PROXY_AUTHZ
	rc = ldap_back_proxy_authz_ctrl( lc, op, rs, &ctrls );
	if ( rc != LDAP_SUCCESS ) {
		send_ldap_result( op, rs );
		rc = -1;
		goto cleanup;
	}
#endif /* LDAP_BACK_PROXY_AUTHZ */

retry:
	rs->sr_err = ldap_rename( lc->ld, mdn.bv_val,
			op->orr_newrdn.bv_val, mnewSuperior.bv_val,
			op->orr_deleteoldrdn,
#ifdef LDAP_BACK_PROXY_AUTHZ
			ctrls,
#else /* ! LDAP_BACK_PROXY_AUTHZ */
			op->o_ctrls,
#endif /* ! LDAP_BACK_PROXY_AUTHZ */
			NULL, &msgid );
	rc = ldap_back_op_result( lc, op, rs, msgid, 1 );
	if ( rs->sr_err == LDAP_SERVER_DOWN && do_retry ) {
		do_retry = 0;
		if ( ldap_back_retry (lc, op, rs )) goto retry;
	}

#ifdef LDAP_BACK_PROXY_AUTHZ
cleanup:
	if ( ctrls && ctrls != op->o_ctrls ) {
		free( ctrls[ 0 ] );
		free( ctrls );
	}
#endif /* LDAP_BACK_PROXY_AUTHZ */

	if ( mdn.bv_val != op->o_req_ndn.bv_val ) {
		free( mdn.bv_val );
	}
	if ( mnewSuperior.bv_val != NULL
		&& mnewSuperior.bv_val != op->oq_modrdn.rs_newSup->bv_val ) {
		free( mnewSuperior.bv_val );
	}

	return rc;
}

