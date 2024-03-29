# $OpenBSD$

COMMENT=	load PNG graphics files and bind them to an OpenGL texture

VERSION=	1.45
DISTNAME=	glpng
PKGNAME=	${DISTNAME}-${VERSION}
REVISION =	3
SHARED_LIBS=	glpng 0.0
CATEGORIES=	graphics

EXTRACT_SUFX=	.zip

HOMEPAGE=	http://www.wyatt100.freeserve.co.uk/

# BSD-like
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=	${HOMEPAGE}

WANTLIB=	GL png>=5

LIB_DEPENDS=	graphics/png


REGRESS_IS_INTERACTIVE=	x11

REGRESS_DEPENDS=	graphics/freeglut

DIST_SUBDIR=	${DISTNAME}-${VERSION}
WRKDIST=	${WRKDIR}
WRKSRC=		${WRKDIST}/src

MAKE_FILE=	${FILESDIR}/Makefile
MAKE_ENV=	SHLIB_MAJOR=${LIBglpng_VERSION:R} \
		SHLIB_MINOR=${LIBglpng_VERSION:E}
FAKE_FLAGS=	LIBDIR=${LOCALBASE}/lib DEBUGLIBS=no
CFLAGS+=	-I${X11BASE}/include -I${LOCALBASE}/include \
			-I${WRKDIR}/include

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/glpng
	${INSTALL_DATA_DIR} ${PREFIX}/include/GL/
	${INSTALL_DATA} ${WRKDIR}/include/GL/glpng.h \
		${PREFIX}/include/GL
	${INSTALL_DATA} ${WRKDIR}/glpng.htm \
		${PREFIX}/share/doc/glpng/glpng.html

do-regress:
	cd ${WRKDIR}/Example \
	&& ${CC} ${CFLAGS} -o Test Test.c -lm -lz \
		-L${X11BASE}/lib -lGLU -lXi -lXmu \
		-L${LOCALBASE}/lib -lglut \
		-L${WRKBUILD} -lglpng \
	&& LD_LIBRARY_PATH=${WRKSRC} ./Test

.include <bsd.port.mk>
