# $OpenBSD$

COMMENT =		Haskell integration with Parrot virtual machine

DISTNAME =		HsParrot-0.0.2.20110925
CATEGORIES =		lang devel

# MIT (see comment in HsParrot.cabal)
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

MODULES =		lang/ghc
MODGHC_BUILD =		cabal hackage haddock register

BUILD_DEPENDS =		${RUN_DEPENDS}
RUN_DEPENDS =		devel/hs-HsSyck \
			devel/hs-pugs-DrIFT

.include <bsd.port.mk>
