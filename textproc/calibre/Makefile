# $OpenBSD$

COMMENT =		ebook management application

DISTNAME =		calibre-0.8.20
CATEGORIES =		textproc
MASTER_SITES =		${MASTER_SITE_SOURCEFORGE:=calibre/}
REVISION =		3

HOMEPAGE =		http://calibre-ebook.com/

# GPLv3
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

MODULES =		lang/python \
			x11/qt4

WANTLIB +=		ICE MagickCore MagickWand QtGui SM X11 Xext
WANTLIB +=		Xi Xinerama Xrender c chm fontconfig freetype
WANTLIB +=		icudata icui18n icuio icuuc m png poppler
WANTLIB +=		stdc++
WANTLIB +=		${MODPY_WANTLIB}

LIB_DEPENDS=		devel/chmlib \
			graphics/ImageMagick \
			graphics/png \
			print/poppler, \
			textproc/icu4c
RUN_DEPENDS =		devel/py-dateutil \
			devel/xdg-utils \
			graphics/ImageMagick \
			graphics/libwmf \
			graphics/py-Imaging \
			net/py-dnspython \
			print/poppler,,-qt4 \
			textproc/py-cssutils>=0.9.7 \
			textproc/py-lxml>=2.2.8 \
			textproc/py-pdf \
			www/py-beautifulsoup \
			www/py-CherryPy \
			www/py-mechanize \
			x11/py-qt4>=4.8.2p1 \
			www/py-mechanize \
			x11/gtk+2,-guic
BUILD_DEPENDS =		${RUN_DEPENDS}

CFLAGS +=		"-I${LOCALBASE}/include"
LDFLAGS +=		"-L${LOCALBASE}/lib"
MAKE_ENV +=		QMAKE="${LOCALBASE}/bin/qmake4" \
			LDFLAGS="${LDFLAGS}" \
			FC_INC_DIR="${X11BASE}/include" \
			FC_LIB_DIR="${X11BASE}/lib" \
			PNG_INC_DIR="`pkg-config --cflags libpng`" \
			PNG_LIB_DIR="`pkg-config --libs libpng`"

# Requires /sys filesystem for HW detection
MAKE_ENV +=		WITH_USB=no

WRKDIST =		${WRKDIR}/calibre
PORTHOME =		${WRKDIR}
NO_REGRESS = 		Yes
MODPY_SETUPTOOLS =	Yes

## setup.py doesn't like the options in our python module
MODPY_DISTUTILS_BUILD = 	build
MODPY_DISTUTILS_INSTALL =	install --prefix=${LOCALBASE} \
				--root=${PREFIX}

# There are 901 files that hard-code the python bin name
# Remove bundled cherrypy and pyPdf so it uses the system versions
pre-configure:
	cd ${WRKSRC} && (rm -rf src/cherrypy src/pyPdf ; \
		find . -name '*.py' -print0 | xargs -0 perl -pi -e \
		's,#!/usr/bin/env python(2)?,#!${MODPY_BIN},' )

do-install:
	${_MODPY_CMD} ${MODPY_DISTUTILS_INSTALL} ${MODPY_DISTUTILS_INSTALLARGS}
	chmod 755 ${PREFIX}/bin/calibre-mount-helper
	${INSTALL_DATA_DIR} ${PREFIX}/share/calibre/recipes
	cd ${WRKSRC}/recipes && find . -type f -exec \
	    ${INSTALL_DATA} {} ${PREFIX}/share/calibre/recipes/ \;

post-install:
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/lib/calibre
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/calibre


.include <bsd.port.mk>
