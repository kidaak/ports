# $OpenBSD$

COMMENT =		HTML/XML parsing library

DISTNAME =		tagsoup-0.12.4
CATEGORIES =		devel textproc
HOMEPAGE =		http://community.haskell.org/~ndm/tagsoup/

MAINTAINER =		Matthias Kilian <kili@openbsd.org>

# BSD3
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

MODULES =		lang/ghc

MODGHC_BUILD =		cabal hackage haddock register

MODGHC_SETUP_CONF_ARGS =	-f download

BUILD_DEPENDS =		${RUN_DEPENDS}
RUN_DEPENDS =		devel/hs-mtl \
			devel/hs-network \
			devel/hs-text

.include <bsd.port.mk>
