# $OpenBSD$


COMMENT =		tool to flash dell bios

DISTNAME =		dellflash-0.2
REVISION =		0

CATEGORIES =		sysutils

ONLY_FOR_ARCHS=		i386 amd64

HOMEPAGE =		http://opensource.conformal.com/wiki/Dell_Flash

MAINTAINER =		Marco Peereboom <marco@peereboom.us>

# BSD
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

WANTLIB =		c

MASTER_SITES =		http://opensource.conformal.com/snapshots/dellflash/

EXTRACT_SUFX =		.tgz

NO_REGRESS=		Yes

INSTDIR=		${PREFIX}/lib/dellflash
SUBST_VARS=		INSTDIR

do-install:
	${INSTALL_DATA_DIR} ${INSTDIR}
	${INSTALL_DATA} ${WRKBUILD}/module/biosmod.o ${INSTDIR}
	${INSTALL_PROGRAM} ${WRKBUILD}/flashit/flashit ${PREFIX}/sbin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dellflash
	${INSTALL_DATA} ${WRKBUILD}/README ${PREFIX}/share/doc/dellflash

.include <bsd.port.mk>
