# $OpenBSD$

COMMENT=	simple tree object

MODULES=	cpan
DISTNAME=	Tree-Simple-1.18
REVISION=	1
CATEGORIES=	devel
USE_GROFF =	Yes

# Artistic
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

REGRESS_DEPENDS= devel/p5-Test-Exception \
		 devel/p5-Test-Memory-Cycle>=1.02

MAKE_ENV=	TEST_POD=Yes

CONFIGURE_STYLE= modbuild

.include <bsd.port.mk>
