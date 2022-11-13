/* This work is part of OpenLDAP Software <http://www.openldap.org/>.
 *
 * Copyright 2004-2005 The OpenLDAP Foundation.
 * Portions Copyright 2004 Pierangelo Masarati.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted only as authorized by the OpenLDAP
 * Public License.
 *
 * A copy of this license is available in file LICENSE in the
 * top-level directory of the distribution or, alternatively, at
 * <http://www.OpenLDAP.org/license.html>.
 */
/* ACKNOWLEDGEMENTS:
 * This work was initially developed by Pierangelo Masarati for inclusion
 * in OpenLDAP Software.
 */

#include "portable.h"

#include <stdio.h>

#include <ac/stdlib.h>

#include <ac/ctype.h>
#include <ac/string.h>
#include <ac/socket.h>
#include <ac/unistd.h>

#include <lber.h>
#include <ldif.h>
#include <lutil.h>

#include "slapcommon.h"

int
slapdn( int argc, char **argv )
{
	int			rc = EXIT_SUCCESS;
	const char		*progname = "slapdn";

#ifdef NEW_LOGGING
	lutil_log_initialize( argc, argv );
#endif
	slap_tool_init( progname, SLAPDN, argc, argv );

	argv = &argv[ optind ];
	argc -= optind;

	for ( ; argc--; argv++ ) {
		struct berval	dn, pdn, ndn;

		dn.bv_val = argv[ 0 ];
		dn.bv_len = strlen( argv[ 0 ] );

		rc = dnPrettyNormal( NULL, &dn,
					&pdn, &ndn, NULL );
		if ( rc != LDAP_SUCCESS ) {
			fprintf( stderr, "DN: <%s> check failed %d (%s)\n",
					dn.bv_val, rc,
					ldap_err2string( rc ) );
			rc = 1;
			
		} else {
			fprintf( stderr, "DN: <%s> check succeeded\n"
					"normalized: <%s>\n"
					"pretty:     <%s>\n",
					dn.bv_val,
					ndn.bv_val, pdn.bv_val );
			ch_free( ndn.bv_val );
			ch_free( pdn.bv_val );
			rc = 0;
		}
	}
	
	slap_tool_destroy();

	return rc;
}