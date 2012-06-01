# $OpenBSD$

COMMENT=	virtual browser that retries on errors

MODULES=	cpan
DISTNAME=	LWP-UserAgent-Determined-1.03
REVISION=	0
CATEGORIES=	www
USE_GROFF =	Yes

MAINTAINER=	Sam Smith <s@msmith.net>

# Perl
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

RUN_DEPENDS=	www/p5-libwww
BUILD_DEPENDS=	${RUN_DEPENDS}

.include <bsd.port.mk>
