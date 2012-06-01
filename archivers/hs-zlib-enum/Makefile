# $OpenBSD$

COMMENT =		enumerator interface for zlib compression

DISTNAME =		zlib-enum-0.2.1
CATEGORIES =		archivers devel

# BSD3
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

MODULES =		lang/ghc

MODGHC_BUILD =		cabal hackage haddock register

RUN_DEPENDS =		archivers/hs-zlib-bindings \
			devel/hs-enumerator>=0.4 \
			devel/hs-transformers>=0.2,<0.3
BUILD_DEPENDS =		${RUN_DEPENDS}

.include <bsd.port.mk>
