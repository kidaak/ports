# $OpenBSD$

COMMENT =	ISP tool for LPC2000 and ADUC70xx microcontrollers

DISTNAME =	lpc21isp_183
PKGNAME =	lpc21isp-1.83
CATEGORIES =	devel

HOMEPAGE =	http://sourceforge.net/projects/lpc21isp/

MAINTAINER =	Alexander Shiryaev <shiryaev.a.v@gmail.com>

# LGPLv3+
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

MASTER_SITES =	${MASTER_SITE_SOURCEFORGE:=lpc21isp/}

WANTLIB =	c

WRKDIST =	${WRKDIR}

USE_GMAKE =	Yes
MAKE_FLAGS =	CC=${CC}

NO_REGRESS =	Yes

do-install:
	${INSTALL_PROGRAM} ${WRKBUILD}/lpc21isp ${PREFIX}/bin/lpc21isp

.include <bsd.port.mk>
