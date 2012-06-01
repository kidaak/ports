# $OpenBSD$

COMMENT=	Diffie-Hellman key exchange system

DISTNAME=	Crypt-DH-0.06
REVISION=	2
CATEGORIES=	security

# perl
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	security/p5-Crypt-Random

MODULES=	cpan

# use a fast computer, tests will finish eventually
#NO_REGRESS=	tests take ages to complete

.include <bsd.port.mk>
