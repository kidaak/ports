# $OpenBSD$

COMMENT=	one-player puzzle game for x11

VERSION=	0.7
DISTNAME=	gemdropx-${VERSION}
REVISION =	0
CATEGORIES=	games x11

HOMEPAGE=	http://www.newbreedsoftware.com/gemdropx/

MAINTAINER=	Peter Valchev <pvalchev@openbsd.org>

PERMIT_PACKAGE_CDROM=   Yes
PERMIT_PACKAGE_FTP=     Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=   Yes
WANTLIB=		X11 Xext c m pthread pthread-stubs usbhid xcb \
			SDL SDL_mixer

MASTER_SITES=	ftp://ftp.sonic.net/pub/users/nbs/unix/x/gemdropx/

LIB_DEPENDS=	devel/sdl \
		devel/sdl-mixer

USE_GMAKE=	Yes
NO_REGRESS=	Yes
MAKE_ENV=	JOY=NO

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gemdropx ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/gemdropx/images
	${INSTALL_DATA} ${WRKSRC}/data/images/* ${PREFIX}/share/gemdropx/images
	${INSTALL_DATA_DIR} ${PREFIX}/share/gemdropx/sounds
	${INSTALL_DATA} ${WRKSRC}/data/sounds/* ${PREFIX}/share/gemdropx/sounds
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gemdropx
	${INSTALL_DATA} ${WRKSRC}/README.txt ${PREFIX}/share/doc/gemdropx/README

.include <bsd.port.mk>
