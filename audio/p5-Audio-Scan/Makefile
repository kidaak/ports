# $OpenBSD$

COMMENT=	XS parser for many common audio formats

SHARED_ONLY=	Yes
DISTNAME=	Audio-Scan-0.87
REVISION=	0
CATEGORIES=	audio

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB=	c z
MODULES=	cpan
CPAN_AUTHOR=	AGRUNDMA
USE_GROFF=	Yes

REGRESS_FLAGS=		TEST_POD=1
REGRESS_DEPENDS=	devel/p5-Test-Pod \
			devel/p5-Test-Pod-Coverage \
			devel/p5-Test-Warn

.include <bsd.port.mk>
