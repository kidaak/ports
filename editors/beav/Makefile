# $OpenBSD$

COMMENT=	binary editor and viewer

DISTNAME=	beav_1.40-15
PKGNAME=	beav-1.40.15
CATEGORIES=	editors

MAINTAINER=	Kevin Lo <kevlo@openbsd.org>

PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes
WANTLIB=		c curses

MASTER_SITES=	${MASTER_SITE_DEBIAN:=main/b/beav/}

WRKDIST=	${WRKDIR}/beav-1.40

USE_GROFF =	Yes
NO_REGRESS=	Yes

post-install:
	@perl -i -pe 's:%%PREFIX%%:${TRUEPREFIX}:' ${PREFIX}/man/man1/beav.1

.include <bsd.port.mk>
