# $OpenBSD$

COMMENT=	3D block-dropping game

DISTNAME=	xbl-1.1.5
REVISION =	0
CATEGORIES=	games
HOMEPAGE=	http://www710.univ-lyon1.fr/ftp/xbl/xbl.html

# GPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB=	X11 Xau Xdmcp Xext c m pthread-stubs xcb

MASTER_SITES=	http://www710.univ-lyon1.fr/ftp/xbl/

USE_GROFF =	Yes
CONFIGURE_STYLE=gnu	# also uses imake
MAKE_ENV=	OPTCFLAGS='${CFLAGS}'

NO_REGRESS=	Yes

.include <bsd.port.mk>
