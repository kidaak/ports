# $OpenBSD$

COMMENT =	simple blog code for valid (X)HTML

MODULES =	cpan
DISTNAME =	HTML-SBC-0.15
REVISION =	0
CATEGORIES =	www
USE_GROFF =	Yes

MAINTAINER =	Simon Bertrang <simon@openbsd.org>

# Perl
PERMIT_PACKAGE_CDROM =		Yes
PERMIT_PACKAGE_FTP =		Yes
PERMIT_DISTFILES_CDROM =	Yes
PERMIT_DISTFILES_FTP =		Yes

# actually REGRESS_DEPENDS but Module::Install screws up
BUILD_DEPENDS =	devel/p5-Test-Exception

MAKE_ENV +=	TEST_POD=1

.include <bsd.port.mk>
