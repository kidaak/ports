# $OpenBSD$

COMMENT-main=	X11 keyboard accessibility tool
COMMENT-gui=	GUI for xkbset

DISTNAME=	xkbset-0.5
PKGNAME-main=	xkbset-0.5
REVISION-main=	1
PKGNAME-gui=	xkbset-gui-0.5
REVISION-gui=	1
CATEGORIES=	x11
MAINTAINER=	Sebastian Stark <seb@todesplanet.de>

# BSD
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

HOMEPAGE=	http://www.math.missouri.edu/~stephen/software/\#xkbset
MASTER_SITES=	http://www.math.missouri.edu/~stephen/software/xkbset/

MAKE_FLAGS=	X11BASE="${X11BASE}"
FAKE_FLAGS=	X11PREFIX="${PREFIX}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}"

USE_GROFF =	Yes

MULTI_PACKAGES=	-main -gui

WANTLIB-main=	X11 c

RUN_DEPENDS-gui=x11/xkbset x11/p5-Tk

NO_REGRESS=	Yes

.include <bsd.port.mk>
