# $OpenBSD$

# vax:	no fenv.h support
NOT_FOR_ARCHS =		vax

COMMENT =		Computational Geometry Algorithms Library

DISTNAME =		CGAL-3.8
PKGNAME =		${DISTNAME:L}
REVISION =		2

SHARED_ONLY =		Yes
SHARED_LIBS =		CGAL		0.0 \
			CGAL_Core	0.0 \
			CGAL_ImageIO	0.0 \
			CGAL_Qt4	0.0 

CATEGORIES =		math

HOMEPAGE =		http://www.cgal.org/

# mix of LGPLv2.1 and QPL; see http://www.cgal.org/license.html
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

# m>=5.3 for fenv.h support
WANTLIB =		GL GLU ICE SM X11 Xext boost_thread-mt gmp gmpxx \
			lib/qt4/QtGui lib/qt4/QtOpenGL m>=5.3 mpfr stdc++ z

# Awkward hosting site; see https://gforge.inria.fr/frs/?group_id=52 for files index.
MASTER_SITES =		https://gforge.inria.fr/frs/download.php/28500/

MODULES =		devel/cmake \
			x11/qt4
LIB_DEPENDS =		devel/boost \
			devel/gmp \
			devel/mpfr

CFLAGS +=		-I${X11BASE}/include

CONFIGURE_ARGS +=	-DCGAL_INSTALL_MAN_DIR="man/man1"
CONFIGURE_ENV =		LDFLAGS="-L${X11BASE}/lib"

post-patch:
	rm ${WRKSRC}/cmake/modules/FindBLAS.cmake \
	   ${WRKSRC}/cmake/modules/FindBoost.cmake \
	   ${WRKSRC}/cmake/modules/FindLAPACK.cmake \
	   ${WRKSRC}/cmake/modules/FindOpenGL.cmake \
	   ${WRKSRC}/cmake/modules/FindPackageMessage.cmake \
	   ${WRKSRC}/scripts/cgal_make_macosx_app

.include <bsd.port.mk>
