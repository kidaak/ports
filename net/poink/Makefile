# $OpenBSD$

COMMENT=	nosuid, secure TCP/IP ping

DISTNAME=	poink
PKGNAME=	${DISTNAME}-1.6
CATEGORIES=	net

HOMEPAGE=	http://lcamtuf.coredump.cx/

MAINTAINER=	Artur Skura <arturs@iidea.pl>

MASTER_SITES=	${HOMEPAGE}/soft/
EXTRACT_SUFX=	.zip

# GPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes
WANTLIB=		c

MAKE_FLAGS=	CC='${CC}' CFLAGS='${CFLAGS}'
USE_GROFF =	Yes

do-install:
	${INSTALL_PROGRAM} ${WRKBUILD}/poink ${PREFIX}/bin
	${INSTALL_MAN} ${WRKBUILD}/ping.1 ${PREFIX}/man/man1/poink.1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/poink
	${INSTALL_DATA} ${WRKBUILD}/README ${PREFIX}/share/doc/poink

.include <bsd.port.mk>
