# $OpenBSD$

BROKEN-powerpc =CPUCore.cc:2347: error: insn does not satisfy its constraints

COMMENT =	MSX home computer emulator

DISTNAME =	openmsx-0.8.2

CATEGORIES =	emulators

HOMEPAGE =	http://openmsx.sourceforge.net/

PERMIT_PACKAGE_CDROM =	claims GPLv2, but no copyright notices in source files
PERMIT_PACKAGE_FTP =	claims GPLv2, but no copyright notices in source files
PERMIT_DISTFILES_CDROM =claims GPLv2, but no copyright notices in source files
PERMIT_DISTFILES_FTP =	claims GPLv2, but no copyright notices in source files

MASTER_SITES =		${MASTER_SITE_SOURCEFORGE:=openmsx/}
CONFIGURE_STYLE =	simple

MAKE_ENV +=	INSTALL_BASE=${PREFIX}/share/openmsx \
		INSTALL_BINARY_DIR=${PREFIX}/bin \
		INSTALL_SHARE_DIR=${PREFIX}/share/openmsx \
		INSTALL_DOC_DIR=${PREFIX}/share/doc/openmsx

WANTLIB +=	GL c freetype m pthread stdc++ z ${MODTCL_LIB} ao
WANTLIB +=	GLEW SDL SDL_ttf ogg png theoradec vorbis xml2

LIB_DEPENDS =	audio/libao \
		audio/libvorbis \
		devel/sdl-ttf \
		graphics/glew \
		graphics/png \
		multimedia/libtheora \
		textproc/libxml \
		${MODTCL_LIB_DEPENDS}

NO_REGRESS =	Yes

MODULES =	converters/libiconv \
		lang/python \
		lang/tcl

MODPY_RUNDEP =	No
MAKE_FILE =	GNUmakefile
USE_GMAKE =	Yes

MAKE_FLAGS =	CC="${CC}" CXX="${CXX}" CFLAGS="${CFLAGS}" \
		CXXFLAGS="${CXXFLAGS}"

pre-configure:
	${SUBST_CMD} ${WRKSRC}/build/python-search.sh

.include <bsd.port.mk>
