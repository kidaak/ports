# $OpenBSD$

COMMENT=	turns your keyboard into an fast pointer mover

DISTNAME=	keynav-20080614.01
PKGNAME=	${DISTNAME:S/.//}
REVISION=	1

CATEGORIES=	x11

HOMEPAGE=	http://www.semicomplete.com/projects/keynav/

# BSD
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=	http://semicomplete.googlecode.com/files/

WANTLIB=	X11 Xau Xdmcp Xext Xtst c pthread-stubs xcb
NO_REGRESS=	Yes

pre-configure:
	${SUBST_CMD} ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/keynav ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/keynav
	${INSTALL_DATA} ${WRKSRC}/keynavrc ${PREFIX}/share/examples/keynav/

.include <bsd.port.mk>
