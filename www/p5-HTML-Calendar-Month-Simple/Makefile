# $OpenBSD$

COMMENT=	Simple HTML Calendars

MODULES=	cpan
DISTNAME=	HTML-CalendarMonthSimple-1.25
REVISION=	1
CATEGORIES=	www
USE_GROFF =	Yes

MAINTAINER=	Sam Smith <S@msmith.net>

# Same as Perl
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

RUN_DEPENDS=	devel/p5-Date-Calc \
		devel/p5-Date-Simple
BUILD_DEPENDS=	${RUN_DEPENDS}

.include <bsd.port.mk>
