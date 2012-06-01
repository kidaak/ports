# $OpenBSD$

COMMENT=		interface to goo.gl shortening site

DISTNAME=		WWW-Shorten-Googl-1.02
CATEGORIES=		www

# Perl
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=	Yes

MODULES=		cpan

BUILD_DEPENDS=		${RUN_DEPENDS}
RUN_DEPENDS=		converters/p5-JSON-Any \
			www/p5-WWW-Shorten

.include <bsd.port.mk>
