# $OpenBSD$

SHARED_ONLY=	Yes

COMMENT-main=	python Qt4 bindings
COMMENT-docs=	py-qt4 documentation

# XXX: Upstream doesn't keep old files; if updating please mirror or ask sthen@
V=		4.8.4
DISTNAME=	PyQt-x11-gpl-${V}
PKGNAME=	py-qt4-${V}
PKGNAME-main=	py-qt4-${V}
PKGNAME-docs=	py-qt4-docs-${V}
EPOCH=		0

REVISION-main=	2
REVISION-docs=	0

CATEGORIES=	x11 devel

HOMEPAGE=	http://www.riverbankcomputing.co.uk/software/pyqt/intro

# GPLv2 or v3 with exceptions for use with certain named open-source licenses
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB += GL GLU X11 Xext c dbus-1 m pthread stdc++ 
WANTLIB += QtDeclarative QtDesigner QtGui QtHelp QtNetwork QtOpenGL
WANTLIB += QtScript QtSql QtSvg QtTest QtWebKit QtXml QtXmlPatterns
WANTLIB += ${MODPY_WANTLIB}

MULTI_PACKAGES=	-main -docs

WANTLIB-docs=
LIB_DEPENDS-docs=
RUN_DEPENDS-docs=
PKG_ARCH-docs=	*

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	devel/py-sip>=4.12.2 \
		x11/dbus-python
LIB_DEPENDS=	${MODQT4_LIB_DEPENDS}>=4.7.2 \
		${MODPY_LIB_DEPENDS}

NO_REGRESS=	Yes

MASTER_SITES=	http://www.riverbankcomputing.co.uk/static/Downloads/PyQt4/ \
		http://spacehopper.org/mirrors/ \
		http://distfiles.nl/

MODULES=	devel/gettext \
		lang/python \
		x11/qt4

CONFIGURE_STYLE=simple
CONFIGURE_SCRIPT=${MODPY_BIN} configure.py
CONFIGURE_ARGS=	--verbose \
		--qmake="${LOCALBASE}/bin/qmake4" \
		--bindir="${PREFIX}/bin" \
		--destdir="${MODPY_SITEPKG}" \
		--sipdir="${PREFIX}/share/sip" \
		--vendorid-incdir="${MODPY_INCDIR}" \
		--vendorid-libdir="${MODPY_LIBDIR}" \
		--no-qsci-api \
		INCDIR_QT=${MODQT_INCDIR} \
		LIBDIR="${X11BASE}/lib ${LOCALBASE}/lib" \
		LIBDIR_QT=${MODQT_LIBDIR} \
		CC=${CC} \
		CXX=${CXX} \
		CFLAGS="${CFLAGS}" \
		CXXFLAGS="${CXXFLAGS}"
FAKE_FLAGS=	INSTALL_ROOT=${DESTDIR}
CONFIGURE_ENV=	LOCALBASE=${LOCALBASE}

PYQTMODS=	QtAssistant QtCore QtDeclarative QtDesigner QtGui QtHelp \
		QtNetwork QtOpenGL QtScript QtSql QtSvg QtTest QtWebKit \
		QtXml QtXmlPatterns

.for i in ${PYQTMODS}
CONFIGURE_ARGS+=--enable=${i}
.endfor

MODPY_MAJOR=${MODPY_VERSION:C/\..*//}
# the distfile has pyuic for both python 2 and 3, normally both are
# installed and they're selected at runtime. this breaks bytecode
# compilation for package generation, so just rm the wrong files.
pre-configure:
.if ${MODPY_MAJOR:M3}
	rm -r ${WRKSRC}/pyuic/uic/port_v2
.else
	rm -r ${WRKSRC}/pyuic/uic/port_v3
.endif

post-install:
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py ${WRKINST}/${MODPY_SITEPKG}
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/py-qt4
	cp -R ${WRKSRC}/doc/* ${PREFIX}/share/doc/py-qt4
	chown -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/doc/py-qt4/*

.include <bsd.port.mk>
