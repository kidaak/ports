# $OpenBSD$

COMMENT=	curses based user interface framework for Perl

MODULES=	cpan
DISTNAME=	Curses-UI-0.9609

CATEGORIES=	devel

RUN_DEPENDS=	devel/p5-Curses \
		devel/p5-Term-ReadKey
BUILD_DEPENDS=	${RUN_DEPENDS} \
		devel/p5-Test-Pod

# perl
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MAKE_ENV=	TEST_POD=Yes

MODCPAN_EXAMPLES=	Yes

.include <bsd.port.mk>
