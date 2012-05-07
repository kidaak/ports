# $OpenBSD$

COMMENT =		fetch metadata about installed packages
DISTNAME =		pkg-config-20120507
CATEGORIES =		sysutils devel

#HOMEPAGE =		???	URL

# ISC
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

MASTER_SITES =		${MASTER_SITE_OBSCURE}

#MODULES =		???
BUILD_DEPENDS =		textproc/mdocml
RUN_DEPENDS =		textproc/man

NO_REGRESS =		Yes

PKG_ARCH =		*

do-install:
	${INSTALL_SCRIPT} ${WRKBUILD}/pkg-config ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKBUILD}/pkg-config.1 ${PREFIX}/man/man1/

.include <bsd.port.mk>
