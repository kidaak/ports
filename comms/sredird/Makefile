# $OpenBSD$

COMMENT=	RFC 2217 compliant serial port redirector

DISTNAME=	sredird-2.2.2
REVISION=	0
CATEGORIES=	comms

MAINTAINER=	Alexey E. Suslikov <alexey.suslikov@gmail.com>

# GPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB=		c

MASTER_SITES=	http://www.ibiblio.org/pub/Linux/system/serial/

USE_GROFF =	Yes
NO_REGRESS=	Yes

pre-build:
	@perl -pi -e "s,%%LOCALBASE%%,${LOCALBASE},g" ${WRKSRC}/sredird.8

do-build:
	${CC} ${CFLAGS} -Wall -o ${WRKSRC}/sredird ${WRKSRC}/sredird.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sredird ${PREFIX}/libexec
	${INSTALL_MAN} ${WRKSRC}/sredird.8 ${PREFIX}/man/man8

.include <bsd.port.mk>
