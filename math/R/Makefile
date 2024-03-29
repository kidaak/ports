# $OpenBSD$

SHARED_ONLY=	Yes

COMMENT=	powerful math/statistics/graphics language
DISTNAME=	R-2.15.1
REVISION=	3

SHARED_LIBS=	R	0.0  \
		Rlapack	30.0 \
		Rblas	30.0

CATEGORIES=	math
HOMEPAGE=	http://www.r-project.org/

MAINTAINER=	Rafael Sadowski <rafael@sizeofvoid.org>

# GPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB=	GL ICE SM X11 Xext Xmu Xrender Xss Xt \
		bz2 c cairo expat fontconfig freetype glib-2.0 \
		gobject-2.0 icui18n icuuc jpeg lzma m ncurses \
		pango-1.0 pangocairo-1.0 pangoft2-1.0 pcre \
		pixman-1 png pthread pthread-stubs readline \
		tiff xcb xcb-render xcb-shm z \
		${MODFORTRAN_WANTLIB} ${MODTK_WANTLIB}

MASTER_SITES=	http://cran.r-project.org/src/base/R-2/ \
		ftp://cran.r-project.org/pub/R/src/base/R-2/ \
		http://cran.at.r-project.org/src/base/R-2/ \
		http://cran.au.r-project.org/src/base/R-2/ \
		http://cran.br.r-project.org/src/base/R-2/ \
		http://cran.ch.r-project.org/src/base/R-2/ \
		http://cran.es.r-project.org/src/base/R-2/ \
		http://cran.dk.r-project.org/src/base/R-2/ \
		http://cran.hu.r-project.org/src/base/R-2/ \
		http://cran.uk.r-project.org/src/base/R-2/ \
		http://cran.us.r-project.org/src/base/R-2/ \
		http://cran.za.r-project.org/src/base/R-2/ \
		ftp://ftp.u-aizu.ac.jp/pub/lang/R/CRAN/src/base/R-2/ \
		http://lib.stat.cmu.edu/R/CRAN/src/base/R-2/ \
		http://cran.stat.ucla.edu/src/base/R-2/ \
		http://probability.ca/cran/src/base/R-2/

MODULES=	fortran devel/gettext x11/tk
MODFORTRAN_COMPILER= g77

BUILD_DEPENDS=	${MODFORTRAN_BUILD_DEPENDS} \
		${RUN_DEPENDS}
LIB_DEPENDS=	${MODFORTRAN_LIB_DEPENDS} \
		${MODTK_LIB_DEPENDS} \
		archivers/bzip2 \
		archivers/xz \
		graphics/cairo \
		graphics/jpeg \
		devel/glib2 \
		devel/pango \
		graphics/png \
		graphics/tiff \
		textproc/icu4c
RUN_DEPENDS=	archivers/gtar \
		devel/xdg-utils

CONFIGURE_STYLE=gnu
MODGNU_CONFIG_GUESS_DIRS=${WRKSRC}/tools
CONFIGURE_ARGS= ${CONFIGURE_SHARED} \
		--enable-prebuilt-html \
		--enable-R-shlib \
		--enable-BLAS-shlib \
		--with-ICU \
		--with-readline \
		--with-tcltk \
		--with-cairo \
		--with-jpeglib \
		--with-libpng \
		--with-system-zlib \
		--with-system-bzlib \
		--with-system-pcre \
		--with-tcl-config=${MODTCL_CONFIG} \
		--with-tk-config=${MODTK_CONFIG}

CONFIGURE_ENV=	FFLAGS="${FFLAGS}" \
		ac_cv_path_TAR="${LOCALBASE}/bin/gtar"

MAKE_FLAGS=	INSTALL_DATA='install -c -m 644' \
		INSTALL_PROGRAM='install -c -s -m 555' \
		INSTALL_SCRIPT='install -c -m 555' \
		LIBR_VERSION=${LIBR_VERSION} \
		LIBRlapack_VERSION=${LIBRlapack_VERSION} \
		LIBRblas_VERSION=${LIBRblas_VERSION}

FAKE_FLAGS=	PREFIX=${PREFIX} \
		INSTALL="${INSTALL_DATA}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}"

SEPARATE_BUILD=	Yes

VMEM_WARNING=	Yes

post-install:
	@perl -i -pe 's:^R_HOME_DIR=.*:R_HOME_DIR=${TRUEPREFIX}/lib/R:' \
		${PREFIX}/bin/R

.include <bsd.port.mk>
