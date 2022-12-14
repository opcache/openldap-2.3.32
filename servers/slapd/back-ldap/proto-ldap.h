/* $OpenLDAP: pkg/ldap/servers/slapd/back-ldap/proto-ldap.h,v 1.3.2.11 2007/01/02 21:44:02 kurt Exp $ */
/* This work is part of OpenLDAP Software <http://www.openldap.org/>.
 *
 * Copyright 2003-2007 The OpenLDAP Foundation.
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

#ifndef PROTO_LDAP_H
#define PROTO_LDAP_H

LDAP_BEGIN_DECL

extern BI_init			ldap_back_initialize;

extern BI_open			ldap_back_open;
extern BI_close			ldap_back_close;
extern BI_destroy		ldap_back_destroy;

extern BI_db_init		ldap_back_db_init;
extern BI_db_open		ldap_back_db_open;
extern BI_db_destroy		ldap_back_db_destroy;

extern BI_op_bind		ldap_back_bind;
extern BI_op_search		ldap_back_search;
extern BI_op_compare		ldap_back_compare;
extern BI_op_modify		ldap_back_modify;
extern BI_op_modrdn		ldap_back_modrdn;
extern BI_op_add		ldap_back_add;
extern BI_op_delete		ldap_back_delete;
extern BI_op_abandon		ldap_back_abandon;
extern BI_op_extended		ldap_back_extended;

extern BI_connection_destroy	ldap_back_conn_destroy;

extern BI_entry_get_rw		ldap_back_entry_get;

int ldap_back_freeconn( Operation *op, ldapconn_t *lc, int dolock );
ldapconn_t *ldap_back_getconn( Operation *op, SlapReply *rs, ldap_back_send_t sendok );
void ldap_back_release_conn_lock( Operation *op, SlapReply *rs, ldapconn_t *lc, int dolock );
#define ldap_back_release_conn(op, rs, lc) ldap_back_release_conn_lock((op), (rs), (lc), 1)
int ldap_back_dobind( ldapconn_t *lc, Operation *op, SlapReply *rs, ldap_back_send_t sendok );
int ldap_back_retry( ldapconn_t **lcp, Operation *op, SlapReply *rs, ldap_back_send_t sendok );
int ldap_back_map_result( SlapReply *rs );
int ldap_back_op_result( ldapconn_t *lc, Operation *op, SlapReply *rs,
	ber_int_t msgid, time_t timeout, ldap_back_send_t sendok );

int ldap_back_init_cf( BackendInfo *bi );

extern int ldap_back_conndn_cmp( const void *c1, const void *c2);
extern int ldap_back_conn_cmp( const void *c1, const void *c2);
extern int ldap_back_conndn_dup( void *c1, void *c2 );
extern void ldap_back_conn_free( void *c );

extern int
ldap_back_proxy_authz_ctrl(
		ldapconn_t	*lc,
		Operation	*op,
		SlapReply	*rs,
		LDAPControl	***pctrls );

extern int
ldap_back_proxy_authz_ctrl_free(
		Operation	*op,
		LDAPControl	***pctrls );

extern int chain_init( void );

extern LDAP_REBIND_PROC		*ldap_back_rebind_f;

LDAP_END_DECL

#endif /* PROTO_LDAP_H */
