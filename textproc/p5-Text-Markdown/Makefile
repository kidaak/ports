# $OpenBSD$

COMMENT=	convert Markdown syntax to (X)HTML

DISTNAME=	Text-Markdown-1.000031
CATEGORIES=	textproc www
MODULES=	cpan

MAINTAINER=	Okan Demirmen <okan@openbsd.org>

# BSD
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

RUN_DEPENDS=	devel/p5-File-Slurp \
		devel/p5-List-MoreUtils \
		devel/p5-Test-Exception

MAKE_ENV=	TEST_POD=Yes

REGRESS_DEPENDS=	devel/p5-Test-Differences \
			www/p5-HTML-Tidy

.include <bsd.port.mk>
