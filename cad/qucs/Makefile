# $OpenBSD$

COMMENT=	graphical circuit design and simulation tool

DISTNAME=	qucs-0.0.16
REVISION=	0
CATEGORIES=	cad
REVISION =	0

HOMEPAGE=	http://qucs.sourceforge.net/

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qucs/}

WANTLIB += ICE SM X11 c m pthread stdc++

MODULES=	x11/qt3

USE_GMAKE=	Yes

CONFIGURE_STYLE=gnu
CONFIGURE_ARGS=	${CONFIGURE_SHARED} 
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -pthread"

pre-configure:
	${SUBST_CMD} ${WRKSRC}/configure

.include <bsd.port.mk>
