# $OpenBSD$

COMMENT =	Perl implementation of the reCAPTCHA API

MODULES =	cpan
DISTNAME =	Captcha-reCAPTCHA-0.94
CATEGORIES =	graphics security
USE_GROFF =	Yes

MAINTAINER =	Simon Bertrang <simon@openbsd.org>

# Perl
PERMIT_PACKAGE_CDROM =		Yes
PERMIT_PACKAGE_FTP =		Yes
PERMIT_DISTFILES_CDROM =	Yes
PERMIT_DISTFILES_FTP =		Yes

CPAN_AUTHOR =	ANDYA

RUN_DEPENDS =	www/p5-HTML-Tiny \
		www/p5-libwww

MAKE_ENV +=	TEST_POD=1

.include <bsd.port.mk>
