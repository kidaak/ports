# $OpenBSD$

COMMENT=		structured Type Constraints for Moose

DISTNAME=		MooseX-Types-Structured-0.26

CATEGORIES=		devel

# perl
PERMIT_PACKAGE_CDROM=   Yes
PERMIT_PACKAGE_FTP=     Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=   Yes

MODULES=		cpan
USE_GROFF =		Yes

RUN_DEPENDS=		devel/p5-Devel-PartialDump \
			devel/p5-MooseX-Types>=0.22 \
			devel/p5-MooseX-Types-DateTime \
			devel/p5-Sub-Exporter
BUILD_DEPENDS=		${RUN_DEPENDS}

REGRESS_DEPENDS=	devel/p5-Test-Fatal

.include <bsd.port.mk>
