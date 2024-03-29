# $OpenBSD$

PKG_ARCH=		*

COMMENT-main=		PAC (Perl Audio Converter)
COMMENT-konqueror=	PAC Konqueror service menu & mime types
COMMENT-amarok=		PAC Amarok plugin

V=			4.0.4
DISTNAME=		pacpl-${V}
PKGNAME-main=		pacpl-${V}
PKGNAME-konqueror=	pacpl-konqueror-${V}
PKGNAME-amarok=		pacpl-amarok-${V}
CATEGORIES=		audio converters perl5

REVISION-main =		1
REVISION =		0

HOMEPAGE=		http://pacpl.sourceforge.net/

# GPLv3
PERMIT_PACKAGE_FTP=	Yes
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes

MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pacpl/}

NO_BUILD=		Yes
NO_REGRESS=		Yes

MULTI_PACKAGES=		-main -konqueror -amarok

RUN_DEPENDS=		audio/bonk \
			audio/lame \
			audio/musepack \
			audio/sox \
			audio/speex \
			audio/vorbis-tools \
			audio/p5-Audio-FLAC-Header \
			audio/p5-Audio-Musepack \
			audio/p5-Audio-WMA \
			audio/p5-CDDB_get \
			audio/p5-MP3-ID3v1Tag \
			audio/p5-MP3-Tag \
			audio/p5-MP4-Info \
			audio/p5-Ogg-Vorbis-Header \
			audio/wavpack \
			graphics/ffmpeg \
			x11/mplayer

BUILD_DEPENDS=		${RUN_DEPENDS}

RUN_DEPENDS-konqueror=	${BUILD_PKGPATH} \
			x11/kde/base3
RUN_DEPENDS-amarok=	${BUILD_PKGPATH} \
			audio/amarok

USE_GMAKE=		Yes
CONFIGURE_STYLE=	gnu
CONFIGURE_ARGS=		--with-konq \
			--with-amarok
CONFIGURE_ENV=		KDEDIR="${LOCALBASE}" \
			AMAROK="yes" \
			KONQ="yes"

pre-configure:
	${SUBST_CMD} ${WRKSRC}/pacpl ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
