# $OpenBSD$

COMMENT=	go client and fully featured sgf editor

DISTNAME=	qgo-1.5.4
REVISION =	2
CATEGORIES=	games

# GPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes
WANTLIB=	X11 Xau Xdmcp Xext ICE SM c jpeg m pthread pthread-stubs \
		stdc++ xcb

MODULES=	x11/qt3

MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qgo/}

WRKDIST=	${WRKDIR}/${DISTNAME:S/-r1//}

USE_GMAKE=Yes
USE_LIBTOOL=Yes

NO_REGRESS= Yes

CONFIGURE_STYLE= gnu
CONFIGURE_ARGS+= --with-extra-includes=${LOCALBASE}/include \
		 --with-extra-libs=${LOCALBASE}/lib \
		 ${MODQT_CONFIGURE_ARGS}

.include <bsd.port.mk>
