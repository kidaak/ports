# $OpenBSD$

COMMENT=	exporter on steroids

MODULES=	cpan
DISTNAME=	Sub-Exporter-0.982
REVISION=	0
CATEGORIES=	devel
USE_GROFF =	Yes

# perl
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

RUN_DEPENDS=	devel/p5-Data-OptList \
		devel/p5-Params-Util \
		devel/p5-Sub-Install

MAKE_ENV=	TEST_POD=Yes \
		PERL_TEST_CRITIC=Yes

REGRESS_DEPENDS=devel/p5-Package-Generator \
		devel/p5-Test-Perl-Critic

.include <bsd.port.mk>
