# $OpenBSD$

COMMENT =		graphical frontend to the objdump disassembler

MODPY_EGG_VERSION = 	9
DISTNAME =		dissy-${MODPY_EGG_VERSION}
CATEGORIES =		devel
HOMEPAGE =		http://code.google.com/p/dissy/
REVISION =		1

MAINTAINER =		Jonathan Armani <armani@openbsd.org>

# GPLv2
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes


MASTER_SITES =	http://dissy.googlecode.com/files/

MODULES =	lang/python
RUN_DEPENDS =	x11/py-gtk2

NO_REGRESS =	Yes
PKG_ARCH =	*

USE_GROFF =	Yes

.include <bsd.port.mk>
