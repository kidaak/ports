# $OpenBSD$

COMMENT =		Snap Haskell Web Framework

DISTNAME =		snap-core-0.8.1
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


RUN_DEPENDS +=		archivers/hs-zlib-enum>=0.2.1,<0.3 \
			devel/hs-HUnit>=1.2,<2 \
			devel/hs-base16-bytestring>=0,<=0.2 \
			devel/hs-blaze-builder>=0.2.1.4,<0.4 \
			devel/hs-blaze-builder-enumerator>=0.2,<0.3 \
			devel/hs-bytestring-mmap>=0.2.2,<0.3 \
			devel/hs-case-insensitive>=0.3,<0.5 \
			devel/hs-dlist>=0.5,<0.6 \
			devel/hs-enumerator>=0.4.15,<0.5 \
			devel/hs-MonadCatchIO-transformers>=0.2.1,<0.4 \
			devel/hs-mtl>=2.0,<2.2 \
			devel/hs-regex-posix>=0,<=0.95.2 \
			devel/hs-text>=0.11,<0.12 \
			devel/hs-transformers>=0.2,<0.4 \
			devel/hs-unix-compat>=0.2,<0.4 \
			devel/hs-unordered-containers>=0.1.4.3,<0.3 \
			devel/hs-vector>=0.6,<0.10 \
			security/hs-mwc-random>=0.10,<0.13 \
			textproc/hs-attoparsec>=0.10,<0.11 \
			textproc/hs-attoparsec-enumerator>=0.3,<0.4 \
			textproc/hs-bytestring-nums \
			textproc/hs-bytestring-show
BUILD_DEPENDS +=	${RUN_DEPENDS}

.include <bsd.port.mk>
