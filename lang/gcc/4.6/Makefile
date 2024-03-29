# $OpenBSD$

ONLY_FOR_ARCHS = amd64 i386 powerpc sparc sparc64
DPB_PROPERTIES = parallel

V = 4.6.3
FULL_VERSION = $V
FULL_PKGVERSION = $V
BOOTSTRAP_GEN = 0
LIBC_VERSION = 63.0
ADASTRAP = adastrap-i386-$V-${BOOTSTRAP_GEN}.tar.xz

PKGNAME-main =  gcc-${FULL_PKGVERSION}
PKGNAME-c++ =   g++-${FULL_PKGVERSION}
PKGNAME-estdc = libstdc++-${FULL_PKGVERSION}
PKGNAME-f95 =   g95-${FULL_PKGVERSION}
PKGNAME-java =  gcj-${FULL_PKGVERSION}
PKGNAME-objc =  gobjc-${FULL_PKGVERSION}
PKGNAME-ada =   gnat-${FULL_PKGVERSION}
PKGNAME-go =	gccgo-${FULL_PKGVERSION}
PKGSPEC-main = gcc->=4.6,<4.7

REVISION-main = 11
REVISION-c++ = 11
REVISION-estdc = 9
REVISION-f95 = 11
REVISION-java = 11
REVISION-objc = 11
REVISION-ada = 11
REVISION-go = 11

SHARED_LIBS =	estdc++		14.0 \
		gfortran	3.0 \
		gcj		1.0 \
		gcj-tools	1.0 \
		gij		1.0 \
		objc		3.0 \
		ssp		1.0 \
		lto_plugin      0.0 \
		go		0.0


PSEUDO_FLAVORS = no_c++ no_f95 no_objc no_java no_ada no_go full
FLAVOR ?= 

ONLY_FOR_ARCHS-ada = i386
ONLY_FOR_ARCHS-java = amd64 i386 sparc64

MULTI_PACKAGES = -main -f95 -objc -java -c++ -estdc -ada -go

.include <bsd.port.arch.mk>

# kill both C++ subpackages
.if !${BUILD_PACKAGES:M-c++}
BUILD_PACKAGES := ${BUILD_PACKAGES:N-estdc}
.endif

DISTNAME =   	gcc-${FULL_VERSION}
DISTFILES =	${DISTNAME}.tar.bz2
# there's no ecj-4.6.jar
ECJ =		ecj-4.5.jar
SUPDISTFILES =	${ADASTRAP}:0 ${ECJ}:1
EXTRACT_ONLY =	${DISTNAME}.tar.bz2

USE_LIBTOOL =	Yes

BUILD_DEPENDS +=	devel/bison \
			devel/libexecinfo

REGRESS_DEPENDS = 	devel/dejagnu \
			devel/autogen

MASTER_SITES =	${MASTER_SITE_GCC:=releases/gcc-$(FULL_VERSION)/}
MASTER_SITES0 =	http://distfiles.tmux.org/adastrap/
MASTER_SITES1 =	ftp://sources.redhat.com/pub/java/

LANGS = c
.if ${BUILD_PACKAGES:M-c++}
LANGS := ${LANGS},c++
REGRESS_DEPENDS += 	${BUILD_PKGPATH},-estdc>=4.6,<4.7
.endif
.if ${BUILD_PACKAGES:M-f95}
LANGS := ${LANGS},fortran
.endif
.if ${BUILD_PACKAGES:M-objc}
LANGS := ${LANGS},objc
.endif
.if ${BUILD_PACKAGES:M-java}
LANGS := ${LANGS},java
DISTFILES +=		${ECJ}:1
BUILD_DEPENDS +=	archivers/zip>=2.3p0
CONFIGURE_ARGS +=	--enable-libgcj --without-jar
VMEM_WARNING =		Yes
.endif
.if ${BUILD_PACKAGES:M-ada}
LANGS := ${LANGS},ada
DISTFILES += ${ADASTRAP}:0
EXTRACT_ONLY += ${ADASTRAP}
EXTRA_ENV += ADAC=${WRKDIR}/bin/egcc GNATBIND=${WRKDIR}/bin/gnatbind
CC = ${WRKDIR}/bin/egcc
REGRESS_DEPENDS += ${BUILD_PKGPATH},-ada
.endif
.if ${BUILD_PACKAGES:M-go}
LANGS := ${LANGS},go
.endif

CONFIGURE_STYLE =		gnu
MODGNU_CONFIG_GUESS_DIRS =	${WRKSRC} ${WRKSRC}/gcc

EXTRA_ENV += am_cv_func_iconv=no JAR=no
EXTRA_ENV += ac_cv_prog_M4=/usr/bin/m4
EXTRA_ENV += ac_cv_header_magic_h=no
MAKE_FLAGS +=	 ac_cv_path_mkdir=/bin/mkdir

CONFIGURE_ENV += ${EXTRA_ENV}
MAKE_ENV += ${EXTRA_ENV}

# Note: the configure target passes CFLAGS to the configure script anyways.

CFLAGS = -O2 -g

CONFIGURE_ARGS += \
	--verbose \
	--program-transform-name=s,^,e, \
	--disable-nls  \
	--disable-checking \
	--with-system-zlib \
	--disable-libmudflap \
	--disable-libgomp \
	--disable-tls \
	--with-as=/usr/bin/as \
	--with-ld=/usr/bin/ld \
	--with-gnu-ld \
	--with-gnu-as \
	--enable-threads=posix \
	--enable-wchar_t \
	--with-gmp="${LOCALBASE}" \
	--disable-libstdcxx-pch \
	--enable-languages=${LANGS}

# This is needed, as internal cpp is no longer compatible with the
# visible beast
CONFIGURE_ARGS += --enable-cpp

CONFIGURE_ARGS += ${CONFIGURE_SHARED}

SEPARATE_BUILD = flavored

USE_GMAKE = yes

.if ${FLAVOR:Mfull}
# you shouldn't skip bootstrap unless you know what you're doing
# use bootstrap-lean if you're pressed for space
ALL_TARGET = bootstrap
.else
# skip the stage2/stage3 bullshit under normal circumstances
ALL_TARGET = bootstrap2
.endif

MAKE_FLAGS += libstdc___la_LDFLAGS='-version-info 31:0:0 -lm'

.if ${MACHINE_ARCH} == "sparc"  || ${MACHINE_ARCH} == "amd64"
PIC = 1
PKG_ARGS += -DPIC=1
.else
PIC = 0
PKG_ARGS += -DPIC=0
.endif

.if ${MACHINE_ARCH} == "powerpc"
PKG_ARGS += -DPPC=1
.else
PKG_ARGS += -DPPC=0
.endif

.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "amd64"
PKG_ARGS += -DI386=1
.else
PKG_ARGS += -DI386=0
.endif

RUN_DEPENDS =		${BUILD_PKGPATH},-main
WANTLIB =		c gmp m mpc mpfr z

RUN_DEPENDS-main =
RUN_DEPENDS-estdc =

RUN_DEPENDS-c++ =	${RUN_DEPENDS} \
			${BUILD_PKGPATH},-estdc>=4.6,<4.7
WANTLIB-estdc =		m
WANTLIB-f95 =		${WANTLIB}
WANTLIB-java =		${WANTLIB} pthread
WANTLIB-go =		${WANTLIB} pthread

LIB_DEPENDS +=		devel/gmp>=4.2 \
			devel/mpfr \
			devel/libmpc
LIB_DEPENDS-estdc =

.if ${MACHINE_ARCH:Mamd64}
CONFIG = x86_64-unknown-openbsd${OSREV}
.endif

post-extract:
.for f in egcc gnatbind gnatmake gnatlink
	echo "#! /bin/sh" >${WRKDIR}/bin/$f
	echo 'GNAT_ROOT=${WRKDIR}/bootstrap GCC_ROOT=${WRKDIR}/bootstrap LD_LIBRARY_PATH=${WRKDIR}/bootstrap/system-libs exec ${WRKDIR}/bootstrap/bin/$f "$$@"' >>${WRKDIR}/bin/$f
	chmod a+x ${WRKDIR}/bin/$f
.endfor
	ln -sf /usr/bin/nm ${WRKDIR}/bin/enm
	echo "# This file automatically generated" >> ${WRKSRC}/libversions
.for l v in ${SHARED_LIBS}
	echo "LIB$l_LTVERSION = -version-info ${v:S/./:/}" >> \
		${WRKSRC}/libversions
.endfor
.if ${BUILD_PACKAGES:M-ada}
	# XXX cheat a bit
	cd ${WRKDIR}/bootstrap/system-libs && ln -sf libc.so.${LIBC_VERSION} libc.so.61.0
	${WRKDIR}/bin/egcc -v # if this fails, you must extract suitable libraries from the relevant OpenBSD release or use the no_ada FLAVOR.
.endif
.if ${BUILD_PACKAGES:M-java}
	cp ${FULLDISTDIR}/${ECJ} ${WRKSRC}/ecj.jar
.endif

post-install:
.if ${BUILD_PACKAGES:M-ada}
	chown -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/gcc/*/$V/adainclude
	chown -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/gcc/*/$V/adalib
.endif
	chown -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/gcc/*/$V/include
	chown -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/gcc/*/$V/include-fixed
	chown ${BINOWN}:${BINGRP} ${PREFIX}/lib/gcc/${CONFIG}/${V}/libgcc.a
	chown ${BINOWN}:${BINGRP} ${PREFIX}/lib/gcc/${CONFIG}/${V}/libgcov.a
.if ${PIC} == "1"
	chown ${BINOWN}:${BINGRP} ${PREFIX}/lib/gcc/${CONFIG}/${V}/fpic/libgcc.a
	chown ${BINOWN}:${BINGRP} \
		${PREFIX}/lib/gcc/${CONFIG}/${V}/fpic/libgcov.a
.endif

.include <bsd.port.mk>

ADA_PACKAGE = ${PACKAGE_REPOSITORY}/i386/all/${PKGNAME-ada}.tgz
GCC_PACKAGE = ${PACKAGE_REPOSITORY}/i386/all/${PKGNAME-main}.tgz

adastrap: ${ADA_PACKAGE} ${GCC_PACKAGE}
.if !defined(LIBC_VERSION)
	@echo 1>&2 "Error: you must specify a libc to bundle"
	@exit 1
.else
	mkdir -p ${WRKDIR}/prepare/bootstrap/system-libs
	cp /usr/lib/libc.so.${LIBC_VERSION} ${WRKDIR}/prepare/bootstrap/system-libs
	cd ${WRKDIR}/prepare/bootstrap && tar zxf ${ADA_PACKAGE}
	cd ${WRKDIR}/prepare/bootstrap && tar zxf ${GCC_PACKAGE}
	rm -rf ${WRKDIR}/prepare/bootstrap/{+*,info,man}
	cd ${WRKDIR}/prepare && tar cf - bootstrap | \
		xz > ${FULLDISTDIR}/${ADASTRAP}
.endif

