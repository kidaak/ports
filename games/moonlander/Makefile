# $OpenBSD$

COMMENT=	clone of atari game
DISTNAME=	moon-lander-1.0
PKGNAME=	moonlander-1.0
REVISION =	1
CATEGORIES=	games x11
MASTER_SITES=	http://downloads.daveblood.com/lunar_lander/

HOMEPAGE=	http://magigames.org/moonlander.html

# BSD
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes
WANTLIB=		SDL X11 Xext c m pthread pthread-stubs usbhid xcb \
			SDL_image SDL_mixer

LIB_DEPENDS=	devel/sdl-image \
		devel/sdl-mixer

NO_REGRESS=	Yes

WRKDIST=	${WRKDIR}/moon-lander

FLAVORS=	no_sound
FLAVOR?=

.if ${FLAVOR:Mno_sound}
CFLAGS+=	-DNOSOUND
.endif

do-configure:
	perl -pi -e 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/moon_lander.c

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/moonlander ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/moonlander
	@cp -R ${WRKSRC}/{fonts,images,sounds} ${PREFIX}/share/moonlander

post-install:
	@find ${PREFIX}/share/moonlander -type f -print0 |xargs -0 chmod 444

.include <bsd.port.mk>
