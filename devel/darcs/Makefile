# $OpenBSD$

COMMENT =		advanced revision control system written in Haskell

DISTNAME =		darcs-2.8.1

CATEGORIES =		devel
HOMEPAGE =		http://www.darcs.net/

WANTLIB =		c curl>=2 gmp m ncursesw pthread util z
MODULES =		lang/ghc converters/libiconv
MODGHC_BUILD =		cabal hackage nort
MODGHC_SETUP_CONF_ARGS =-f 'curl -http -library test'
LIB_DEPENDS =		devel/gmp \
			net/curl

# Yes, build dependencies, because GHC libs are still static and we
# don't want to pull in all of ghc.
BUILD_DEPENDS =		archivers/hs-zlib>=0.5.1.0,<0.6.0.0 \
			devel/hs-tar>=0.3,<0.4 \
			devel/hs-hashed-storage>=0.5.6,<0.6 \
			devel/hs-haskeline>=0.6.3,<0.7 \
			devel/hs-mmap>=0.5,<0.6 \
			devel/hs-mtl>=1.0,<2.2 \
			devel/hs-network>=2.2,<2.4 \
			devel/hs-parsec>=2.0,<3.2 \
			devel/hs-regex-compat=0.95.1 \
			devel/hs-terminfo>=0.3,<0.4 \
			devel/hs-text>=0.11.0.6,<0.12.0.0 \
			devel/hs-vector>=0.7 \
			www/hs-html>=1.0,<1.1 \
			print/texlive/texmf,-full \
 			textproc/latex2html \
			${RUN_DEPENDS}

# Used for building the test suite (which is done during normal
# build time, not during regress time).
BUILD_DEPENDS +=	devel/hs-QuickCheck>=2.3 \
			devel/hs-HUnit>=1.0 \
			devel/hs-cmdlib>=0.2.1,<0.4 \
			devel/hs-shellish>=0.1.3,<0.2 \
			devel/hs-test-framework>=0.4.0 \
			devel/hs-test-framework-hunit>=0.2.2 \
			devel/hs-test-framework-quickcheck2>=0.2.8

REGRESS_DEPENDS =	devel/hs-hlint \
			shells/bash \
			sysutils/coreutils \
			textproc/gsed

# For the documentation
USE_GMAKE =		Yes
PORTHOME =		${WRKDIR}

post-build:
	@cd ${WRKBUILD} && exec ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} html

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/darcs
	cd ${WRKBUILD}/doc/manual && umask 022 && pax -rw . ${PREFIX}/share/doc/darcs
	# Wrong directory, and wrong permissions (600):
	rm -rf ${PREFIX}/share/man
	${INSTALL_MAN_DIR} ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKBUILD}/dist/build/darcs/darcs.1 ${PREFIX}/man/man1

# Some of the tests rely on GNU functionality.
pre-regress:
	ln -fs ${LOCALBASE}/bin/gdate ${WRKDIR}/bin/date
	ln -fs ${LOCALBASE}/bin/gsed ${WRKDIR}/bin/sed

# GPLv2
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

.include <bsd.port.mk>
