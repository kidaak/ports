# $OpenBSD$

COMMENT=	library for communicating with an icecast server

DISTNAME=	libshout-2.2.2
REVISION=	1
SHARED_LIBS=	shout	5.0
CATEGORIES=	net audio

HOMEPAGE=	http://www.icecast.org/

# LGPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB=	m ogg vorbis>=4 theora>=1

MASTER_SITES=	http://downloads.xiph.org/releases/libshout/

BUILD_DEPENDS=	audio/speex
LIB_DEPENDS=	audio/libvorbis \
		multimedia/libtheora

FAKE_FLAGS=	docdir='${PREFIX}/share/examples/libshout'

CONFIGURE_STYLE= gnu
CONFIGURE_ARGS+= ${CONFIGURE_SHARED}

SEPARATE_BUILD=	Yes
USE_LIBTOOL=	Yes

.include <bsd.port.mk>
