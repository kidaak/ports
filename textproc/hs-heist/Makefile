# $OpenBSD$

COMMENT =		xhtml templating system

DISTNAME =		heist-0.8.1.1
CATEGORIES =		textproc

MAINTAINER =		Jim Razmus II <jim@openbsd.org>, \
			Matthias Kilian <kili@openbsd.org>

# BSD3
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

MODULES =		lang/ghc

MODGHC_BUILD =		cabal hackage haddock register

RUN_DEPENDS +=		devel/hs-MonadCatchIO-transformers>=0.2.1,<0.4 \
			devel/hs-aeson>=0.6,<0.7 \
			devel/hs-blaze-builder>=0.2,<0.4 \
			devel/hs-directory-tree \
			devel/hs-mtl>=2.0,<2.2 \
			devel/hs-random \
			devel/hs-text>=0.10,<0.12 \
			devel/hs-transformers \
			devel/hs-unordered-containers>=0.1.4,<0.3 \
			devel/hs-vector>=0.9,<0.10 \
			textproc/hs-attoparsec>=0.10,<0.11 \
			textproc/hs-blaze-html>=0.4,<0.6 \
			textproc/hs-xmlhtml>=0.1.6,<0.3
BUILD_DEPENDS +=	${RUN_DEPENDS}

.include <bsd.port.mk>
