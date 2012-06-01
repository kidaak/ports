# $OpenBSD$

COMMENT=		fast HTML combinator library

DISTNAME=		blaze-html-0.4.1.6
CATEGORIES=		textproc

# BSD3
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

MODULES=		lang/ghc

MODGHC_BUILD =          cabal hackage haddock register

RUN_DEPENDS =		devel/hs-blaze-builder \
			devel/hs-text

BUILD_DEPENDS = 	${RUN_DEPENDS}

.include <bsd.port.mk>
