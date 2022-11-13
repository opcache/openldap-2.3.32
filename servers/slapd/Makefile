# Generated automatically from srv.mk by configure.
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

## Makefile.in for slapd
# $OpenLDAP: pkg/ldap/servers/slapd/Makefile.in,v 1.124.2.16 2005/01/20 17:01:05 kurt Exp $
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

SLAPTOOLS=slapadd slapcat slapdn slapindex slappasswd slaptest
PROGRAMS=slapd $(SLAPTOOLS)
XPROGRAMS=sslapd libbackends.a .backend liboverlays.a
XSRCS=version.c

SUBDIRS=back-* shell-backends slapi overlays

NT_SRCS = nt_svc.c
NT_OBJS = nt_svc.o ../../libraries/liblutil/slapdmsg.res

SRCS	= main.c globals.c config.c daemon.c \
		connection.c search.c filter.c add.c cr.c \
		attr.c entry.c backend.c result.c operation.c \
		dn.c compare.c modify.c delete.c modrdn.c ch_malloc.c \
		value.c ava.c bind.c unbind.c abandon.c filterentry.c \
		phonetic.c acl.c str2filter.c aclparse.c init.c user.c \
		repl.c lock.c controls.c extended.c kerberos.c passwd.c \
		schema.c schema_check.c schema_init.c schema_prep.c \
		schemaparse.c ad.c at.c mr.c syntax.c oc.c saslauthz.c \
		oidm.c starttls.c index.c sets.c referral.c root_dse.c \
		sasl.c module.c mra.c mods.c sl_malloc.c limits.c \
		backglue.c operational.c matchedValues.c cancel.c syncrepl.c \
		backover.c ctxcsn.c ldapsync.c sessionlog.c \
		slapadd.c slapcat.c slapcommon.c slapdn.c slapindex.c \
		slappasswd.c slaptest.c \
		$(UNIX_SRCS)

OBJS	= main.o globals.o config.o daemon.o \
		connection.o search.o filter.o add.o cr.o \
		attr.o entry.o backend.o result.o operation.o \
		dn.o compare.o modify.o delete.o modrdn.o ch_malloc.o \
		value.o ava.o bind.o unbind.o abandon.o filterentry.o \
		phonetic.o acl.o str2filter.o aclparse.o init.o user.o \
		repl.o lock.o controls.o extended.o kerberos.o passwd.o \
		schema.o schema_check.o schema_init.o schema_prep.o \
		schemaparse.o ad.o at.o mr.o syntax.o oc.o saslauthz.o \
		oidm.o starttls.o index.o sets.o referral.o root_dse.o \
		sasl.o module.o mra.o mods.o sl_malloc.o limits.o \
		backglue.o operational.o matchedValues.o cancel.o syncrepl.o \
		backover.o ctxcsn.o ldapsync.o sessionlog.o \
		slapadd.o slapcat.o slapcommon.o slapdn.o slapindex.o \
		slappasswd.o slaptest.o \
		$(UNIX_OBJS)

LDAP_INCDIR= ../../include -I$(srcdir)/slapi
LDAP_LIBDIR= ../../libraries

SLAP_DIR=
SLAPD_STATIC_DEPENDS= libbackends.a
SLAPD_STATIC_BACKENDS= back-bdb back-monitor
SLAPD_DYNAMIC_BACKENDS=

SLAPI_LIBS= 

XDEFS = $(MODULES_CPPFLAGS)
XLDFLAGS = $(MODULES_LDFLAGS)

XLIBS = $(SLAPD_STATIC_DEPENDS) $(SLAPD_L) liboverlays.a
XXLIBS = $(SLAPD_LIBS) $(SECURITY_LIBS) $(LUTIL_LIBS)
XXXLIBS = $(LTHREAD_LIBS) $(SLAPI_LIBS) $(MODULES_LIBS)

BUILD_OPT = "--enable-slapd"
BUILD_SRV = yes

all-local-srv: all-cffiles

NT_SLAPD_DEPENDS = slapd.exp
NT_SLAPD_OBJECTS = slapd.exp symdummy.o $(OBJS) version.o

UNIX_SLAPD_DEPENDS = $(SLAPD_STATIC_DEPENDS) version.o $(SLAPD_L)
UNIX_SLAPD_OBJECTS = $(OBJS) version.o

SLAPD_DEPENDS = liboverlays.a $(UNIX_SLAPD_DEPENDS)
SLAPD_OBJECTS = $(UNIX_SLAPD_OBJECTS)

# Notes about slapd for Windows
# =============================
# slapd.exe must export all of its global symbols, just like a DLL.
# The purpose of this is to allow dynamic modules (dynamic backends
# or external dynamic modules) to bind with the symbols at run-time.
# 
# Exporting symbols from an .EXE is a bit tricky and involves multiple
# steps. First a .DEF file must be generated. The .DEF file indicates
# the set of symbols that are to be exported. Many times, it's possible
# to manually create this file with an editor. However, with slapd,
# we want to export EVERY global symbol that it knows about (NOT including
# symbols that are imported from other DLLs). The set of symbols to
# export INCLUDES symbols from all static libraries that slapd gets
# linked with, e.g. avl, ldbm, lunicode, lutil, etc. This list
# will also include liblber and libldap_r if they were built as static
# libraries. ALSO included will be symbols from other STATIC libraries
# outside the domain of the OpenLDAP source tree, e.g. regex, ltdl,
# crypto, ssl, sasl, etc. (If these libraries are dynamic, we won't want
# to include their symbols in the list). The correct set of symbols
# CAN be determined at build time. The slapd.def target automatically
# determines the correct set of symbols and generates the slapd.def file.
#
# The slapd.def file, serving multiple purposes, will:
#
# 1) be used to generate libslapd.a, the import library for slapd.exe.
#
# 2) be used to generate the symdummy.c file.
#
# 3) be used to help create slapd.exp, the binary-formated slapd export file.
#
# The import library is used by dynamic modules at link time. With this
# library, dynamic modules indicate to the linker that it will resolve
# these symbols from the slapd.exe binary at run-time. Of course, whenever
# a module imports dynamic symbols, those symbols should be marked with
# the __declspec(dllimport) directive in the header files that the dynamic
# modules build with. In OpenLDAP, this is handled automatically in the
# header files. (See ldap_cdefs.h for an explanation). Writers of
# dynamic backend modules should keep in mind that slapd.exe might export
# other global symbols that are not part of OpenLDAP (e.g. regex, ltdl,
# crypto, ssl, sasl, etc.) When a writer actually uses (i.e. imports) these
# symbols, he must verify that the header files from these external packages
# include a mechanism to mark imported symbols with the __declspec(dllimport)
# directive. Whether or not such a mechanism exists, the writer must be
# able to include these directives appropriately when their symbols are
# being imported from slapd.exe. The directive is not completely necessary
# for functions, but it is required for variables.
#
# The symdummy.c file basically references EVERY symbol available to slapd.exe,
# including symbols that slapd.exe never actually refereneced. The file
# is compiled and included at link time. Without this object file, slapd.exe
# would NOT export symbols that it never referenced. The reason that these
# symbols must still be exported is because a dynamic module may want to
# use a symbol even if it had not been referenced by slapd.exe.
#

#
# slapd.def REALLY depends upon all slapd objects and all static libraries
# included in $(LIBS), including static libraries outside of OpenLDAP.
# When slapd.def is built, the absolute paths to all static libraries
# (both inside and outside of OpenLDAP) are generated. We don't have
# any way to include this generated list as a dependency of slapd.def (sigh).
# Thus, we do the best we can by depending on version.o, which depends
# on its own very long list of dependencies.
#
slapd.def: libbackends.a liboverlays.a version.o
	@for i in $(LDFLAGS) ; do \
	    path=`expr "$$i" : "-L\(.*\)"`; \
	    if test $$? != 0; then continue; fi; \
	    paths="$$paths $$path"; \
	done; \
	objs=""; \
	for i in $(OBJS) version.o $(LIBS) ; do \
	    obj="" ; \
	    case $$i in \
		-l*) \
		    done="" ;\
		    base=`expr "$$i" : "-l\(.*\)"`; \
		    for p in $$paths ; do \
			for ext in la dll a ; do \
			    path=$$p/lib$$base.$$ext; \
			    test ! -f $$path && continue; \
			    if test $$ext = la ; then \
				for t in dlname old_library ; do \
				    line=`grep "^$$t=" $$path`; \
				    lib=`expr "$$line" : "[^']*'\(.*\)'"`; \
				    test -n "$$lib" && test -f $$p/$$lib && \
					path=$$p/$$lib && break; \
				done; \
				test $$t = dlname && ext=dll; \
				test $$t = old_library && ext=a; \
			    fi; \
			    if test $$ext = a ; then \
				obj=$$path; \
			    fi; \
			    done=done; \
			    break; \
			done; \
			test -n "$$done" && break; \
		    done; \
		    test -z "$$obj" && continue; \
		    ;; \
		*.o | *.a) \
		    obj=$$i; \
	    esac; \
	    objs="$$objs $$obj"; \
	done; \
	echo dlltool --exclude-symbols main,ServiceMain@8 --export-all-symbols \
			--output-def $@.tmp $$objs; \
	dlltool --exclude-symbols main,ServiceMain@8 --export-all-symbols \
			--output-def $@.tmp $$objs;
	echo EXPORTS > $@
	$(SED) -e 1,2d -e 's/ @ [0-9][0-9]*//' $@.tmp | sort >> $@
	$(RM) $@.tmp

symdummy.c: slapd.def
	$(RM) $@
	@echo "generating $@..."; \
	echo "static void never_called() {" > $@.tmp; \
	cat $< | while read line; \
	do \
	    set dummy $$line; \
	    case $$# in \
		3) \
		    echo "int $$2();" >> $@; \
		    echo "$$2();" >> $@.tmp; \
		    ;; \
		4) \
		    echo "extern int $$2;" >> $@; \
		    echo "$$2 = 0;" >> $@.tmp; \
		    ;; \
	    esac; \
	done; \
	echo "" >> $@; \
	echo "}" >> $@.tmp; \
	cat $@.tmp >> $@; \
	$(RM) $@.tmp

libslapd.a: symdummy.o
	dlltool --dllname slapd.exe --input-def slapd.def --output-lib $@

slapd.exp: libslapd.a
	@echo $(LTLINK) -Wl,--base-file,slapd.base -o slapd \
		$(OBJS) symdummy.o version.o $(LIBS) $(WRAP_LIBS); \
	$(LTLINK) -Wl,--base-file,slapd.base -o slapd \
		$(OBJS) symdummy.o version.o $(LIBS) $(WRAP_LIBS)
	$(RM) slapd.exe
	@echo dlltool --dllname slapd.exe --input-def slapd.def \
		--base-file slapd.base --output-exp $@; \
	dlltool --dllname slapd.exe --input-def slapd.def \
		--base-file slapd.base --output-exp $@; \
	echo $(LTLINK) -Wl,--base-file,slapd.base -o slapd $@ \
		$(OBJS) symdummy.o version.o $(LIBS) $(WRAP_LIBS); \
	$(LTLINK) -Wl,--base-file,slapd.base -o slapd $@ \
		$(OBJS) symdummy.o version.o $(LIBS) $(WRAP_LIBS)
	$(RM) slapd.exe
	@echo dlltool --dllname slapd.exe --input-def slapd.def \
		--base-file slapd.base --output-exp $@; \
	dlltool --dllname slapd.exe --input-def slapd.def \
		--base-file slapd.base --output-exp $@

slapi/.libs/libslapi.a: FORCE
	(cd slapi; $(MAKE) $(MFLAGS) all)

libslapi.a: slapi/.libs/libslapi.a
	cp slapi/.libs/libslapi.a .

slapd: $(SLAPD_DEPENDS) 
	$(LTLINK) -o $@ $(SLAPD_OBJECTS) $(LIBS) \
		$(WRAP_LIBS)
	rm -f $(SLAPTOOLS)
	for i in $(SLAPTOOLS); do \
		$(LN_S) slapd$(EXEEXT) $$i$(EXEEXT); done


sslapd: version.o
	$(LTLINK) -static -o $@ $(OBJS) version.o $(LIBS) $(WRAP_LIBS)

dummy $(SLAPD_DYNAMIC_BACKENDS): slapd
	cd $@; $(MAKE) $(MFLAGS) all
	@touch $@

#
# In Windows, dynamic backends have to be built after slapd. For this
# reason, we only build static backends now and dynamic backends later.
#
.backend: FORCE
	@if test -n "$(SLAPD_STATIC_BACKENDS)"; then \
	    echo "building static backends..."; \
	    for i in XX $(SLAPD_STATIC_BACKENDS); do \
	    	if test $$i != XX; then \
		    echo " "; echo "  cd $$i; $(MAKE) $(MFLAGS) all"; \
		    ( cd $$i; $(MAKE) $(MFLAGS) all ); \
		    if test $$? != 0; then exit 1; fi; \
		fi; \
	    done; \
	    echo " "; \
	fi

libbackends.a: .backend
	@$(RM) -r tmp
	@$(MKDIR) tmp
	@-for i in back-*/*.a; do \
		( \
		  cd tmp; \
		  $(AR) x ../$$i; \
		  pre=`echo $$i | $(SED) -e 's/\/.*$$//' -e 's/back-//'`; \
		  for j in *.o; do \
			mv $$j $${pre}$$j; \
		  done; \
		  $(AR) ruv libbackends.a *.o 2>&1 | grep -v truncated; \
		  $(RM) *.o __.SYMDEF  ________64ELEL_ ; \
		  echo "added backend library $$i"; \
		  echo ""; \
		); \
	done
	@mv -f tmp/libbackends.a ./libbackends.a
	@$(RM) -r tmp
	@if test ! -z "$(RANLIB)" ; then \
		$(RANLIB) libbackends.a; \
	fi
	@ls -l libbackends.a; echo ""

liboverlays.a: FORCE
	@cd overlays; $(MAKE) $(MFLAGS) all

version.c: Makefile
	@-$(RM) $@
	$(MKVERSION) -s -n Versionstr slapd > $@

version.o: version.c $(OBJS) $(SLAPD_LIBDEPEND) 

depend-local-srv: FORCE
	@for i in $(SUBDIRS); do \
		if test -d $$i -a -f $$i/Makefile ; then \
			echo; echo "  cd $$i; $(MAKE) $(MFLAGS) depend"; \
			( cd $$i; $(MAKE) $(MFLAGS) depend ); \
			if test $$? != 0 ; then exit 1; fi ; \
		fi; \
	done
	@echo ""

clean-local:
	rm -f *.exp *.def *.base *.a *.objs symdummy.c

clean-local-srv: FORCE
	@for i in $(SUBDIRS); do \
		if test -d $$i -a -f $$i/Makefile ; then \
			echo; echo "  cd $$i; $(MAKE) $(MFLAGS) clean"; \
			( cd $$i; $(MAKE) $(MFLAGS) clean ); \
			if test $$? != 0 ; then exit 1; fi ; \
		fi; \
	done
	rm -f *.tmp all-cffiles

veryclean-local-srv: FORCE
	@for i in $(SUBDIRS); do \
		if test -d $$i -a -f $$i/Makefile ; then \
			echo; echo "  cd $$i; $(MAKE) $(MFLAGS) clean"; \
			( cd $$i; $(MAKE) $(MFLAGS) veryclean ); \
		fi; \
	done

install-local-srv: install-slapd install-conf install-schema install-tools

install-slapd: FORCE
	-$(MKDIR) $(DESTDIR)$(libexecdir)
	-$(MKDIR) $(DESTDIR)$(localstatedir)/run
	$(LTINSTALL) $(INSTALLFLAGS) -s -m 755 \
		slapd$(EXEEXT) $(DESTDIR)$(libexecdir)
	@for i in $(SUBDIRS); do \
	    if test -d $$i -a -f $$i/Makefile ; then \
		echo; echo "  cd $$i; $(MAKE) $(MFLAGS) install"; \
		( cd $$i; $(MAKE) $(MFLAGS) install ); \
		if test $$? != 0 ; then exit 1; fi ; \
	    fi; \
	done

all-cffiles: slapd $(SLAPD_DYNAMIC_BACKENDS)
	@if test $(PLAT) = NT; then \
	    sysconfdir=`cygpath -w $(sysconfdir) | \
		$(SED) -e 's/\\\\/\\\\\\\\\\\\\\\\/g'`; \
	    localstatedir=`cygpath -w $(localstatedir) | \
		$(SED) -e 's/\\\\/\\\\\\\\\\\\\\\\/g'`; \
	    moduledir=`cygpath -w $(moduledir) | \
		$(SED) -e 's/\\\\/\\\\\\\\\\\\\\\\/g'`; \
	else \
	    sysconfdir=$(sysconfdir); \
	    localstatedir=$(localstatedir); \
	    moduledir=$(moduledir); \
	fi; \
	$(SED) -e "s;%SYSCONFDIR%;$$sysconfdir;" \
		-e "s;%LOCALSTATEDIR%;$$localstatedir;" \
		-e "s;%MODULEDIR%;$$moduledir;" \
		$(srcdir)/slapd.conf > slapd.conf.tmp ; \
	touch all-cffiles

install-schema: FORCE
	@-$(MKDIR) $(DESTDIR)$(schemadir)
	i="$(srcdir)/schema/README" ; \
	SF=`basename $$i` ; \
	SD="$(DESTDIR)$(schemadir)/$$SF" ; \
	echo $(INSTALL) $(INSTALLFLAGS) -m 444 $$i $$SD ; \
	$(INSTALL) $(INSTALLFLAGS) -m 444 $$i $$SD
	for i in $(srcdir)/schema/*.schema ; do \
		SF=`basename $$i` ; \
		SD="$(DESTDIR)$(schemadir)/$$SF" ; \
		if test ! -f $$SD ; then \
			echo "installing $$SF in $(schemadir)" ; \
			echo $(INSTALL) $(INSTALLFLAGS) -m 444 $$i $$SD ; \
			$(INSTALL) $(INSTALLFLAGS) -m 444 $$i $$SD ; \
		else \
			echo "PRESERVING EXISTING SCHEMA FILE $$SD" ; \
		fi ; \
		$(INSTALL) $(INSTALLFLAGS) -m 444 $$i $$SD.default ; \
	done

install-conf: FORCE
	@-$(MKDIR) $(DESTDIR)$(sysconfdir)
	@-$(INSTALL) -m 700 -d $(DESTDIR)$(localstatedir)/openldap-data
	$(INSTALL) $(INSTALLFLAGS) -m 600 slapd.conf.tmp $(DESTDIR)$(sysconfdir)/slapd.conf.default
	if test ! -f $(DESTDIR)$(sysconfdir)/slapd.conf; then \
		echo "installing slapd.conf in $(sysconfdir)"; \
		echo "$(INSTALL) $(INSTALLFLAGS) -m 600 slapd.conf.tmp $(DESTDIR)$(sysconfdir)/slapd.conf"; \
		$(INSTALL) $(INSTALLFLAGS) -m 600 slapd.conf.tmp $(DESTDIR)$(sysconfdir)/slapd.conf; \
	else \
		echo "PRESERVING EXISTING CONFIGURATION FILE $(DESTDIR)$(sysconfdir)/slapd.conf" ; \
	fi

install-tools: FORCE
	-$(MKDIR) $(DESTDIR)$(sbindir)
	cd $(DESTDIR)$(sbindir); \
	rm -f $(SLAPTOOLS); \
	for i in $(SLAPTOOLS); do \
		$(LN_S) $(libexecdir)/slapd$(EXEEXT) $$i$(EXEEXT); \
	done

# $OpenLDAP: pkg/ldap/build/srv.mk,v 1.13.2.3 2005/01/20 17:00:55 kurt Exp $
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
# files: -I../../include -I./slapi -I../../include -I/usr/local/berkeleydb/include -D_GNU_SOURCE main.c globals.c config.c daemon.c connection.c search.c filter.c add.c cr.c attr.c entry.c backend.c result.c operation.c dn.c compare.c modify.c delete.c modrdn.c ch_malloc.c value.c ava.c bind.c unbind.c abandon.c filterentry.c phonetic.c acl.c str2filter.c aclparse.c init.c user.c repl.c lock.c controls.c extended.c kerberos.c passwd.c schema.c schema_check.c schema_init.c schema_prep.c schemaparse.c ad.c at.c mr.c syntax.c oc.c saslauthz.c oidm.c starttls.c index.c sets.c referral.c root_dse.c sasl.c module.c mra.c mods.c sl_malloc.c limits.c backglue.c operational.c matchedValues.c cancel.c syncrepl.c backover.c ctxcsn.c ldapsync.c sessionlog.c slapadd.c slapcat.c slapcommon.c slapdn.c slapindex.c slappasswd.c slaptest.c
# command: cc -M -I.  -I../../include -I./slapi -I../../include -I/usr/local/berkeleydb/include -D_GNU_SOURCE main.c globals.c config.c daemon.c connection.c search.c filter.c add.c cr.c attr.c entry.c backend.c result.c operation.c dn.c compare.c modify.c delete.c modrdn.c ch_malloc.c value.c ava.c bind.c unbind.c abandon.c filterentry.c phonetic.c acl.c str2filter.c aclparse.c init.c user.c repl.c lock.c controls.c extended.c kerberos.c passwd.c schema.c schema_check.c schema_init.c schema_prep.c schemaparse.c ad.c at.c mr.c syntax.c oc.c saslauthz.c oidm.c starttls.c index.c sets.c referral.c root_dse.c sasl.c module.c mra.c mods.c sl_malloc.c limits.c backglue.c operational.c matchedValues.c cancel.c syncrepl.c backover.c ctxcsn.c ldapsync.c sessionlog.c slapadd.c slapcat.c slapcommon.c slapdn.c slapindex.c slappasswd.c slaptest.c
#

kerberos.o: kerberos.c
kerberos.o: ../../include/portable.h
kerberos.o: /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/stddef.h
kerberos.o: ../../include/ac/fdset.h
kerberos.o: ../../include/ldap_cdefs.h
kerberos.o: ../../include/ldap_features.h
kerberos.o: ../../include/ac/assert.h
kerberos.o: /usr/include/assert.h
kerberos.o: /usr/include/features.h
kerberos.o: /usr/include/sys/cdefs.h
kerberos.o: /usr/include/bits/wordsize.h
kerberos.o: /usr/include/gnu/stubs.h
kerberos.o: /usr/include/gnu/stubs-64.h
kerberos.o: ../../include/ac/localize.h
slappasswd.o: slappasswd.c
slappasswd.o: ../../include/portable.h
slappasswd.o: /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/stddef.h
slappasswd.o: ../../include/ac/fdset.h
slappasswd.o: ../../include/ldap_cdefs.h
slappasswd.o: ../../include/ldap_features.h
slappasswd.o: ../../include/ac/assert.h
slappasswd.o: /usr/include/assert.h
slappasswd.o: /usr/include/features.h
slappasswd.o: /usr/include/sys/cdefs.h
slappasswd.o: /usr/include/bits/wordsize.h
slappasswd.o: /usr/include/gnu/stubs.h
slappasswd.o: /usr/include/gnu/stubs-64.h
slappasswd.o: ../../include/ac/localize.h
slappasswd.o: /usr/include/stdio.h
slappasswd.o: /usr/include/bits/types.h
slappasswd.o: /usr/include/bits/typesizes.h
slappasswd.o: /usr/include/libio.h
slappasswd.o: /usr/include/_G_config.h
slappasswd.o: /usr/include/wchar.h
slappasswd.o: /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/stdarg.h
slappasswd.o: /usr/include/bits/stdio_lim.h
slappasswd.o: /usr/include/bits/sys_errlist.h
slappasswd.o: ../../include/ac/stdlib.h
slappasswd.o: /usr/include/stdlib.h
slappasswd.o: /usr/include/bits/waitflags.h
slappasswd.o: /usr/include/bits/waitstatus.h
slappasswd.o: /usr/include/endian.h
slappasswd.o: /usr/include/bits/endian.h
slappasswd.o: /usr/include/bits/byteswap.h
slappasswd.o: /usr/include/xlocale.h
slappasswd.o: /usr/include/sys/types.h
slappasswd.o: /usr/include/time.h
slappasswd.o: /usr/include/sys/select.h
slappasswd.o: /usr/include/bits/select.h
slappasswd.o: /usr/include/bits/sigset.h
slappasswd.o: /usr/include/bits/time.h
slappasswd.o: /usr/include/sys/sysmacros.h
slappasswd.o: /usr/include/bits/pthreadtypes.h
slappasswd.o: /usr/include/alloca.h
slappasswd.o: ../../include/ac/ctype.h
slappasswd.o: /usr/include/ctype.h
slappasswd.o: ../../include/ac/signal.h
slappasswd.o: /usr/include/signal.h
slappasswd.o: /usr/include/bits/signum.h
slappasswd.o: /usr/include/bits/siginfo.h
slappasswd.o: /usr/include/bits/sigaction.h
slappasswd.o: /usr/include/bits/sigcontext.h
slappasswd.o: /usr/include/bits/sigstack.h
slappasswd.o: /usr/include/sys/ucontext.h
slappasswd.o: /usr/include/bits/sigthread.h
slappasswd.o: ../../include/ac/socket.h
slappasswd.o: /usr/include/sys/socket.h
slappasswd.o: /usr/include/sys/uio.h
slappasswd.o: /usr/include/bits/uio.h
slappasswd.o: /usr/include/bits/socket.h
slappasswd.o: /usr/include/bits/sockaddr.h
slappasswd.o: /usr/include/asm/socket.h
slappasswd.o: /usr/include/asm-generic/socket.h
slappasswd.o: /usr/include/asm/sockios.h
slappasswd.o: /usr/include/asm-generic/sockios.h
slappasswd.o: /usr/include/sys/un.h
slappasswd.o: /usr/include/string.h
slappasswd.o: /usr/include/netinet/in.h
slappasswd.o: /usr/include/stdint.h
slappasswd.o: /usr/include/bits/wchar.h
slappasswd.o: /usr/include/bits/in.h
slappasswd.o: /usr/include/netinet/tcp.h
slappasswd.o: /usr/include/arpa/inet.h
slappasswd.o: /usr/include/arpa/nameser.h
slappasswd.o: /usr/include/sys/param.h
slappasswd.o: /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/limits.h
slappasswd.o: /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/syslimits.h
slappasswd.o: /usr/include/limits.h
slappasswd.o: /usr/include/bits/posix1_lim.h
slappasswd.o: /usr/include/bits/local_lim.h
slappasswd.o: /usr/include/linux/limits.h
slappasswd.o: /usr/include/bits/posix2_lim.h
slappasswd.o: /usr/include/bits/xopen_lim.h
slappasswd.o: /usr/include/linux/param.h
slappasswd.o: /usr/include/asm/param.h
slappasswd.o: /usr/include/asm-generic/param.h
slappasswd.o: /usr/include/sys/bitypes.h
slappasswd.o: /usr/include/arpa/nameser_compat.h
slappasswd.o: /usr/include/netdb.h
slappasswd.o: /usr/include/rpc/netdb.h
slappasswd.o: /usr/include/bits/netdb.h
slappasswd.o: /usr/include/resolv.h
slappasswd.o: ../../include/ac/string.h
slappasswd.o: ../../include/ac/time.h
slappasswd.o: /usr/include/sys/time.h
slappasswd.o: ../../include/ac/unistd.h
slappasswd.o: /usr/include/unistd.h
slappasswd.o: /usr/include/bits/posix_opt.h
slappasswd.o: /usr/include/bits/environments.h
slappasswd.o: /usr/include/bits/confname.h
slappasswd.o: /usr/include/getopt.h
slappasswd.o: ../../include/lutil_lockf.h
slappasswd.o: ../../include/ldap.h
slappasswd.o: ../../include/lber.h
slappasswd.o: ../../include/lber_types.h
slappasswd.o: ../../include/ldap_cdefs.h
slappasswd.o: ../../include/ldap_features.h
slappasswd.o: ../../include/lutil.h
slappasswd.o: ../../include/ldap_defaults.h
slappasswd.o: ../../include/ldap_config.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
