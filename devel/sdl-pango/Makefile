# $OpenBSD$

COMMENT=	SDL wrapper around the Pango library

V=		0.1.2
DISTNAME=	SDL_Pango-${V}
PKGNAME=	sdl-pango-${V}
CATEGORIES=	devel x11

REVISION=	7

MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sdlpango/}
MASTER_SITES0=	http://zarb.org/~gc/t/

PATCHFILES=	SDL_Pango-0.1.2-API-adds.patch:0

SHARED_LIBS=	SDL_Pango	0.0 # .2.0

HOMEPAGE=	http://sdlpango.sourceforge.net/

# LGPLv2.1+
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB=	SDL X11 Xau Xdmcp expat fontconfig freetype glib-2.0 \
		gmodule-2.0 gobject-2.0 gthread-2.0 m pango-1.0 \
		pangoft2-1.0 pcre pthread-stubs sndio usbhid xcb z

MODULES=	devel/gettext
LIB_DEPENDS=	devel/pango \
		devel/sdl

USE_LIBTOOL=	Yes
CONFIGURE_STYLE=gnu
CONFIGURE_ARGS=	${CONFIGURE_SHARED}

REGRESS_IS_INTERACTIVE=	x11

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/sdl-pango
	${INSTALL_DATA} ${WRKSRC}/docs/html/{*.html,*.css,*.png} \
		${PREFIX}/share/doc/sdl-pango

do-regress:
	cd ${WRKSRC}/test && \
	${CXX} -o testbench testbench.c \
		-I../src `sdl-config --cflags` \
		`sdl-config --libs` -L../src/.libs -lSDL_Pango && \
	${SETENV} ${ALL_REGRESS_FLAGS} LD_LIBRARY_PATH=${WRKBUILD}/src/.libs ./testbench markup.txt

.include <bsd.port.mk>
