# $OpenBSD$

ONLY_FOR_ARCHS=	amd64 i386

COMMENT=	3D realtime strategy on a future earth

DISTNAME=	warzone2100-2.3.9
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=warzone2100/}

HOMEPAGE=	http://wz2100.net/

# GPLv2+
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB=	GL GLC GLU SDL X11 c m physfs ogg openal png popt \
		pthread sndio stdc++ theora vorbis vorbisfile z

MODULES=	devel/gettext
LIB_DEPENDS=	audio/libogg \
		audio/libvorbis \
		audio/openal>=20110627 \
		devel/physfs \
		devel/popt \
		devel/sdl \
		graphics/png \
		graphics/quesoglc \
		multimedia/libtheora
BUILD_DEPENDS=	archivers/unzip \
		archivers/zip \
		devel/bison \
		devel/flex
RUN_DEPENDS=	devel/desktop-file-utils

USE_GMAKE=	Yes
CONFIGURE_STYLE= autoconf
AUTOCONF_VERSION= 2.65
CONFIGURE_ARGS+=--disable-motif \
		--with-distributor="OpenBSD"
CONFIGURE_ENV+=	CPPFLAGS="-I${X11BASE}/include -I${LOCALBASE}/include/libpng \
		    -I${LOCALBASE}/include" \
		LDFLAGS="-L${X11BASE}/lib -L${LOCALBASE}/lib" \
		YACC="bison -y" \
		ac_cv_prog_LEX="gflex"

pre-build:
.for _prog in git svn svnversion
	@cd ${WRKDIR}/bin && ln -sf /usr/bin/true ${_prog}
.endfor

.include <bsd.port.mk>
