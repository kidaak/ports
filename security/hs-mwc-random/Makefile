# $OpenBSD$

COMMENT=		fast, high quality pseudo random number generation

DISTNAME=		mwc-random-0.10.0.1
CATEGORIES=		math security

# BSD3
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

MODULES=		lang/ghc

MODGHC_BUILD =          cabal hackage haddock register

RUN_DEPENDS =		devel/hs-primitive \
			devel/hs-vector>=0.6.0.2
BUILD_DEPENDS =		${RUN_DEPENDS}

.include <bsd.port.mk>
