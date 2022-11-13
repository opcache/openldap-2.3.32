# Generated automatically from rules.mk by configure.
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

# Makefile for LDAP tools
# $OpenLDAP: pkg/ldap/clients/tools/Makefile.in,v 1.36.2.3 2005/01/20 17:00:55 kurt Exp $
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

SRCS	= ldapsearch.c ldapmodify.c ldapdelete.c ldapmodrdn.c \
		ldappasswd.c ldapwhoami.c ldapcompare.c common.c
OBJS	= ldapsearch.o ldapmodify.o ldapdelete.o ldapmodrdn.o \
		ldappasswd.o ldapwhoami.o ldapcompare.o common.o

LDAP_INCDIR= ../../include       
LDAP_LIBDIR= ../../libraries

MKVOPTS = -s

XLIBS =  $(LDAP_L)
XXLIBS	= $(SECURITY_LIBS) $(LUTIL_LIBS)

XSRCS	= ldsversion.c ldmversion.c lddversion.c ldrversion.c \
	ldpversion.c ldwversion.c ldcversion.c

PROGRAMS = ldapsearch ldapmodify ldapdelete ldapmodrdn \
	ldappasswd ldapwhoami ldapcompare


ldapsearch:	ldsversion.o
	$(LTLINK) -o $@ ldapsearch.o common.o ldsversion.o $(LIBS)

ldapmodify:	ldmversion.o
	$(LTLINK) -o $@ ldapmodify.o common.o ldmversion.o $(LIBS)

ldapdelete:	lddversion.o
	$(LTLINK) -o $@ ldapdelete.o common.o lddversion.o $(LIBS)

ldapmodrdn:	ldrversion.o
	$(LTLINK) -o $@ ldapmodrdn.o common.o ldrversion.o $(LIBS)

ldappasswd:	ldpversion.o
	$(LTLINK) -o $@ ldappasswd.o common.o ldpversion.o $(LIBS)

ldapwhoami:	ldwversion.o
	$(LTLINK) -o $@ ldapwhoami.o common.o ldwversion.o $(LIBS)

ldapcompare: ldcversion.o
	$(LTLINK) -o $@ ldapcompare.o common.o ldcversion.o $(LIBS)

ldsversion.c: Makefile
	@-$(RM) $@
	$(MKVERSION) $(MKVOPTS) ldapsearch > $@

ldsversion.o: ldapsearch.o common.o $(XLIBS)

ldmversion.c: Makefile
	@-$(RM) $@
	$(MKVERSION) $(MKVOPTS) ldapmodify > $@

ldmversion.o: ldapmodify.o common.o $(XLIBS)

lddversion.c: Makefile
	@-$(RM) $@
	$(MKVERSION) $(MKVOPTS) ldapdelete > $@

lddversion.o: ldapdelete.o common.o $(XLIBS)

ldpversion.c: Makefile
	@-$(RM) $@
	$(MKVERSION) $(MKVOPTS) ldappasswd > $@

ldpversion.o: ldappasswd.o common.o $(XLIBS)

ldrversion.c: Makefile
	@-$(RM) $@
	$(MKVERSION) $(MKVOPTS) ldapmodrdn > $@

ldrversion.o: ldapmodrdn.o common.o $(XLIBS)

ldwversion.c: Makefile
	@-$(RM) $@
	$(MKVERSION) $(MKVOPTS) ldapwhoami > $@

ldwversion.o: ldapwhoami.o common.o $(XLIBS)

ldcversion.c: Makefile
	@-$(RM) $@
	$(MKVERSION) $(MKVOPTS) ldapcompare > $@

ldcversion.o: ldapcompare.o common.o $(XLIBS)

install-local:	FORCE
	-$(MKDIR) $(DESTDIR)$(bindir)
	@(								\
	    for prg in $(PROGRAMS); do					\
		$(LTINSTALL) $(INSTALLFLAGS) -s -m 755 $$prg$(EXEEXT)	\
		    $(DESTDIR)$(bindir);				\
	    done							\
	)
	$(RM) $(DESTDIR)$(bindir)/ldapadd$(EXEEXT)
	$(LN) $(DESTDIR)$(bindir)/ldapmodify$(EXEEXT) $(DESTDIR)$(bindir)/ldapadd$(EXEEXT)

# $OpenLDAP: pkg/ldap/build/rules.mk,v 1.10.2.3 2005/01/20 17:00:55 kurt Exp $
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
# Makefile Template for Programs
#

all-common: $(PROGRAMS) FORCE

clean-common: 	FORCE
	$(RM) $(PROGRAMS) $(XPROGRAMS) $(XSRCS) *.o *.lo a.out core *.core \
		    .libs/* *.exe

depend-common: FORCE
	$(MKDEP) $(DEFS) $(DEFINES) $(SRCS)

lint: FORCE
	$(LINT) $(DEFS) $(DEFINES) $(SRCS)

lint5: FORCE
	$(5LINT) $(DEFS) $(DEFINES) $(SRCS)

Makefile: $(top_srcdir)/build/rules.mk

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.


#
# files: -I../../include -I../../include -I/usr/local/berkeleydb/include -D_GNU_SOURCE ldapsearch.c ldapmodify.c ldapdelete.c ldapmodrdn.c ldappasswd.c ldapwhoami.c ldapcompare.c common.c
# command: cc -M -I.  -I../../include -I../../include -I/usr/local/berkeleydb/include -D_GNU_SOURCE ldapsearch.c ldapmodify.c ldapdelete.c ldapmodrdn.c ldappasswd.c ldapwhoami.c ldapcompare.c common.c
#

ldapsearch.o: ldapsearch.c
ldapsearch.o: ../../include/portable.h
ldapsearch.o: /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/stddef.h
ldapsearch.o: ../../include/ac/fdset.h
ldapsearch.o: ../../include/ldap_cdefs.h
ldapsearch.o: ../../include/ldap_features.h
ldapsearch.o: ../../include/ac/assert.h
ldapsearch.o: /usr/include/assert.h
ldapsearch.o: /usr/include/features.h
ldapsearch.o: /usr/include/sys/cdefs.h
ldapsearch.o: /usr/include/bits/wordsize.h
ldapsearch.o: /usr/include/gnu/stubs.h
ldapsearch.o: /usr/include/gnu/stubs-64.h
ldapsearch.o: ../../include/ac/localize.h
ldapsearch.o: /usr/include/stdio.h
ldapsearch.o: /usr/include/bits/types.h
ldapsearch.o: /usr/include/bits/typesizes.h
ldapsearch.o: /usr/include/libio.h
ldapsearch.o: /usr/include/_G_config.h
ldapsearch.o: /usr/include/wchar.h
ldapsearch.o: /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/stdarg.h
ldapsearch.o: /usr/include/bits/stdio_lim.h
ldapsearch.o: /usr/include/bits/sys_errlist.h
ldapsearch.o: ../../include/ac/stdlib.h
ldapsearch.o: /usr/include/stdlib.h
ldapsearch.o: /usr/include/bits/waitflags.h
ldapsearch.o: /usr/include/bits/waitstatus.h
ldapsearch.o: /usr/include/endian.h
ldapsearch.o: /usr/include/bits/endian.h
ldapsearch.o: /usr/include/bits/byteswap.h
ldapsearch.o: /usr/include/xlocale.h
ldapsearch.o: /usr/include/sys/types.h
ldapsearch.o: /usr/include/time.h
ldapsearch.o: /usr/include/sys/select.h
ldapsearch.o: /usr/include/bits/select.h
ldapsearch.o: /usr/include/bits/sigset.h
ldapsearch.o: /usr/include/bits/time.h
ldapsearch.o: /usr/include/sys/sysmacros.h
ldapsearch.o: /usr/include/bits/pthreadtypes.h
ldapsearch.o: /usr/include/alloca.h
ldapsearch.o: ../../include/ac/ctype.h
ldapsearch.o: /usr/include/ctype.h
ldapsearch.o: ../../include/ac/string.h
ldapsearch.o: /usr/include/string.h
ldapsearch.o: ../../include/ac/unistd.h
ldapsearch.o: /usr/include/unistd.h
ldapsearch.o: /usr/include/bits/posix_opt.h
ldapsearch.o: /usr/include/bits/environments.h
ldapsearch.o: /usr/include/bits/confname.h
ldapsearch.o: /usr/include/getopt.h
ldapsearch.o: ../../include/lutil_lockf.h
ldapsearch.o: ../../include/ac/errno.h
ldapsearch.o: /usr/include/errno.h
ldapsearch.o: /usr/include/bits/errno.h
ldapsearch.o: /usr/include/linux/errno.h
ldapsearch.o: /usr/include/asm/errno.h
ldapsearch.o: /usr/include/asm-generic/errno.h
ldapsearch.o: /usr/include/asm-generic/errno-base.h
ldapsearch.o: /usr/include/sys/stat.h
ldapsearch.o: /usr/include/bits/stat.h
ldapsearch.o: /usr/include/fcntl.h
ldapsearch.o: /usr/include/bits/fcntl.h
ldapsearch.o: /usr/include/bits/uio.h
ldapsearch.o: ../../include/ldap.h
ldapsearch.o: ../../include/lber.h
ldapsearch.o: ../../include/lber_types.h
ldapsearch.o: ../../include/ldap_cdefs.h
ldapsearch.o: ../../include/ldap_features.h
ldapsearch.o: ../../include/ldif.h
ldapsearch.o: ../../include/lutil.h
ldapsearch.o: ../../include/lutil_ldap.h
ldapsearch.o: ../../include/ldap_defaults.h
ldapsearch.o: ../../include/ldap_config.h
ldapsearch.o: ../../include/ldap_log.h
ldapsearch.o: ../../include/ldap_pvt.h
ldapsearch.o: ../../include/ldap_pvt_uc.h
ldapsearch.o: ../../include/ac/bytes.h
ldapsearch.o: ../../include/../libraries/liblunicode/ucdata/ucdata.h
ldapsearch.o: common.h
ldapmodify.o: ldapmodify.c
ldapmodify.o: ../../include/portable.h
ldapmodify.o: /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/stddef.h
ldapmodify.o: ../../include/ac/fdset.h
ldapmodify.o: ../../include/ldap_cdefs.h
ldapmodify.o: ../../include/ldap_features.h
ldapmodify.o: ../../include/ac/assert.h
ldapmodify.o: /usr/include/assert.h
ldapmodify.o: /usr/include/features.h
ldapmodify.o: /usr/include/sys/cdefs.h
ldapmodify.o: /usr/include/bits/wordsize.h
ldapmodify.o: /usr/include/gnu/stubs.h
ldapmodify.o: /usr/include/gnu/stubs-64.h
ldapmodify.o: ../../include/ac/localize.h
ldapmodify.o: /usr/include/stdio.h
ldapmodify.o: /usr/include/bits/types.h
ldapmodify.o: /usr/include/bits/typesizes.h
ldapmodify.o: /usr/include/libio.h
ldapmodify.o: /usr/include/_G_config.h
ldapmodify.o: /usr/include/wchar.h
ldapmodify.o: /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/stdarg.h
ldapmodify.o: /usr/include/bits/stdio_lim.h
ldapmodify.o: /usr/include/bits/sys_errlist.h
ldapmodify.o: ../../include/ac/stdlib.h
ldapmodify.o: /usr/include/stdlib.h
ldapmodify.o: /usr/include/bits/waitflags.h
ldapmodify.o: /usr/include/bits/waitstatus.h
ldapmodify.o: /usr/include/endian.h
ldapmodify.o: /usr/include/bits/endian.h
ldapmodify.o: /usr/include/bits/byteswap.h
ldapmodify.o: /usr/include/xlocale.h
ldapmodify.o: /usr/include/sys/types.h
ldapmodify.o: /usr/include/time.h
ldapmodify.o: /usr/include/sys/select.h
ldapmodify.o: /usr/include/bits/select.h
ldapmodify.o: /usr/include/bits/sigset.h
ldapmodify.o: /usr/include/bits/time.h
ldapmodify.o: /usr/include/sys/sysmacros.h
ldapmodify.o: /usr/include/bits/pthreadtypes.h
ldapmodify.o: /usr/include/alloca.h
ldapmodify.o: ../../include/ac/ctype.h
ldapmodify.o: /usr/include/ctype.h
ldapmodify.o: ../../include/ac/string.h
ldapmodify.o: /usr/include/string.h
ldapmodify.o: ../../include/ac/unistd.h
ldapmodify.o: /usr/include/unistd.h
ldapmodify.o: /usr/include/bits/posix_opt.h
ldapmodify.o: /usr/include/bits/environments.h
ldapmodify.o: /usr/include/bits/confname.h
ldapmodify.o: /usr/include/getopt.h
ldapmodify.o: ../../include/lutil_lockf.h
ldapmodify.o: /usr/include/sys/stat.h
ldapmodify.o: /usr/include/bits/stat.h
ldapmodify.o: /usr/include/sys/file.h
ldapmodify.o: /usr/include/fcntl.h
ldapmodify.o: /usr/include/bits/fcntl.h
ldapmodify.o: /usr/include/bits/uio.h
ldapmodify.o: ../../include/ldap.h
ldapmodify.o: ../../include/lber.h
ldapmodify.o: ../../include/lber_types.h
ldapmodify.o: ../../include/ldap_cdefs.h
ldapmodify.o: ../../include/ldap_features.h
ldapmodify.o: ../../include/lutil.h
ldapmodify.o: ../../include/lutil_ldap.h
ldapmodify.o: ../../include/ldif.h
ldapmodify.o: ../../include/ldap_defaults.h
ldapmodify.o: ../../include/ldap_config.h
ldapmodify.o: ../../include/ldap_log.h
ldapmodify.o: ../../include/ldap_pvt.h
ldapmodify.o: ../../include/ldap_pvt_uc.h
ldapmodify.o: ../../include/ac/bytes.h
ldapmodify.o: ../../include/../libraries/liblunicode/ucdata/ucdata.h
ldapmodify.o: common.h
ldapdelete.o: ldapdelete.c
ldapdelete.o: ../../include/portable.h
ldapdelete.o: /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/stddef.h
ldapdelete.o: ../../include/ac/fdset.h
ldapdelete.o: ../../include/ldap_cdefs.h
ldapdelete.o: ../../include/ldap_features.h
ldapdelete.o: ../../include/ac/assert.h
ldapdelete.o: /usr/include/assert.h
ldapdelete.o: /usr/include/features.h
ldapdelete.o: /usr/include/sys/cdefs.h
ldapdelete.o: /usr/include/bits/wordsize.h
ldapdelete.o: /usr/include/gnu/stubs.h
ldapdelete.o: /usr/include/gnu/stubs-64.h
ldapdelete.o: ../../include/ac/localize.h
ldapdelete.o: /usr/include/stdio.h
ldapdelete.o: /usr/include/bits/types.h
ldapdelete.o: /usr/include/bits/typesizes.h
ldapdelete.o: /usr/include/libio.h
ldapdelete.o: /usr/include/_G_config.h
ldapdelete.o: /usr/include/wchar.h
ldapdelete.o: /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/stdarg.h
ldapdelete.o: /usr/include/bits/stdio_lim.h
ldapdelete.o: /usr/include/bits/sys_errlist.h
ldapdelete.o: ../../include/ac/stdlib.h
ldapdelete.o: /usr/include/stdlib.h
ldapdelete.o: /usr/include/bits/waitflags.h
ldapdelete.o: /usr/include/bits/waitstatus.h
ldapdelete.o: /usr/include/endian.h
ldapdelete.o: /usr/include/bits/endian.h
ldapdelete.o: /usr/include/bits/byteswap.h
ldapdelete.o: /usr/include/xlocale.h
ldapdelete.o: /usr/include/sys/types.h
ldapdelete.o: /usr/include/time.h
ldapdelete.o: /usr/include/sys/select.h
ldapdelete.o: /usr/include/bits/select.h
ldapdelete.o: /usr/include/bits/sigset.h
ldapdelete.o: /usr/include/bits/time.h
ldapdelete.o: /usr/include/sys/sysmacros.h
ldapdelete.o: /usr/include/bits/pthreadtypes.h
ldapdelete.o: /usr/include/alloca.h
ldapdelete.o: ../../include/ac/ctype.h
ldapdelete.o: /usr/include/ctype.h
ldapdelete.o: ../../include/ac/string.h
ldapdelete.o: /usr/include/string.h
ldapdelete.o: ../../include/ac/unistd.h
ldapdelete.o: /usr/include/unistd.h
ldapdelete.o: /usr/include/bits/posix_opt.h
ldapdelete.o: /usr/include/bits/environments.h
ldapdelete.o: /usr/include/bits/confname.h
ldapdelete.o: /usr/include/getopt.h
ldapdelete.o: ../../include/lutil_lockf.h
ldapdelete.o: ../../include/ldap.h
ldapdelete.o: ../../include/lber.h
ldapdelete.o: ../../include/lber_types.h
ldapdelete.o: ../../include/ldap_cdefs.h
ldapdelete.o: ../../include/ldap_features.h
ldapdelete.o: ../../include/lutil.h
ldapdelete.o: ../../include/lutil_ldap.h
ldapdelete.o: ../../include/ldap_defaults.h
ldapdelete.o: ../../include/ldap_config.h
ldapdelete.o: common.h
ldapmodrdn.o: ldapmodrdn.c
ldapmodrdn.o: ../../include/portable.h
ldapmodrdn.o: /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/stddef.h
ldapmodrdn.o: ../../include/ac/fdset.h
ldapmodrdn.o: ../../include/ldap_cdefs.h
ldapmodrdn.o: ../../include/ldap_features.h
ldapmodrdn.o: ../../include/ac/assert.h
ldapmodrdn.o: /usr/include/assert.h
ldapmodrdn.o: /usr/include/features.h
ldapmodrdn.o: /usr/include/sys/cdefs.h
ldapmodrdn.o: /usr/include/bits/wordsize.h
ldapmodrdn.o: /usr/include/gnu/stubs.h
ldapmodrdn.o: /usr/include/gnu/stubs-64.h
ldapmodrdn.o: ../../include/ac/localize.h
ldapmodrdn.o: /usr/include/stdio.h
ldapmodrdn.o: /usr/include/bits/types.h
ldapmodrdn.o: /usr/include/bits/typesizes.h
ldapmodrdn.o: /usr/include/libio.h
ldapmodrdn.o: /usr/include/_G_config.h
ldapmodrdn.o: /usr/include/wchar.h
ldapmodrdn.o: /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/stdarg.h
ldapmodrdn.o: /usr/include/bits/stdio_lim.h
ldapmodrdn.o: /usr/include/bits/sys_errlist.h
ldapmodrdn.o: ../../include/ac/stdlib.h
ldapmodrdn.o: /usr/include/stdlib.h
ldapmodrdn.o: /usr/include/bits/waitflags.h
ldapmodrdn.o: /usr/include/bits/waitstatus.h
ldapmodrdn.o: /usr/include/endian.h
ldapmodrdn.o: /usr/include/bits/endian.h
ldapmodrdn.o: /usr/include/bits/byteswap.h
ldapmodrdn.o: /usr/include/xlocale.h
ldapmodrdn.o: /usr/include/sys/types.h
ldapmodrdn.o: /usr/include/time.h
ldapmodrdn.o: /usr/include/sys/select.h
ldapmodrdn.o: /usr/include/bits/select.h
ldapmodrdn.o: /usr/include/bits/sigset.h
ldapmodrdn.o: /usr/include/bits/time.h
ldapmodrdn.o: /usr/include/sys/sysmacros.h
ldapmodrdn.o: /usr/include/bits/pthreadtypes.h
ldapmodrdn.o: /usr/include/alloca.h
ldapmodrdn.o: ../../include/ac/ctype.h
ldapmodrdn.o: /usr/include/ctype.h
ldapmodrdn.o: ../../include/ac/string.h
ldapmodrdn.o: /usr/include/string.h
ldapmodrdn.o: ../../include/ac/unistd.h
ldapmodrdn.o: /usr/include/unistd.h
ldapmodrdn.o: /usr/include/bits/posix_opt.h
ldapmodrdn.o: /usr/include/bits/environments.h
ldapmodrdn.o: /usr/include/bits/confname.h
ldapmodrdn.o: /usr/include/getopt.h
ldapmodrdn.o: ../../include/lutil_lockf.h
ldapmodrdn.o: ../../include/ldap.h
ldapmodrdn.o: ../../include/lber.h
ldapmodrdn.o: ../../include/lber_types.h
ldapmodrdn.o: ../../include/ldap_cdefs.h
ldapmodrdn.o: ../../include/ldap_features.h
ldapmodrdn.o: ../../include/lutil.h
ldapmodrdn.o: ../../include/lutil_ldap.h
ldapmodrdn.o: ../../include/ldap_defaults.h
ldapmodrdn.o: ../../include/ldap_config.h
ldapmodrdn.o: common.h
ldappasswd.o: ldappasswd.c
ldappasswd.o: ../../include/portable.h
ldappasswd.o: /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/stddef.h
ldappasswd.o: ../../include/ac/fdset.h
ldappasswd.o: ../../include/ldap_cdefs.h
ldappasswd.o: ../../include/ldap_features.h
ldappasswd.o: ../../include/ac/assert.h
ldappasswd.o: /usr/include/assert.h
ldappasswd.o: /usr/include/features.h
ldappasswd.o: /usr/include/sys/cdefs.h
ldappasswd.o: /usr/include/bits/wordsize.h
ldappasswd.o: /usr/include/gnu/stubs.h
ldappasswd.o: /usr/include/gnu/stubs-64.h
ldappasswd.o: ../../include/ac/localize.h
ldappasswd.o: /usr/include/stdio.h
ldappasswd.o: /usr/include/bits/types.h
ldappasswd.o: /usr/include/bits/typesizes.h
ldappasswd.o: /usr/include/libio.h
ldappasswd.o: /usr/include/_G_config.h
ldappasswd.o: /usr/include/wchar.h
ldappasswd.o: /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/stdarg.h
ldappasswd.o: /usr/include/bits/stdio_lim.h
ldappasswd.o: /usr/include/bits/sys_errlist.h
ldappasswd.o: ../../include/ac/stdlib.h
ldappasswd.o: /usr/include/stdlib.h
ldappasswd.o: /usr/include/bits/waitflags.h
ldappasswd.o: /usr/include/bits/waitstatus.h
ldappasswd.o: /usr/include/endian.h
ldappasswd.o: /usr/include/bits/endian.h
ldappasswd.o: /usr/include/bits/byteswap.h
ldappasswd.o: /usr/include/xlocale.h
ldappasswd.o: /usr/include/sys/types.h
ldappasswd.o: /usr/include/time.h
ldappasswd.o: /usr/include/sys/select.h
ldappasswd.o: /usr/include/bits/select.h
ldappasswd.o: /usr/include/bits/sigset.h
ldappasswd.o: /usr/include/bits/time.h
ldappasswd.o: /usr/include/sys/sysmacros.h
ldappasswd.o: /usr/include/bits/pthreadtypes.h
ldappasswd.o: /usr/include/alloca.h
ldappasswd.o: ../../include/ac/ctype.h
ldappasswd.o: /usr/include/ctype.h
ldappasswd.o: ../../include/ac/socket.h
ldappasswd.o: /usr/include/sys/socket.h
ldappasswd.o: /usr/include/sys/uio.h
ldappasswd.o: /usr/include/bits/uio.h
ldappasswd.o: /usr/include/bits/socket.h
ldappasswd.o: /usr/include/bits/sockaddr.h
ldappasswd.o: /usr/include/asm/socket.h
ldappasswd.o: /usr/include/asm-generic/socket.h
ldappasswd.o: /usr/include/asm/sockios.h
ldappasswd.o: /usr/include/asm-generic/sockios.h
ldappasswd.o: /usr/include/sys/un.h
ldappasswd.o: /usr/include/string.h
ldappasswd.o: /usr/include/netinet/in.h
ldappasswd.o: /usr/include/stdint.h
ldappasswd.o: /usr/include/bits/wchar.h
ldappasswd.o: /usr/include/bits/in.h
ldappasswd.o: /usr/include/netinet/tcp.h
ldappasswd.o: /usr/include/arpa/inet.h
ldappasswd.o: /usr/include/arpa/nameser.h
ldappasswd.o: /usr/include/sys/param.h
ldappasswd.o: /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/limits.h
ldappasswd.o: /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/syslimits.h
ldappasswd.o: /usr/include/limits.h
ldappasswd.o: /usr/include/bits/posix1_lim.h
ldappasswd.o: /usr/include/bits/local_lim.h
ldappasswd.o: /usr/include/linux/limits.h
ldappasswd.o: /usr/include/bits/posix2_lim.h
ldappasswd.o: /usr/include/bits/xopen_lim.h
ldappasswd.o: /usr/include/linux/param.h
ldappasswd.o: /usr/include/asm/param.h
ldappasswd.o: /usr/include/asm-generic/param.h
ldappasswd.o: /usr/include/sys/bitypes.h
ldappasswd.o: /usr/include/arpa/nameser_compat.h
ldappasswd.o: /usr/include/netdb.h
ldappasswd.o: /usr/include/rpc/netdb.h
ldappasswd.o: /usr/include/bits/siginfo.h
ldappasswd.o: /usr/include/bits/netdb.h
ldappasswd.o: /usr/include/resolv.h
ldappasswd.o: ../../include/ac/string.h
ldappasswd.o: ../../include/ac/time.h
ldappasswd.o: /usr/include/sys/time.h
ldappasswd.o: ../../include/ac/unistd.h
ldappasswd.o: /usr/include/unistd.h
ldappasswd.o: /usr/include/bits/posix_opt.h
ldappasswd.o: /usr/include/bits/environments.h
ldappasswd.o: /usr/include/bits/confname.h
ldappasswd.o: /usr/include/getopt.h
ldappasswd.o: ../../include/lutil_lockf.h
ldappasswd.o: ../../include/ldap.h
ldappasswd.o: ../../include/lber.h
ldappasswd.o: ../../include/lber_types.h
ldappasswd.o: ../../include/ldap_cdefs.h
ldappasswd.o: ../../include/ldap_features.h
ldappasswd.o: ../../include/lutil.h
ldappasswd.o: ../../include/lutil_ldap.h
ldappasswd.o: ../../include/ldap_defaults.h
ldappasswd.o: ../../include/ldap_config.h
ldappasswd.o: common.h
ldapwhoami.o: ldapwhoami.c
ldapwhoami.o: ../../include/portable.h
ldapwhoami.o: /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/stddef.h
ldapwhoami.o: ../../include/ac/fdset.h
ldapwhoami.o: ../../include/ldap_cdefs.h
ldapwhoami.o: ../../include/ldap_features.h
ldapwhoami.o: ../../include/ac/assert.h
ldapwhoami.o: /usr/include/assert.h
ldapwhoami.o: /usr/include/features.h
ldapwhoami.o: /usr/include/sys/cdefs.h
ldapwhoami.o: /usr/include/bits/wordsize.h
ldapwhoami.o: /usr/include/gnu/stubs.h
ldapwhoami.o: /usr/include/gnu/stubs-64.h
ldapwhoami.o: ../../include/ac/localize.h
ldapwhoami.o: /usr/include/stdio.h
ldapwhoami.o: /usr/include/bits/types.h
ldapwhoami.o: /usr/include/bits/typesizes.h
ldapwhoami.o: /usr/include/libio.h
ldapwhoami.o: /usr/include/_G_config.h
ldapwhoami.o: /usr/include/wchar.h
ldapwhoami.o: /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/stdarg.h
ldapwhoami.o: /usr/include/bits/stdio_lim.h
ldapwhoami.o: /usr/include/bits/sys_errlist.h
ldapwhoami.o: ../../include/ac/stdlib.h
ldapwhoami.o: /usr/include/stdlib.h
ldapwhoami.o: /usr/include/bits/waitflags.h
ldapwhoami.o: /usr/include/bits/waitstatus.h
ldapwhoami.o: /usr/include/endian.h
ldapwhoami.o: /usr/include/bits/endian.h
ldapwhoami.o: /usr/include/bits/byteswap.h
ldapwhoami.o: /usr/include/xlocale.h
ldapwhoami.o: /usr/include/sys/types.h
ldapwhoami.o: /usr/include/time.h
ldapwhoami.o: /usr/include/sys/select.h
ldapwhoami.o: /usr/include/bits/select.h
ldapwhoami.o: /usr/include/bits/sigset.h
ldapwhoami.o: /usr/include/bits/time.h
ldapwhoami.o: /usr/include/sys/sysmacros.h
ldapwhoami.o: /usr/include/bits/pthreadtypes.h
ldapwhoami.o: /usr/include/alloca.h
ldapwhoami.o: ../../include/ac/ctype.h
ldapwhoami.o: /usr/include/ctype.h
ldapwhoami.o: ../../include/ac/socket.h
ldapwhoami.o: /usr/include/sys/socket.h
ldapwhoami.o: /usr/include/sys/uio.h
ldapwhoami.o: /usr/include/bits/uio.h
ldapwhoami.o: /usr/include/bits/socket.h
ldapwhoami.o: /usr/include/bits/sockaddr.h
ldapwhoami.o: /usr/include/asm/socket.h
ldapwhoami.o: /usr/include/asm-generic/socket.h
ldapwhoami.o: /usr/include/asm/sockios.h
ldapwhoami.o: /usr/include/asm-generic/sockios.h
ldapwhoami.o: /usr/include/sys/un.h
ldapwhoami.o: /usr/include/string.h
ldapwhoami.o: /usr/include/netinet/in.h
ldapwhoami.o: /usr/include/stdint.h
ldapwhoami.o: /usr/include/bits/wchar.h
ldapwhoami.o: /usr/include/bits/in.h
ldapwhoami.o: /usr/include/netinet/tcp.h
ldapwhoami.o: /usr/include/arpa/inet.h
ldapwhoami.o: /usr/include/arpa/nameser.h
ldapwhoami.o: /usr/include/sys/param.h
ldapwhoami.o: /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/limits.h
ldapwhoami.o: /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/syslimits.h
ldapwhoami.o: /usr/include/limits.h
ldapwhoami.o: /usr/include/bits/posix1_lim.h
ldapwhoami.o: /usr/include/bits/local_lim.h
ldapwhoami.o: /usr/include/linux/limits.h
ldapwhoami.o: /usr/include/bits/posix2_lim.h
ldapwhoami.o: /usr/include/bits/xopen_lim.h
ldapwhoami.o: /usr/include/linux/param.h
ldapwhoami.o: /usr/include/asm/param.h
ldapwhoami.o: /usr/include/asm-generic/param.h
ldapwhoami.o: /usr/include/sys/bitypes.h
ldapwhoami.o: /usr/include/arpa/nameser_compat.h
ldapwhoami.o: /usr/include/netdb.h
ldapwhoami.o: /usr/include/rpc/netdb.h
ldapwhoami.o: /usr/include/bits/siginfo.h
ldapwhoami.o: /usr/include/bits/netdb.h
ldapwhoami.o: /usr/include/resolv.h
ldapwhoami.o: ../../include/ac/string.h
ldapwhoami.o: ../../include/ac/time.h
ldapwhoami.o: /usr/include/sys/time.h
ldapwhoami.o: ../../include/ac/unistd.h
ldapwhoami.o: /usr/include/unistd.h
ldapwhoami.o: /usr/include/bits/posix_opt.h
ldapwhoami.o: /usr/include/bits/environments.h
ldapwhoami.o: /usr/include/bits/confname.h
ldapwhoami.o: /usr/include/getopt.h
ldapwhoami.o: ../../include/lutil_lockf.h
ldapwhoami.o: ../../include/ldap.h
ldapwhoami.o: ../../include/lber.h
ldapwhoami.o: ../../include/lber_types.h
ldapwhoami.o: ../../include/ldap_cdefs.h
ldapwhoami.o: ../../include/ldap_features.h
ldapwhoami.o: ../../include/lutil.h
ldapwhoami.o: ../../include/lutil_ldap.h
ldapwhoami.o: ../../include/ldap_defaults.h
ldapwhoami.o: ../../include/ldap_config.h
ldapwhoami.o: common.h
ldapcompare.o: ldapcompare.c
ldapcompare.o: ../../include/portable.h
ldapcompare.o: /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/stddef.h
ldapcompare.o: ../../include/ac/fdset.h
ldapcompare.o: ../../include/ldap_cdefs.h
ldapcompare.o: ../../include/ldap_features.h
ldapcompare.o: ../../include/ac/assert.h
ldapcompare.o: /usr/include/assert.h
ldapcompare.o: /usr/include/features.h
ldapcompare.o: /usr/include/sys/cdefs.h
ldapcompare.o: /usr/include/bits/wordsize.h
ldapcompare.o: /usr/include/gnu/stubs.h
ldapcompare.o: /usr/include/gnu/stubs-64.h
ldapcompare.o: ../../include/ac/localize.h
ldapcompare.o: /usr/include/stdio.h
ldapcompare.o: /usr/include/bits/types.h
ldapcompare.o: /usr/include/bits/typesizes.h
ldapcompare.o: /usr/include/libio.h
ldapcompare.o: /usr/include/_G_config.h
ldapcompare.o: /usr/include/wchar.h
ldapcompare.o: /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/stdarg.h
ldapcompare.o: /usr/include/bits/stdio_lim.h
ldapcompare.o: /usr/include/bits/sys_errlist.h
ldapcompare.o: ../../include/ac/stdlib.h
ldapcompare.o: /usr/include/stdlib.h
ldapcompare.o: /usr/include/bits/waitflags.h
ldapcompare.o: /usr/include/bits/waitstatus.h
ldapcompare.o: /usr/include/endian.h
ldapcompare.o: /usr/include/bits/endian.h
ldapcompare.o: /usr/include/bits/byteswap.h
ldapcompare.o: /usr/include/xlocale.h
ldapcompare.o: /usr/include/sys/types.h
ldapcompare.o: /usr/include/time.h
ldapcompare.o: /usr/include/sys/select.h
ldapcompare.o: /usr/include/bits/select.h
ldapcompare.o: /usr/include/bits/sigset.h
ldapcompare.o: /usr/include/bits/time.h
ldapcompare.o: /usr/include/sys/sysmacros.h
ldapcompare.o: /usr/include/bits/pthreadtypes.h
ldapcompare.o: /usr/include/alloca.h
ldapcompare.o: ../../include/ac/ctype.h
ldapcompare.o: /usr/include/ctype.h
ldapcompare.o: ../../include/ac/string.h
ldapcompare.o: /usr/include/string.h
ldapcompare.o: ../../include/ac/unistd.h
ldapcompare.o: /usr/include/unistd.h
ldapcompare.o: /usr/include/bits/posix_opt.h
ldapcompare.o: /usr/include/bits/environments.h
ldapcompare.o: /usr/include/bits/confname.h
ldapcompare.o: /usr/include/getopt.h
ldapcompare.o: ../../include/lutil_lockf.h
ldapcompare.o: ../../include/ac/errno.h
ldapcompare.o: /usr/include/errno.h
ldapcompare.o: /usr/include/bits/errno.h
ldapcompare.o: /usr/include/linux/errno.h
ldapcompare.o: /usr/include/asm/errno.h
ldapcompare.o: /usr/include/asm-generic/errno.h
ldapcompare.o: /usr/include/asm-generic/errno-base.h
ldapcompare.o: /usr/include/sys/stat.h
ldapcompare.o: /usr/include/bits/stat.h
ldapcompare.o: /usr/include/fcntl.h
ldapcompare.o: /usr/include/bits/fcntl.h
ldapcompare.o: /usr/include/bits/uio.h
ldapcompare.o: ../../include/ldap.h
ldapcompare.o: ../../include/lber.h
ldapcompare.o: ../../include/lber_types.h
ldapcompare.o: ../../include/ldap_cdefs.h
ldapcompare.o: ../../include/ldap_features.h
ldapcompare.o: ../../include/lutil.h
ldapcompare.o: ../../include/lutil_ldap.h
ldapcompare.o: ../../include/ldap_defaults.h
ldapcompare.o: ../../include/ldap_config.h
ldapcompare.o: common.h
common.o: common.c
common.o: ../../include/portable.h
common.o: /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/stddef.h
common.o: ../../include/ac/fdset.h
common.o: ../../include/ldap_cdefs.h
common.o: ../../include/ldap_features.h
common.o: ../../include/ac/assert.h
common.o: /usr/include/assert.h
common.o: /usr/include/features.h
common.o: /usr/include/sys/cdefs.h
common.o: /usr/include/bits/wordsize.h
common.o: /usr/include/gnu/stubs.h
common.o: /usr/include/gnu/stubs-64.h
common.o: ../../include/ac/localize.h
common.o: /usr/include/stdio.h
common.o: /usr/include/bits/types.h
common.o: /usr/include/bits/typesizes.h
common.o: /usr/include/libio.h
common.o: /usr/include/_G_config.h
common.o: /usr/include/wchar.h
common.o: /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/stdarg.h
common.o: /usr/include/bits/stdio_lim.h
common.o: /usr/include/bits/sys_errlist.h
common.o: ../../include/ac/stdlib.h
common.o: /usr/include/stdlib.h
common.o: /usr/include/bits/waitflags.h
common.o: /usr/include/bits/waitstatus.h
common.o: /usr/include/endian.h
common.o: /usr/include/bits/endian.h
common.o: /usr/include/bits/byteswap.h
common.o: /usr/include/xlocale.h
common.o: /usr/include/sys/types.h
common.o: /usr/include/time.h
common.o: /usr/include/sys/select.h
common.o: /usr/include/bits/select.h
common.o: /usr/include/bits/sigset.h
common.o: /usr/include/bits/time.h
common.o: /usr/include/sys/sysmacros.h
common.o: /usr/include/bits/pthreadtypes.h
common.o: /usr/include/alloca.h
common.o: ../../include/ac/signal.h
common.o: /usr/include/signal.h
common.o: /usr/include/bits/signum.h
common.o: /usr/include/bits/siginfo.h
common.o: /usr/include/bits/sigaction.h
common.o: /usr/include/bits/sigcontext.h
common.o: /usr/include/bits/sigstack.h
common.o: /usr/include/sys/ucontext.h
common.o: /usr/include/bits/sigthread.h
common.o: ../../include/ac/string.h
common.o: /usr/include/string.h
common.o: ../../include/ac/unistd.h
common.o: /usr/include/unistd.h
common.o: /usr/include/bits/posix_opt.h
common.o: /usr/include/bits/environments.h
common.o: /usr/include/bits/confname.h
common.o: /usr/include/getopt.h
common.o: ../../include/lutil_lockf.h
common.o: ../../include/ac/errno.h
common.o: /usr/include/errno.h
common.o: /usr/include/bits/errno.h
common.o: /usr/include/linux/errno.h
common.o: /usr/include/asm/errno.h
common.o: /usr/include/asm-generic/errno.h
common.o: /usr/include/asm-generic/errno-base.h
common.o: ../../include/ldap.h
common.o: ../../include/lber.h
common.o: ../../include/lber_types.h
common.o: ../../include/ldap_cdefs.h
common.o: ../../include/ldap_features.h
common.o: ../../include/lutil_ldap.h
common.o: ../../include/ldap_defaults.h
common.o: ../../include/ldap_config.h
common.o: ../../include/ldap_pvt.h
common.o: ../../include/ldap_pvt_uc.h
common.o: ../../include/ac/bytes.h
common.o: ../../include/../libraries/liblunicode/ucdata/ucdata.h
common.o: ../../include/lber_pvt.h
common.o: common.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
