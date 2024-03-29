# $OpenBSD$

COMMENT=	block-sorting file compressor, unencumbered

VERSION=	1.0.6
DISTNAME=	bzip2-${VERSION}
CATEGORIES=	archivers
MASTER_SITES=	${HOMEPAGE}${VERSION}/
SHARED_LIBS=	bz2	10.4

HOMEPAGE=	http://www.bzip.org/

# BSD
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes
WANTLIB=	c

BZ2_CFLAGS=	-Wall -Winline
.if ${MACHINE_ARCH} != "m68k"
BZ2_CFLAGS+=	-fomit-frame-pointer -fno-strength-reduce
.endif

MAKE_FLAGS=	CC="${CC}" CFLAGS="${CFLAGS} ${BZ2_CFLAGS}" \
		LIBbz2_VERSION=${LIBbz2_VERSION} PREFIX=${TRUEPREFIX}
REGRESS_FLAGS=	LD_LIBRARY_PATH="${WRKBUILD}" LIBbz2_VERSION=${LIBbz2_VERSION}

REGRESS_TARGET=	test

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/bzip2
	${INSTALL_DATA} ${WRKBUILD}/manual.html ${PREFIX}/share/doc/bzip2

.include <bsd.port.mk>

.if defined(NO_SHARED_LIBS) && ${NO_SHARED_LIBS:L} == "yes"
MAKE_ENV+=	NO_SHARED_LIBS=Yes
.endif
