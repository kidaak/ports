# $OpenBSD$

COMMENT=	complex rogue-style game of dungeon exploration

VERSION=	0.90.4
DISTFILES=	omega-${VERSION}-src.tar.gz
DISTNAME=	omega-${VERSION}
REVISION =	1
CATEGORIES=     games
MASTER_SITES=   http://www.alcyone.com/binaries/omega/

HOMEPAGE=	http://www.alcyone.com/max/projects/omega/

# LGPL
PERMIT_PACKAGE_CDROM=   Yes
PERMIT_PACKAGE_FTP=     Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=   Yes
WANTLIB=		c curses termcap

WRKDIST=        ${WRKDIR}/omega
WRKSRC=         ${WRKDIST}

NO_REGRESS=	Yes

ALL_TARGET=

.include <bsd.port.mk>
