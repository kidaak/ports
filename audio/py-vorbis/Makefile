# $OpenBSD$

SHARED_ONLY =	Yes

COMMENT =	Python wrapper for the Vorbis libraries

MODPY_EGG_VERSION=1.4
DISTNAME =	pyvorbis-${MODPY_EGG_VERSION}
PKGNAME =	${DISTNAME:S/py/py-/}
REVISION =	3
CATEGORIES =	audio
HOMEPAGE =	http://ekyo.nerim.net/software/pyogg/

# LGPL 
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

MASTER_SITES =	${HOMEPAGE}

WANTLIB =	ogg vorbis vorbisenc vorbisfile ${MODPY_WANTLIB}

MODULES =	lang/python

BUILD_DEPENDS =	audio/py-ogg

LIB_DEPENDS =	audio/libogg \
		audio/libvorbis

RUN_DEPENDS =	audio/py-ao \
		audio/py-ogg

NO_REGRESS =	Yes

MODPY_ADJ_FILES =	test/comment.py \
			test/enc.py \
			test/enc2.py \
			test/ogg123.py \
			test/short.py

EXAMPLESDIR =	${PREFIX}/share/examples/py-vorbis

do-configure:
	@cd ${WRKSRC} && ${MODPY_BIN} ./config_unix.py --prefix ${PREFIX} 

post-install:
	${INSTALL_DATA_DIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/test/*.py ${EXAMPLESDIR}

.include <bsd.port.mk>
