# $OpenBSD$

COMMENT =	session management for Mojo

MODULES =	cpan
DISTNAME =	MojoX-Session-0.25
CATEGORIES =	www

# Perl
PERMIT_PACKAGE_CDROM =		Yes
PERMIT_PACKAGE_FTP =		Yes
PERMIT_DISTFILES_CDROM =	Yes
PERMIT_DISTFILES_FTP =		Yes

CPAN_AUTHOR =	VTI

RUN_DEPENDS =	security/p5-Digest-SHA1 \
		www/p5-Mojo

MAKE_ENV +=	TEST_POD=1

.include <bsd.port.mk>
