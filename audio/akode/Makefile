# $OpenBSD$

SHARED_ONLY=	Yes

COMMENT=	decoding library for KDE Multimedia

DISTNAME=	akode-2.0.2
REVISION=	19

SHARED_LIBS +=	akode                2.1      # .2.0

CATEGORIES=	audio multimedia x11/kde

HOMEPAGE=	http://www.carewolf.com/akode/

MASTER_SITES=	http://www.kde-apps.org/CONTENT/content-files/
EXTRACT_SUFX=	.tar.bz2
DISTFILES=	30375-${DISTNAME}${EXTRACT_SUFX}

# LGPLv2
PERMIT_PACKAGE_CDROM=   Yes
PERMIT_PACKAGE_FTP=     Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=   Yes

WANTLIB=	FLAC avcodec avformat avutil bz2 c gsm ltdl m mad mp3lame ogg \
		orc-0.4 pthread samplerate schroedinger-1.0 sndio speex stdc++ \
		theoradec theoraenc vorbis vorbisenc vorbisfile vpx x264 \
		xvidcore z

LIB_DEPENDS=	audio/flac \
		audio/libmad \
		audio/libsamplerate \
		audio/speex \
		audio/libvorbis \
		devel/libtool,-ltdl \
		graphics/ffmpeg>=20100512

USE_GMAKE=	Yes
USE_LIBTOOL=	Yes

BUILD_DEPENDS=	${MODGNU_AUTOCONF_DEPENDS} \
		${MODGNU_AUTOMAKE_DEPENDS}
# uses libtoolize
BUILD_DEPENDS+=	devel/libtool

CONFIGURE_STYLE=	gnu
AUTOCONF_VERSION=	2.60
AUTOMAKE_VERSION=	1.9
CONFIGURE=		/bin/sh ${WRKDIST}/admin/cvs.sh configure
CONFIGURE_ARGS+=	--with-extra-includes=${LOCALBASE}/include \
			--with-extra-libs=${LOCALBASE}/lib \
			--without-jack \
			--without-polyaudio \
			--without-oss \
			--without-sun

post-extract:
	@mkdir -p ${WRKSRC}/akode/plugins/sndio_sink
	@cp ${FILESDIR}/{Makefile.am,sndio_sink.*}  ${WRKSRC}/akode/plugins/sndio_sink

pre-configure:
	@cd ${WRKSRC} && \
		AUTOCONF_VERSION=${AUTOCONF_VERSION} \
		AUTOMAKE_VERSION=${AUTOMAKE_VERSION} \
		autoreconf -i

post-install:
	@rm ${PREFIX}/lib/libakode_*.a
	@rm ${PREFIX}/lib/libakode_*.la

.include <bsd.port.mk>
