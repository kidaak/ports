# $OpenBSD$

COMMENT=	Athena port of xminesweeper

DISTNAME=	xmine-1.0.3-Xaw
PKGNAME=	xmine-1.0.3
REVISION =	2
CATEGORIES=	games

MAINTAINER=	Paul Janzen <pjanzen@openbsd.org>

# License: BSD
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB=	ICE SM Xau Xdmcp X11 Xext Xmu Xpm Xt c pthread-stubs xcb Xaw3d

LIB_DEPENDS=    x11/Xaw3d

CONFIGURE_STYLE=imake
USE_GROFF =	Yes
NO_REGRESS=	Yes

.include <bsd.port.mk>
