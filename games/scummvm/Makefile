# $OpenBSD$

COMMENT=	graphical adventure game interpreter
DISTNAME=	scummvm-1.5.0
CATEGORIES=	games x11 emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scummvm/}

HOMEPAGE=	http://scummvm.sourceforge.net/

MAINTAINER=	Jonathan Gray <jsg@openbsd.org>

# GPLv2+
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB=	FLAC>=5 SDL c faad m mad>=2 pthread sndio stdc++ theoradec z

.if ${MACHINE_ARCH} == "i386"
BUILD_DEPENDS=	devel/nasm
.endif

RUN_DEPENDS=	devel/desktop-file-utils
LIB_DEPENDS=	audio/libmad \
		audio/flac \
		audio/faad>=2.7 \
		devel/sdl \
		multimedia/libtheora

CONFIGURE_STYLE=simple
CONFIGURE_ARGS+=--disable-alsa --disable-debug --disable-seq-midi --enable-sndio
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_GROFF =	Yes

.if ${MACHINE_ARCH} == "arm"
CONFIGURE_ARGS +=	--enable-tremor --disable-vorbis
LIB_DEPENDS +=		audio/tremor
WANTLIB +=		vorbisidec>=1
.else
LIB_DEPENDS +=		audio/libvorbis
WANTLIB +=		ogg vorbis>=0 vorbisfile>=1
.endif

NO_REGRESS=	Yes
USE_GMAKE=	Yes

MAKE_ENV+=	CXXFLAGS="${CXXFLAGS}" CXX="${CXX}" VERBOSE_BUILD=1

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/scummvm
	${INSTALL_DATA_DIR} ${PREFIX}/share/icons
	${INSTALL_DATA_DIR} ${PREFIX}/share/scummvm
	${INSTALL_DATA_DIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/{NEWS,AUTHORS,README} \
	    ${PREFIX}/share/doc/scummvm
	${INSTALL_DATA} ${WRKSRC}/icons/scummvm.{svg,xpm} ${PREFIX}/share/icons
	${INSTALL_MAN} ${WRKSRC}/dists/scummvm.6 ${PREFIX}/man/man6
	${INSTALL_DATA} ${WRKSRC}/gui/themes/{scummmodern,scummclassic}.zip \
	    ${PREFIX}/share/scummvm
	${INSTALL_DATA} ${WRKSRC}/gui/themes/translations.dat \
	    ${PREFIX}/share/scummvm
	${INSTALL_DATA} ${WRKSRC}/dists/scummvm.desktop \
	    ${PREFIX}/share/applications
	${INSTALL_PROGRAM} ${WRKSRC}/scummvm ${PREFIX}/bin

.include <bsd.port.mk>
