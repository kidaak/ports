# $OpenBSD$

COMMENT=	top-like X server resources usage display tool
DISTNAME=	xrestop-0.4
REVISION=	1

CATEGORIES=	x11

HOMEPAGE=	http://www.freedesktop.org/wiki/Software/xrestop

MAINTAINER=	Matthieu Herrb <matthieu@openbsd.org>

# GPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=	http://projects.o-hand.com/sources/xrestop/

WANTLIB=	XRes Xext X11 Xau Xdmcp ncurses c pthread-stubs xcb

SEPARATE_BUILD=	Yes
USE_GROFF =	Yes

CONFIGURE_STYLE=gnu
CONFIGURE_ENV=	CPPFLAGS=-I${X11BASE}/include

.include <bsd.port.mk>
