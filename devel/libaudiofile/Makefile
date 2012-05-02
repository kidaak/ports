# $OpenBSD: ports/devel/libaudiofile/Makefile,v 1.40 2012/03/29 13:38:30 sthen Exp $

COMMENT=	SGI audiofile library clone

V=		0.3.3
SUBST_VARS=	V
DISTNAME=	audiofile-${V}
PKGNAME=	lib${DISTNAME}
SHARED_LIBS +=	audiofile 1.0
CATEGORIES=	devel audio
MASTER_SITES=	${HOMEPAGE}

HOMEPAGE=	http://www.68k.org/~michael/audiofile/

# GPLv2/LGPLv2
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB += c m stdc++

USE_LIBTOOL=	Yes

SEPARATE_BUILD=	Yes

CONFIGURE_STYLE= gnu
CONFIGURE_ENV=	ac_cv_path_ASCIIDOC=no
CONFIGURE_ARGS=	${CONFIGURE_SHARED}

# audiofile-config is still needed by audio/normalize and devel/libspectrum
post-install:
	${SUBST_CMD} -o ${BINOWN} -g ${BINGRP} -c ${FILESDIR}/audiofile-config \
		${PREFIX}/bin/audiofile-config
	chmod ${BINMODE} ${PREFIX}/bin/audiofile-config

.include <bsd.port.mk>