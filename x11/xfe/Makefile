# $OpenBSD$

COMMENT=	MS-Explorer like file manager for X

DISTNAME= 	xfe-1.32.2
REVISION=	0
CATEGORIES= 	x11

HOMEPAGE=	http://roland65.free.fr/xfe/

MAINTAINER=	Amit Kulkarni <amitkulz@gmail.com>

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xfe/}

WANTLIB=	X11 Xau Xdmcp Xft Xrender c expat fontconfig freetype \
		m pthread stdc++ png z pthread-stubs util xcb

MODULES=	devel/gettext textproc/intltool
LIB_DEPENDS =	devel/fox
WANTLIB +=	FOX-1.6>=1

RUN_DEPENDS=	devel/desktop-file-utils

USE_LIBTOOL=	Yes
USE_GMAKE=	Yes
USE_GROFF =	Yes

CONFIGURE_STYLE=gnu
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include \
			-I${LOCALBASE}/include/fox-1.6 \
			-I${X11BASE}/include \
			-I${X11BASE}/include/freetype2 \
			-I${LOCALBASE}/include/libpng" \
		LDFLAGS="-L${LOCALBASE}/lib \
			-L${X11BASE}/lib -lXft -pthread"

MAKE_FLAGS=	CXXFLAGS="${CXXFLAGS} -DHAVE_XFT_H"

.include <bsd.port.mk>
