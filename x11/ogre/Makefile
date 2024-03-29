# $OpenBSD$

SHARED_ONLY =		Yes

COMMENT-main =		3D rendering engine
COMMENT-samples =	3D rendering engine, demos

V =			1.7.4
DISTNAME =		ogre_src_v${V:S/./-/g}
PKGNAME-main =		ogre-${V}
PKGNAME-samples =	ogre-samples-${V}

MULTI_PACKAGES =	-main -samples

SHARED_LIBS +=  OgreMain                  0.0 # 1.7
SHARED_LIBS +=  OgrePaging                0.0 # 1.7
SHARED_LIBS +=  OgreProperty              0.0 # 1.7
SHARED_LIBS +=  OgreRTShaderSystem        0.0 # 1.7
SHARED_LIBS +=  OgreTerrain               0.0 # 1.7

CATEGORIES =		x11

HOMEPAGE =		http://www.ogre3d.org

MAINTAINER =		Pascal Stumpf <Pascal.Stumpf@cubes.de>

# MIT
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

WANTLIB += ICE SM X11 Xaw Xext Xt boost_date_time-mt
WANTLIB += boost_thread-mt c freeimage freetype m pthread stdc++
WANTLIB += z zzip

WANTLIB-main = ${WANTLIB} GL GLU Xrandr
WANTLIB-samples += ${WANTLIB} OIS OgreMain OgrePaging OgreRTShaderSystem
WANTLIB-samples += OgreTerrain


MASTER_SITES =		${MASTER_SITE_SOURCEFORGE:=ogre/}
EXTRACT_SUFX =		.tar.bz2

CONFIGURE_ARGS +=	-DOGRE_INSTALL_SAMPLES=1

VMEM_WARNING =		Yes

MODULES =		devel/cmake
LIB_DEPENDS =		graphics/freeimage \
			devel/boost \
			archivers/zziplib
LIB_DEPENDS-samples =	${LIB_DEPENDS} \
			devel/ois \
			x11/ogre,-main

NO_REGRESS =		Yes

.include <bsd.port.mk>
