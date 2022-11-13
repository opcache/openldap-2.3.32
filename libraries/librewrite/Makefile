# Generated automatically from lib-static.mk by configure.
# $OpenLDAP: pkg/ldap/build/top.mk,v 1.78.2.9 2005/01/20 17:00:55 kurt Exp $
## Copyright 1998-2005 The OpenLDAP Foundation.
## All rights reserved.
##
## Redistribution and use in source and binary forms, with or without
## modification, are permitted only as authorized by the OpenLDAP
## Public License.
##
## A copy of this license is available in the file LICENSE in the
## top-level directory of the distribution or, alternatively, at
##---------------------------------------------------------------------------
#
# Top-level Makefile template
#

PACKAGE= OpenLDAP
VERSION= 2.2.30
RELEASEDATE= 2005/11/18


SHELL = /bin/sh

top_builddir = /opt/data/openldap-2.2.30

srcdir = .
top_srcdir = ../..
prefix = /usr/local/openldap
exec_prefix = ${prefix}
ldap_subdir = /openldap

bindir = ${exec_prefix}/bin
datadir = ${prefix}/share$(ldap_subdir)
includedir = ${prefix}/include
infodir = ${prefix}/info
libdir = ${exec_prefix}/lib
libexecdir = ${exec_prefix}/libexec
localstatedir = ${prefix}/var
mandir = ${prefix}/man
moduledir = ${exec_prefix}/libexec$(ldap_subdir)
sbindir = ${exec_prefix}/sbin
sharedstatedir = ${prefix}/com
sysconfdir = ${prefix}/etc$(ldap_subdir)
schemadir = $(sysconfdir)/schema

PLAT = UNIX
EXEEXT = 
OBJEXT = o

BUILD_LIBS_DYNAMIC = static

INSTALL = /usr/bin/install -c
INSTALL_PROGRAM = ${INSTALL}
INSTALL_DATA = ${INSTALL} -m 644
INSTALL_SCRIPT = ${INSTALL}

LINT = lint
5LINT = 5lint

MKDEP = $(top_srcdir)/build/mkdep $(MKDEPFLAG) \
	-d "$(srcdir)" -c "$(MKDEP_CC)" -m "$(MKDEP_CFLAGS)"
MKDEP_CC	= cc
MKDEP_CFLAGS = -M

MKVERSION = $(top_srcdir)/build/mkversion -v "$(VERSION)"

SHTOOL = $(top_srcdir)/build/shtool

LIBTOOL = $(SHELL) $(top_builddir)/libtool
LIBRELEASE = 2.2
LIBVERSION = 7:23:0
LTVERSION = -release $(LIBRELEASE) -version-info $(LIBVERSION)

# libtool --only flag for libraries: platform specific
NT_LTONLY_LIB = # --only-$(BUILD_LIBS_DYNAMIC)
LTONLY_LIB = $(UNIX_LTONLY_LIB)

# libtool --only flag for modules: depends on linkage of module
# The BUILD_MOD macro is defined in each backend Makefile.in file
LTONLY_yes = static
LTONLY_mod = shared
LTONLY_MOD = # --only-$(BUILD_MOD)

# platform-specific libtool flags
NT_LTFLAGS_LIB = -no-undefined -avoid-version -rpath $(libdir)
NT_LTFLAGS_MOD = -no-undefined -avoid-version -rpath $(moduledir)
UNIX_LTFLAGS_LIB = $(LTVERSION) -rpath $(libdir)
UNIX_LTFLAGS_MOD = $(LTVERSION) -rpath $(moduledir)

# libtool flags
LTFLAGS     = $(UNIX_LTFLAGS)
LTFLAGS_LIB = $(UNIX_LTFLAGS_LIB)
LTFLAGS_MOD = $(UNIX_LTFLAGS_MOD)

# LIB_DEFS defined in liblber and libldap Makefile.in files.
# MOD_DEFS defined in backend Makefile.in files.

# platform-specific LINK_LIBS defined in various Makefile.in files.
# LINK_LIBS referenced in library and module link commands.
LINK_LIBS = $(MOD_LIBS) $(UNIX_LINK_LIBS)

LTSTATIC = -static

LTLINK   = $(LIBTOOL) --mode=link \
	$(CC) $(LTSTATIC) $(LT_CFLAGS) $(LDFLAGS) $(LTFLAGS)

LTCOMPILE_LIB = $(LIBTOOL) $(LTONLY_LIB) --mode=compile \
	$(CC) $(LT_CFLAGS) $(LT_CPPFLAGS) $(LIB_DEFS) -c

LTLINK_LIB = $(LIBTOOL) $(LTONLY_LIB) --mode=link \
	$(CC) $(LT_CFLAGS) $(LDFLAGS) $(LTFLAGS_LIB)

LTCOMPILE_MOD = $(LIBTOOL) $(LTONLY_MOD) --mode=compile \
	$(CC) $(LT_CFLAGS) $(LT_CPPFLAGS) $(MOD_DEFS) -c

LTLINK_MOD = $(LIBTOOL) $(LTONLY_MOD) --mode=link \
	$(CC) $(LT_CFLAGS) $(LDFLAGS) $(LTFLAGS_MOD)

LTINSTALL = $(LIBTOOL) --mode=install $(INSTALL) 
LTFINISH = $(LIBTOOL) --mode=finish

# Misc UNIX commands used in build environment
AR = ar
BASENAME = basename
CAT = cat
CHMOD = chmod
DATE = date
HOSTNAME = $(SHTOOL) echo -e "%h%d"
LN = ln
LN_H = ln
LN_S = ln -s
MAKEINFO = /opt/data/openldap-2.2.30/build/missing makeinfo
MKDIR = $(SHTOOL) mkdir -p
MV = mv
PWD = pwd
RANLIB = ranlib
RM = rm -f
SED = sed

# For manual pages
# MANCOMPRESS=@MANCOMPRESS@
# MANCOMPRESSSUFFIX=@MANCOMPRESSSUFFIX@
MANCOMPRESS=$(CAT)
MANCOMPRESSSUFFIX=

INCLUDEDIR= $(top_srcdir)/include
LDAP_INCPATH= -I$(LDAP_INCDIR) -I$(INCLUDEDIR)
LDAP_LIBDIR= $(top_builddir)/libraries

LUTIL_LIBS = 
LDBM_LIBS =  -ldb-4.2
LTHREAD_LIBS =  -pthread

LDAP_LIBLBER_LA = $(LDAP_LIBDIR)/liblber/liblber.la
LDAP_LIBLDAP_LA = $(LDAP_LIBDIR)/libldap/libldap.la
LDAP_LIBLDAP_R_LA = $(LDAP_LIBDIR)/libldap_r/libldap_r.la

LDAP_LIBREWRITE_A = $(LDAP_LIBDIR)/librewrite/librewrite.a
LDAP_LIBLUNICODE_A = $(LDAP_LIBDIR)/liblunicode/liblunicode.a
LDAP_LIBLUTIL_A = $(LDAP_LIBDIR)/liblutil/liblutil.a

LDAP_L = $(LDAP_LIBLUTIL_A) \
	$(LDAP_LIBLDAP_LA) $(LDAP_LIBLBER_LA)
SLURPD_L = $(LDAP_LIBLUTIL_A) \
	$(LDAP_LIBLDAP_R_LA) $(LDAP_LIBLBER_LA)
SLAPD_L = $(LDAP_LIBLUNICODE_A) $(LDAP_LIBREWRITE_A) \
	$(SLURPD_L)

WRAP_LIBS = 
# AutoConfig generated 
AC_CC	= cc
AC_CFLAGS = -g -O2
AC_DEFS = -I/usr/local/berkeleydb/include -D_GNU_SOURCE # -DHAVE_CONFIG_H
AC_LDFLAGS = -L/usr/local/berkeleydb/lib
AC_LIBS = -lresolv 

KRB4_LIBS = 
KRB5_LIBS = 
KRB_LIBS =  
SASL_LIBS = 
TLS_LIBS = 
AUTH_LIBS = 
SECURITY_LIBS = $(SASL_LIBS) $(KRB_LIBS) $(TLS_LIBS) $(AUTH_LIBS)

MODULES_CPPFLAGS = 
MODULES_LDFLAGS = 
MODULES_LIBS = 
SLAPD_PERL_LDFLAGS = 

SLAPD_SQL_LDFLAGS = 
SLAPD_SQL_INCLUDES = 
SLAPD_SQL_LIBS = 

SLAPD_LIBS =  $(LDBM_LIBS)    
SLURPD_LIBS = 

# Our Defaults
CC = $(AC_CC)
DEFS = $(LDAP_INCPATH) $(XINCPATH) $(XDEFS) $(AC_DEFS) $(DEFINES)
CFLAGS = $(AC_CFLAGS) $(DEFS)
LDFLAGS = $(LDAP_LIBPATH) $(AC_LDFLAGS) $(XLDFLAGS)
LIBS = $(XLIBS) $(XXLIBS) $(AC_LIBS) $(XXXLIBS)

LT_CFLAGS = $(AC_CFLAGS)
LT_CPPFLAGS = $(DEFS)

all:		all-common all-local FORCE
install:	install-common install-local FORCE
clean:		clean-common clean-local FORCE
veryclean:	veryclean-common veryclean-local FORCE
depend:		depend-common depend-local FORCE

# empty common rules
all-common:
install-common:
clean-common:
veryclean-common:	clean-common FORCE
depend-common:
lint-common:
lint5-common:

# empty local rules
all-local:
install-local:
clean-local:
veryclean-local:	clean-local FORCE
depend-local:
lint-local:
lint5-local:

veryclean: FORCE
	$(RM) Makefile
	$(RM) -r .libs

Makefile: Makefile.in $(top_srcdir)/build/top.mk

pathtest:
	$(SHTOOL) --version

# empty rule for forcing rules
FORCE:

##---------------------------------------------------------------------------

# LIBREWRITE
# $OpenLDAP: pkg/ldap/libraries/librewrite/Makefile.in,v 1.4.2.4 2005/01/20 17:01:04 kurt Exp $
## This work is part of OpenLDAP Software <http://www.openldap.org/>.
##
## Copyright 1998-2005 The OpenLDAP Foundation.
## All rights reserved.
##
## Redistribution and use in source and binary forms, with or without
## modification, are permitted only as authorized by the OpenLDAP
## Public License.
##
## A copy of this license is available in the file LICENSE in the
## top-level directory of the distribution or, alternatively, at
## <http://www.OpenLDAP.org/license.html>.
##
## Copyright 2000-2001 Pierangelo Masarati <ando@sys-net.it>
##

SRCS = config.c context.c info.c ldapmap.c map.c params.c rule.c \
	session.c subst.c var.c xmap.c \
	parse.c rewrite.c
XSRCS = version.c
OBJS = config.o context.o info.o ldapmap.o map.o params.o rule.o \
	session.o subst.o var.o xmap.o

LDAP_INCDIR= ../../include       
LDAP_LIBDIR= ../../libraries

LIBRARY = librewrite.a
PROGRAMS	= rewrite
XLIBS = $(LIBRARY) $(LDAP_LIBLUTIL_A) \
	$(LDAP_LIBLDAP_R_LA) $(LDAP_LIBLBER_LA)
XXLIBS  = $(SECURITY_LIBS) $(LUTIL_LIBS)
XXXLIBS = $(LTHREAD_LIBS)

rewrite:	$(XLIBS) rewrite.o parse.o
	$(LTLINK) -o $@ rewrite.o parse.o $(LIBS)
# $OpenLDAP: pkg/ldap/build/lib.mk,v 1.18.2.3 2005/01/20 17:00:55 kurt Exp $
## Copyright 1998-2005 The OpenLDAP Foundation.
## All rights reserved.
##
## Redistribution and use in source and binary forms, with or without
## modification, are permitted only as authorized by the OpenLDAP
## Public License.
##
## A copy of this license is available in the file LICENSE in the
## top-level directory of the distribution or, alternatively, at
## <http://www.OpenLDAP.org/license.html>.
##---------------------------------------------------------------------------
#
# Makefile Template for Libraries
#

all-common: $(LIBRARY) $(PROGRAMS)

version.c: Makefile
	$(RM) $@
	$(MKVERSION) $(LIBRARY) > $@

version.o version.lo: version.c $(OBJS)

install-common: FORCE

lint: lint-local FORCE
	$(LINT) $(DEFS) $(DEFINES) $(SRCS)

lint5: lint5-local FORCE
	$(5LINT) $(DEFS) $(DEFINES) $(SRCS)

#
# In the mingw/cygwin environment, the so and dll files must be
# deleted separately, instead of using the {.so*,*.dll} construct
# that was previously used. It just didn't work.
#
clean-common: 	FORCE
	$(RM) $(LIBRARY) ../$(LIBRARY) $(XLIBRARY) \
		$(PROGRAMS) $(XPROGRAMS) $(XSRCS) $(XXSRCS) \
		*.o *.lo a.out *.exe core version.c .libs/* \
		../`$(BASENAME) $(LIBRARY) .la`.so* \
		../`$(BASENAME) $(LIBRARY) .la`*.dll

depend-common: FORCE
	$(MKDEP) $(DEFS) $(DEFINES) $(SRCS) $(XXSRCS)

lint-local: FORCE
lint5-local: FORCE

Makefile: $(top_srcdir)/build/lib.mk

# $OpenLDAP: pkg/ldap/build/lib-static.mk,v 1.8.2.3 2005/01/20 17:00:55 kurt Exp $
## Copyright 1998-2005 The OpenLDAP Foundation.
## All rights reserved.
##
## Redistribution and use in source and binary forms, with or without
## modification, are permitted only as authorized by the OpenLDAP
## Public License.
##
## A copy of this license is available in the file LICENSE in the
## top-level directory of the distribution or, alternatively, at
## <http://www.OpenLDAP.org/license.html>.
##---------------------------------------------------------------------------
#
# Makefile Template for Static Libraries
#

$(LIBRARY): version.o
	$(AR) ru $@ $(OBJS) version.o
	@$(RANLIB) $@

Makefile: $(top_srcdir)/build/lib-static.mk
# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.


#
# files: -I../../include -I../../include -I/usr/local/berkeleydb/include -D_GNU_SOURCE config.c context.c info.c ldapmap.c map.c params.c rule.c session.c subst.c var.c xmap.c parse.c rewrite.c
# command: cc -M -I.  -I../../include -I../../include -I/usr/local/berkeleydb/include -D_GNU_SOURCE config.c context.c info.c ldapmap.c map.c params.c rule.c session.c subst.c var.c xmap.c parse.c rewrite.c
#

rewrite.o: rewrite.c
rewrite.o: ../../include/portable.h
rewrite.o: /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/stddef.h
rewrite.o: ../../include/ac/fdset.h
rewrite.o: ../../include/ldap_cdefs.h
rewrite.o: ../../include/ldap_features.h
rewrite.o: ../../include/ac/assert.h
rewrite.o: /usr/include/assert.h
rewrite.o: /usr/include/features.h
rewrite.o: /usr/include/sys/cdefs.h
rewrite.o: /usr/include/bits/wordsize.h
rewrite.o: /usr/include/gnu/stubs.h
rewrite.o: /usr/include/gnu/stubs-64.h
rewrite.o: ../../include/ac/localize.h
rewrite.o: ../../include/ac/stdlib.h
rewrite.o: /usr/include/stdlib.h
rewrite.o: /usr/include/bits/waitflags.h
rewrite.o: /usr/include/bits/waitstatus.h
rewrite.o: /usr/include/endian.h
rewrite.o: /usr/include/bits/endian.h
rewrite.o: /usr/include/bits/byteswap.h
rewrite.o: /usr/include/xlocale.h
rewrite.o: /usr/include/sys/types.h
rewrite.o: /usr/include/bits/types.h
rewrite.o: /usr/include/bits/typesizes.h
rewrite.o: /usr/include/time.h
rewrite.o: /usr/include/sys/select.h
rewrite.o: /usr/include/bits/select.h
rewrite.o: /usr/include/bits/sigset.h
rewrite.o: /usr/include/bits/time.h
rewrite.o: /usr/include/sys/sysmacros.h
rewrite.o: /usr/include/bits/pthreadtypes.h
rewrite.o: /usr/include/alloca.h
rewrite.o: ../../include/ac/string.h
rewrite.o: /usr/include/string.h
rewrite.o: ../../include/ac/syslog.h
rewrite.o: /usr/include/syslog.h
rewrite.o: /usr/include/sys/syslog.h
rewrite.o: /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/stdarg.h
rewrite.o: /usr/include/bits/syslog-path.h
rewrite.o: ../../include/ac/regex.h
rewrite.o: /usr/include/regex.h
rewrite.o: ../../include/ac/socket.h
rewrite.o: /usr/include/sys/socket.h
rewrite.o: /usr/include/sys/uio.h
rewrite.o: /usr/include/bits/uio.h
rewrite.o: /usr/include/bits/socket.h
rewrite.o: /usr/include/bits/sockaddr.h
rewrite.o: /usr/include/asm/socket.h
rewrite.o: /usr/include/asm-generic/socket.h
rewrite.o: /usr/include/asm/sockios.h
rewrite.o: /usr/include/asm-generic/sockios.h
rewrite.o: /usr/include/sys/un.h
rewrite.o: /usr/include/netinet/in.h
rewrite.o: /usr/include/stdint.h
rewrite.o: /usr/include/bits/wchar.h
rewrite.o: /usr/include/bits/in.h
rewrite.o: /usr/include/netinet/tcp.h
rewrite.o: /usr/include/arpa/inet.h
rewrite.o: /usr/include/arpa/nameser.h
rewrite.o: /usr/include/sys/param.h
rewrite.o: /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/limits.h
rewrite.o: /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/syslimits.h
rewrite.o: /usr/include/limits.h
rewrite.o: /usr/include/bits/posix1_lim.h
rewrite.o: /usr/include/bits/local_lim.h
rewrite.o: /usr/include/linux/limits.h
rewrite.o: /usr/include/bits/posix2_lim.h
rewrite.o: /usr/include/bits/xopen_lim.h
rewrite.o: /usr/include/bits/stdio_lim.h
rewrite.o: /usr/include/linux/param.h
rewrite.o: /usr/include/asm/param.h
rewrite.o: /usr/include/asm-generic/param.h
rewrite.o: /usr/include/sys/bitypes.h
rewrite.o: /usr/include/arpa/nameser_compat.h
rewrite.o: /usr/include/netdb.h
rewrite.o: /usr/include/rpc/netdb.h
rewrite.o: /usr/include/bits/siginfo.h
rewrite.o: /usr/include/bits/netdb.h
rewrite.o: /usr/include/resolv.h
rewrite.o: /usr/include/stdio.h
rewrite.o: /usr/include/libio.h
rewrite.o: /usr/include/_G_config.h
rewrite.o: /usr/include/wchar.h
rewrite.o: /usr/include/bits/sys_errlist.h
rewrite.o: ../../include/ac/unistd.h
rewrite.o: /usr/include/unistd.h
rewrite.o: /usr/include/bits/posix_opt.h
rewrite.o: /usr/include/bits/environments.h
rewrite.o: /usr/include/bits/confname.h
rewrite.o: /usr/include/getopt.h
rewrite.o: ../../include/lutil_lockf.h
rewrite.o: ../../include/ac/ctype.h
rewrite.o: /usr/include/ctype.h
rewrite.o: ../../include/rewrite.h
rewrite.o: ../../include/ldap.h
rewrite.o: ../../include/lber.h
rewrite.o: ../../include/lber_types.h
rewrite.o: ../../include/ldap_cdefs.h
rewrite.o: ../../include/ldap_features.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
