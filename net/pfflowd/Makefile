# $OpenBSD$

COMMENT=	PF to NetFlow converter

BROKEN=		needs updating for pfsync changes, try pflow(4) instead

DISTNAME=	pfflowd-0.7
REVISION=	0
CATEGORIES=	net
MASTER_SITES=	http://www.mindrot.org/files/pfflowd/

HOMEPAGE=	http://www.mindrot.org/pfflowd.html

MAINTAINER=	Damien Miller <djm@openbsd.org>

# BSD
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes
WANTLIB=		c pcap util 

NO_REGRESS=		Yes
MAKE_FLAGS=		CC="${CC}" CFLAGS="${CFLAGS}"
USE_GROFF =		Yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pfflowd ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/pfflowd.8 ${PREFIX}/man/man8

.include <bsd.port.mk>
