# $OpenBSD$

COMMENT =		Snap Haskell Web Framework Server

DISTNAME =		snap-server-0.8.1.1
CATEGORIES =		www
HOMEPAGE =		http://snapframework.com/

MAINTAINER =		Jim Razmus II <jim@openbsd.org>, \
			Matthias Kilian <kili@openbsd.org>

# BSD3
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

MODULES =		lang/ghc

MODGHC_BUILD =		cabal hackage haddock register

RUN_DEPENDS +=		devel/hs-binary>=0.5,<0.6 \
			devel/hs-blaze-builder>=0.2.1.4,<0.4 \
			devel/hs-blaze-builder-enumerator>=0.2.0,<0.3 \
			devel/hs-case-insensitive>=0.3,<0.5 \
			devel/hs-directory-tree>=0.10,<0.11 \
			devel/hs-enumerator>=0.4.15,<0.5 \
			devel/hs-MonadCatchIO-transformers>=0.2.1,<0.4 \
			devel/hs-murmur-hash>=0.1,<0.2 \
			devel/hs-mtl>=2,<3 \
			devel/hs-network>=2.3,<2.4 \
			devel/hs-PSQueue>=1.1,<1.2 \
			devel/hs-transformers>=0.2,<0.4 \
			devel/hs-text>=0.11,<0.12 \
			devel/hs-unix-compat>=0.2,<0.4 \
			devel/hs-vector>=0.7,<0.10 \
			devel/hs-vector-algorithms>=0.4,<0.6 \
			textproc/hs-attoparsec>=0.10,<0.11 \
			textproc/hs-attoparsec-enumerator>=0.3,<0.4 \
			textproc/hs-bytestring-nums \
			www/hs-snap-core>=0.8.1,<0.9
BUILD_DEPENDS +=	${RUN_DEPENDS}

.include <bsd.port.mk>
