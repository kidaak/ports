# $OpenBSD$

COMMENT= 	create readonly variables faster

MODULES=	cpan
SHARED_ONLY=	Yes
DISTNAME=	Readonly-XS-1.05
REVISION=	2
CATEGORIES=	devel
USE_GROFF =	Yes

# perl licence
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB += c

RUN_DEPENDS=	devel/p5-Readonly>=1.02

.include <bsd.port.mk>
