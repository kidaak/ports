# $OpenBSD$

COMMENT =	3D creation software
BROKEN-sparc64 = error: cast from 'ccl::uchar*' to 'CUdeviceptr' loses precision

DISTNAME =	blender-2.63a

CATEGORIES =	graphics

HOMEPAGE =	http://www.blender.org/

MAINTAINER =	Pascal Stumpf <Pascal.Stumpf@cubes.de>

VMEM_WARNING =	Yes

# GPLv2+
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

MASTER_SITES =	http://download.blender.org/source/ \
		http://mirror.cs.umn.edu/blender.org/source/

MODULES =	devel/cmake \
		lang/python \
		devel/gettext
MODPY_VERSION = ${MODPY_DEFAULT_VERSION_3}

CONFIGURE_ARGS =	-DPYTHON_LIBRARY="${LOCALBASE}/lib/libpython${MODPY_VERSION}m.so" \
			-DPYTHON_INCLUDE_DIR="${MODPY_INCDIR}" \
			-DPYTHON_VERSION=${MODPY_VERSION} \
			-DWITH_BUILTIN_GLEW=OFF \
			-DWITH_CODEC_FFMPEG=ON

BUILD_DEPENDS =	devel/gflags
LIB_DEPENDS =	graphics/png \
		graphics/jpeg \
		graphics/glew \
		graphics/openexr \
		graphics/tiff \
		devel/boost \
		devel/sdl \
		audio/openal \
		graphics/openjpeg \
		graphics/ffmpeg>=20111126 \
		graphics/openimageio \
		${MODPY_LIB_DEPENDS}
RUN_DEPENDS =	devel/desktop-file-utils \
		x11/gnome/librsvg

WANTLIB += GL GLEW GLU Half Iex IlmImf IlmThread Imath OpenImageIO
WANTLIB += SDL X11 Xi Xxf86vm avcodec avdevice avformat avutil
WANTLIB += boost_filesystem-mt boost_regex-mt boost_system-mt
WANTLIB += boost_thread-mt c freetype jpeg m openal openjpeg png
WANTLIB += pthread ${MODPY_WANTLIB} stdc++ swscale tiff util z

NO_REGRESS =	Yes

CFLAGS +=	-I${LOCALBASE}/include -I${X11BASE}/include -pthread

MODPY_ADJ_FILES =	release/bin/blender-thumbnailer.py \
			release/scripts/modules/blend_render_info.py

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/blender ${PREFIX}/bin
	${SUBST_CMD} ${PREFIX}/bin/blender
	${INSTALL_PROGRAM} ${WRKBUILD}/bin/blender ${PREFIX}/bin/blender-bin
	${INSTALL_SCRIPT} ${WRKSRC}/release/bin/blender-thumbnailer.py \
		${PREFIX}/bin/blender-thumbnailer
	${INSTALL_DATA_DIR} ${PREFIX}/share/blender/scripts
	${INSTALL_DATA_DIR} ${PREFIX}/share/blender/datafiles
	cd ${WRKSRC}/release/scripts && pax -rw . \
		${PREFIX}/share/blender/scripts
	${INSTALL_DATA_DIR} ${PREFIX}/share/blender/scripts/addons/cycles
	cd ${WRKSRC}/intern/cycles/blender/addon && pax -rw . \
		${PREFIX}/share/blender/scripts/addons/cycles
	cd ${WRKSRC}/release/datafiles && pax -rw . \
		${PREFIX}/share/blender/datafiles
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/blender
	${INSTALL_DATA} ${WRKSRC}/release/text/*license* \
		${PREFIX}/share/doc/blender
	${INSTALL_DATA} ${WRKSRC}/release/text/copy* \
		${PREFIX}/share/doc/blender
	${INSTALL_DATA_DIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/release/freedesktop/blender.desktop \
		${PREFIX}/share/applications
	${INSTALL_DATA_DIR} ${PREFIX}/share/pixmaps
	${INSTALL_DATA} \
		${WRKSRC}/release/freedesktop/icons/scalable/apps/blender.svg \
		${PREFIX}/share/pixmaps
	${INSTALL_MAN} ${WRKSRC}/doc/manpage/blender.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
