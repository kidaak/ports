# $OpenBSD$

COMMENT=	CAD drawing program for X11

VERSION=	3.2.5b
DISTNAME=	xfig.${VERSION}.full
PKGNAME=	xfig-${VERSION}
REVISION =	6
CATEGORIES=	graphics x11

HOMEPAGE=	http://www.xfig.org/

# MIT
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB += ICE SM X11 Xmu Xpm Xt c m z jpeg>=62 png>=2
WANTLIB += Xaw3d>=6.1

MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mcj/}

FAKE=		lib
PATCHORIG=	.pat.orig
LIB_DEPENDS=	graphics/jpeg \
		graphics/png \
		x11/Xaw3d
RUN_DEPENDS=	print/transfig \
		textproc/xpdf

MAKE_FLAGS=	XAPPLOADDIR="${PREFIX}/lib/X11/app-defaults" \
		XFIGDOCDIR="${PREFIX}/share/doc/xfig" \
		XFIGLIBDIR="${PREFIX}/lib/X11/xfig"

CONFIGURE_STYLE= imake

INSTALL_TARGET=	install install.all

WRKDIST=	${WRKDIR}/xfig.${VERSION}

NO_REGRESS=	Yes

USE_GROFF =	Yes

post-extract:
	chmod -R a+rX,go-w ${WRKSRC}/Libraries ${WRKSRC}/Doc
	find ${WRKSRC}/Libraries ${WRKSRC}/Doc -type f -exec chmod -x "{}" \;

.include <bsd.port.mk>
