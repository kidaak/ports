# $OpenBSD$

COMMENT=	tcp connection logger daemon

DISTNAME=	clog-1.6
CATEGORIES=	net security

MASTER_SITES=	ftp://ftp.rediris.es/mirror/coast/tools/unix/logutils/clog/

PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes
WANTLIB=		c pcap

WRKDIST=	${WRKDIR}/clog
ALL_TARGET=	freebsd

USE_GROFF =	Yes
NO_REGRESS=	Yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/clog ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/clog.8 ${PREFIX}/man/man8

.include <bsd.port.mk>
