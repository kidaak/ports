# $OpenBSD$

COMMENT=		generate nice HTML files from HTML syntax trees

DISTNAME=		HTML-PrettyPrinter-0.03
CATEGORIES=		www textproc

# perl
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MODULES=		cpan

BUILD_DEPENDS=		${RUN_DEPENDS}
RUN_DEPENDS=		www/p5-HTML-Tagset \
			www/p5-HTML-Tree

.include <bsd.port.mk>
