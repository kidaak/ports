# $OpenBSD$

COMMENT =		web server for WAI applications

DISTNAME =		warp-1.2.2
CATEGORIES =		devel www
HOMEPAGE =		http://github.com/snoyberg/warp

MAINTAINER =		Matthias Kilian <kili@openbsd.org>

# BSD3
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

MODULES =		lang/ghc

MODGHC_BUILD =		cabal hackage haddock register

BUILD_DEPENDS =		${RUN_DEPENDS}
RUN_DEPENDS =		devel/hs-blaze-builder>=0.2.1.4,<0.4 \
			devel/hs-blaze-builder-conduit>=0.4,<0.5 \
			devel/hs-case-insensitive>=0.2 \
			devel/hs-conduit>=0.4,<0.5 \
			devel/hs-enumerator>=0.4.8,<0.5 \
			devel/hs-lifted-base>=0.1,<0.2 \
			devel/hs-network>=2.3,<2.4 \
			devel/hs-network-conduit>=0.4,<0.5 \
			devel/hs-simple-sendfile>=0.2.4,<0.3 \
			devel/hs-transformers>=0.2.2,<0.4 \
			devel/hs-unix-compat>=0.2 \
			www/hs-http-types>=0.6,<0.7 \
			www/hs-wai>=1.2,<1.3

.include <bsd.port.mk>
