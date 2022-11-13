/* $OpenLDAP: pkg/ldap/libraries/librewrite/rewrite.c,v 1.5.2.4 2004/03/06 16:10:31 ando Exp $ */
/* This work is part of OpenLDAP Software <http://www.openldap.org/>.
 *
 * Copyright 2000-2004 The OpenLDAP Foundation.
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
/* ACKNOWLEDGEMENT:
 * This work was initially developed by Pierangelo Masarati for
 * inclusion in OpenLDAP Software.
 */

#include <portable.h>

#include <ac/stdlib.h>
#include <ac/string.h>
#include <ac/syslog.h>
#include <ac/regex.h>
#include <ac/socket.h>
#include <ac/unistd.h>
#include <ac/ctype.h>
#include <ac/string.h>
#include <stdio.h>

#include <rewrite.h>

int ldap_debug;
int ldap_syslog;
int ldap_syslog_level;

char *
apply( 
		FILE *fin, 
		const char *rewriteContext,
		const char *arg
)
{
	struct rewrite_info *info;
	char *string, *sep, *result = NULL;
	int rc;
	void *cookie = &info;

	info = rewrite_info_init( REWRITE_MODE_ERR );

	if ( rewrite_read( fin, info ) != 0 ) {
		exit( EXIT_FAILURE );
	}

	rewrite_param_set( info, "prog", "rewrite" );

	rewrite_session_init( info, cookie );

	string = strdup( arg );
	for ( sep = strchr( rewriteContext, ',' );
			rewriteContext != NULL;
			rewriteContext = sep,
			sep ? sep = strchr( rewriteContext, ',' ) : NULL ) {
		if ( sep != NULL ) {
			sep[ 0 ] = '\0';
			sep++;
		}
		/* rc = rewrite( info, rewriteContext, string, &result ); */
		rc = rewrite_session( info, rewriteContext, string,
				cookie, &result );
		
		fprintf( stdout, "%s -> %s\n", string, 
				( result ? result : "unwilling to perform" ) );
		if ( result == NULL ) {
			break;
		}
		free( string );
		string = result;
	}

	free( string );

	rewrite_session_delete( info, cookie );

	rewrite_info_delete( &info );

	return result;
}

int
main( int argc, char *argv[] )
{
	FILE *fin = NULL;
	char *rewriteContext = REWRITE_DEFAULT_CONTEXT;

	while ( 1 ) {
		int opt = getopt( argc, argv, "f:hr:" );

		if ( opt == EOF ) {
			break;
		}

		switch ( opt ) {
		case 'f':
			fin = fopen( optarg, "r" );
			if ( fin == NULL ) {
				fprintf( stderr, "unable to open file '%s'\n",
						optarg );
				exit( EXIT_FAILURE );
			}
			break;
			
		case 'h':
			fprintf( stderr, 
	"usage: rewrite [options] string\n"
	"\n"
	"\t\t-f file\t\tconfiguration file\n"
	"\t\t-r rule[s]\tlist of comma-separated rules\n"
	"\n"
	"\tsyntax:\n"
	"\t\trewriteEngine\t{on|off}\n"
	"\t\trewriteContext\tcontextName [alias aliasedContextName]\n"
	"\t\trewriteRule\tpattern subst [flags]\n"
	"\n" 
				);
			exit( EXIT_SUCCESS );
			
		case 'r':
			rewriteContext = optarg;
			break;
		}
	}
	
	if ( optind >= argc ) {
		return -1;
	}

	apply( ( fin ? fin : stdin ), rewriteContext, argv[ optind ] );

	if ( fin ) {
		fclose( fin );
	}

	return 0;
}

