# $OpenBSD$

SHARED_ONLY=		Yes

COMMENT=		adding keywords to perl, in perl

DISTNAME=		Devel-Declare-0.006007
REVISION=		0

CATEGORIES=		devel

# perl
PERMIT_PACKAGE_CDROM=   Yes
PERMIT_PACKAGE_FTP=     Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=   Yes

WANTLIB += c

MODULES=		cpan

BUILD_DEPENDS=		devel/p5-B-Hooks-OP-Check>=0.19
RUN_DEPENDS=		devel/p5-B-Hooks-OP-Check>=0.19 \
			devel/p5-B-Hooks-EndOfScope \
			devel/p5-Sub-Name
REGRESS_DEPENDS=	devel/p5-Test-Warn

.include <bsd.port.mk>
