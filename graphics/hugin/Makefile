# $OpenBSD$

VMEM_WARNING =		Yes
SHARED_ONLY =		Yes

COMMENT =		panorama image stitcher

DISTNAME =		hugin-2011.0.0
REVISION=		0
EXTRACT_SUFX =		.tar.bz2

# not needed for releases, but makes RCs/betas easier to work with
PKGNAME =		${DISTNAME:S/_//:L}
WRKDIST =		${WRKDIR}/${DISTNAME:C/_.*//}

SHARED_LIBS +=  huginbasewx               0.0
SHARED_LIBS +=  celeste                   0.0
SHARED_LIBS +=  huginANN                  0.0
SHARED_LIBS +=  huginbase                 1.0
SHARED_LIBS +=  huginvigraimpex           0.0
SHARED_LIBS +=  icpfindlib                0.0
SHARED_LIBS +=  localfeatures             0.0
SHARED_LIBS +=  makefilelib               0.0

CATEGORIES =		graphics x11

HOMEPAGE =		http://hugin.sourceforge.net/

MAINTAINER =		Stuart Henderson <sthen@openbsd.org>

# GPLv2+
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

WANTLIB += GL GLEW GLU Half Iex Imath IlmImf IlmThread ICE SM X11
WANTLIB += Xext Xi Xmu boost_date_time-mt boost_filesystem-mt
WANTLIB += boost_iostreams-mt boost_regex-mt boost_signals-mt
WANTLIB += boost_system-mt boost_thread-mt c exiv2 glut>=4.1
WANTLIB += jpeg m pano13>=2.0 png pthread stdc++ tiff wx_base
WANTLIB += wx_base_net wx_base_xml wx_gtk2_adv wx_gtk2_aui
WANTLIB += wx_gtk2_core wx_gtk2_gl wx_gtk2_html wx_gtk2_xrc z

MASTER_SITES =		${MASTER_SITE_SOURCEFORGE:=hugin/}

RUN_DEPENDS =		devel/desktop-file-utils \
			graphics/enblend-enfuse \
			graphics/p5-Image-ExifTool \
			devel/gmake # yes, really a RUN_DEPENDS
LIB_DEPENDS =		devel/boost \
			graphics/exiv2>=0.12 \
			graphics/glew \
			graphics/freeglut \
			graphics/ilmbase \
			graphics/jpeg \
			graphics/libpano13>=2.9.18beta1 \
			graphics/openexr \
			graphics/png \
			graphics/tiff \
			x11/wxWidgets>=2.7

USE_GROFF =		Yes
MODULES +=		devel/cmake
SEPARATE_BUILD =	Yes
CONFIGURE_STYLE =	cmake
CONFIGURE_ENV =		MANDIR=man
NO_REGRESS =		Yes
CFLAGS +=		-pthread
LDFLAGS +=		-L${X11BASE}/lib

pre-patch:
	find ${WRKSRC} -name '*.orig' | xargs rm
	cd ${WRKSRC}/CMakeModules; perl -i -pe 's/\r$$//' `find . -type f` \
	    ../src/CMakeLists.txt

pre-configure:
	${SUBST_CMD} ${WRKSRC}/CMakeModules/FindPNG.cmake \
	    ${WRKSRC}/CMakeModules/FindGLEW.cmake

.include <bsd.port.mk>
