# $OpenBSD$

SHARED_ONLY =		Yes

COMMENT =		expose the flag which marks global destruction

DISTNAME =		Devel-GlobalDestruction-0.03
REVISION =		0
CATEGORIES =		devel

# perl
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =	Yes
PERMIT_DISTFILES_FTP =	Yes

WANTLIB += c

MODULES =		cpan
USE_GROFF =		Yes

RUN_DEPENDS =		devel/p5-Scope-Guard \
			devel/p5-Sub-Exporter

.include <bsd.port.mk>
