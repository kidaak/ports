# $OpenBSD$

COMMENT=	view and manipulate contents of a tar file

DISTNAME=	xtar-1.4
REVISION=	3
CATEGORIES=	misc

MASTER_SITES=	${MASTER_SITE_XCONTRIB:=utilities/}

# License: BSD
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB=	ICE SM X11 Xau Xdmcp Xext Xt c m pthread-stubs xcb Xm

CONFIGURE_STYLE=imake
LIB_DEPENDS+=	x11/openmotif
USE_GROFF =	Yes
MAKE_FLAGS=	EXTRA_LDOPTIONS=-L${WRKBUILD}/common
MAKE_ENV+=MOTIFLIB='-L${LOCALBASE}/lib -lXm'

NO_REGRESS=	Yes

.include <bsd.port.mk>
