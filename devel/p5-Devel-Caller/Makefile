# $OpenBSD$

COMMENT =		meatier versions of caller

SHARED_ONLY =		Yes
MODULES =		cpan
DISTNAME =		Devel-Caller-2.05
REVISION =		0
CATEGORIES =		devel
CPAN_AUTHOR =		RCLAMP

# Perl
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

WANTLIB += c

RUN_DEPENDS =		devel/p5-PadWalker

pre-configure:
	@rm -f ${WRKSRC}/lib/Devel/Caller.pm.orig

.include <bsd.port.mk>
