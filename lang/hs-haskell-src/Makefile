# $OpenBSD$

COMMENT =		manipulating Haskell source code

DISTNAME =		haskell-src-1.0.1.5
CATEGORIES =		lang devel

MAINTAINER =		Matthias Kilian <kili@openbsd.org>

# BSD3
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

MODULES =		lang/ghc

MODGHC_BUILD =		cabal hackage haddock register

BUILD_DEPENDS =		devel/happy \
			${RUN_DEPENDS}
RUN_DEPENDS=		devel/hs-syb

.include <bsd.port.mk>
