# $OpenBSD$

COMMENT=	buffer sporadic I/O for faster tape and pipe throughput

DISTNAME=	buffer-1.17.1
REVISION=	0
CATEGORIES=	misc

MAINTAINER=	Christian Weisgerber <naddy@openbsd.org>

# GPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB=		c

MASTER_SITES=	${MASTER_SITE_FREEBSD_LOCAL:=steve/}
EXTRACT_SUFX=	.tar.bz2

MAKE_ENV=	CC="${CC}"

WRKDIST=	${WRKDIR}

NO_REGRESS=	Yes

.include <bsd.port.mk>
