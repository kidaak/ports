# $OpenBSD$

COMMENT=		parse and create PostGresql date objects

MODULES=		cpan
DISTNAME=		DateTime-Format-Pg-0.16005
CATEGORIES=		devel converters
USE_GROFF =		Yes

# perl
PERMIT_PACKAGE_CDROM=   Yes
PERMIT_PACKAGE_FTP=     Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=   Yes

RUN_DEPENDS=		devel/p5-DateTime-Format-Builder
BUILD_DEPENDS=		${RUN_DEPENDS}
MAKE_ENV=		TEST_POD=Yes

.include <bsd.port.mk>	
