# $OpenBSD$

COMMENT =		GMP bindings for OCaml

V =			0.13
REVISION =		0
DISTNAME =		mlgmp-${V}
PKGNAME =		ocaml-mlgmp-${V}

CATEGORIES =		devel math
HOMEPAGE =		http://caml.inria.fr/cgi-bin/hump.en.cgi?contrib=278
MAINTAINER =		Edd Barrett <edd@openbsd.org>

# GPLv2
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

MASTER_SITES =		http://theunixzoo.co.uk/files/

MODULES =		lang/ocaml
BUILD_DEPENDS =		devel/gmp devel/mpfr
RUN_DEPENDS =		${BUILD_DEPENDS}

USE_GMAKE =		Yes

# overide their site specific include/lib paths
MAKE_FLAGS += GMP_LIBDIR=${LOCALBASE}/lib
MAKE_FLAGS += GMP_INCLUDES=-I${LOCALBASE}/include
MAKE_FLAGS += CFLAGS_MISC="${CFLAGS}"

# build does not support just bytecode, but we can
# deal with this my calling certain make targets
LIBS_NATIVE =	gmp.a gmp.cmxa
LIBS_OTHER =	libmlgmp.a gmp.cma gmp.cmi

.include <bsd.port.arch.mk>
.if ${PROPERTIES:Mocaml_native}
MAKE_FLAGS +=	LIBS="${LIBS_OTHER} ${LIBS_NATIVE}"
MAKE_FLAGS +=	TESTS="test_suite test_suite.opt"
MAKE_FLAGS +=	TESTS_RUN="tests-nonative tests-native"
.else
MAKE_FLAGS +=	LIBS="${LIBS_OTHER}"
MAKE_FLAGS +=	TESTS="test_suite"
MAKE_FLAGS +=	TESTS_RUN="tests-nonative"
.endif

REGRESS_TARGET =	tests

# make dependencies are screwed up in the release tarball
pre-build:
	cd ${WRKBUILD} && ${MAKE_PROGRAM} clean

post-install:
	${SUBST_CMD} -o ${BINOWN} -g ${BINGRP} -c \
		${FILESDIR}/META ${PREFIX}/lib/ocaml/gmp/META

.include <bsd.port.mk>
