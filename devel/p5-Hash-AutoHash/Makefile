#	$OpenBSD$

COMMENT=	object-oriented access to real and tied hashes  

DISTNAME=	Hash-AutoHash-1.12
REVISION=	2
CATEGORIES=	devel

# perl
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=	Yes

MODULES=		cpan
USE_GROFF =		Yes

CONFIGURE_STYLE=	modbuild

RUN_DEPENDS=		devel/p5-List-MoreUtils \
			devel/p5-Tie-Hash-MultiValue \
			devel/p5-Tie-ToObject
REGRESS_DEPENDS=	devel/p5-Test-Deep

.include <bsd.port.mk>
