# $OpenBSD$

# This port is not wired to the build by intention. It's not even
# meant to be built, because it's just a helper port to avoid
# downloading that huge distfile if you only want to build lilypond
# and not run the regression tests.

COMMENT =		data for lilypond regression tests

DISTNAME =		lilypond-test-baseline-2.14.1

CATEGORIES =		print

MAINTAINER =		Matthias Kilian <kili@openbsd.org>

# GPLv2 (snippets from and data created with lilypond)
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

# Currently rolled by my own, but I'll ask the lilypond developers
# to publish the test-baseline together with sources and documentation
# for future releases.
MASTER_SITES =		http://openbsd.dead-parrot.de/distfiles/

EXTRACT_SUFX =		.tar.bz2

PLIST = 		/dev/null
NO_BUILD =		Yes
NO_REGRESS =		Yes

.include <bsd.port.mk>
