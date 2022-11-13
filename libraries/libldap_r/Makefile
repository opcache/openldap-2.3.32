# Generated automatically from lib-shared.mk by configure.
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

# Makefile.in for LDAP -lldap
# $OpenLDAP: pkg/ldap/libraries/libldap_r/Makefile.in,v 1.64.2.3 2005/01/20 17:01:02 kurt Exp $
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

LIBRARY = libldap_r.la

PROGRAMS = apitest ltest

XXDIR = $(srcdir)/../libldap
XXSRCS    = apitest.c test.c \
	bind.c open.c result.c error.c compare.c search.c \
	controls.c messages.c references.c extended.c cyrus.c \
	modify.c add.c modrdn.c delete.c abandon.c \
	sasl.c sbind.c kbind.c unbind.c cancel.c \
	filter.c free.c sort.c passwd.c whoami.c \
	getdn.c getentry.c getattr.c getvalues.c addentry.c \
	request.c os-ip.c url.c sortctrl.c vlvctrl.c \
	init.c options.c print.c string.c util-int.c schema.c \
	charray.c tls.c os-local.c dnssrv.c utf-8.c utf-8-conv.c
SRCS	= threads.c rdwr.c tpool.c rq.c \
	thr_posix.c thr_cthreads.c thr_thr.c thr_lwp.c thr_nt.c \
	thr_pth.c thr_stub.c
OBJS	= threads.lo rdwr.lo tpool.lo  rq.lo \
	thr_posix.lo thr_cthreads.lo thr_thr.lo thr_lwp.lo thr_nt.lo \
	thr_pth.lo thr_stub.lo \
	bind.lo open.lo result.lo error.lo compare.lo search.lo \
	controls.lo messages.lo references.lo extended.lo cyrus.lo \
	modify.lo add.lo modrdn.lo delete.lo abandon.lo \
	sasl.lo sbind.lo kbind.lo unbind.lo cancel.lo \
	filter.lo free.lo sort.lo passwd.lo whoami.lo \
	getdn.lo getentry.lo getattr.lo getvalues.lo addentry.lo \
	request.lo os-ip.lo url.lo sortctrl.lo vlvctrl.lo \
	init.lo options.lo print.lo string.lo util-int.lo schema.lo \
	charray.lo tls.lo os-local.lo dnssrv.lo utf-8.lo utf-8-conv.lo

LDAP_INCDIR= ../../include       
LDAP_LIBDIR= ../../libraries

LIB_DEFS = -DLDAP_LIBRARY

XDEFS = -DLDAP_R_COMPILE -I$(XXDIR)
XLIBS = $(LIBRARY) $(LDAP_LIBLBER_LA) $(LDAP_LIBLUTIL_A)
XXLIBS = $(SECURITY_LIBS) $(LUTIL_LIBS)
XXXLIBS = $(LTHREAD_LIBS)
NT_LINK_LIBS = $(LDAP_LIBLBER_LA) $(AC_LIBS) $(SECURITY_LIBS)
UNIX_LINK_LIBS = $(LDAP_LIBLBER_LA) $(AC_LIBS) $(SECURITY_LIBS)

.links : Makefile
	@for i in $(XXSRCS); do \
		$(RM) $$i ; \
		$(LN_S) $(XXDIR)/$$i . ; \
	done
	touch .links

$(XXSRCS) : .links

clean-local: FORCE
	@$(RM) .links

depend-common: .links

apitest:	$(XLIBS) apitest.o
	$(LTLINK) -o $@ apitest.o $(LIBS)
ltest:	$(XLIBS) test.o
	$(LTLINK) -o $@ test.o $(LIBS)

install-local: $(CFFILES) FORCE
	-$(MKDIR) $(DESTDIR)$(libdir)
	$(LTINSTALL) $(INSTALLFLAGS) -m 644 $(LIBRARY) $(DESTDIR)$(libdir)
	$(LTFINISH) $(DESTDIR)$(libdir)

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

# $OpenLDAP: pkg/ldap/build/lib-shared.mk,v 1.17.2.3 2005/01/20 17:00:55 kurt Exp $
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
# Makefile Template for Shared Libraries
#

MKDEPFLAG = -l

.SUFFIXES: .c .o .lo

.c.lo:
	$(LTCOMPILE_LIB) $<

$(LIBRARY): version.lo
	$(LTLINK_LIB) -o $@ $(OBJS) version.lo $(LINK_LIBS)

Makefile: $(top_srcdir)/build/lib-shared.mk

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.


#
# files: -I../../include -I../../include -DLDAP_R_COMPILE -I./../libldap -I/usr/local/berkeleydb/include -D_GNU_SOURCE threads.c rdwr.c tpool.c rq.c thr_posix.c thr_cthreads.c thr_thr.c thr_lwp.c thr_nt.c thr_pth.c thr_stub.c apitest.c test.c bind.c open.c result.c error.c compare.c search.c controls.c messages.c references.c extended.c cyrus.c modify.c add.c modrdn.c delete.c abandon.c sasl.c sbind.c kbind.c unbind.c cancel.c filter.c free.c sort.c passwd.c whoami.c getdn.c getentry.c getattr.c getvalues.c addentry.c request.c os-ip.c url.c sortctrl.c vlvctrl.c init.c options.c print.c string.c util-int.c schema.c charray.c tls.c os-local.c dnssrv.c utf-8.c utf-8-conv.c
# command: cc -M -I.  -I../../include -I../../include -DLDAP_R_COMPILE -I./../libldap -I/usr/local/berkeleydb/include -D_GNU_SOURCE threads.c rdwr.c tpool.c rq.c thr_posix.c thr_cthreads.c thr_thr.c thr_lwp.c thr_nt.c thr_pth.c thr_stub.c apitest.c test.c bind.c open.c result.c error.c compare.c search.c controls.c messages.c references.c extended.c cyrus.c modify.c add.c modrdn.c delete.c abandon.c sasl.c sbind.c kbind.c unbind.c cancel.c filter.c free.c sort.c passwd.c whoami.c getdn.c getentry.c getattr.c getvalues.c addentry.c request.c os-ip.c url.c sortctrl.c vlvctrl.c init.c options.c print.c string.c util-int.c schema.c charray.c tls.c os-local.c dnssrv.c utf-8.c utf-8-conv.c
#

thr_cthreads.lo: thr_cthreads.c
thr_cthreads.lo: ../../include/portable.h
thr_cthreads.lo: /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/stddef.h
thr_cthreads.lo: ../../include/ac/fdset.h
thr_cthreads.lo: ../../include/ldap_cdefs.h
thr_cthreads.lo: ../../include/ldap_features.h
thr_cthreads.lo: ../../include/ac/assert.h
thr_cthreads.lo: /usr/include/assert.h
thr_cthreads.lo: /usr/include/features.h
thr_cthreads.lo: /usr/include/sys/cdefs.h
thr_cthreads.lo: /usr/include/bits/wordsize.h
thr_cthreads.lo: /usr/include/gnu/stubs.h
thr_cthreads.lo: /usr/include/gnu/stubs-64.h
thr_cthreads.lo: ../../include/ac/localize.h
thr_thr.lo: thr_thr.c
thr_thr.lo: ../../include/portable.h
thr_thr.lo: /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/stddef.h
thr_thr.lo: ../../include/ac/fdset.h
thr_thr.lo: ../../include/ldap_cdefs.h
thr_thr.lo: ../../include/ldap_features.h
thr_thr.lo: ../../include/ac/assert.h
thr_thr.lo: /usr/include/assert.h
thr_thr.lo: /usr/include/features.h
thr_thr.lo: /usr/include/sys/cdefs.h
thr_thr.lo: /usr/include/bits/wordsize.h
thr_thr.lo: /usr/include/gnu/stubs.h
thr_thr.lo: /usr/include/gnu/stubs-64.h
thr_thr.lo: ../../include/ac/localize.h
thr_lwp.lo: thr_lwp.c
thr_lwp.lo: ../../include/portable.h
thr_lwp.lo: /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/stddef.h
thr_lwp.lo: ../../include/ac/fdset.h
thr_lwp.lo: ../../include/ldap_cdefs.h
thr_lwp.lo: ../../include/ldap_features.h
thr_lwp.lo: ../../include/ac/assert.h
thr_lwp.lo: /usr/include/assert.h
thr_lwp.lo: /usr/include/features.h
thr_lwp.lo: /usr/include/sys/cdefs.h
thr_lwp.lo: /usr/include/bits/wordsize.h
thr_lwp.lo: /usr/include/gnu/stubs.h
thr_lwp.lo: /usr/include/gnu/stubs-64.h
thr_lwp.lo: ../../include/ac/localize.h
thr_nt.lo: thr_nt.c
thr_nt.lo: ../../include/portable.h
thr_nt.lo: /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/stddef.h
thr_nt.lo: ../../include/ac/fdset.h
thr_nt.lo: ../../include/ldap_cdefs.h
thr_nt.lo: ../../include/ldap_features.h
thr_nt.lo: ../../include/ac/assert.h
thr_nt.lo: /usr/include/assert.h
thr_nt.lo: /usr/include/features.h
thr_nt.lo: /usr/include/sys/cdefs.h
thr_nt.lo: /usr/include/bits/wordsize.h
thr_nt.lo: /usr/include/gnu/stubs.h
thr_nt.lo: /usr/include/gnu/stubs-64.h
thr_nt.lo: ../../include/ac/localize.h
thr_pth.lo: thr_pth.c
thr_pth.lo: ../../include/portable.h
thr_pth.lo: /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/stddef.h
thr_pth.lo: ../../include/ac/fdset.h
thr_pth.lo: ../../include/ldap_cdefs.h
thr_pth.lo: ../../include/ldap_features.h
thr_pth.lo: ../../include/ac/assert.h
thr_pth.lo: /usr/include/assert.h
thr_pth.lo: /usr/include/features.h
thr_pth.lo: /usr/include/sys/cdefs.h
thr_pth.lo: /usr/include/bits/wordsize.h
thr_pth.lo: /usr/include/gnu/stubs.h
thr_pth.lo: /usr/include/gnu/stubs-64.h
thr_pth.lo: ../../include/ac/localize.h
thr_stub.lo: thr_stub.c
thr_stub.lo: ../../include/portable.h
thr_stub.lo: /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/stddef.h
thr_stub.lo: ../../include/ac/fdset.h
thr_stub.lo: ../../include/ldap_cdefs.h
thr_stub.lo: ../../include/ldap_features.h
thr_stub.lo: ../../include/ac/assert.h
thr_stub.lo: /usr/include/assert.h
thr_stub.lo: /usr/include/features.h
thr_stub.lo: /usr/include/sys/cdefs.h
thr_stub.lo: /usr/include/bits/wordsize.h
thr_stub.lo: /usr/include/gnu/stubs.h
thr_stub.lo: /usr/include/gnu/stubs-64.h
thr_stub.lo: ../../include/ac/localize.h
apitest.lo: apitest.c
apitest.lo: ../../include/portable.h
apitest.lo: /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/stddef.h
apitest.lo: ../../include/ac/fdset.h
apitest.lo: ../../include/ldap_cdefs.h
apitest.lo: ../../include/ldap_features.h
apitest.lo: ../../include/ac/assert.h
apitest.lo: /usr/include/assert.h
apitest.lo: /usr/include/features.h
apitest.lo: /usr/include/sys/cdefs.h
apitest.lo: /usr/include/bits/wordsize.h
apitest.lo: /usr/include/gnu/stubs.h
apitest.lo: /usr/include/gnu/stubs-64.h
apitest.lo: ../../include/ac/localize.h
apitest.lo: ../../include/ac/stdlib.h
apitest.lo: /usr/include/stdlib.h
apitest.lo: /usr/include/bits/waitflags.h
apitest.lo: /usr/include/bits/waitstatus.h
apitest.lo: /usr/include/endian.h
apitest.lo: /usr/include/bits/endian.h
apitest.lo: /usr/include/bits/byteswap.h
apitest.lo: /usr/include/xlocale.h
apitest.lo: /usr/include/sys/types.h
apitest.lo: /usr/include/bits/types.h
apitest.lo: /usr/include/bits/typesizes.h
apitest.lo: /usr/include/time.h
apitest.lo: /usr/include/sys/select.h
apitest.lo: /usr/include/bits/select.h
apitest.lo: /usr/include/bits/sigset.h
apitest.lo: /usr/include/bits/time.h
apitest.lo: /usr/include/sys/sysmacros.h
apitest.lo: /usr/include/bits/pthreadtypes.h
apitest.lo: /usr/include/alloca.h
apitest.lo: /usr/include/stdio.h
apitest.lo: /usr/include/libio.h
apitest.lo: /usr/include/_G_config.h
apitest.lo: /usr/include/wchar.h
apitest.lo: /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/stdarg.h
apitest.lo: /usr/include/bits/stdio_lim.h
apitest.lo: /usr/include/bits/sys_errlist.h
apitest.lo: ../../include/ldap.h
apitest.lo: ../../include/lber.h
apitest.lo: ../../include/lber_types.h
apitest.lo: ../../include/ldap_cdefs.h
apitest.lo: /usr/include/string.h
apitest.lo: ../../include/ldap_features.h
kbind.lo: kbind.c
kbind.lo: ../../include/portable.h
kbind.lo: /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/stddef.h
kbind.lo: ../../include/ac/fdset.h
kbind.lo: ../../include/ldap_cdefs.h
kbind.lo: ../../include/ldap_features.h
kbind.lo: ../../include/ac/assert.h
kbind.lo: /usr/include/assert.h
kbind.lo: /usr/include/features.h
kbind.lo: /usr/include/sys/cdefs.h
kbind.lo: /usr/include/bits/wordsize.h
kbind.lo: /usr/include/gnu/stubs.h
kbind.lo: /usr/include/gnu/stubs-64.h
kbind.lo: ../../include/ac/localize.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
