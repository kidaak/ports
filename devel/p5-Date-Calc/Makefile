# $OpenBSD$

SHARED_ONLY=	Yes

COMMENT=	date calculations for the Gregorian calendar

MODULES=	cpan
DISTNAME=	Date-Calc-6.3
REVISION=	1
CATEGORIES=	devel
USE_GROFF =	Yes

MAINTAINER=	Kevin Lo <kevlo@openbsd.org>

# Perl
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

RUN_DEPENDS=	math/p5-Bit-Vector>=6.2 \
		devel/p5-Carp-Clan>=5.3
BUILD_DEPENDS=	${RUN_DEPENDS}

.include <bsd.port.mk>
