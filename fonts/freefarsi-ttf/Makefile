# $OpenBSD$

COMMENT=		free TrueType Persian fonts

DISTNAME=		freefarsi-ttf-1.0.0b
REVISION=		0
CATEGORIES=		fonts x11

HOMEPAGE=		http://sourceforge.net/projects/fpf/

# GPLv2
PERMIT_PACKAGE_CDROM =		Yes
PERMIT_PACKAGE_FTP =		Yes
PERMIT_DISTFILES_CDROM =	Yes
PERMIT_DISTFILES_FTP =		Yes

# The original distfile contains .sfd files, the Debian package contains
# .ttf files. These are the files we install.
MASTER_SITES=		http://distfiles.nl/

PKG_ARCH=		*
NO_BUILD=		Yes
NO_REGRESS=		Yes

FONTSDIR=               ${PREFIX}/lib/X11/fonts/freefarsi

do-install:
	${INSTALL_DATA_DIR} ${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${FONTSDIR}

.include <bsd.port.mk>
