# $OpenBSD$

COMMENT=	audio/video converter and streamer

V=		20120610
DISTNAME=	ffmpeg-git-${V}
PKGNAME=	ffmpeg-${V}
REVISION=	1
CATEGORIES=	graphics multimedia
MASTER_SITES=	http://comstyle.com/source/
EXTRACT_SUFX=	.tar.xz

SHARED_LIBS=	avcodec		17.0 \
		avdevice	5.0 \
		avfilter	3.0 \
		avformat	15.0 \
		avutil		9.0 \
		postproc	14.0 \
		swscale		4.0

HOMEPAGE=	http://ffmpeg.org/

MAINTAINER=	Brad Smith <brad@comstyle.com>

# LGPLv2.1 and GPLv2
PERMIT_PACKAGE_CDROM=	patents
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB=	SDL X11 Xext Xfixes bz2 c gsm m mp3lame pthread \
		schroedinger-1.0>=2 sndio speex theoradec theoraenc \
		vorbis vorbisenc vpx x264>=8 xvidcore z

BUILD_DEPENDS=	textproc/texi2html
.if ${MACHINE_ARCH} == "amd64" || ${MACHINE_ARCH} == "i386"
BUILD_DEPENDS+=	devel/yasm
.endif
LIB_DEPENDS=	archivers/bzip2 \
		audio/lame \
		audio/libvorbis \
		audio/speex \
		audio/gsm \
		devel/sdl \
		multimedia/libtheora \
		multimedia/libvpx \
		multimedia/schroedinger>=1.0.10 \
		multimedia/x264>=20111027 \
		multimedia/xvidcore

# inter-library dependencies for the current configuration
LIBavcodec_EXTRALIBS=-L${LOCALBASE}/lib -lgsm -lmp3lame -logg -lorc-0.4 -lschroedinger-1.0 -lspeex -ltheoradec -ltheoraenc -lvorbis -lvorbisenc -lvpx -lx264 -lxvidcore -lz -pthread
LIBavdevice_EXTRALIBS=-L${X11BASE}/lib -lX11 -lXext -lXfixes -lsndio
LIBavfilter_EXTRALIBS=
LIBavformat_EXTRALIBS=-L${LOCALBASE}/lib -lbz2
LIBavutil_EXTRALIBS=-lm
LIBpostproc_EXTRALIBS=
LIBswscale_EXTRALIBS=-lm

# configure wants a directory it can execute files in 
WRKTMP=		${WRKDIR}/tmp

.if ${MACHINE_ARCH:Marm}
# uses ARM EABI
FFMPEG_ARCH=	generic
.else
FFMPEG_ARCH=	${MACHINE_ARCH}
.endif

USE_GMAKE=	Yes
CONFIGURE_STYLE= simple
CONFIGURE_ARGS+= ${CONFIGURE_SHARED} \
		--arch=${FFMPEG_ARCH} \
		--cc=${CC} \
		--disable-altivec \
		--disable-armv5te \
		--disable-armv6 \
		--disable-armv6t2 \
		--disable-armvfp \
		--disable-debug \
		--disable-indev=jack \
		--disable-indev=oss \
		--disable-iwmmxt \
		--disable-neon \
		--disable-outdev=oss \
		--disable-outdev=sdl \
		--enable-gpl \
		--enable-libgsm \
		--enable-libmp3lame \
		--enable-libschroedinger \
		--enable-libspeex \
		--enable-libtheora \
		--enable-libvorbis \
		--enable-libvpx \
		--enable-libx264 \
		--enable-libxvid \
		--enable-runtime-cpudetect \
		--enable-x11grab \
		--extra-cflags="-I${LOCALBASE}/include -I${X11BASE}/include" \
		--extra-libs="-L${LOCALBASE}/lib -L${X11BASE}/lib" \
		--mandir=${PREFIX}/man

CONFIGURE_ENV+=	LIBavcodec_EXTRALIBS="${LIBavcodec_EXTRALIBS}" \
		LIBavdevice_EXTRALIBS="${LIBavdevice_EXTRALIBS}" \
		LIBavfilter_EXTRALIBS="${LIBavfilter_EXTRALIBS}" \
		LIBavformat_EXTRALIBS="${LIBavformat_EXTRALIBS}" \
		LIBavutil_EXTRALIBS="${LIBavutil_EXTRALIBS}" \
		LIBpostproc_EXTRALIBS="${LIBpostproc_EXTRALIBS}" \
		LIBswscale_EXTRALIBS="${LIBswscale_EXTRALIBS}" \
		LIBavcodec_LINKFLAGS="" \
		LIBavdevice_LINKFLAGS="-Wl,-rpath-link,${X11BASE}/lib" \
		LIBavfilter_LINKFLAGS="" \
		LIBavformat_LINKFLAGS="" \
		LIBavutil_LINKFLAGS="" \
		LIBpostproc_LINKFLAGS="" \
		LIBswscale_LINKFLAGS="" \
		TMPDIR=${WRKTMP}

VERSION_FLAGS=	libavcodec_VERSION=${LIBavcodec_VERSION} \
		libavdevice_VERSION=${LIBavdevice_VERSION} \
		libavfilter_VERSION=${LIBavfilter_VERSION} \
		libavformat_VERSION=${LIBavformat_VERSION} \
		libavutil_VERSION=${LIBavutil_VERSION} \
		libpostproc_VERSION=${LIBpostproc_VERSION} \
		libswscale_VERSION=${LIBswscale_VERSION}

MAKE_ENV=	V=1

MAKE_FLAGS=	${VERSION_FLAGS} \
		LIBavcodec_EXTRALIBS="-lavutil ${LIBavcodec_EXTRALIBS}" \
		LIBavdevice_EXTRALIBS="-lavformat -lavcodec -lavutil ${LIBavdevice_EXTRALIBS}" \
		LIBavfilter_EXTRALIBS="-lavformat -lavcodec -lavutil -lswscale ${LIBavfilter_EXTRALIBS}" \
		LIBavformat_EXTRALIBS="-lavcodec -lavutil ${LIBavformat_EXTRALIBS}" \
		LIBavutil_EXTRALIBS="${LIBavutil_EXTRALIBS}" \
		LIBpostproc_EXTRALIBS="-lavutil ${LIBpostproc_EXTRALIBS}" \
		LIBswscale_EXTRALIBS="-lavutil ${LIBswscale_EXTRALIBS}"
FAKE_FLAGS=	${VERSION_FLAGS} \
		LDCONFIG=true

.ifdef DEBUG
CONFIGURE_ARGS+=--disable-stripping
.endif

ALL_TARGET=	all tools/qt-faststart

# regression tests incompatible with libswscale
NO_REGRESS=	Yes

HTML_DOCS=	developer faq ffmpeg ffplay ffprobe ffserver general libavfilter

post-extract:
	@rm ${WRKSRC}/VERSION

pre-configure:
	@mkdir -p ${WRKTMP}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/ffmpeg
	${INSTALL_PROGRAM} ${WRKBUILD}/tools/qt-faststart ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ffmpeg
.for doc in ${HTML_DOCS}
	${INSTALL_DATA} ${WRKBUILD}/doc/${doc}.html ${PREFIX}/share/doc/ffmpeg
.endfor
	${INSTALL_DATA} ${WRKBUILD}/doc/ffserver.conf \
		${PREFIX}/share/examples/ffmpeg

.include <bsd.port.mk>
