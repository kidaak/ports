# $OpenBSD$

COMMENT =	greytrapping daemon to compliment OpenBSD spamd

DISTNAME =	greyscanner-1.01
REVISION =	0
CATEGORIES =	mail
HOMEPAGE =	http://bitbucket.org/bonetruck/greyscanner/

MAINTAINER =	Jim Razmus II <jim@openbsd.org>

# BSD
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

#MASTER_SITES =	http://bitbucket.org/bonetruck/greyscanner/get/
MASTER_SITES =	http://spacehopper.org/mirrors/

RUN_DEPENDS =	mail/p5-Email-Valid \
		net/p5-Net-DNS

WRKDIST =	${WRKDIR}/greyscanner

NO_BUILD =	Yes
NO_REGRESS =	Yes
USE_GROFF =	Yes
PKG_ARCH =	*

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/greyscanner ${PREFIX}/sbin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/greyscanner
	${INSTALL_DATA} ${WRKSRC}/greyscanner.conf ${PREFIX}/share/examples/greyscanner
	${INSTALL_MAN} ${WRKSRC}/greyscanner.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
