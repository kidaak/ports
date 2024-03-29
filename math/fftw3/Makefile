# $OpenBSD$

COMMENT-main=	C routines for computing the Discrete Fourier Transform
COMMENT-common=	common files for the fftw3 packages

V=		3.2.2
DISTNAME=	fftw-${V}
PKGNAME=	fftw3-${V}
FULLPKGNAME-main=	fftw3-${V}
# XXX set it to its default value so that bsd.port.mk won't whine
FULLPKGPATH-main=	math/fftw3,-main${FLAVOR_EXT:S/-/,/g}
FULLPKGNAME-common=	fftw3-common-${V}
REVISION-main=	0
REVISION-common=0
SHARED_LIBS=	fftw3	5.0 \
		fftw3f	5.0
CATEGORIES=	math

HOMEPAGE=	http://www.fftw.org/

# GPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=	ftp://ftp.fftw.org/pub/fftw/ \
		http://fftw.mirror.fr/ \
		ftp://ftp.fftw.org/pub/fftw/old/

SEPARATE_BUILD=	Yes

MULTI_PACKAGES=	-main -common

FLAVORS=	double float
FLAVOR?=	double

USE_GMAKE=	Yes
USE_LIBTOOL=	Yes
USE_GROFF =	Yes
CONFIGURE_STYLE=gnu
CONFIGURE_ARGS=	${CONFIGURE_SHARED} \
		--enable-portable-binary

.if ${FLAVOR} == "float"
CONFIGURE_ARGS+=--enable-float
FULLPKGNAME-main=	fftw3-float-${V}
.endif

FULLPKGPATH-common=	math/fftw3,-common
RUN_DEPENDS-main=	${FULLPKGPATH-common}
WANTLIB-main=		c m
PKG_ARCH-common=	*

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/fftw3
	${INSTALL_DATA} ${WRKSRC}/doc/fftw3.pdf ${PREFIX}/share/doc/fftw3

.include <bsd.port.mk>
