# $OpenBSD$

COMMENT=	extensible open standard audio/video container library

DISTNAME=	libmatroska-1.3.0
CATEGORIES=	multimedia
MASTER_SITES=	http://dl.matroska.org/downloads/libmatroska/
EXTRACT_SUFX=	.tar.bz2

SHARED_LIBS=	matroska	3.0

HOMEPAGE=	http://www.matroska.org/

MAINTAINER=	Brad Smith <brad@comstyle.com>

# LGPLv2.1+
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes

WANTLIB=	ebml>=2.1 m stdc++

LIB_DEPENDS=	textproc/libebml>=1.2.2

MAKE_ENV+=	LIBmatroska_VERSION=${LIBmatroska_VERSION}
MAKE_FLAGS+=	CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" LOCALBASE=${LOCALBASE}
FAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}

USE_GMAKE=	Yes

REGRESS_TARGET=	test

WRKSRC=		${WRKDIST}/make/linux

post-extract:
	@perl -pi -e 's/\r\n/\n/;' ${WRKSRC}/Makefile
	@piconv -t utf-8 ${WRKDIST}/test/mux/test6.cpp \
		>${WRKDIST}/test/mux/test6.cpp.tmp \
		&& mv ${WRKDIST}/test/mux/test6.cpp.tmp \
		${WRKDIST}/test/mux/test6.cpp

.include <bsd.port.mk>
