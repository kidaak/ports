# $OpenBSD$

COMMENT=	lightweight video thumbnailer for file managers

DISTNAME=	ffmpegthumbnailer-2.0.7
CATEGORIES=	graphics multimedia
MASTER_SITES=	http://ffmpegthumbnailer.googlecode.com/files/
REVISION=	0

SHARED_LIBS=	ffmpegthumbnailer	4.1

HOMEPAGE=	http://code.google.com/p/ffmpegthumbnailer

# GPLv2+
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB += avcodec avformat avutil c jpeg m png pthread stdc++
WANTLIB += swscale

LIB_DEPENDS=	graphics/ffmpeg \
		graphics/jpeg \
		graphics/png

USE_LIBTOOL=	Yes
CONFIGURE_STYLE= autoconf
AUTOCONF_VERSION= 2.68
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	${CONFIGURE_SHARED}

.include <bsd.port.mk>
