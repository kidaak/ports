# $OpenBSD$

BROKEN-powerpc =	qdoc3 goes into an infinite loop

COMMENT =		cross-platform IDE for use with Qt

V = 			1.3.1
DISTNAME =		qt-creator-${V}-src
PKGNAME =		qt-creator-${V}
REVISION =		4
EXTRACT_SUFX = 		.zip
ONLY_FOR_ARCHS =	${GCC4_ARCHS}

SHARED_LIBS =		Aggregation 0.0 \
			CPlusPlus 0.0 \
			DebuggingHelper 0.0 \
			ExtensionSystem 0.0 \
			QtConcurrent 0.0 \
			Utils 0.0

MAKE_FLAGS += 	LIBAggregation_VERSION=${LIBAggregation_VERSION} \
		LIBCPlusPlus_VERSION=${LIBCPlusPlus_VERSION} \
		LIBDebuggingHelper_VERSION=${LIBDebuggingHelper_VERSION} \
		LIBExtensionSystem_VERSION=${LIBExtensionSystem_VERSION} \
		LIBQtConcurrent_VERSION=${LIBQtConcurrent_VERSION} \
		LIBUtils_VERSION=${LIBUtils_VERSION}

CATEGORIES =		devel editors

HOMEPAGE =		http://qt.nokia.com/products/appdev/developer-tools/developer-tools

# LGPL 2.1 with C++ headers exception (more permissive than LGPL)
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

WANTLIB +=	c m pthread stdc++ sqlite3
WANTLIB +=	QtDBus QtWebKit QtXmlPatterns QtDesigner>=7 
WANTLIB +=	QtDesignerComponents>=7 QtGui>=8 QtHelp QtNetwork>=7 
WANTLIB +=	QtScript QtSql>=7 QtSvg>=7 QtXml>=7 phonon
MASTER_SITES =	http://get.qt.nokia.com/qtcreator/

MODULES =	x11/qt4

RUN_DEPENDS = 	devel/gmake

PORTHOME =		${WRKDIR}

SEPARATE_BUILD =	Yes

ALL_TARGET = 		all qch_docs

#NO_REGRESS =		Yes

FAKE_FLAGS =		INSTALL_ROOT=${WRKINST}${TRUEPREFIX}

pre-configure:
	mkdir -p ${WRKDIR}/bin/tools/qdoc3
	mkdir -p ${WRKDIR}/bin/bin
	ln -sf ${PREFIX}/lib/qt4/bin/qdoc3 ${WRKDIR}/bin/tools/qdoc3
	ln -sf ${PREFIX}/lib/qt4/bin/qhelpgenerator ${WRKDIR}/bin/bin

do-configure:
	cd ${WRKBUILD} && QTDIR=${WRKDIR}/bin qmake4 ${WRKSRC}/qtcreator.pro #CONFIG+=debug

.include <bsd.port.mk>
