# $OpenBSD$

COMMENT=	interface to palm pdb databases

# This is needed because PKGNAME defaults to p5-${DISTNAME} with the
# cpan MODULE and we'll end up with a PKGNAME like p5-p5-Palm-...
PKGNAME=	${DISTNAME}

MODULES=	cpan
DISTNAME=	p5-Palm-1.3.0
REVISION=	1
CATEGORIES=	databases productivity
HOMEPAGE=	http://www.coldsync.org/
CPAN_AUTHOR=	ARENSB

# refers to the artistic license perl uses, but doesn't include it
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WRKDIST=	${WRKDIR}/p5-Palm-1.003_000
USE_GROFF=	Yes
PKG_ARCH=	*

.include <bsd.port.mk>
