# $OpenBSD$

COMMENT=	Sendmail Log Analysis Report

VERSION=	1.4
DISTNAME=	sma-${VERSION}
REVISION =	0
CATEGORIES=	mail

HOMEPAGE=	http://www.klake.org/sma/

# BSD
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes
WANTLIB=		c

MASTER_SITES=	http://www.klake.org/sma/dl/

USE_GROFF =	Yes
NO_REGRESS=	Yes
ALL_TARGET=	sma

pre-patch:
	@perl -pi -e 's,./sma.conf,${SYSCONFDIR}/sma.conf,g' \
		${WRKSRC}/docs/sma.8 ${WRKSRC}/conf.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sma ${PREFIX}/bin/sma
	${INSTALL_MAN} ${WRKSRC}/docs/sma.8 ${PREFIX}/man/man8/sma.8
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/sma
	${INSTALL_DATA} ${WRKSRC}/sma.conf ${PREFIX}/share/examples/sma
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/sma
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/sma

.include <bsd.port.mk>
