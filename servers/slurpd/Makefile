# $OpenLDAP: pkg/ldap/build/top.mk,v 1.93.2.11 2007/01/02 23:42:47 kurt Exp $
## This work is part of OpenLDAP Software <http://www.openldap.org/>.
##
## Copyright 1998-2007 The OpenLDAP Foundation.
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
VERSION= 2.3.32
RELEASEDATE= 2007/1/4


SHELL = /bin/sh

top_builddir = ../../

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

SHTOOL = $(top_srcdir)/build/shtool

INSTALL = $(SHTOOL) install -c
INSTALL_PROGRAM = $(INSTALL)
INSTALL_DATA = $(INSTALL) -m 644
INSTALL_SCRIPT = $(INSTALL)

STRIP = -s

LINT = lint
5LINT = 5lint

MKDEP = $(top_srcdir)/build/mkdep $(MKDEPFLAG) \
	-d "$(srcdir)" -c "$(MKDEP_CC)" -m "$(MKDEP_CFLAGS)"
MKDEP_CC	= cc
MKDEP_CFLAGS = -M

MKVERSION = $(top_srcdir)/build/mkversion -v "$(VERSION)"

LIBTOOL = $(SHELL) $(top_builddir)/libtool
LIBRELEASE = 2.3
LIBVERSION = 2:20:2
LTVERSION = -release $(LIBRELEASE) -version-info $(LIBVERSION)

# libtool --only flag for libraries: platform specific
NT_LTONLY_LIB = # --only-$(BUILD_LIBS_DYNAMIC)
LTONLY_LIB = $(UNIX_LTONLY_LIB)

# libtool --only flag for modules: depends on linkage of module
# The BUILD_MOD macro is defined in each backend Makefile.in file
LTONLY_yes = --tag=disable-shared
LTONLY_mod = --tag=disable-static
LTONLY_MOD = $(LTONLY_$(BUILD_MOD))

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
ECHO = $(SHTOOL) echo
HOSTNAME = $(SHTOOL) echo -e "%h%d"
LN = $(SHTOOL) mkln
LN_H = $(LN)
LN_S = $(LN) -s
MAKEINFO = ${SHELL} /opt/data/openldap-2.3.32/build/missing --run makeinfo
MKDIR = $(SHTOOL) mkdir -p
MV = $(SHTOOL) move
PWD = pwd
RANLIB = ranlib
RM = rm -f
SED = sed
SUBST = $(SHTOOL) subst

# For manual pages
# MANCOMPRESS=@MANCOMPRESS@
# MANCOMPRESSSUFFIX=@MANCOMPRESSSUFFIX@
MANCOMPRESS=$(CAT)
MANCOMPRESSSUFFIX=

INCLUDEDIR= $(top_srcdir)/include
LDAP_INCPATH= -I$(LDAP_INCDIR) -I$(INCLUDEDIR)
LDAP_LIBDIR= $(top_builddir)/libraries

LUTIL_LIBS = 
LDBM_LIBS =  -ldb-4
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
AC_DEFS = -I/usr/local/berkeleydb/include  -D_GNU_SOURCE # -DHAVE_CONFIG_H
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

# Makefile.in for slurpd
# $OpenLDAP: pkg/ldap/servers/slurpd/Makefile.in,v 1.36.2.4 2007/01/02 21:44:11 kurt Exp $
## This work is part of OpenLDAP Software <http://www.openldap.org/>.
##
## Copyright 1998-2007 The OpenLDAP Foundation.
## All rights reserved.
##
## Redistribution and use in source and binary forms, with or without
## modification, are permitted only as authorized by the OpenLDAP
## Public License.
##
## A copy of this license is available in the file LICENSE in the
## top-level directory of the distribution or, alternatively, at
## <http://www.OpenLDAP.org/license.html>.

PROGRAMS = slurpd
XPROGRAMS = sslurpd

XSRCS	= version.c

NT_SRCS	= nt_svc.c
NT_OBJS = nt_svc.o ../../libraries/liblutil/slapdmsg.res

SRCS	=	admin.c args.c ch_malloc.c config.c \
		fm.c globals.c ldap_op.c lock.c main.c re.c \
		reject.c replica.c replog.c ri.c rq.c sanity.c st.c \
		$(UNIX_SRCS)
OBJS	=	admin.o args.o ch_malloc.o config.o \
		fm.o globals.o ldap_op.o lock.o main.o re.o \
		reject.o replica.o replog.o ri.o rq.o sanity.o st.o \
		$(UNIX_OBJS)

LDAP_INCDIR= ../../include       
LDAP_LIBDIR= ../../libraries

BUILD_OPT = "--enable-slurpd"
BUILD_SRV = yes

all-local-srv: 	$(PROGRAMS)

# $(LTHREAD_LIBS) must be last!
XLIBS = $(SLURPD_L)
XXLIBS = $(SLURPD_LIBS) $(SECURITY_LIBS) $(LUTIL_LIBS)
XXXLIBS = $(LTHREAD_LIBS)

slurpd:	version.o
	$(LTLINK) -o $@ $(OBJS) version.o $(LIBS)

sslurpd:	version.o
	$(LTLINK) -static -o $@ $(OBJS) version.o $(LIBS)

version.c: Makefile
	@-$(RM) $@
	$(MKVERSION) -s -n Versionstr slurpd > $@

version.o: version.c $(OBJS) $(SLURPD_L)

install-local-srv: FORCE
	-$(MKDIR) $(DESTDIR)$(libexecdir)
	@-$(INSTALL) -m 700 -d $(DESTDIR)$(localstatedir)/openldap-slurp
	@(								\
	    for prg in $(PROGRAMS); do					\
		$(LTINSTALL) $(INSTALLFLAGS) $(STRIP) -m 755 $$prg$(EXEEXT)	\
		    $(DESTDIR)$(libexecdir);				\
	    done							\
	)

# $OpenLDAP: pkg/ldap/build/srv.mk,v 1.15.2.4 2007/01/02 21:43:41 kurt Exp $
## This work is part of OpenLDAP Software <http://www.openldap.org/>.
##
## Copyright 1998-2007 The OpenLDAP Foundation.
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
# Makefile Template for Servers
#

all-common: all-$(BUILD_SRV)
all-no lint-no 5lint-no depend-no install-no:
	@echo "run configure with $(BUILD_OPT) to make $(PROGRAMS)"

clean-common: clean-srv FORCE
veryclean-common: veryclean-srv FORCE

lint-common: lint-$(BUILD_SRV)

5lint-common: 5lint-$(BUILD_SRV)

depend-common: depend-$(BUILD_SRV)

install-common: install-$(BUILD_SRV)

all-local-srv:
all-yes: all-local-srv FORCE

install-local-srv:
install-yes: install-local-srv FORCE

lint-local-srv:
lint-yes: lint-local-srv FORCE
	$(LINT) $(DEFS) $(DEFINES) $(SRCS)

5lint-local-srv:
5lint-yes: 5lint-local-srv FORCE
	$(5LINT) $(DEFS) $(DEFINES) $(SRCS)

clean-local-srv:
clean-srv: 	clean-local-srv FORCE
	$(RM) $(PROGRAMS) $(XPROGRAMS) $(XSRCS) *.o a.out core .libs/* *.exe

depend-local-srv:
depend-yes: depend-local-srv FORCE
	$(MKDEP) $(DEFS) $(DEFINES) $(SRCS)

veryclean-local-srv:
veryclean-srv: 	clean-srv veryclean-local-srv

Makefile: $(top_srcdir)/build/srv.mk
# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.


#
# files: -I../../include -I../../include -I/usr/local/berkeleydb/include -D_GNU_SOURCE admin.c args.c ch_malloc.c config.c fm.c globals.c ldap_op.c lock.c main.c re.c reject.c replica.c replog.c ri.c rq.c sanity.c st.c
# command: cc -M -I.  -I../../include -I../../include -I/usr/local/berkeleydb/include -D_GNU_SOURCE admin.c args.c ch_malloc.c config.c fm.c globals.c ldap_op.c lock.c main.c re.c reject.c replica.c replog.c ri.c rq.c sanity.c st.c
#

admin.o: admin.c
admin.o: /usr/include/stdc-predef.h
admin.o: ../../include/portable.h
admin.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h
admin.o: ../../include/ac/fdset.h
admin.o: /usr/include/bits/types.h
admin.o: /usr/include/features.h
admin.o: /usr/include/sys/cdefs.h
admin.o: /usr/include/bits/wordsize.h
admin.o: /usr/include/gnu/stubs.h
admin.o: /usr/include/gnu/stubs-64.h
admin.o: /usr/include/bits/typesizes.h
admin.o: ../../include/ldap_cdefs.h
admin.o: ../../include/ldap_features.h
admin.o: ../../include/ac/assert.h
admin.o: /usr/include/assert.h
admin.o: ../../include/ac/localize.h
admin.o: /usr/include/stdio.h
admin.o: /usr/include/libio.h
admin.o: /usr/include/_G_config.h
admin.o: /usr/include/wchar.h
admin.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stdarg.h
admin.o: /usr/include/bits/stdio_lim.h
admin.o: /usr/include/bits/sys_errlist.h
admin.o: ../../include/ac/stdlib.h
admin.o: /usr/include/stdlib.h
admin.o: /usr/include/bits/waitflags.h
admin.o: /usr/include/bits/waitstatus.h
admin.o: /usr/include/endian.h
admin.o: /usr/include/bits/endian.h
admin.o: /usr/include/bits/byteswap.h
admin.o: /usr/include/bits/byteswap-16.h
admin.o: /usr/include/xlocale.h
admin.o: /usr/include/sys/types.h
admin.o: /usr/include/time.h
admin.o: /usr/include/sys/select.h
admin.o: /usr/include/bits/select.h
admin.o: /usr/include/bits/sigset.h
admin.o: /usr/include/bits/time.h
admin.o: /usr/include/sys/sysmacros.h
admin.o: /usr/include/bits/pthreadtypes.h
admin.o: /usr/include/alloca.h
admin.o: /usr/include/bits/stdlib-float.h
admin.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/limits.h
admin.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/syslimits.h
admin.o: /usr/include/limits.h
admin.o: /usr/include/bits/posix1_lim.h
admin.o: /usr/include/bits/local_lim.h
admin.o: /usr/include/linux/limits.h
admin.o: /usr/include/bits/posix2_lim.h
admin.o: /usr/include/bits/xopen_lim.h
admin.o: ../../include/ac/signal.h
admin.o: /usr/include/signal.h
admin.o: /usr/include/bits/signum.h
admin.o: /usr/include/bits/siginfo.h
admin.o: /usr/include/bits/sigaction.h
admin.o: /usr/include/bits/sigcontext.h
admin.o: /usr/include/bits/sigstack.h
admin.o: /usr/include/sys/ucontext.h
admin.o: /usr/include/bits/sigthread.h
admin.o: slurp.h
admin.o: ../../include/ac/errno.h
admin.o: /usr/include/errno.h
admin.o: /usr/include/bits/errno.h
admin.o: /usr/include/linux/errno.h
admin.o: /usr/include/asm/errno.h
admin.o: /usr/include/asm-generic/errno.h
admin.o: /usr/include/asm-generic/errno-base.h
admin.o: ../../include/ac/param.h
admin.o: /usr/include/sys/param.h
admin.o: /usr/include/bits/param.h
admin.o: /usr/include/linux/param.h
admin.o: /usr/include/asm/param.h
admin.o: /usr/include/asm-generic/param.h
admin.o: ../../include/ac/syslog.h
admin.o: /usr/include/syslog.h
admin.o: /usr/include/sys/syslog.h
admin.o: /usr/include/bits/syslog-path.h
admin.o: ../../include/ac/time.h
admin.o: /usr/include/sys/time.h
admin.o: /usr/include/bits/timex.h
admin.o: ../../include/ldap.h
admin.o: ../../include/lber.h
admin.o: ../../include/lber_types.h
admin.o: ../../include/ldap_cdefs.h
admin.o: /usr/include/string.h
admin.o: ../../include/ldap_features.h
admin.o: ../../include/ldap_log.h
admin.o: ../../include/ldap_pvt_thread.h
admin.o: ../../include/ldap_int_thread.h
admin.o: /usr/include/pthread.h
admin.o: /usr/include/sched.h
admin.o: /usr/include/bits/sched.h
admin.o: /usr/include/bits/setjmp.h
admin.o: ../../include/ldap_defaults.h
admin.o: globals.h
admin.o: ../../include/ldap_config.h
admin.o: ../../include/ldif.h
admin.o: proto-slurp.h
args.o: args.c
args.o: /usr/include/stdc-predef.h
args.o: ../../include/portable.h
args.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h
args.o: ../../include/ac/fdset.h
args.o: /usr/include/bits/types.h
args.o: /usr/include/features.h
args.o: /usr/include/sys/cdefs.h
args.o: /usr/include/bits/wordsize.h
args.o: /usr/include/gnu/stubs.h
args.o: /usr/include/gnu/stubs-64.h
args.o: /usr/include/bits/typesizes.h
args.o: ../../include/ldap_cdefs.h
args.o: ../../include/ldap_features.h
args.o: ../../include/ac/assert.h
args.o: /usr/include/assert.h
args.o: ../../include/ac/localize.h
args.o: /usr/include/stdio.h
args.o: /usr/include/libio.h
args.o: /usr/include/_G_config.h
args.o: /usr/include/wchar.h
args.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stdarg.h
args.o: /usr/include/bits/stdio_lim.h
args.o: /usr/include/bits/sys_errlist.h
args.o: ../../include/ac/stdlib.h
args.o: /usr/include/stdlib.h
args.o: /usr/include/bits/waitflags.h
args.o: /usr/include/bits/waitstatus.h
args.o: /usr/include/endian.h
args.o: /usr/include/bits/endian.h
args.o: /usr/include/bits/byteswap.h
args.o: /usr/include/bits/byteswap-16.h
args.o: /usr/include/xlocale.h
args.o: /usr/include/sys/types.h
args.o: /usr/include/time.h
args.o: /usr/include/sys/select.h
args.o: /usr/include/bits/select.h
args.o: /usr/include/bits/sigset.h
args.o: /usr/include/bits/time.h
args.o: /usr/include/sys/sysmacros.h
args.o: /usr/include/bits/pthreadtypes.h
args.o: /usr/include/alloca.h
args.o: /usr/include/bits/stdlib-float.h
args.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/limits.h
args.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/syslimits.h
args.o: /usr/include/limits.h
args.o: /usr/include/bits/posix1_lim.h
args.o: /usr/include/bits/local_lim.h
args.o: /usr/include/linux/limits.h
args.o: /usr/include/bits/posix2_lim.h
args.o: /usr/include/bits/xopen_lim.h
args.o: ../../include/ac/string.h
args.o: /usr/include/string.h
args.o: ../../include/ac/time.h
args.o: /usr/include/sys/time.h
args.o: /usr/include/bits/timex.h
args.o: ../../include/ac/unistd.h
args.o: /usr/include/unistd.h
args.o: /usr/include/bits/posix_opt.h
args.o: /usr/include/bits/environments.h
args.o: /usr/include/bits/confname.h
args.o: /usr/include/getopt.h
args.o: ../../include/lutil_lockf.h
args.o: ../../include/ldap.h
args.o: ../../include/lber.h
args.o: ../../include/lber_types.h
args.o: ../../include/ldap_cdefs.h
args.o: ../../include/ldap_features.h
args.o: ../../include/lutil.h
args.o: slurp.h
args.o: ../../include/ac/errno.h
args.o: /usr/include/errno.h
args.o: /usr/include/bits/errno.h
args.o: /usr/include/linux/errno.h
args.o: /usr/include/asm/errno.h
args.o: /usr/include/asm-generic/errno.h
args.o: /usr/include/asm-generic/errno-base.h
args.o: ../../include/ac/param.h
args.o: /usr/include/sys/param.h
args.o: /usr/include/signal.h
args.o: /usr/include/bits/signum.h
args.o: /usr/include/bits/siginfo.h
args.o: /usr/include/bits/sigaction.h
args.o: /usr/include/bits/sigcontext.h
args.o: /usr/include/bits/sigstack.h
args.o: /usr/include/sys/ucontext.h
args.o: /usr/include/bits/sigthread.h
args.o: /usr/include/bits/param.h
args.o: /usr/include/linux/param.h
args.o: /usr/include/asm/param.h
args.o: /usr/include/asm-generic/param.h
args.o: ../../include/ac/signal.h
args.o: ../../include/ac/syslog.h
args.o: /usr/include/syslog.h
args.o: /usr/include/sys/syslog.h
args.o: /usr/include/bits/syslog-path.h
args.o: ../../include/ldap_log.h
args.o: ../../include/ldap_pvt_thread.h
args.o: ../../include/ldap_int_thread.h
args.o: /usr/include/pthread.h
args.o: /usr/include/sched.h
args.o: /usr/include/bits/sched.h
args.o: /usr/include/bits/setjmp.h
args.o: ../../include/ldap_defaults.h
args.o: globals.h
args.o: ../../include/ldap_config.h
args.o: ../../include/ldif.h
args.o: proto-slurp.h
ch_malloc.o: ch_malloc.c
ch_malloc.o: /usr/include/stdc-predef.h
ch_malloc.o: ../../include/portable.h
ch_malloc.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h
ch_malloc.o: ../../include/ac/fdset.h
ch_malloc.o: /usr/include/bits/types.h
ch_malloc.o: /usr/include/features.h
ch_malloc.o: /usr/include/sys/cdefs.h
ch_malloc.o: /usr/include/bits/wordsize.h
ch_malloc.o: /usr/include/gnu/stubs.h
ch_malloc.o: /usr/include/gnu/stubs-64.h
ch_malloc.o: /usr/include/bits/typesizes.h
ch_malloc.o: ../../include/ldap_cdefs.h
ch_malloc.o: ../../include/ldap_features.h
ch_malloc.o: ../../include/ac/assert.h
ch_malloc.o: /usr/include/assert.h
ch_malloc.o: ../../include/ac/localize.h
ch_malloc.o: /usr/include/stdio.h
ch_malloc.o: /usr/include/libio.h
ch_malloc.o: /usr/include/_G_config.h
ch_malloc.o: /usr/include/wchar.h
ch_malloc.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stdarg.h
ch_malloc.o: /usr/include/bits/stdio_lim.h
ch_malloc.o: /usr/include/bits/sys_errlist.h
ch_malloc.o: ../../include/ac/stdlib.h
ch_malloc.o: /usr/include/stdlib.h
ch_malloc.o: /usr/include/bits/waitflags.h
ch_malloc.o: /usr/include/bits/waitstatus.h
ch_malloc.o: /usr/include/endian.h
ch_malloc.o: /usr/include/bits/endian.h
ch_malloc.o: /usr/include/bits/byteswap.h
ch_malloc.o: /usr/include/bits/byteswap-16.h
ch_malloc.o: /usr/include/xlocale.h
ch_malloc.o: /usr/include/sys/types.h
ch_malloc.o: /usr/include/time.h
ch_malloc.o: /usr/include/sys/select.h
ch_malloc.o: /usr/include/bits/select.h
ch_malloc.o: /usr/include/bits/sigset.h
ch_malloc.o: /usr/include/bits/time.h
ch_malloc.o: /usr/include/sys/sysmacros.h
ch_malloc.o: /usr/include/bits/pthreadtypes.h
ch_malloc.o: /usr/include/alloca.h
ch_malloc.o: /usr/include/bits/stdlib-float.h
ch_malloc.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/limits.h
ch_malloc.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/syslimits.h
ch_malloc.o: /usr/include/limits.h
ch_malloc.o: /usr/include/bits/posix1_lim.h
ch_malloc.o: /usr/include/bits/local_lim.h
ch_malloc.o: /usr/include/linux/limits.h
ch_malloc.o: /usr/include/bits/posix2_lim.h
ch_malloc.o: /usr/include/bits/xopen_lim.h
ch_malloc.o: ../../include/ac/socket.h
ch_malloc.o: /usr/include/poll.h
ch_malloc.o: /usr/include/sys/poll.h
ch_malloc.o: /usr/include/bits/poll.h
ch_malloc.o: /usr/include/sys/socket.h
ch_malloc.o: /usr/include/sys/uio.h
ch_malloc.o: /usr/include/bits/uio.h
ch_malloc.o: /usr/include/bits/socket.h
ch_malloc.o: /usr/include/bits/socket_type.h
ch_malloc.o: /usr/include/bits/sockaddr.h
ch_malloc.o: /usr/include/asm/socket.h
ch_malloc.o: /usr/include/asm-generic/socket.h
ch_malloc.o: /usr/include/asm/sockios.h
ch_malloc.o: /usr/include/asm-generic/sockios.h
ch_malloc.o: /usr/include/sys/un.h
ch_malloc.o: /usr/include/string.h
ch_malloc.o: /usr/include/netinet/in.h
ch_malloc.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stdint.h
ch_malloc.o: /usr/include/stdint.h
ch_malloc.o: /usr/include/bits/wchar.h
ch_malloc.o: /usr/include/bits/in.h
ch_malloc.o: /usr/include/netinet/tcp.h
ch_malloc.o: /usr/include/arpa/inet.h
ch_malloc.o: /usr/include/arpa/nameser.h
ch_malloc.o: /usr/include/sys/param.h
ch_malloc.o: /usr/include/signal.h
ch_malloc.o: /usr/include/bits/signum.h
ch_malloc.o: /usr/include/bits/siginfo.h
ch_malloc.o: /usr/include/bits/sigaction.h
ch_malloc.o: /usr/include/bits/sigcontext.h
ch_malloc.o: /usr/include/bits/sigstack.h
ch_malloc.o: /usr/include/sys/ucontext.h
ch_malloc.o: /usr/include/bits/sigthread.h
ch_malloc.o: /usr/include/bits/param.h
ch_malloc.o: /usr/include/linux/param.h
ch_malloc.o: /usr/include/asm/param.h
ch_malloc.o: /usr/include/asm-generic/param.h
ch_malloc.o: /usr/include/arpa/nameser_compat.h
ch_malloc.o: /usr/include/netdb.h
ch_malloc.o: /usr/include/rpc/netdb.h
ch_malloc.o: /usr/include/bits/netdb.h
ch_malloc.o: /usr/include/resolv.h
ch_malloc.o: ../slapd/slap.h
ch_malloc.o: ../../include/ldap_defaults.h
ch_malloc.o: ../../include/ldap_config.h
ch_malloc.o: ../../include/ac/syslog.h
ch_malloc.o: /usr/include/syslog.h
ch_malloc.o: /usr/include/sys/syslog.h
ch_malloc.o: /usr/include/bits/syslog-path.h
ch_malloc.o: ../../include/ac/regex.h
ch_malloc.o: /usr/include/regex.h
ch_malloc.o: ../../include/ac/signal.h
ch_malloc.o: ../../include/ac/time.h
ch_malloc.o: /usr/include/sys/time.h
ch_malloc.o: /usr/include/bits/timex.h
ch_malloc.o: ../../include/ac/param.h
ch_malloc.o: ../../include/avl.h
ch_malloc.o: ../../include/ldap_cdefs.h
ch_malloc.o: ../../include/ldap_log.h
ch_malloc.o: ../../include/ldap.h
ch_malloc.o: ../../include/lber.h
ch_malloc.o: ../../include/lber_types.h
ch_malloc.o: ../../include/ldap_features.h
ch_malloc.o: ../../include/ldap_schema.h
ch_malloc.o: ../../include/lber_pvt.h
ch_malloc.o: ../../include/ldap_pvt.h
ch_malloc.o: ../../include/ldap_pvt_uc.h
ch_malloc.o: ../../include/ac/bytes.h
ch_malloc.o: ../../include/../libraries/liblunicode/ucdata/ucdata.h
ch_malloc.o: ../../include/ldap_pvt_thread.h
ch_malloc.o: ../../include/ldap_int_thread.h
ch_malloc.o: /usr/include/pthread.h
ch_malloc.o: /usr/include/sched.h
ch_malloc.o: /usr/include/bits/sched.h
ch_malloc.o: /usr/include/bits/setjmp.h
ch_malloc.o: ../../include/ldap_queue.h
ch_malloc.o: ../slapd/proto-slap.h
config.o: config.c
config.o: /usr/include/stdc-predef.h
config.o: ../../include/portable.h
config.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h
config.o: ../../include/ac/fdset.h
config.o: /usr/include/bits/types.h
config.o: /usr/include/features.h
config.o: /usr/include/sys/cdefs.h
config.o: /usr/include/bits/wordsize.h
config.o: /usr/include/gnu/stubs.h
config.o: /usr/include/gnu/stubs-64.h
config.o: /usr/include/bits/typesizes.h
config.o: ../../include/ldap_cdefs.h
config.o: ../../include/ldap_features.h
config.o: ../../include/ac/assert.h
config.o: /usr/include/assert.h
config.o: ../../include/ac/localize.h
config.o: /usr/include/stdio.h
config.o: /usr/include/libio.h
config.o: /usr/include/_G_config.h
config.o: /usr/include/wchar.h
config.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stdarg.h
config.o: /usr/include/bits/stdio_lim.h
config.o: /usr/include/bits/sys_errlist.h
config.o: ../../include/ac/stdlib.h
config.o: /usr/include/stdlib.h
config.o: /usr/include/bits/waitflags.h
config.o: /usr/include/bits/waitstatus.h
config.o: /usr/include/endian.h
config.o: /usr/include/bits/endian.h
config.o: /usr/include/bits/byteswap.h
config.o: /usr/include/bits/byteswap-16.h
config.o: /usr/include/xlocale.h
config.o: /usr/include/sys/types.h
config.o: /usr/include/time.h
config.o: /usr/include/sys/select.h
config.o: /usr/include/bits/select.h
config.o: /usr/include/bits/sigset.h
config.o: /usr/include/bits/time.h
config.o: /usr/include/sys/sysmacros.h
config.o: /usr/include/bits/pthreadtypes.h
config.o: /usr/include/alloca.h
config.o: /usr/include/bits/stdlib-float.h
config.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/limits.h
config.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/syslimits.h
config.o: /usr/include/limits.h
config.o: /usr/include/bits/posix1_lim.h
config.o: /usr/include/bits/local_lim.h
config.o: /usr/include/linux/limits.h
config.o: /usr/include/bits/posix2_lim.h
config.o: /usr/include/bits/xopen_lim.h
config.o: ../../include/ac/string.h
config.o: /usr/include/string.h
config.o: ../../include/ac/socket.h
config.o: /usr/include/poll.h
config.o: /usr/include/sys/poll.h
config.o: /usr/include/bits/poll.h
config.o: /usr/include/sys/socket.h
config.o: /usr/include/sys/uio.h
config.o: /usr/include/bits/uio.h
config.o: /usr/include/bits/socket.h
config.o: /usr/include/bits/socket_type.h
config.o: /usr/include/bits/sockaddr.h
config.o: /usr/include/asm/socket.h
config.o: /usr/include/asm-generic/socket.h
config.o: /usr/include/asm/sockios.h
config.o: /usr/include/asm-generic/sockios.h
config.o: /usr/include/sys/un.h
config.o: /usr/include/netinet/in.h
config.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stdint.h
config.o: /usr/include/stdint.h
config.o: /usr/include/bits/wchar.h
config.o: /usr/include/bits/in.h
config.o: /usr/include/netinet/tcp.h
config.o: /usr/include/arpa/inet.h
config.o: /usr/include/arpa/nameser.h
config.o: /usr/include/sys/param.h
config.o: /usr/include/signal.h
config.o: /usr/include/bits/signum.h
config.o: /usr/include/bits/siginfo.h
config.o: /usr/include/bits/sigaction.h
config.o: /usr/include/bits/sigcontext.h
config.o: /usr/include/bits/sigstack.h
config.o: /usr/include/sys/ucontext.h
config.o: /usr/include/bits/sigthread.h
config.o: /usr/include/bits/param.h
config.o: /usr/include/linux/param.h
config.o: /usr/include/asm/param.h
config.o: /usr/include/asm-generic/param.h
config.o: /usr/include/arpa/nameser_compat.h
config.o: /usr/include/netdb.h
config.o: /usr/include/rpc/netdb.h
config.o: /usr/include/bits/netdb.h
config.o: /usr/include/resolv.h
config.o: ../../include/ac/ctype.h
config.o: /usr/include/ctype.h
config.o: ../../include/ldap.h
config.o: ../../include/lber.h
config.o: ../../include/lber_types.h
config.o: ../../include/ldap_cdefs.h
config.o: ../../include/ldap_features.h
config.o: ../../include/lutil.h
config.o: slurp.h
config.o: ../../include/ac/errno.h
config.o: /usr/include/errno.h
config.o: /usr/include/bits/errno.h
config.o: /usr/include/linux/errno.h
config.o: /usr/include/asm/errno.h
config.o: /usr/include/asm-generic/errno.h
config.o: /usr/include/asm-generic/errno-base.h
config.o: ../../include/ac/param.h
config.o: ../../include/ac/signal.h
config.o: ../../include/ac/syslog.h
config.o: /usr/include/syslog.h
config.o: /usr/include/sys/syslog.h
config.o: /usr/include/bits/syslog-path.h
config.o: ../../include/ac/time.h
config.o: /usr/include/sys/time.h
config.o: /usr/include/bits/timex.h
config.o: ../../include/ldap_log.h
config.o: ../../include/ldap_pvt_thread.h
config.o: ../../include/ldap_int_thread.h
config.o: /usr/include/pthread.h
config.o: /usr/include/sched.h
config.o: /usr/include/bits/sched.h
config.o: /usr/include/bits/setjmp.h
config.o: ../../include/ldap_defaults.h
config.o: globals.h
config.o: ../../include/ldap_config.h
config.o: ../../include/ldif.h
config.o: proto-slurp.h
fm.o: fm.c
fm.o: /usr/include/stdc-predef.h
fm.o: ../../include/portable.h
fm.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h
fm.o: ../../include/ac/fdset.h
fm.o: /usr/include/bits/types.h
fm.o: /usr/include/features.h
fm.o: /usr/include/sys/cdefs.h
fm.o: /usr/include/bits/wordsize.h
fm.o: /usr/include/gnu/stubs.h
fm.o: /usr/include/gnu/stubs-64.h
fm.o: /usr/include/bits/typesizes.h
fm.o: ../../include/ldap_cdefs.h
fm.o: ../../include/ldap_features.h
fm.o: ../../include/ac/assert.h
fm.o: /usr/include/assert.h
fm.o: ../../include/ac/localize.h
fm.o: /usr/include/stdio.h
fm.o: /usr/include/libio.h
fm.o: /usr/include/_G_config.h
fm.o: /usr/include/wchar.h
fm.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stdarg.h
fm.o: /usr/include/bits/stdio_lim.h
fm.o: /usr/include/bits/sys_errlist.h
fm.o: ../../include/ac/stdlib.h
fm.o: /usr/include/stdlib.h
fm.o: /usr/include/bits/waitflags.h
fm.o: /usr/include/bits/waitstatus.h
fm.o: /usr/include/endian.h
fm.o: /usr/include/bits/endian.h
fm.o: /usr/include/bits/byteswap.h
fm.o: /usr/include/bits/byteswap-16.h
fm.o: /usr/include/xlocale.h
fm.o: /usr/include/sys/types.h
fm.o: /usr/include/time.h
fm.o: /usr/include/sys/select.h
fm.o: /usr/include/bits/select.h
fm.o: /usr/include/bits/sigset.h
fm.o: /usr/include/bits/time.h
fm.o: /usr/include/sys/sysmacros.h
fm.o: /usr/include/bits/pthreadtypes.h
fm.o: /usr/include/alloca.h
fm.o: /usr/include/bits/stdlib-float.h
fm.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/limits.h
fm.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/syslimits.h
fm.o: /usr/include/limits.h
fm.o: /usr/include/bits/posix1_lim.h
fm.o: /usr/include/bits/local_lim.h
fm.o: /usr/include/linux/limits.h
fm.o: /usr/include/bits/posix2_lim.h
fm.o: /usr/include/bits/xopen_lim.h
fm.o: ../../include/ac/string.h
fm.o: /usr/include/string.h
fm.o: ../../include/ac/signal.h
fm.o: /usr/include/signal.h
fm.o: /usr/include/bits/signum.h
fm.o: /usr/include/bits/siginfo.h
fm.o: /usr/include/bits/sigaction.h
fm.o: /usr/include/bits/sigcontext.h
fm.o: /usr/include/bits/sigstack.h
fm.o: /usr/include/sys/ucontext.h
fm.o: /usr/include/bits/sigthread.h
fm.o: ../../include/ac/socket.h
fm.o: /usr/include/poll.h
fm.o: /usr/include/sys/poll.h
fm.o: /usr/include/bits/poll.h
fm.o: /usr/include/sys/socket.h
fm.o: /usr/include/sys/uio.h
fm.o: /usr/include/bits/uio.h
fm.o: /usr/include/bits/socket.h
fm.o: /usr/include/bits/socket_type.h
fm.o: /usr/include/bits/sockaddr.h
fm.o: /usr/include/asm/socket.h
fm.o: /usr/include/asm-generic/socket.h
fm.o: /usr/include/asm/sockios.h
fm.o: /usr/include/asm-generic/sockios.h
fm.o: /usr/include/sys/un.h
fm.o: /usr/include/netinet/in.h
fm.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stdint.h
fm.o: /usr/include/stdint.h
fm.o: /usr/include/bits/wchar.h
fm.o: /usr/include/bits/in.h
fm.o: /usr/include/netinet/tcp.h
fm.o: /usr/include/arpa/inet.h
fm.o: /usr/include/arpa/nameser.h
fm.o: /usr/include/sys/param.h
fm.o: /usr/include/bits/param.h
fm.o: /usr/include/linux/param.h
fm.o: /usr/include/asm/param.h
fm.o: /usr/include/asm-generic/param.h
fm.o: /usr/include/arpa/nameser_compat.h
fm.o: /usr/include/netdb.h
fm.o: /usr/include/rpc/netdb.h
fm.o: /usr/include/bits/netdb.h
fm.o: /usr/include/resolv.h
fm.o: ../../include/ac/unistd.h
fm.o: /usr/include/unistd.h
fm.o: /usr/include/bits/posix_opt.h
fm.o: /usr/include/bits/environments.h
fm.o: /usr/include/bits/confname.h
fm.o: /usr/include/getopt.h
fm.o: ../../include/lutil_lockf.h
fm.o: slurp.h
fm.o: ../../include/ac/errno.h
fm.o: /usr/include/errno.h
fm.o: /usr/include/bits/errno.h
fm.o: /usr/include/linux/errno.h
fm.o: /usr/include/asm/errno.h
fm.o: /usr/include/asm-generic/errno.h
fm.o: /usr/include/asm-generic/errno-base.h
fm.o: ../../include/ac/param.h
fm.o: ../../include/ac/syslog.h
fm.o: /usr/include/syslog.h
fm.o: /usr/include/sys/syslog.h
fm.o: /usr/include/bits/syslog-path.h
fm.o: ../../include/ac/time.h
fm.o: /usr/include/sys/time.h
fm.o: /usr/include/bits/timex.h
fm.o: ../../include/ldap.h
fm.o: ../../include/lber.h
fm.o: ../../include/lber_types.h
fm.o: ../../include/ldap_cdefs.h
fm.o: ../../include/ldap_features.h
fm.o: ../../include/ldap_log.h
fm.o: ../../include/ldap_pvt_thread.h
fm.o: ../../include/ldap_int_thread.h
fm.o: /usr/include/pthread.h
fm.o: /usr/include/sched.h
fm.o: /usr/include/bits/sched.h
fm.o: /usr/include/bits/setjmp.h
fm.o: ../../include/ldap_defaults.h
fm.o: globals.h
fm.o: ../../include/ldap_config.h
fm.o: ../../include/ldif.h
fm.o: proto-slurp.h
globals.o: globals.c
globals.o: /usr/include/stdc-predef.h
globals.o: ../../include/portable.h
globals.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h
globals.o: ../../include/ac/fdset.h
globals.o: /usr/include/bits/types.h
globals.o: /usr/include/features.h
globals.o: /usr/include/sys/cdefs.h
globals.o: /usr/include/bits/wordsize.h
globals.o: /usr/include/gnu/stubs.h
globals.o: /usr/include/gnu/stubs-64.h
globals.o: /usr/include/bits/typesizes.h
globals.o: ../../include/ldap_cdefs.h
globals.o: ../../include/ldap_features.h
globals.o: ../../include/ac/assert.h
globals.o: /usr/include/assert.h
globals.o: ../../include/ac/localize.h
globals.o: /usr/include/stdio.h
globals.o: /usr/include/libio.h
globals.o: /usr/include/_G_config.h
globals.o: /usr/include/wchar.h
globals.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stdarg.h
globals.o: /usr/include/bits/stdio_lim.h
globals.o: /usr/include/bits/sys_errlist.h
globals.o: ../../include/ac/stdlib.h
globals.o: /usr/include/stdlib.h
globals.o: /usr/include/bits/waitflags.h
globals.o: /usr/include/bits/waitstatus.h
globals.o: /usr/include/endian.h
globals.o: /usr/include/bits/endian.h
globals.o: /usr/include/bits/byteswap.h
globals.o: /usr/include/bits/byteswap-16.h
globals.o: /usr/include/xlocale.h
globals.o: /usr/include/sys/types.h
globals.o: /usr/include/time.h
globals.o: /usr/include/sys/select.h
globals.o: /usr/include/bits/select.h
globals.o: /usr/include/bits/sigset.h
globals.o: /usr/include/bits/time.h
globals.o: /usr/include/sys/sysmacros.h
globals.o: /usr/include/bits/pthreadtypes.h
globals.o: /usr/include/alloca.h
globals.o: /usr/include/bits/stdlib-float.h
globals.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/limits.h
globals.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/syslimits.h
globals.o: /usr/include/limits.h
globals.o: /usr/include/bits/posix1_lim.h
globals.o: /usr/include/bits/local_lim.h
globals.o: /usr/include/linux/limits.h
globals.o: /usr/include/bits/posix2_lim.h
globals.o: /usr/include/bits/xopen_lim.h
globals.o: ../../include/ac/string.h
globals.o: /usr/include/string.h
globals.o: slurp.h
globals.o: ../../include/ac/errno.h
globals.o: /usr/include/errno.h
globals.o: /usr/include/bits/errno.h
globals.o: /usr/include/linux/errno.h
globals.o: /usr/include/asm/errno.h
globals.o: /usr/include/asm-generic/errno.h
globals.o: /usr/include/asm-generic/errno-base.h
globals.o: ../../include/ac/param.h
globals.o: /usr/include/sys/param.h
globals.o: /usr/include/signal.h
globals.o: /usr/include/bits/signum.h
globals.o: /usr/include/bits/siginfo.h
globals.o: /usr/include/bits/sigaction.h
globals.o: /usr/include/bits/sigcontext.h
globals.o: /usr/include/bits/sigstack.h
globals.o: /usr/include/sys/ucontext.h
globals.o: /usr/include/bits/sigthread.h
globals.o: /usr/include/bits/param.h
globals.o: /usr/include/linux/param.h
globals.o: /usr/include/asm/param.h
globals.o: /usr/include/asm-generic/param.h
globals.o: ../../include/ac/signal.h
globals.o: ../../include/ac/syslog.h
globals.o: /usr/include/syslog.h
globals.o: /usr/include/sys/syslog.h
globals.o: /usr/include/bits/syslog-path.h
globals.o: ../../include/ac/time.h
globals.o: /usr/include/sys/time.h
globals.o: /usr/include/bits/timex.h
globals.o: ../../include/ldap.h
globals.o: ../../include/lber.h
globals.o: ../../include/lber_types.h
globals.o: ../../include/ldap_cdefs.h
globals.o: ../../include/ldap_features.h
globals.o: ../../include/ldap_log.h
globals.o: ../../include/ldap_pvt_thread.h
globals.o: ../../include/ldap_int_thread.h
globals.o: /usr/include/pthread.h
globals.o: /usr/include/sched.h
globals.o: /usr/include/bits/sched.h
globals.o: /usr/include/bits/setjmp.h
globals.o: ../../include/ldap_defaults.h
globals.o: globals.h
globals.o: ../../include/ldap_config.h
globals.o: ../../include/ldif.h
globals.o: proto-slurp.h
ldap_op.o: ldap_op.c
ldap_op.o: /usr/include/stdc-predef.h
ldap_op.o: ../../include/portable.h
ldap_op.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h
ldap_op.o: ../../include/ac/fdset.h
ldap_op.o: /usr/include/bits/types.h
ldap_op.o: /usr/include/features.h
ldap_op.o: /usr/include/sys/cdefs.h
ldap_op.o: /usr/include/bits/wordsize.h
ldap_op.o: /usr/include/gnu/stubs.h
ldap_op.o: /usr/include/gnu/stubs-64.h
ldap_op.o: /usr/include/bits/typesizes.h
ldap_op.o: ../../include/ldap_cdefs.h
ldap_op.o: ../../include/ldap_features.h
ldap_op.o: ../../include/ac/assert.h
ldap_op.o: /usr/include/assert.h
ldap_op.o: ../../include/ac/localize.h
ldap_op.o: /usr/include/stdio.h
ldap_op.o: /usr/include/libio.h
ldap_op.o: /usr/include/_G_config.h
ldap_op.o: /usr/include/wchar.h
ldap_op.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stdarg.h
ldap_op.o: /usr/include/bits/stdio_lim.h
ldap_op.o: /usr/include/bits/sys_errlist.h
ldap_op.o: ../../include/ac/stdlib.h
ldap_op.o: /usr/include/stdlib.h
ldap_op.o: /usr/include/bits/waitflags.h
ldap_op.o: /usr/include/bits/waitstatus.h
ldap_op.o: /usr/include/endian.h
ldap_op.o: /usr/include/bits/endian.h
ldap_op.o: /usr/include/bits/byteswap.h
ldap_op.o: /usr/include/bits/byteswap-16.h
ldap_op.o: /usr/include/xlocale.h
ldap_op.o: /usr/include/sys/types.h
ldap_op.o: /usr/include/time.h
ldap_op.o: /usr/include/sys/select.h
ldap_op.o: /usr/include/bits/select.h
ldap_op.o: /usr/include/bits/sigset.h
ldap_op.o: /usr/include/bits/time.h
ldap_op.o: /usr/include/sys/sysmacros.h
ldap_op.o: /usr/include/bits/pthreadtypes.h
ldap_op.o: /usr/include/alloca.h
ldap_op.o: /usr/include/bits/stdlib-float.h
ldap_op.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/limits.h
ldap_op.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/syslimits.h
ldap_op.o: /usr/include/limits.h
ldap_op.o: /usr/include/bits/posix1_lim.h
ldap_op.o: /usr/include/bits/local_lim.h
ldap_op.o: /usr/include/linux/limits.h
ldap_op.o: /usr/include/bits/posix2_lim.h
ldap_op.o: /usr/include/bits/xopen_lim.h
ldap_op.o: ../../include/ac/errno.h
ldap_op.o: /usr/include/errno.h
ldap_op.o: /usr/include/bits/errno.h
ldap_op.o: /usr/include/linux/errno.h
ldap_op.o: /usr/include/asm/errno.h
ldap_op.o: /usr/include/asm-generic/errno.h
ldap_op.o: /usr/include/asm-generic/errno-base.h
ldap_op.o: ../../include/ac/string.h
ldap_op.o: /usr/include/string.h
ldap_op.o: ../../include/ac/ctype.h
ldap_op.o: /usr/include/ctype.h
ldap_op.o: ../../include/ac/time.h
ldap_op.o: /usr/include/sys/time.h
ldap_op.o: /usr/include/bits/timex.h
ldap_op.o: ../../include/ac/unistd.h
ldap_op.o: /usr/include/unistd.h
ldap_op.o: /usr/include/bits/posix_opt.h
ldap_op.o: /usr/include/bits/environments.h
ldap_op.o: /usr/include/bits/confname.h
ldap_op.o: /usr/include/getopt.h
ldap_op.o: ../../include/lutil_lockf.h
ldap_op.o: ../../include/ldap.h
ldap_op.o: ../../include/lber.h
ldap_op.o: ../../include/lber_types.h
ldap_op.o: ../../include/ldap_cdefs.h
ldap_op.o: ../../include/ldap_features.h
ldap_op.o: ../../include/lutil_ldap.h
ldap_op.o: slurp.h
ldap_op.o: ../../include/ac/param.h
ldap_op.o: /usr/include/sys/param.h
ldap_op.o: /usr/include/signal.h
ldap_op.o: /usr/include/bits/signum.h
ldap_op.o: /usr/include/bits/siginfo.h
ldap_op.o: /usr/include/bits/sigaction.h
ldap_op.o: /usr/include/bits/sigcontext.h
ldap_op.o: /usr/include/bits/sigstack.h
ldap_op.o: /usr/include/sys/ucontext.h
ldap_op.o: /usr/include/bits/sigthread.h
ldap_op.o: /usr/include/bits/param.h
ldap_op.o: /usr/include/linux/param.h
ldap_op.o: /usr/include/asm/param.h
ldap_op.o: /usr/include/asm-generic/param.h
ldap_op.o: ../../include/ac/signal.h
ldap_op.o: ../../include/ac/syslog.h
ldap_op.o: /usr/include/syslog.h
ldap_op.o: /usr/include/sys/syslog.h
ldap_op.o: /usr/include/bits/syslog-path.h
ldap_op.o: ../../include/ldap_log.h
ldap_op.o: ../../include/ldap_pvt_thread.h
ldap_op.o: ../../include/ldap_int_thread.h
ldap_op.o: /usr/include/pthread.h
ldap_op.o: /usr/include/sched.h
ldap_op.o: /usr/include/bits/sched.h
ldap_op.o: /usr/include/bits/setjmp.h
ldap_op.o: ../../include/ldap_defaults.h
ldap_op.o: ../../include/ldap_config.h
ldap_op.o: ../../include/ldif.h
ldap_op.o: proto-slurp.h
lock.o: lock.c
lock.o: /usr/include/stdc-predef.h
lock.o: ../../include/portable.h
lock.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h
lock.o: ../../include/ac/fdset.h
lock.o: /usr/include/bits/types.h
lock.o: /usr/include/features.h
lock.o: /usr/include/sys/cdefs.h
lock.o: /usr/include/bits/wordsize.h
lock.o: /usr/include/gnu/stubs.h
lock.o: /usr/include/gnu/stubs-64.h
lock.o: /usr/include/bits/typesizes.h
lock.o: ../../include/ldap_cdefs.h
lock.o: ../../include/ldap_features.h
lock.o: ../../include/ac/assert.h
lock.o: /usr/include/assert.h
lock.o: ../../include/ac/localize.h
lock.o: /usr/include/stdio.h
lock.o: /usr/include/libio.h
lock.o: /usr/include/_G_config.h
lock.o: /usr/include/wchar.h
lock.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stdarg.h
lock.o: /usr/include/bits/stdio_lim.h
lock.o: /usr/include/bits/sys_errlist.h
lock.o: ../../include/ac/param.h
lock.o: /usr/include/sys/param.h
lock.o: /usr/include/sys/types.h
lock.o: /usr/include/time.h
lock.o: /usr/include/endian.h
lock.o: /usr/include/bits/endian.h
lock.o: /usr/include/bits/byteswap.h
lock.o: /usr/include/bits/byteswap-16.h
lock.o: /usr/include/sys/select.h
lock.o: /usr/include/bits/select.h
lock.o: /usr/include/bits/sigset.h
lock.o: /usr/include/bits/time.h
lock.o: /usr/include/sys/sysmacros.h
lock.o: /usr/include/bits/pthreadtypes.h
lock.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/limits.h
lock.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/syslimits.h
lock.o: /usr/include/limits.h
lock.o: /usr/include/bits/posix1_lim.h
lock.o: /usr/include/bits/local_lim.h
lock.o: /usr/include/linux/limits.h
lock.o: /usr/include/bits/posix2_lim.h
lock.o: /usr/include/bits/xopen_lim.h
lock.o: /usr/include/signal.h
lock.o: /usr/include/bits/signum.h
lock.o: /usr/include/bits/siginfo.h
lock.o: /usr/include/bits/sigaction.h
lock.o: /usr/include/bits/sigcontext.h
lock.o: /usr/include/bits/sigstack.h
lock.o: /usr/include/sys/ucontext.h
lock.o: /usr/include/bits/sigthread.h
lock.o: /usr/include/bits/param.h
lock.o: /usr/include/linux/param.h
lock.o: /usr/include/asm/param.h
lock.o: /usr/include/asm-generic/param.h
lock.o: ../../include/ac/string.h
lock.o: /usr/include/string.h
lock.o: /usr/include/xlocale.h
lock.o: ../../include/ac/socket.h
lock.o: /usr/include/poll.h
lock.o: /usr/include/sys/poll.h
lock.o: /usr/include/bits/poll.h
lock.o: /usr/include/sys/socket.h
lock.o: /usr/include/sys/uio.h
lock.o: /usr/include/bits/uio.h
lock.o: /usr/include/bits/socket.h
lock.o: /usr/include/bits/socket_type.h
lock.o: /usr/include/bits/sockaddr.h
lock.o: /usr/include/asm/socket.h
lock.o: /usr/include/asm-generic/socket.h
lock.o: /usr/include/asm/sockios.h
lock.o: /usr/include/asm-generic/sockios.h
lock.o: /usr/include/sys/un.h
lock.o: /usr/include/netinet/in.h
lock.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stdint.h
lock.o: /usr/include/stdint.h
lock.o: /usr/include/bits/wchar.h
lock.o: /usr/include/bits/in.h
lock.o: /usr/include/netinet/tcp.h
lock.o: /usr/include/arpa/inet.h
lock.o: /usr/include/arpa/nameser.h
lock.o: /usr/include/arpa/nameser_compat.h
lock.o: /usr/include/netdb.h
lock.o: /usr/include/rpc/netdb.h
lock.o: /usr/include/bits/netdb.h
lock.o: /usr/include/resolv.h
lock.o: ../../include/ac/time.h
lock.o: /usr/include/sys/time.h
lock.o: /usr/include/bits/timex.h
lock.o: ../../include/ac/unistd.h
lock.o: /usr/include/unistd.h
lock.o: /usr/include/bits/posix_opt.h
lock.o: /usr/include/bits/environments.h
lock.o: /usr/include/bits/confname.h
lock.o: /usr/include/getopt.h
lock.o: ../../include/lutil_lockf.h
lock.o: /usr/include/sys/file.h
lock.o: /usr/include/fcntl.h
lock.o: /usr/include/bits/fcntl.h
lock.o: /usr/include/bits/fcntl-linux.h
lock.o: /usr/include/linux/falloc.h
lock.o: /usr/include/bits/stat.h
lock.o: slurp.h
lock.o: ../../include/ac/errno.h
lock.o: /usr/include/errno.h
lock.o: /usr/include/bits/errno.h
lock.o: /usr/include/linux/errno.h
lock.o: /usr/include/asm/errno.h
lock.o: /usr/include/asm-generic/errno.h
lock.o: /usr/include/asm-generic/errno-base.h
lock.o: ../../include/ac/signal.h
lock.o: ../../include/ac/syslog.h
lock.o: /usr/include/syslog.h
lock.o: /usr/include/sys/syslog.h
lock.o: /usr/include/bits/syslog-path.h
lock.o: ../../include/ldap.h
lock.o: ../../include/lber.h
lock.o: ../../include/lber_types.h
lock.o: ../../include/ldap_cdefs.h
lock.o: ../../include/ldap_features.h
lock.o: ../../include/ldap_log.h
lock.o: ../../include/ldap_pvt_thread.h
lock.o: ../../include/ldap_int_thread.h
lock.o: /usr/include/pthread.h
lock.o: /usr/include/sched.h
lock.o: /usr/include/bits/sched.h
lock.o: /usr/include/bits/setjmp.h
lock.o: ../../include/ldap_defaults.h
lock.o: ../../include/ldap_config.h
lock.o: ../../include/ldif.h
lock.o: proto-slurp.h
main.o: main.c
main.o: /usr/include/stdc-predef.h
main.o: ../../include/portable.h
main.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h
main.o: ../../include/ac/fdset.h
main.o: /usr/include/bits/types.h
main.o: /usr/include/features.h
main.o: /usr/include/sys/cdefs.h
main.o: /usr/include/bits/wordsize.h
main.o: /usr/include/gnu/stubs.h
main.o: /usr/include/gnu/stubs-64.h
main.o: /usr/include/bits/typesizes.h
main.o: ../../include/ldap_cdefs.h
main.o: ../../include/ldap_features.h
main.o: ../../include/ac/assert.h
main.o: /usr/include/assert.h
main.o: ../../include/ac/localize.h
main.o: /usr/include/stdio.h
main.o: /usr/include/libio.h
main.o: /usr/include/_G_config.h
main.o: /usr/include/wchar.h
main.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stdarg.h
main.o: /usr/include/bits/stdio_lim.h
main.o: /usr/include/bits/sys_errlist.h
main.o: /usr/include/sys/stat.h
main.o: /usr/include/time.h
main.o: /usr/include/bits/stat.h
main.o: ../../include/ac/stdlib.h
main.o: /usr/include/stdlib.h
main.o: /usr/include/bits/waitflags.h
main.o: /usr/include/bits/waitstatus.h
main.o: /usr/include/endian.h
main.o: /usr/include/bits/endian.h
main.o: /usr/include/bits/byteswap.h
main.o: /usr/include/bits/byteswap-16.h
main.o: /usr/include/xlocale.h
main.o: /usr/include/sys/types.h
main.o: /usr/include/sys/select.h
main.o: /usr/include/bits/select.h
main.o: /usr/include/bits/sigset.h
main.o: /usr/include/bits/time.h
main.o: /usr/include/sys/sysmacros.h
main.o: /usr/include/bits/pthreadtypes.h
main.o: /usr/include/alloca.h
main.o: /usr/include/bits/stdlib-float.h
main.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/limits.h
main.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/syslimits.h
main.o: /usr/include/limits.h
main.o: /usr/include/bits/posix1_lim.h
main.o: /usr/include/bits/local_lim.h
main.o: /usr/include/linux/limits.h
main.o: /usr/include/bits/posix2_lim.h
main.o: /usr/include/bits/xopen_lim.h
main.o: ../../include/ac/unistd.h
main.o: /usr/include/unistd.h
main.o: /usr/include/bits/posix_opt.h
main.o: /usr/include/bits/environments.h
main.o: /usr/include/bits/confname.h
main.o: /usr/include/getopt.h
main.o: ../../include/lutil_lockf.h
main.o: slurp.h
main.o: ../../include/ac/errno.h
main.o: /usr/include/errno.h
main.o: /usr/include/bits/errno.h
main.o: /usr/include/linux/errno.h
main.o: /usr/include/asm/errno.h
main.o: /usr/include/asm-generic/errno.h
main.o: /usr/include/asm-generic/errno-base.h
main.o: ../../include/ac/param.h
main.o: /usr/include/sys/param.h
main.o: /usr/include/signal.h
main.o: /usr/include/bits/signum.h
main.o: /usr/include/bits/siginfo.h
main.o: /usr/include/bits/sigaction.h
main.o: /usr/include/bits/sigcontext.h
main.o: /usr/include/bits/sigstack.h
main.o: /usr/include/sys/ucontext.h
main.o: /usr/include/bits/sigthread.h
main.o: /usr/include/bits/param.h
main.o: /usr/include/linux/param.h
main.o: /usr/include/asm/param.h
main.o: /usr/include/asm-generic/param.h
main.o: ../../include/ac/signal.h
main.o: ../../include/ac/syslog.h
main.o: /usr/include/syslog.h
main.o: /usr/include/sys/syslog.h
main.o: /usr/include/bits/syslog-path.h
main.o: ../../include/ac/time.h
main.o: /usr/include/sys/time.h
main.o: /usr/include/bits/timex.h
main.o: ../../include/ldap.h
main.o: ../../include/lber.h
main.o: ../../include/lber_types.h
main.o: ../../include/ldap_cdefs.h
main.o: /usr/include/string.h
main.o: ../../include/ldap_features.h
main.o: ../../include/ldap_log.h
main.o: ../../include/ldap_pvt_thread.h
main.o: ../../include/ldap_int_thread.h
main.o: /usr/include/pthread.h
main.o: /usr/include/sched.h
main.o: /usr/include/bits/sched.h
main.o: /usr/include/bits/setjmp.h
main.o: ../../include/ldap_defaults.h
main.o: globals.h
main.o: ../../include/ldap_config.h
main.o: ../../include/ldif.h
main.o: proto-slurp.h
main.o: ../../include/lutil.h
main.o: ../../include/ldap_pvt.h
main.o: ../../include/ldap_pvt_uc.h
main.o: ../../include/ac/bytes.h
main.o: ../../include/../libraries/liblunicode/ucdata/ucdata.h
re.o: re.c
re.o: /usr/include/stdc-predef.h
re.o: ../../include/portable.h
re.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h
re.o: ../../include/ac/fdset.h
re.o: /usr/include/bits/types.h
re.o: /usr/include/features.h
re.o: /usr/include/sys/cdefs.h
re.o: /usr/include/bits/wordsize.h
re.o: /usr/include/gnu/stubs.h
re.o: /usr/include/gnu/stubs-64.h
re.o: /usr/include/bits/typesizes.h
re.o: ../../include/ldap_cdefs.h
re.o: ../../include/ldap_features.h
re.o: ../../include/ac/assert.h
re.o: /usr/include/assert.h
re.o: ../../include/ac/localize.h
re.o: /usr/include/stdio.h
re.o: /usr/include/libio.h
re.o: /usr/include/_G_config.h
re.o: /usr/include/wchar.h
re.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stdarg.h
re.o: /usr/include/bits/stdio_lim.h
re.o: /usr/include/bits/sys_errlist.h
re.o: ../../include/ac/stdlib.h
re.o: /usr/include/stdlib.h
re.o: /usr/include/bits/waitflags.h
re.o: /usr/include/bits/waitstatus.h
re.o: /usr/include/endian.h
re.o: /usr/include/bits/endian.h
re.o: /usr/include/bits/byteswap.h
re.o: /usr/include/bits/byteswap-16.h
re.o: /usr/include/xlocale.h
re.o: /usr/include/sys/types.h
re.o: /usr/include/time.h
re.o: /usr/include/sys/select.h
re.o: /usr/include/bits/select.h
re.o: /usr/include/bits/sigset.h
re.o: /usr/include/bits/time.h
re.o: /usr/include/sys/sysmacros.h
re.o: /usr/include/bits/pthreadtypes.h
re.o: /usr/include/alloca.h
re.o: /usr/include/bits/stdlib-float.h
re.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/limits.h
re.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/syslimits.h
re.o: /usr/include/limits.h
re.o: /usr/include/bits/posix1_lim.h
re.o: /usr/include/bits/local_lim.h
re.o: /usr/include/linux/limits.h
re.o: /usr/include/bits/posix2_lim.h
re.o: /usr/include/bits/xopen_lim.h
re.o: ../../include/ac/errno.h
re.o: /usr/include/errno.h
re.o: /usr/include/bits/errno.h
re.o: /usr/include/linux/errno.h
re.o: /usr/include/asm/errno.h
re.o: /usr/include/asm-generic/errno.h
re.o: /usr/include/asm-generic/errno-base.h
re.o: ../../include/ac/socket.h
re.o: /usr/include/poll.h
re.o: /usr/include/sys/poll.h
re.o: /usr/include/bits/poll.h
re.o: /usr/include/sys/socket.h
re.o: /usr/include/sys/uio.h
re.o: /usr/include/bits/uio.h
re.o: /usr/include/bits/socket.h
re.o: /usr/include/bits/socket_type.h
re.o: /usr/include/bits/sockaddr.h
re.o: /usr/include/asm/socket.h
re.o: /usr/include/asm-generic/socket.h
re.o: /usr/include/asm/sockios.h
re.o: /usr/include/asm-generic/sockios.h
re.o: /usr/include/sys/un.h
re.o: /usr/include/string.h
re.o: /usr/include/netinet/in.h
re.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stdint.h
re.o: /usr/include/stdint.h
re.o: /usr/include/bits/wchar.h
re.o: /usr/include/bits/in.h
re.o: /usr/include/netinet/tcp.h
re.o: /usr/include/arpa/inet.h
re.o: /usr/include/arpa/nameser.h
re.o: /usr/include/sys/param.h
re.o: /usr/include/signal.h
re.o: /usr/include/bits/signum.h
re.o: /usr/include/bits/siginfo.h
re.o: /usr/include/bits/sigaction.h
re.o: /usr/include/bits/sigcontext.h
re.o: /usr/include/bits/sigstack.h
re.o: /usr/include/sys/ucontext.h
re.o: /usr/include/bits/sigthread.h
re.o: /usr/include/bits/param.h
re.o: /usr/include/linux/param.h
re.o: /usr/include/asm/param.h
re.o: /usr/include/asm-generic/param.h
re.o: /usr/include/arpa/nameser_compat.h
re.o: /usr/include/netdb.h
re.o: /usr/include/rpc/netdb.h
re.o: /usr/include/bits/netdb.h
re.o: /usr/include/resolv.h
re.o: ../../include/ac/string.h
re.o: ../../include/ac/ctype.h
re.o: /usr/include/ctype.h
re.o: ../slapd/slap.h
re.o: ../../include/ldap_defaults.h
re.o: ../../include/ldap_config.h
re.o: ../../include/ac/syslog.h
re.o: /usr/include/syslog.h
re.o: /usr/include/sys/syslog.h
re.o: /usr/include/bits/syslog-path.h
re.o: ../../include/ac/regex.h
re.o: /usr/include/regex.h
re.o: ../../include/ac/signal.h
re.o: ../../include/ac/time.h
re.o: /usr/include/sys/time.h
re.o: /usr/include/bits/timex.h
re.o: ../../include/ac/param.h
re.o: ../../include/avl.h
re.o: ../../include/ldap_cdefs.h
re.o: ../../include/ldap_log.h
re.o: ../../include/ldap.h
re.o: ../../include/lber.h
re.o: ../../include/lber_types.h
re.o: ../../include/ldap_features.h
re.o: ../../include/ldap_schema.h
re.o: ../../include/lber_pvt.h
re.o: ../../include/ldap_pvt.h
re.o: ../../include/ldap_pvt_uc.h
re.o: ../../include/ac/bytes.h
re.o: ../../include/../libraries/liblunicode/ucdata/ucdata.h
re.o: ../../include/ldap_pvt_thread.h
re.o: ../../include/ldap_int_thread.h
re.o: /usr/include/pthread.h
re.o: /usr/include/sched.h
re.o: /usr/include/bits/sched.h
re.o: /usr/include/bits/setjmp.h
re.o: ../../include/ldap_queue.h
re.o: proto-slurp.h
re.o: ../slapd/proto-slap.h
re.o: slurp.h
re.o: ../../include/ldif.h
re.o: globals.h
re.o: ../../include/lutil.h
reject.o: reject.c
reject.o: /usr/include/stdc-predef.h
reject.o: ../../include/portable.h
reject.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h
reject.o: ../../include/ac/fdset.h
reject.o: /usr/include/bits/types.h
reject.o: /usr/include/features.h
reject.o: /usr/include/sys/cdefs.h
reject.o: /usr/include/bits/wordsize.h
reject.o: /usr/include/gnu/stubs.h
reject.o: /usr/include/gnu/stubs-64.h
reject.o: /usr/include/bits/typesizes.h
reject.o: ../../include/ldap_cdefs.h
reject.o: ../../include/ldap_features.h
reject.o: ../../include/ac/assert.h
reject.o: /usr/include/assert.h
reject.o: ../../include/ac/localize.h
reject.o: /usr/include/stdio.h
reject.o: /usr/include/libio.h
reject.o: /usr/include/_G_config.h
reject.o: /usr/include/wchar.h
reject.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stdarg.h
reject.o: /usr/include/bits/stdio_lim.h
reject.o: /usr/include/bits/sys_errlist.h
reject.o: ../../include/ac/stdlib.h
reject.o: /usr/include/stdlib.h
reject.o: /usr/include/bits/waitflags.h
reject.o: /usr/include/bits/waitstatus.h
reject.o: /usr/include/endian.h
reject.o: /usr/include/bits/endian.h
reject.o: /usr/include/bits/byteswap.h
reject.o: /usr/include/bits/byteswap-16.h
reject.o: /usr/include/xlocale.h
reject.o: /usr/include/sys/types.h
reject.o: /usr/include/time.h
reject.o: /usr/include/sys/select.h
reject.o: /usr/include/bits/select.h
reject.o: /usr/include/bits/sigset.h
reject.o: /usr/include/bits/time.h
reject.o: /usr/include/sys/sysmacros.h
reject.o: /usr/include/bits/pthreadtypes.h
reject.o: /usr/include/alloca.h
reject.o: /usr/include/bits/stdlib-float.h
reject.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/limits.h
reject.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/syslimits.h
reject.o: /usr/include/limits.h
reject.o: /usr/include/bits/posix1_lim.h
reject.o: /usr/include/bits/local_lim.h
reject.o: /usr/include/linux/limits.h
reject.o: /usr/include/bits/posix2_lim.h
reject.o: /usr/include/bits/xopen_lim.h
reject.o: ../../include/ac/string.h
reject.o: /usr/include/string.h
reject.o: ../../include/ac/errno.h
reject.o: /usr/include/errno.h
reject.o: /usr/include/bits/errno.h
reject.o: /usr/include/linux/errno.h
reject.o: /usr/include/asm/errno.h
reject.o: /usr/include/asm-generic/errno.h
reject.o: /usr/include/asm-generic/errno-base.h
reject.o: ../../include/ac/unistd.h
reject.o: /usr/include/unistd.h
reject.o: /usr/include/bits/posix_opt.h
reject.o: /usr/include/bits/environments.h
reject.o: /usr/include/bits/confname.h
reject.o: /usr/include/getopt.h
reject.o: ../../include/lutil_lockf.h
reject.o: /usr/include/sys/stat.h
reject.o: /usr/include/bits/stat.h
reject.o: /usr/include/fcntl.h
reject.o: /usr/include/bits/fcntl.h
reject.o: /usr/include/bits/fcntl-linux.h
reject.o: /usr/include/bits/uio.h
reject.o: /usr/include/linux/falloc.h
reject.o: slurp.h
reject.o: ../../include/ac/param.h
reject.o: /usr/include/sys/param.h
reject.o: /usr/include/signal.h
reject.o: /usr/include/bits/signum.h
reject.o: /usr/include/bits/siginfo.h
reject.o: /usr/include/bits/sigaction.h
reject.o: /usr/include/bits/sigcontext.h
reject.o: /usr/include/bits/sigstack.h
reject.o: /usr/include/sys/ucontext.h
reject.o: /usr/include/bits/sigthread.h
reject.o: /usr/include/bits/param.h
reject.o: /usr/include/linux/param.h
reject.o: /usr/include/asm/param.h
reject.o: /usr/include/asm-generic/param.h
reject.o: ../../include/ac/signal.h
reject.o: ../../include/ac/syslog.h
reject.o: /usr/include/syslog.h
reject.o: /usr/include/sys/syslog.h
reject.o: /usr/include/bits/syslog-path.h
reject.o: ../../include/ac/time.h
reject.o: /usr/include/sys/time.h
reject.o: /usr/include/bits/timex.h
reject.o: ../../include/ldap.h
reject.o: ../../include/lber.h
reject.o: ../../include/lber_types.h
reject.o: ../../include/ldap_cdefs.h
reject.o: ../../include/ldap_features.h
reject.o: ../../include/ldap_log.h
reject.o: ../../include/ldap_pvt_thread.h
reject.o: ../../include/ldap_int_thread.h
reject.o: /usr/include/pthread.h
reject.o: /usr/include/sched.h
reject.o: /usr/include/bits/sched.h
reject.o: /usr/include/bits/setjmp.h
reject.o: ../../include/ldap_defaults.h
reject.o: globals.h
reject.o: ../../include/ldap_config.h
reject.o: ../../include/ldif.h
reject.o: proto-slurp.h
reject.o: ../../include/lber_pvt.h
reject.o: ../../include/lutil.h
replica.o: replica.c
replica.o: /usr/include/stdc-predef.h
replica.o: ../../include/portable.h
replica.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h
replica.o: ../../include/ac/fdset.h
replica.o: /usr/include/bits/types.h
replica.o: /usr/include/features.h
replica.o: /usr/include/sys/cdefs.h
replica.o: /usr/include/bits/wordsize.h
replica.o: /usr/include/gnu/stubs.h
replica.o: /usr/include/gnu/stubs-64.h
replica.o: /usr/include/bits/typesizes.h
replica.o: ../../include/ldap_cdefs.h
replica.o: ../../include/ldap_features.h
replica.o: ../../include/ac/assert.h
replica.o: /usr/include/assert.h
replica.o: ../../include/ac/localize.h
replica.o: /usr/include/stdio.h
replica.o: /usr/include/libio.h
replica.o: /usr/include/_G_config.h
replica.o: /usr/include/wchar.h
replica.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stdarg.h
replica.o: /usr/include/bits/stdio_lim.h
replica.o: /usr/include/bits/sys_errlist.h
replica.o: ../../include/ac/stdlib.h
replica.o: /usr/include/stdlib.h
replica.o: /usr/include/bits/waitflags.h
replica.o: /usr/include/bits/waitstatus.h
replica.o: /usr/include/endian.h
replica.o: /usr/include/bits/endian.h
replica.o: /usr/include/bits/byteswap.h
replica.o: /usr/include/bits/byteswap-16.h
replica.o: /usr/include/xlocale.h
replica.o: /usr/include/sys/types.h
replica.o: /usr/include/time.h
replica.o: /usr/include/sys/select.h
replica.o: /usr/include/bits/select.h
replica.o: /usr/include/bits/sigset.h
replica.o: /usr/include/bits/time.h
replica.o: /usr/include/sys/sysmacros.h
replica.o: /usr/include/bits/pthreadtypes.h
replica.o: /usr/include/alloca.h
replica.o: /usr/include/bits/stdlib-float.h
replica.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/limits.h
replica.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/syslimits.h
replica.o: /usr/include/limits.h
replica.o: /usr/include/bits/posix1_lim.h
replica.o: /usr/include/bits/local_lim.h
replica.o: /usr/include/linux/limits.h
replica.o: /usr/include/bits/posix2_lim.h
replica.o: /usr/include/bits/xopen_lim.h
replica.o: slurp.h
replica.o: ../../include/ac/errno.h
replica.o: /usr/include/errno.h
replica.o: /usr/include/bits/errno.h
replica.o: /usr/include/linux/errno.h
replica.o: /usr/include/asm/errno.h
replica.o: /usr/include/asm-generic/errno.h
replica.o: /usr/include/asm-generic/errno-base.h
replica.o: ../../include/ac/param.h
replica.o: /usr/include/sys/param.h
replica.o: /usr/include/signal.h
replica.o: /usr/include/bits/signum.h
replica.o: /usr/include/bits/siginfo.h
replica.o: /usr/include/bits/sigaction.h
replica.o: /usr/include/bits/sigcontext.h
replica.o: /usr/include/bits/sigstack.h
replica.o: /usr/include/sys/ucontext.h
replica.o: /usr/include/bits/sigthread.h
replica.o: /usr/include/bits/param.h
replica.o: /usr/include/linux/param.h
replica.o: /usr/include/asm/param.h
replica.o: /usr/include/asm-generic/param.h
replica.o: ../../include/ac/signal.h
replica.o: ../../include/ac/syslog.h
replica.o: /usr/include/syslog.h
replica.o: /usr/include/sys/syslog.h
replica.o: /usr/include/bits/syslog-path.h
replica.o: ../../include/ac/time.h
replica.o: /usr/include/sys/time.h
replica.o: /usr/include/bits/timex.h
replica.o: ../../include/ldap.h
replica.o: ../../include/lber.h
replica.o: ../../include/lber_types.h
replica.o: ../../include/ldap_cdefs.h
replica.o: /usr/include/string.h
replica.o: ../../include/ldap_features.h
replica.o: ../../include/ldap_log.h
replica.o: ../../include/ldap_pvt_thread.h
replica.o: ../../include/ldap_int_thread.h
replica.o: /usr/include/pthread.h
replica.o: /usr/include/sched.h
replica.o: /usr/include/bits/sched.h
replica.o: /usr/include/bits/setjmp.h
replica.o: ../../include/ldap_defaults.h
replica.o: globals.h
replica.o: ../../include/ldap_config.h
replica.o: ../../include/ldif.h
replica.o: proto-slurp.h
replog.o: replog.c
replog.o: /usr/include/stdc-predef.h
replog.o: ../../include/portable.h
replog.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h
replog.o: ../../include/ac/fdset.h
replog.o: /usr/include/bits/types.h
replog.o: /usr/include/features.h
replog.o: /usr/include/sys/cdefs.h
replog.o: /usr/include/bits/wordsize.h
replog.o: /usr/include/gnu/stubs.h
replog.o: /usr/include/gnu/stubs-64.h
replog.o: /usr/include/bits/typesizes.h
replog.o: ../../include/ldap_cdefs.h
replog.o: ../../include/ldap_features.h
replog.o: ../../include/ac/assert.h
replog.o: /usr/include/assert.h
replog.o: ../../include/ac/localize.h
replog.o: /usr/include/stdio.h
replog.o: /usr/include/libio.h
replog.o: /usr/include/_G_config.h
replog.o: /usr/include/wchar.h
replog.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stdarg.h
replog.o: /usr/include/bits/stdio_lim.h
replog.o: /usr/include/bits/sys_errlist.h
replog.o: ../../include/ac/stdlib.h
replog.o: /usr/include/stdlib.h
replog.o: /usr/include/bits/waitflags.h
replog.o: /usr/include/bits/waitstatus.h
replog.o: /usr/include/endian.h
replog.o: /usr/include/bits/endian.h
replog.o: /usr/include/bits/byteswap.h
replog.o: /usr/include/bits/byteswap-16.h
replog.o: /usr/include/xlocale.h
replog.o: /usr/include/sys/types.h
replog.o: /usr/include/time.h
replog.o: /usr/include/sys/select.h
replog.o: /usr/include/bits/select.h
replog.o: /usr/include/bits/sigset.h
replog.o: /usr/include/bits/time.h
replog.o: /usr/include/sys/sysmacros.h
replog.o: /usr/include/bits/pthreadtypes.h
replog.o: /usr/include/alloca.h
replog.o: /usr/include/bits/stdlib-float.h
replog.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/limits.h
replog.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/syslimits.h
replog.o: /usr/include/limits.h
replog.o: /usr/include/bits/posix1_lim.h
replog.o: /usr/include/bits/local_lim.h
replog.o: /usr/include/linux/limits.h
replog.o: /usr/include/bits/posix2_lim.h
replog.o: /usr/include/bits/xopen_lim.h
replog.o: ../../include/ac/errno.h
replog.o: /usr/include/errno.h
replog.o: /usr/include/bits/errno.h
replog.o: /usr/include/linux/errno.h
replog.o: /usr/include/asm/errno.h
replog.o: /usr/include/asm-generic/errno.h
replog.o: /usr/include/asm-generic/errno-base.h
replog.o: ../../include/ac/param.h
replog.o: /usr/include/sys/param.h
replog.o: /usr/include/signal.h
replog.o: /usr/include/bits/signum.h
replog.o: /usr/include/bits/siginfo.h
replog.o: /usr/include/bits/sigaction.h
replog.o: /usr/include/bits/sigcontext.h
replog.o: /usr/include/bits/sigstack.h
replog.o: /usr/include/sys/ucontext.h
replog.o: /usr/include/bits/sigthread.h
replog.o: /usr/include/bits/param.h
replog.o: /usr/include/linux/param.h
replog.o: /usr/include/asm/param.h
replog.o: /usr/include/asm-generic/param.h
replog.o: ../../include/ac/string.h
replog.o: /usr/include/string.h
replog.o: ../../include/ac/syslog.h
replog.o: /usr/include/syslog.h
replog.o: /usr/include/sys/syslog.h
replog.o: /usr/include/bits/syslog-path.h
replog.o: ../../include/ac/time.h
replog.o: /usr/include/sys/time.h
replog.o: /usr/include/bits/timex.h
replog.o: ../../include/ac/unistd.h
replog.o: /usr/include/unistd.h
replog.o: /usr/include/bits/posix_opt.h
replog.o: /usr/include/bits/environments.h
replog.o: /usr/include/bits/confname.h
replog.o: /usr/include/getopt.h
replog.o: ../../include/lutil_lockf.h
replog.o: /usr/include/sys/stat.h
replog.o: /usr/include/bits/stat.h
replog.o: /usr/include/fcntl.h
replog.o: /usr/include/bits/fcntl.h
replog.o: /usr/include/bits/fcntl-linux.h
replog.o: /usr/include/bits/uio.h
replog.o: /usr/include/linux/falloc.h
replog.o: slurp.h
replog.o: ../../include/ac/signal.h
replog.o: ../../include/ldap.h
replog.o: ../../include/lber.h
replog.o: ../../include/lber_types.h
replog.o: ../../include/ldap_cdefs.h
replog.o: ../../include/ldap_features.h
replog.o: ../../include/ldap_log.h
replog.o: ../../include/ldap_pvt_thread.h
replog.o: ../../include/ldap_int_thread.h
replog.o: /usr/include/pthread.h
replog.o: /usr/include/sched.h
replog.o: /usr/include/bits/sched.h
replog.o: /usr/include/bits/setjmp.h
replog.o: ../../include/ldap_defaults.h
replog.o: globals.h
replog.o: ../../include/ldap_config.h
replog.o: ../../include/ldif.h
replog.o: proto-slurp.h
ri.o: ri.c
ri.o: /usr/include/stdc-predef.h
ri.o: ../../include/portable.h
ri.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h
ri.o: ../../include/ac/fdset.h
ri.o: /usr/include/bits/types.h
ri.o: /usr/include/features.h
ri.o: /usr/include/sys/cdefs.h
ri.o: /usr/include/bits/wordsize.h
ri.o: /usr/include/gnu/stubs.h
ri.o: /usr/include/gnu/stubs-64.h
ri.o: /usr/include/bits/typesizes.h
ri.o: ../../include/ldap_cdefs.h
ri.o: ../../include/ldap_features.h
ri.o: ../../include/ac/assert.h
ri.o: /usr/include/assert.h
ri.o: ../../include/ac/localize.h
ri.o: /usr/include/stdio.h
ri.o: /usr/include/libio.h
ri.o: /usr/include/_G_config.h
ri.o: /usr/include/wchar.h
ri.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stdarg.h
ri.o: /usr/include/bits/stdio_lim.h
ri.o: /usr/include/bits/sys_errlist.h
ri.o: ../../include/ac/stdlib.h
ri.o: /usr/include/stdlib.h
ri.o: /usr/include/bits/waitflags.h
ri.o: /usr/include/bits/waitstatus.h
ri.o: /usr/include/endian.h
ri.o: /usr/include/bits/endian.h
ri.o: /usr/include/bits/byteswap.h
ri.o: /usr/include/bits/byteswap-16.h
ri.o: /usr/include/xlocale.h
ri.o: /usr/include/sys/types.h
ri.o: /usr/include/time.h
ri.o: /usr/include/sys/select.h
ri.o: /usr/include/bits/select.h
ri.o: /usr/include/bits/sigset.h
ri.o: /usr/include/bits/time.h
ri.o: /usr/include/sys/sysmacros.h
ri.o: /usr/include/bits/pthreadtypes.h
ri.o: /usr/include/alloca.h
ri.o: /usr/include/bits/stdlib-float.h
ri.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/limits.h
ri.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/syslimits.h
ri.o: /usr/include/limits.h
ri.o: /usr/include/bits/posix1_lim.h
ri.o: /usr/include/bits/local_lim.h
ri.o: /usr/include/linux/limits.h
ri.o: /usr/include/bits/posix2_lim.h
ri.o: /usr/include/bits/xopen_lim.h
ri.o: ../../include/ac/string.h
ri.o: /usr/include/string.h
ri.o: ../../include/ac/signal.h
ri.o: /usr/include/signal.h
ri.o: /usr/include/bits/signum.h
ri.o: /usr/include/bits/siginfo.h
ri.o: /usr/include/bits/sigaction.h
ri.o: /usr/include/bits/sigcontext.h
ri.o: /usr/include/bits/sigstack.h
ri.o: /usr/include/sys/ucontext.h
ri.o: /usr/include/bits/sigthread.h
ri.o: slurp.h
ri.o: ../../include/ac/errno.h
ri.o: /usr/include/errno.h
ri.o: /usr/include/bits/errno.h
ri.o: /usr/include/linux/errno.h
ri.o: /usr/include/asm/errno.h
ri.o: /usr/include/asm-generic/errno.h
ri.o: /usr/include/asm-generic/errno-base.h
ri.o: ../../include/ac/param.h
ri.o: /usr/include/sys/param.h
ri.o: /usr/include/bits/param.h
ri.o: /usr/include/linux/param.h
ri.o: /usr/include/asm/param.h
ri.o: /usr/include/asm-generic/param.h
ri.o: ../../include/ac/syslog.h
ri.o: /usr/include/syslog.h
ri.o: /usr/include/sys/syslog.h
ri.o: /usr/include/bits/syslog-path.h
ri.o: ../../include/ac/time.h
ri.o: /usr/include/sys/time.h
ri.o: /usr/include/bits/timex.h
ri.o: ../../include/ldap.h
ri.o: ../../include/lber.h
ri.o: ../../include/lber_types.h
ri.o: ../../include/ldap_cdefs.h
ri.o: ../../include/ldap_features.h
ri.o: ../../include/ldap_log.h
ri.o: ../../include/ldap_pvt_thread.h
ri.o: ../../include/ldap_int_thread.h
ri.o: /usr/include/pthread.h
ri.o: /usr/include/sched.h
ri.o: /usr/include/bits/sched.h
ri.o: /usr/include/bits/setjmp.h
ri.o: ../../include/ldap_defaults.h
ri.o: globals.h
ri.o: ../../include/ldap_config.h
ri.o: ../../include/ldif.h
ri.o: proto-slurp.h
rq.o: rq.c
rq.o: /usr/include/stdc-predef.h
rq.o: ../../include/portable.h
rq.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h
rq.o: ../../include/ac/fdset.h
rq.o: /usr/include/bits/types.h
rq.o: /usr/include/features.h
rq.o: /usr/include/sys/cdefs.h
rq.o: /usr/include/bits/wordsize.h
rq.o: /usr/include/gnu/stubs.h
rq.o: /usr/include/gnu/stubs-64.h
rq.o: /usr/include/bits/typesizes.h
rq.o: ../../include/ldap_cdefs.h
rq.o: ../../include/ldap_features.h
rq.o: ../../include/ac/assert.h
rq.o: /usr/include/assert.h
rq.o: ../../include/ac/localize.h
rq.o: /usr/include/stdio.h
rq.o: /usr/include/libio.h
rq.o: /usr/include/_G_config.h
rq.o: /usr/include/wchar.h
rq.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stdarg.h
rq.o: /usr/include/bits/stdio_lim.h
rq.o: /usr/include/bits/sys_errlist.h
rq.o: /usr/include/sys/stat.h
rq.o: /usr/include/time.h
rq.o: /usr/include/bits/stat.h
rq.o: ../../include/ac/stdlib.h
rq.o: /usr/include/stdlib.h
rq.o: /usr/include/bits/waitflags.h
rq.o: /usr/include/bits/waitstatus.h
rq.o: /usr/include/endian.h
rq.o: /usr/include/bits/endian.h
rq.o: /usr/include/bits/byteswap.h
rq.o: /usr/include/bits/byteswap-16.h
rq.o: /usr/include/xlocale.h
rq.o: /usr/include/sys/types.h
rq.o: /usr/include/sys/select.h
rq.o: /usr/include/bits/select.h
rq.o: /usr/include/bits/sigset.h
rq.o: /usr/include/bits/time.h
rq.o: /usr/include/sys/sysmacros.h
rq.o: /usr/include/bits/pthreadtypes.h
rq.o: /usr/include/alloca.h
rq.o: /usr/include/bits/stdlib-float.h
rq.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/limits.h
rq.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/syslimits.h
rq.o: /usr/include/limits.h
rq.o: /usr/include/bits/posix1_lim.h
rq.o: /usr/include/bits/local_lim.h
rq.o: /usr/include/linux/limits.h
rq.o: /usr/include/bits/posix2_lim.h
rq.o: /usr/include/bits/xopen_lim.h
rq.o: ../../include/ac/string.h
rq.o: /usr/include/string.h
rq.o: ../../include/ac/unistd.h
rq.o: /usr/include/unistd.h
rq.o: /usr/include/bits/posix_opt.h
rq.o: /usr/include/bits/environments.h
rq.o: /usr/include/bits/confname.h
rq.o: /usr/include/getopt.h
rq.o: ../../include/lutil_lockf.h
rq.o: /usr/include/fcntl.h
rq.o: /usr/include/bits/fcntl.h
rq.o: /usr/include/bits/fcntl-linux.h
rq.o: /usr/include/bits/uio.h
rq.o: /usr/include/linux/falloc.h
rq.o: slurp.h
rq.o: ../../include/ac/errno.h
rq.o: /usr/include/errno.h
rq.o: /usr/include/bits/errno.h
rq.o: /usr/include/linux/errno.h
rq.o: /usr/include/asm/errno.h
rq.o: /usr/include/asm-generic/errno.h
rq.o: /usr/include/asm-generic/errno-base.h
rq.o: ../../include/ac/param.h
rq.o: /usr/include/sys/param.h
rq.o: /usr/include/signal.h
rq.o: /usr/include/bits/signum.h
rq.o: /usr/include/bits/siginfo.h
rq.o: /usr/include/bits/sigaction.h
rq.o: /usr/include/bits/sigcontext.h
rq.o: /usr/include/bits/sigstack.h
rq.o: /usr/include/sys/ucontext.h
rq.o: /usr/include/bits/sigthread.h
rq.o: /usr/include/bits/param.h
rq.o: /usr/include/linux/param.h
rq.o: /usr/include/asm/param.h
rq.o: /usr/include/asm-generic/param.h
rq.o: ../../include/ac/signal.h
rq.o: ../../include/ac/syslog.h
rq.o: /usr/include/syslog.h
rq.o: /usr/include/sys/syslog.h
rq.o: /usr/include/bits/syslog-path.h
rq.o: ../../include/ac/time.h
rq.o: /usr/include/sys/time.h
rq.o: /usr/include/bits/timex.h
rq.o: ../../include/ldap.h
rq.o: ../../include/lber.h
rq.o: ../../include/lber_types.h
rq.o: ../../include/ldap_cdefs.h
rq.o: ../../include/ldap_features.h
rq.o: ../../include/ldap_log.h
rq.o: ../../include/ldap_pvt_thread.h
rq.o: ../../include/ldap_int_thread.h
rq.o: /usr/include/pthread.h
rq.o: /usr/include/sched.h
rq.o: /usr/include/bits/sched.h
rq.o: /usr/include/bits/setjmp.h
rq.o: ../../include/ldap_defaults.h
rq.o: globals.h
rq.o: ../../include/ldap_config.h
rq.o: ../../include/ldif.h
rq.o: proto-slurp.h
sanity.o: sanity.c
sanity.o: /usr/include/stdc-predef.h
sanity.o: ../../include/portable.h
sanity.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h
sanity.o: ../../include/ac/fdset.h
sanity.o: /usr/include/bits/types.h
sanity.o: /usr/include/features.h
sanity.o: /usr/include/sys/cdefs.h
sanity.o: /usr/include/bits/wordsize.h
sanity.o: /usr/include/gnu/stubs.h
sanity.o: /usr/include/gnu/stubs-64.h
sanity.o: /usr/include/bits/typesizes.h
sanity.o: ../../include/ldap_cdefs.h
sanity.o: ../../include/ldap_features.h
sanity.o: ../../include/ac/assert.h
sanity.o: /usr/include/assert.h
sanity.o: ../../include/ac/localize.h
sanity.o: /usr/include/stdio.h
sanity.o: /usr/include/libio.h
sanity.o: /usr/include/_G_config.h
sanity.o: /usr/include/wchar.h
sanity.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stdarg.h
sanity.o: /usr/include/bits/stdio_lim.h
sanity.o: /usr/include/bits/sys_errlist.h
sanity.o: ../../include/ac/stdlib.h
sanity.o: /usr/include/stdlib.h
sanity.o: /usr/include/bits/waitflags.h
sanity.o: /usr/include/bits/waitstatus.h
sanity.o: /usr/include/endian.h
sanity.o: /usr/include/bits/endian.h
sanity.o: /usr/include/bits/byteswap.h
sanity.o: /usr/include/bits/byteswap-16.h
sanity.o: /usr/include/xlocale.h
sanity.o: /usr/include/sys/types.h
sanity.o: /usr/include/time.h
sanity.o: /usr/include/sys/select.h
sanity.o: /usr/include/bits/select.h
sanity.o: /usr/include/bits/sigset.h
sanity.o: /usr/include/bits/time.h
sanity.o: /usr/include/sys/sysmacros.h
sanity.o: /usr/include/bits/pthreadtypes.h
sanity.o: /usr/include/alloca.h
sanity.o: /usr/include/bits/stdlib-float.h
sanity.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/limits.h
sanity.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/syslimits.h
sanity.o: /usr/include/limits.h
sanity.o: /usr/include/bits/posix1_lim.h
sanity.o: /usr/include/bits/local_lim.h
sanity.o: /usr/include/linux/limits.h
sanity.o: /usr/include/bits/posix2_lim.h
sanity.o: /usr/include/bits/xopen_lim.h
sanity.o: ../../include/ac/unistd.h
sanity.o: /usr/include/unistd.h
sanity.o: /usr/include/bits/posix_opt.h
sanity.o: /usr/include/bits/environments.h
sanity.o: /usr/include/bits/confname.h
sanity.o: /usr/include/getopt.h
sanity.o: ../../include/lutil_lockf.h
sanity.o: ../../include/ac/string.h
sanity.o: /usr/include/string.h
sanity.o: slurp.h
sanity.o: ../../include/ac/errno.h
sanity.o: /usr/include/errno.h
sanity.o: /usr/include/bits/errno.h
sanity.o: /usr/include/linux/errno.h
sanity.o: /usr/include/asm/errno.h
sanity.o: /usr/include/asm-generic/errno.h
sanity.o: /usr/include/asm-generic/errno-base.h
sanity.o: ../../include/ac/param.h
sanity.o: /usr/include/sys/param.h
sanity.o: /usr/include/signal.h
sanity.o: /usr/include/bits/signum.h
sanity.o: /usr/include/bits/siginfo.h
sanity.o: /usr/include/bits/sigaction.h
sanity.o: /usr/include/bits/sigcontext.h
sanity.o: /usr/include/bits/sigstack.h
sanity.o: /usr/include/sys/ucontext.h
sanity.o: /usr/include/bits/sigthread.h
sanity.o: /usr/include/bits/param.h
sanity.o: /usr/include/linux/param.h
sanity.o: /usr/include/asm/param.h
sanity.o: /usr/include/asm-generic/param.h
sanity.o: ../../include/ac/signal.h
sanity.o: ../../include/ac/syslog.h
sanity.o: /usr/include/syslog.h
sanity.o: /usr/include/sys/syslog.h
sanity.o: /usr/include/bits/syslog-path.h
sanity.o: ../../include/ac/time.h
sanity.o: /usr/include/sys/time.h
sanity.o: /usr/include/bits/timex.h
sanity.o: ../../include/ldap.h
sanity.o: ../../include/lber.h
sanity.o: ../../include/lber_types.h
sanity.o: ../../include/ldap_cdefs.h
sanity.o: ../../include/ldap_features.h
sanity.o: ../../include/ldap_log.h
sanity.o: ../../include/ldap_pvt_thread.h
sanity.o: ../../include/ldap_int_thread.h
sanity.o: /usr/include/pthread.h
sanity.o: /usr/include/sched.h
sanity.o: /usr/include/bits/sched.h
sanity.o: /usr/include/bits/setjmp.h
sanity.o: ../../include/ldap_defaults.h
sanity.o: globals.h
sanity.o: ../../include/ldap_config.h
sanity.o: ../../include/ldif.h
sanity.o: proto-slurp.h
st.o: st.c
st.o: /usr/include/stdc-predef.h
st.o: ../../include/portable.h
st.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h
st.o: ../../include/ac/fdset.h
st.o: /usr/include/bits/types.h
st.o: /usr/include/features.h
st.o: /usr/include/sys/cdefs.h
st.o: /usr/include/bits/wordsize.h
st.o: /usr/include/gnu/stubs.h
st.o: /usr/include/gnu/stubs-64.h
st.o: /usr/include/bits/typesizes.h
st.o: ../../include/ldap_cdefs.h
st.o: ../../include/ldap_features.h
st.o: ../../include/ac/assert.h
st.o: /usr/include/assert.h
st.o: ../../include/ac/localize.h
st.o: /usr/include/stdio.h
st.o: /usr/include/libio.h
st.o: /usr/include/_G_config.h
st.o: /usr/include/wchar.h
st.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stdarg.h
st.o: /usr/include/bits/stdio_lim.h
st.o: /usr/include/bits/sys_errlist.h
st.o: ../../include/ac/stdlib.h
st.o: /usr/include/stdlib.h
st.o: /usr/include/bits/waitflags.h
st.o: /usr/include/bits/waitstatus.h
st.o: /usr/include/endian.h
st.o: /usr/include/bits/endian.h
st.o: /usr/include/bits/byteswap.h
st.o: /usr/include/bits/byteswap-16.h
st.o: /usr/include/xlocale.h
st.o: /usr/include/sys/types.h
st.o: /usr/include/time.h
st.o: /usr/include/sys/select.h
st.o: /usr/include/bits/select.h
st.o: /usr/include/bits/sigset.h
st.o: /usr/include/bits/time.h
st.o: /usr/include/sys/sysmacros.h
st.o: /usr/include/bits/pthreadtypes.h
st.o: /usr/include/alloca.h
st.o: /usr/include/bits/stdlib-float.h
st.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/limits.h
st.o: /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/syslimits.h
st.o: /usr/include/limits.h
st.o: /usr/include/bits/posix1_lim.h
st.o: /usr/include/bits/local_lim.h
st.o: /usr/include/linux/limits.h
st.o: /usr/include/bits/posix2_lim.h
st.o: /usr/include/bits/xopen_lim.h
st.o: ../../include/ac/string.h
st.o: /usr/include/string.h
st.o: ../../include/ac/unistd.h
st.o: /usr/include/unistd.h
st.o: /usr/include/bits/posix_opt.h
st.o: /usr/include/bits/environments.h
st.o: /usr/include/bits/confname.h
st.o: /usr/include/getopt.h
st.o: ../../include/lutil_lockf.h
st.o: slurp.h
st.o: ../../include/ac/errno.h
st.o: /usr/include/errno.h
st.o: /usr/include/bits/errno.h
st.o: /usr/include/linux/errno.h
st.o: /usr/include/asm/errno.h
st.o: /usr/include/asm-generic/errno.h
st.o: /usr/include/asm-generic/errno-base.h
st.o: ../../include/ac/param.h
st.o: /usr/include/sys/param.h
st.o: /usr/include/signal.h
st.o: /usr/include/bits/signum.h
st.o: /usr/include/bits/siginfo.h
st.o: /usr/include/bits/sigaction.h
st.o: /usr/include/bits/sigcontext.h
st.o: /usr/include/bits/sigstack.h
st.o: /usr/include/sys/ucontext.h
st.o: /usr/include/bits/sigthread.h
st.o: /usr/include/bits/param.h
st.o: /usr/include/linux/param.h
st.o: /usr/include/asm/param.h
st.o: /usr/include/asm-generic/param.h
st.o: ../../include/ac/signal.h
st.o: ../../include/ac/syslog.h
st.o: /usr/include/syslog.h
st.o: /usr/include/sys/syslog.h
st.o: /usr/include/bits/syslog-path.h
st.o: ../../include/ac/time.h
st.o: /usr/include/sys/time.h
st.o: /usr/include/bits/timex.h
st.o: ../../include/ldap.h
st.o: ../../include/lber.h
st.o: ../../include/lber_types.h
st.o: ../../include/ldap_cdefs.h
st.o: ../../include/ldap_features.h
st.o: ../../include/ldap_log.h
st.o: ../../include/ldap_pvt_thread.h
st.o: ../../include/ldap_int_thread.h
st.o: /usr/include/pthread.h
st.o: /usr/include/sched.h
st.o: /usr/include/bits/sched.h
st.o: /usr/include/bits/setjmp.h
st.o: ../../include/ldap_defaults.h
st.o: globals.h
st.o: ../../include/ldap_config.h
st.o: ../../include/ldif.h
st.o: proto-slurp.h
st.o: ../../include/lutil.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
