# $OpenBSD$

COMMENT =		stream socket data using conduits

DISTNAME =		network-conduit-0.4.0.1
CATEGORIES =		devel

MAINTAINER =		Matthias Kilian <kili@openbsd.org>

# BSD3
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

MODULES =		lang/ghc

MODGHC_BUILD =		cabal hackage haddock register

BUILD_DEPENDS =		${RUN_DEPENDS}

RUN_DEPENDS =		devel/hs-conduit>=0.4,<0.5 \
			devel/hs-lifted-base>=0.1,<0.2 \
			devel/hs-monad-control>=0.3,<0.4 \
			devel/hs-network>=2.3,<2.4 \
			devel/hs-transformers>=0.2.2,<0.4



.include <bsd.port.mk>
