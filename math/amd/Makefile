# $OpenBSD$

COMMENT=	order a sparse matrix prior to Cholesky factorization

VERSION=	2.2.1
DISTNAME=	AMD-${VERSION}
PKGNAME=	${DISTNAME:L}
REVISION=	2
SHARED_LIBS=	amd	0.0 \
		amdf77	0.0

CATEGORIES=	math

HOMEPAGE=	http://www.cise.ufl.edu/research/sparse/amd/

# LGPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=	${HOMEPAGE}/
WRKDIST=	${WRKDIR}/AMD
WRKSRC=		${WRKDIST}/Source
MODULES=	fortran
MODFORTRAN_COMPILER = g77
BUILD_DEPENDS=	${MODFORTRAN_BUILD_DEPENDS} \
		math/ufconfig
RUN_DEPENDS=	math/ufconfig

MAKE_FILE=	${FILESDIR}/Makefile
MAKE_ENV=	SHLIB_MAJOR=${LIBamd_VERSION:R} \
		SHLIB_MINOR=${LIBamd_VERSION:E}
MAKE_FLAGS=	CSRC="${CSRC}"
MAKE_ENV_F77=	SHLIB_MAJOR=${LIBamdf77_VERSION:R} \
		SHLIB_MINOR=${LIBamdf77_VERSION:E} \
		PATH=${PORTPATH} \
		FC=${FC}
FAKE_FLAGS=	LIBDIR=${LOCALBASE}/lib DEBUGLIBS=no
CFLAGS+=	-I${WRKDIST}/Include -I${LOCALBASE}/include

CSRC=	aat 1 2 dump postorder post_tree defaults order control info \
	valid preprocess

pre-configure:
	@echo "#define DINT 1"  > ${WRKSRC}/di.c
	@echo "#define DLONG 1" > ${WRKSRC}/dl.c
.for s in ${CSRC}
	@cd ${WRKSRC} && cat di.c amd_${s}.c > amd_i_${s}.c
	@cd ${WRKSRC} && cat dl.c amd_${s}.c > amd_l_${s}.c
.endfor

post-build:
	cd ${WRKBUILD} && ${SETENV} ${MAKE_ENV_F77} ${MAKE_PROGRAM} \
		${MAKE_FLAGS} -f ${FILESDIR}/Makefile.f77 ${ALL_TARGET}

post-install:
	cd ${WRKBUILD} && ${SETENV} ${MAKE_ENV_F77} ${MAKE_PROGRAM} \
		${ALL_FAKE_FLAGS} -f ${FILESDIR}/Makefile.f77 ${INSTALL_TARGET}
	${INSTALL_DATA_DIR} ${PREFIX}/include/amd
	${INSTALL_DATA} ${WRKDIST}/Include/amd.h ${PREFIX}/include/amd

.include <bsd.port.mk>
