# $OpenBSD$

COMMENT=	graphical front end to Unix diff

DISTNAME=	mgdiff
PKGNAME=	${DISTNAME}-1.0
REVISION=	6
CATEGORIES=	textproc

MASTER_SITES=	${MASTER_SITE_XCONTRIB:=applications/}

# X11
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB=	ICE SM X11 Xau Xdmcp Xext Xmu Xt c m Xm

LIB_DEPENDS+=		x11/openmotif
USE_GROFF =	Yes
CONFIGURE_STYLE=imake
MAKE_ENV+=MOTIFLIB='-L${LOCALBASE}/lib -lXm'

NO_REGRESS=	Yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/X11/mgdiff
	${INSTALL_DATA} ${WRKSRC}/mgdiff.x[bp]m ${PREFIX}/lib/X11/mgdiff

.include <bsd.port.mk>
