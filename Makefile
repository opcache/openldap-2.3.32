# Generated automatically from dir.mk by configure.
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
top_srcdir = .
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

# Master Makefile for OpenLDAP
# $OpenLDAP: pkg/ldap/Makefile.in,v 1.24.2.3 2005/01/20 17:00:27 kurt Exp $
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

SUBDIRS= include libraries clients servers tests doc
CLEANDIRS=
INSTALLDIRS= 

makefiles:	FORCE
	./config.status

# force a make all before make install
#	only done at the top-level
install-common: all FORCE

clean-local: FORCE
	$(RM) config.log

veryclean-local: FORCE
	$(RM) config.cache config.status libtool stamp-h stamp-h.in

distclean: veryclean FORCE

check: test
test: FORCE
	cd tests; make test
# $OpenLDAP: pkg/ldap/build/dir.mk,v 1.12.2.3 2005/01/20 17:00:55 kurt Exp $
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
# Makes subdirectories
#


all-common: FORCE
	@echo "Making all in `$(PWD)`"
	@for i in $(SUBDIRS) $(ALLDIRS); do 		\
		echo "  Entering subdirectory $$i";		\
		( cd $$i; $(MAKE) $(MFLAGS) all );		\
		if test $$? != 0 ; then exit 1; fi ;	\
		echo " ";								\
	done

install-common: FORCE
	@echo "Making install in `$(PWD)`"
	@for i in $(SUBDIRS) $(INSTALLDIRS); do 	\
		echo "  Entering subdirectory $$i";		\
		( cd $$i; $(MAKE) $(MFLAGS) install );	\
		if test $$? != 0 ; then exit 1; fi ;	\
		echo " ";								\
	done

clean-common: FORCE
	@echo "Making clean in `$(PWD)`"
	@for i in $(SUBDIRS) $(CLEANDIRS); do		\
		echo "  Entering subdirectory $$i";		\
		( cd $$i; $(MAKE) $(MFLAGS) clean );	\
		if test $$? != 0 ; then exit 1; fi ;	\
		echo " ";								\
	done

veryclean-common: FORCE
	@echo "Making veryclean in `$(PWD)`"
	@for i in $(SUBDIRS) $(CLEANDIRS); do		\
		echo "  Entering subdirectory $$i";		\
		( cd $$i; $(MAKE) $(MFLAGS) veryclean );	\
		if test $$? != 0 ; then exit 1; fi ;	\
		echo " ";								\
	done

depend-common: FORCE
	@echo "Making depend in `$(PWD)`"
	@for i in $(SUBDIRS) $(DEPENDDIRS); do		\
		echo "  Entering subdirectory $$i";		\
		( cd $$i; $(MAKE) $(MFLAGS) depend );	\
		if test $$? != 0 ; then exit 1; fi ;	\
		echo " ";								\
	done

Makefile: $(top_srcdir)/build/dir.mk