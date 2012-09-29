# $OpenBSD$

COMMENT=		use standard configuration files

MODULES=		cpan
DISTNAME=		Config-Std-0.900
CATEGORIES=		devel

# Perl
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

RUN_DEPENDS=		devel/p5-Class-Std
BUILD_DEPENDS=		${RUN_DEPENDS}

REGRESS_DEPENDS=	devel/p5-Test-Distribution \
			devel/p5-Test-Pod-Coverage>=1.04

.include <bsd.port.mk>
