# $OpenBSD$

ONLY_FOR_ARCHS=	${GCC4_ARCHS}

COMMENT=	x86 with DOS emulator targeted at playing games

DISTNAME=	dosbox-0.74
REVISION=	1
CATEGORIES=	games x11 emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dosbox/}

HOMEPAGE=	http://dosbox.sourceforge.net/

MAINTAINER=	Jonathan Gray <jsg@openbsd.org>

# GPL
PERMIT_PACKAGE_CDROM=   Yes
PERMIT_PACKAGE_FTP=     Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=   Yes

WANTLIB=		SDL SDL_net SDL_sound png X11 c m pthread z

LIB_DEPENDS=	devel/sdl-net \
		devel/sdl-sound \
		graphics/png

USE_GROFF=	Yes
NO_REGRESS=	Yes

CONFIGURE_STYLE= gnu
CONFIGURE_ENV=CPPFLAGS="-I${LOCALBASE}/include/libpng -I${LOCALBASE}/include -I${X11BASE}/include" 
CONFIGURE_ENV+=LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
CONFIGURE_ARGS+=	--disable-alsatest
CONFIGURE_ARGS+=	--disable-opengl

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dosbox
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/dosbox

.include <bsd.port.mk>
