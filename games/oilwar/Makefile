# $OpenBSD$

COMMENT=	sdl shoot 'em up; stop evil army from getting your oil
DISTNAME=	OilWar-1.2.1
PKGNAME=	${DISTNAME:L}
REVISION =	4
CATEGORIES=	games x11
MASTER_SITES=	${MASTER_SITE_BACKUP}

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB=	SDL c m pthread stdc++ SDL_image SDL_mixer

NO_REGRESS=     Yes

LIB_DEPENDS=	devel/sdl-image \
		devel/sdl-mixer

CONFIGURE_STYLE=gnu

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/{doc/oilwar,oilwar}
	${INSTALL_PROGRAM} ${WRKSRC}/oilwar ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/oilwar
	${INSTALL_DATA} ${WRKSRC}/*.{png,wav} ${PREFIX}/share/oilwar
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/oilwar/
	${INSTALL_DATA} /dev/null ${PREFIX}/share/examples/oilwar/oilwar.scores

.include <bsd.port.mk>
