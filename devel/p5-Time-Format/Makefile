# $OpenBSD$

COMMENT=		easy-to-use date/time formatting

DISTNAME=		Time-Format-1.11
REVISION=		0
CATEGORIES=		devel

MAINTAINER=		Alexander Bluhm <bluhm@openbsd.org>

# Perl
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MODULES=		cpan
USE_GROFF =		Yes
REGRESS_DEPENDS=	converters/p5-DateManip \
			devel/p5-DateTime

.include <bsd.port.mk>
