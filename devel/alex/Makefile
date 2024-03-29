# $OpenBSD$

COMMENT =	lexical analyser generator for Haskell

DISTNAME =	alex-3.0.1
CATEGORIES =	devel

HOMEPAGE =	http://www.haskell.org/alex/

# BSD3
PERMIT_PACKAGE_CDROM =		Yes
PERMIT_PACKAGE_FTP =		Yes
PERMIT_DISTFILES_CDROM =	Yes
PERMIT_DISTFILES_FTP =		Yes

WANTLIB =		c gmp m pthread util

MODULES =		lang/ghc converters/libiconv
MODGHC_BUILD =          cabal hackage nort

# Required for building the documentation:
USE_GMAKE =		Yes
CONFIGURE_STYLE =	autoconf no-autoheader
AUTOCONF_VERSION =	2.61
AUTOCONF_DIR =		${WRKSRC}/doc
WRKCONF =		${AUTOCONF_DIR}

BUILD_DEPENDS +=	devel/hs-QuickCheck>=2 \
			textproc/docbook-xsl

LIB_DEPENDS =		devel/gmp

post-extract:
	@chmod -R a+r ${WRKSRC}

post-build:
	@cd ${WRKBUILD}/doc && exec ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} html

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc
	cd ${WRKBUILD}/doc && umask 022 && pax -rw alex ${PREFIX}/share/doc

# Skip the tokens_bytestring.x test, it's missing from the distfile.
do-regress:
	cd ${WRKBUILD}/tests && exec ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} \
		all TESTS="simple.x tokens.x tokens_posn.x tokens_gscan.x"

.include <bsd.port.mk>
