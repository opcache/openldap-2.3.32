/* ctxcsn.c -- back-bdb Context CSN Management Routines */
/* $OpenLDAP: pkg/ldap/servers/slapd/back-bdb/ctxcsn.c,v 1.10.2.16 2005/04/26 16:29:23 hyc Exp $ */
/* This work is part of OpenLDAP Software <http://www.openldap.org/>.
 *
 * Copyright 2003-2005 The OpenLDAP Foundation.
 * Portions Copyright 2003 IBM Corporation.
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

#include "portable.h"

#include <stdio.h>

#include <ac/string.h>
#include <ac/time.h>

#include "lutil.h"
#include "back-bdb.h"
#include "external.h"

int
bdb_csn_commit(
	Operation *op,
	SlapReply *rs,
	DB_TXN *tid,
	EntryInfo *ei,
	EntryInfo **suffix_ei,
	Entry **ctxcsn_e,
	int *ctxcsn_added,
	u_int32_t locker
)
{
	struct bdb_info	*bdb = (struct bdb_info *) op->o_bd->be_private;
	EntryInfo		*ctxcsn_ei = NULL;
	DB_LOCK			ctxcsn_lock;
	struct berval	max_committed_csn;
	int				rc, ret;
	ID				ctxcsn_id;
	EntryInfo		*eip = NULL;

	assert( !BER_BVISNULL( &op->o_bd->be_context_csn ) );

	rc =  bdb_dn2entry( op, tid, &op->o_bd->be_context_csn, &ctxcsn_ei,
			1, locker, &ctxcsn_lock );
	switch( rc ) {
	case 0:
	case DB_NOTFOUND:
		break;
	case DB_LOCK_DEADLOCK:
	case DB_LOCK_NOTGRANTED:
		return BDB_CSN_RETRY;
	default:
		return BDB_CSN_ABORT;
	}
	
	*ctxcsn_e = ctxcsn_ei->bei_e;
	*ctxcsn_added = 0;

	slap_get_commit_csn( op, &max_committed_csn );

	if ( max_committed_csn.bv_val == NULL ) {
		return BDB_CSN_COMMIT;
	}

	switch( rc ) {
	case 0:
		if ( !*ctxcsn_e ) {
			rs->sr_err = LDAP_OTHER;
			rs->sr_text = "context csn not present";
			op->o_tmpfree( max_committed_csn.bv_val, op->o_tmpmemctx );
			return BDB_CSN_ABORT;
		} else {
			Entry *e = *ctxcsn_e;
			Attribute *a = attr_find(e->e_attrs,slap_schema.si_ad_contextCSN);

			ret = bdb_cache_entry_db_relock( bdb->bi_dbenv, locker,
				ctxcsn_ei, 1, 0, &ctxcsn_lock );
			switch ( ret ) {
			case 0 :
				break;
			case DB_LOCK_DEADLOCK :
			case DB_LOCK_NOTGRANTED :
				op->o_tmpfree( max_committed_csn.bv_val, op->o_tmpmemctx );
				goto rewind;
			default :
				rs->sr_err = ret;
				rs->sr_text = "context csn lock failed";
				op->o_tmpfree( max_committed_csn.bv_val, op->o_tmpmemctx );
				return BDB_CSN_ABORT;
			}

			/* Is the contextCSN missing, or too short? - should never
			 * happen, our CSNs are all fixed length and this attribute
			 * is always populated.
			 */
			if ( !a || a->a_vals[0].bv_len < max_committed_csn.bv_len ) {
				/* If attrs are contiguous, make a new copy.
				 */
				if ((void *)e->e_attrs == (void *)(e+1)) {
					e->e_attrs = attrs_dup( e->e_attrs );
					if ( a )
						a = attr_find( e->e_attrs,
							slap_schema.si_ad_contextCSN );
				}
				/* If attr existed and value was too short, free it
				 * and replace it.
				 */
				if ( a ) {
					ch_free( a->a_vals[0].bv_val );
					ber_dupbv( a->a_vals, &max_committed_csn );
				} else {
				/* Else it never existed, merge it in. */
					attr_merge_one( e, slap_schema.si_ad_contextCSN,
						&max_committed_csn, NULL );
				}
			} else {
				/* The usual case - just overwrite the old with the new */
				strcpy( a->a_vals[0].bv_val, max_committed_csn.bv_val );
				a->a_vals[0].bv_len = max_committed_csn.bv_len;
			}
			op->o_tmpfree( max_committed_csn.bv_val, op->o_tmpmemctx );

			ret = bdb_id2entry_update( op->o_bd, tid, *ctxcsn_e );
			switch ( ret ) {
			case 0 :
				break;
			case DB_LOCK_DEADLOCK :
			case DB_LOCK_NOTGRANTED :
				goto rewind;
			default :
				rs->sr_err = ret;
				rs->sr_text = "context csn update failed";
				return BDB_CSN_ABORT;
			}
		}
		break;
	case DB_NOTFOUND:
		if ( op->o_tag == LDAP_REQ_ADD &&
						be_issuffix( op->o_bd, &op->oq_add.rs_e->e_nname )) {
			*suffix_ei = NULL;
			eip = (EntryInfo *) ch_calloc( 1, sizeof( EntryInfo ));
			eip->bei_id = op->oq_add.rs_e->e_id;
		} else {
			eip = *suffix_ei = ctxcsn_ei;
		}

		/* This serializes add. But this case is very rare : only once. */
		rs->sr_err = bdb_next_id( op->o_bd, tid, &ctxcsn_id );
		if ( rs->sr_err != 0 ) {
			Debug( LDAP_DEBUG_TRACE,
				"bdb_csn_commit: next_id failed (%d)\n",
				rs->sr_err, 0, 0 );
			rs->sr_err = LDAP_OTHER;
			rs->sr_text = "internal error";
			return BDB_CSN_ABORT;
		}

		*ctxcsn_e = slap_create_context_csn_entry( op->o_bd, &max_committed_csn );
		op->o_tmpfree( max_committed_csn.bv_val, op->o_tmpmemctx );
		(*ctxcsn_e)->e_id = ctxcsn_id;
		*ctxcsn_added = 1;

		ret = bdb_dn2id_add( op, tid, eip, *ctxcsn_e );
		switch ( ret ) {
		case 0 :
			break;
		case DB_LOCK_DEADLOCK :
		case DB_LOCK_NOTGRANTED :
			goto rewind;
		case DB_KEYEXIST :
			rs->sr_err = LDAP_OTHER;
			rs->sr_text = "context csn exists before context prefix does";
			return BDB_CSN_ABORT;
		default :
			rs->sr_err = LDAP_OTHER;
			rs->sr_text = "context csn store failed";
			return BDB_CSN_ABORT;
		}

		if ( *suffix_ei == NULL ) {
			ch_free( eip );
		}

		ret = bdb_id2entry_add( op->o_bd, tid, *ctxcsn_e );
		switch ( ret ) {
		case 0 :
			break;
		case DB_LOCK_DEADLOCK :
		case DB_LOCK_NOTGRANTED :
			goto rewind;
		default :
			rs->sr_err = LDAP_OTHER;
			rs->sr_text = "context csn store failed";
			return BDB_CSN_ABORT;
		}
		break;
	}

	return BDB_CSN_COMMIT;

rewind :
	slap_rewind_commit_csn( op );
	return BDB_CSN_RETRY;
}

int
bdb_get_commit_csn(
	Operation	*op,
	SlapReply	*rs,
	struct berval	**search_context_csn,
	u_int32_t	locker,
	DB_LOCK		*ctxcsn_lock
)
{
	struct bdb_info *bdb = (struct bdb_info *) op->o_bd->be_private;
	struct berval csn = BER_BVNULL;
	EntryInfo	*ctxcsn_ei = NULL;
	EntryInfo	*suffix_ei = NULL;
	Entry		*ctxcsn_e = NULL;
	DB_TXN		*ltid = NULL;
	Attribute	*csn_a;
	char		gid[DB_XIDDATASIZE];
	char		csnbuf[ LDAP_LUTIL_CSNSTR_BUFSIZE ];
	int			num_retries = 0;
	int			ctxcsn_added = 0;
	struct sync_cookie syncCookie = { NULL, -1, NULL};
	syncinfo_t	*si;
	u_int32_t	ctxcsn_locker = 0;

	if ( op->o_sync_mode != SLAP_SYNC_NONE &&
		 !LDAP_STAILQ_EMPTY( &op->o_bd->be_syncinfo )) {
		char substr[67];
		struct berval ctxcsn_ndn = BER_BVNULL;
		struct berval bv;

		LDAP_STAILQ_FOREACH( si, &op->o_bd->be_syncinfo, si_next ) {
			sprintf( substr, "cn=syncrepl%ld", si->si_rid );
			ber_str2bv( substr, 0, 0, &bv );
			build_new_dn( &ctxcsn_ndn, &op->o_bd->be_nsuffix[0], &bv, op->o_tmpmemctx );

consumer_ctxcsn_retry :
			rs->sr_err = bdb_dn2entry( op, NULL, &ctxcsn_ndn, &ctxcsn_ei,
										0, locker, ctxcsn_lock );
			switch(rs->sr_err) {
			case DB_LOCK_DEADLOCK:
			case DB_LOCK_NOTGRANTED:
				goto consumer_ctxcsn_retry;
			case 0:
				op->o_tmpfree( ctxcsn_ndn.bv_val, op->o_tmpmemctx );
				ctxcsn_ndn.bv_val = NULL;
				if ( ctxcsn_ei ) {
					ctxcsn_e = ctxcsn_ei->bei_e;
				}
				break;
			case DB_NOTFOUND:
			default:
				rs->sr_err = LDAP_OTHER;
			case LDAP_BUSY:
				op->o_tmpfree( ctxcsn_ndn.bv_val, op->o_tmpmemctx );
				ctxcsn_ndn.bv_val = NULL;
				goto done;
			}

			if ( ctxcsn_e ) {
				csn_a = attr_find( ctxcsn_e->e_attrs,
							slap_schema.si_ad_syncreplCookie );
				if ( csn_a ) {
					struct berval cookie;
					const char *text;
					int match = -1;
					ber_dupbv( &cookie, &csn_a->a_vals[0] );
					ber_bvarray_add( &syncCookie.octet_str, &cookie );
					slap_parse_sync_cookie( &syncCookie );
					if ( *search_context_csn &&
						(*search_context_csn)->bv_val != NULL )
					{
						value_match( &match, slap_schema.si_ad_entryCSN,
							slap_schema.si_ad_entryCSN->ad_type->sat_ordering,
							SLAP_MR_VALUE_OF_ATTRIBUTE_SYNTAX,
							syncCookie.ctxcsn, *search_context_csn, &text );
					}
					if ( match < 0 ) {
						/* set search_context_csn to the
						   smallest syncrepl cookie value */
						if ( *search_context_csn ) {
							ch_free( (*search_context_csn)->bv_val );
							ch_free( *search_context_csn );
						}
						*search_context_csn = ber_dupbv( NULL,
							syncCookie.ctxcsn );
					}
					slap_sync_cookie_free( &syncCookie, 0 );
				} else {
					*search_context_csn = NULL;
				} 
			} else {
				*search_context_csn = NULL;
			}
		}
	} else if ( op->o_sync_mode != SLAP_SYNC_NONE &&
		 LDAP_STAILQ_EMPTY( &op->o_bd->be_syncinfo )) {

provider_ctxcsn_retry :
		rs->sr_err = bdb_dn2entry( op, NULL, &op->o_bd->be_context_csn, &ctxcsn_ei,
									0, locker, ctxcsn_lock );
		switch(rs->sr_err) {
		case 0:
			if ( ctxcsn_ei ) {
				ctxcsn_e = ctxcsn_ei->bei_e;
			}
			break;
		case LDAP_BUSY:
			goto done;
		case DB_LOCK_DEADLOCK:
		case DB_LOCK_NOTGRANTED:
			goto provider_ctxcsn_retry;
		case DB_NOTFOUND:
			snprintf( gid, sizeof( gid ), "%s-%08lx-%08lx",
				bdb_uuid.bv_val, (long) op->o_connid, (long) op->o_opid );

			slap_get_csn( op, csnbuf, sizeof(csnbuf), &csn, 1 );

			if ( 0 ) {
txn_retry:
				rs->sr_err = TXN_ABORT( ltid );
				ltid = NULL;
				if ( rs->sr_err != 0 ) {
					rs->sr_err = LDAP_OTHER;
					goto done;
				}
				ldap_pvt_thread_yield();
				bdb_trans_backoff( ++num_retries );
			}
			rs->sr_err = TXN_BEGIN( bdb->bi_dbenv, NULL,
								&ltid, bdb->bi_db_opflags );
			if ( rs->sr_err != 0 ) {
				rs->sr_err = LDAP_OTHER;
				goto done;
			}

			ctxcsn_locker = TXN_ID ( ltid );

			rs->sr_err = bdb_csn_commit( op, rs, ltid, NULL,
						&suffix_ei, &ctxcsn_e,
						&ctxcsn_added, ctxcsn_locker );
			switch( rs->sr_err ) {
			case BDB_CSN_ABORT:
				rs->sr_err = LDAP_OTHER;
				goto done;	
			case BDB_CSN_RETRY:
				goto txn_retry;
			}

			rs->sr_err = TXN_PREPARE( ltid, gid );
			if ( rs->sr_err != 0 ) {
				rs->sr_err = LDAP_OTHER;
				goto done;
			}

			bdb_cache_add( bdb, suffix_ei, ctxcsn_e,
					(struct berval *)&slap_ldapsync_cn_bv, ctxcsn_locker );

			rs->sr_err = TXN_COMMIT( ltid, 0 );
			if ( rs->sr_err != 0 ) {
				rs->sr_err = LDAP_OTHER;
				goto done;
			}

			rs->sr_err = bdb_dn2entry( op, NULL,
						&op->o_bd->be_context_csn,
						&ctxcsn_ei, 0, ctxcsn_locker,
						ctxcsn_lock );

			if ( ctxcsn_ei ) {
				ctxcsn_e = ctxcsn_ei->bei_e;
			}
			break;

		default:
			rs->sr_err = LDAP_OTHER;
			goto done;
		}

		if ( ctxcsn_e ) {
			csn_a = attr_find( ctxcsn_e->e_attrs,
						slap_schema.si_ad_contextCSN );
			if ( csn_a ) {
				*search_context_csn = ber_dupbv( NULL, &csn_a->a_vals[0] );
			} else {
				*search_context_csn = NULL;
			}
		} else {
			*search_context_csn = NULL;
		}
	}

	ltid = NULL;
	rs->sr_err = LDAP_SUCCESS;

done:
    if( ltid != NULL ) {
        TXN_ABORT( ltid );
    }

	return rs->sr_err;
}
