# $OpenBSD: ports/graphics/mpeg_encode/Makefile,v 1.14 2010/11/22 10:16:08 espie Exp $
# $FreeBSD: ports/graphics/mpeg_encode/Makefile,v 1.11 2000/10/28 13:05:25 lioux Exp $

COMMENT=	UCB's MPEG-I video stream encoder

DISTNAME=	mpeg_encode-1.5b-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	graphics

# BSD
PERMIT_PACKAGE_CDROM=   patents
PERMIT_PACKAGE_FTP=     Yes
PERMIT_DISTFILES_CDROM= patents
PERMIT_DISTFILES_FTP=   Yes
WANTLIB=		c m jpeg>=62

MASTER_SITES=	http://bmrc.berkeley.edu/ftp/pub/multimedia/mpeg/encode/

LIB_DEPENDS=    graphics/jpeg

WRKDIST=	${WRKDIR}/mpeg_encode
USE_GROFF =	Yes

REGRESS_TARGET=	test_all

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mpeg_encode ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/mpeg_encode.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mpeg_encode
.for i in users-guide.ps template.param
	${INSTALL_DATA} ${WRKSRC}/docs/${i} ${PREFIX}/share/doc/mpeg_encode
.endfor

.include <bsd.port.mk>