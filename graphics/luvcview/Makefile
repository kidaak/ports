# $OpenBSD$

COMMENT=		V4L compatible video application

DISTNAME=		luvcview-20070512
REVISION=		5
CATEGORIES=		graphics x11

# GPLv2+
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

HOMEPAGE=	http://mxhaard.free.fr/
MASTER_SITES=	${HOMEPAGE}/spca50x/Investigation/uvc/

LIB_DEPENDS=	devel/sdl>=1.2.5
WANTLIB=	SDL c pthread

MAKE_FLAGS=	CC="${CC}" \
		CFLAGS+="-I${X11BASE}/include -I${LOCALBASE}/include"

NO_REGRESS=	Yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/luvcview ${PREFIX}/bin

.include <bsd.port.mk>
