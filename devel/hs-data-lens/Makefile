# $OpenBSD$

COMMENT =		Haskell 98 lenses

DISTNAME =		data-lens-2.9.0
CATEGORIES =		devel

# BSD3
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

MODULES =		lang/ghc

MODGHC_BUILD =		cabal hackage haddock register

RUN_DEPENDS =		devel/hs-comonad>=1.1.1.3,<1.2 \
			devel/hs-comonad-transformers>=2.0,<2.2 \
			devel/hs-contravariant>=0.2.0.1,<0.3 \
			devel/hs-distributive>=0.2.1,<0.3 \
			devel/hs-semigroupoids>=1.2.4,<1.4 \
			devel/hs-transformers>=0.2.0,<0.4
BUILD_DEPENDS =		${RUN_DEPENDS}

.include <bsd.port.mk>
