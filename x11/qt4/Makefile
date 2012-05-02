# $OpenBSD: ports/x11/qt4/Makefile,v 1.96 2012/03/29 13:39:01 sthen Exp $

USE_GMAKE =		Yes
COMMENT-debug =		C++ GUI toolkit, debug
COMMENT-main =		C++ X11 GUI toolkit
COMMENT-examples =	examples for qt4
COMMENT-html =		off-line html documentation for qt4
COMMENT-postgresql =	PostgresSQL plugin for qt4
COMMENT-mysql =		MySQL plugin for qt4
COMMENT-sqlite2 =	sqlite2 plugin for qt4
COMMENT-sqlite =	sqlite plugin for qt4
COMMENT-tds =		tds plugin for qt4

PKGNAME =		qt4-${VERSION}
PKGNAME-mysql =		qt4-mysql-${PKGVERSION}
PKGNAME-postgresql =	qt4-postgresql-${PKGVERSION}
PKGNAME-examples =	qt4-examples-${PKGVERSION}
PKGNAME-sqlite2 =	qt4-sqlite2-${PKGVERSION}
PKGNAME-sqlite =	qt4-sqlite-${PKGVERSION}
PKGNAME-tds =		qt4-tds-${PKGVERSION}
PKGNAME-main =		qt4-${VERSION}
PKGNAME-debug =		qt4-debug-${PKGVERSION}
FULLPKGNAME-html =	qt4-html-${PKGVERSION}
FULLPKGPATH-html =	${BASE_PKGPATH},-html

REVISION-mysql =	0
REVISION-postgresql =	0
REVISION-examples =	0
REVISION-sqlite2 =	0
REVISION-sqlite =	0
REVISION-tds =		0
REVISION-main =		3
REVISION-debug =	0
REVISION-html =		0


SHARED_LIBS =	Qt3Support 8.0 \
		QtCore 9.0 \
		QtDesigner 7.0 \
		QtDesignerComponents 7.0 \
		QtGui 10.0 \
		QtNetwork 9.1 \
		QtOpenGL 7.0 \
		QtSql 8.0 \
		QtXml 8.0 \
		QtSvg 7.0 \
		QtTest 7.0 \
		QtDBus 2.0 \
		QtMultimedia 0.0 \
		QtScript 2.0 \
		QtCLucene 0.0 \
		QtHelp 1.0 \
		QtXmlPatterns 0.0 \
		QtScriptTools 0.0 \
		QtWebKit 2.0 \
		phonon 4.1 \
		QtDeclarative 0.0 


VERSION =	4.7.4
PKGVERSION =	4.7.4
DISTNAME =	qt-everywhere-opensource-src-${VERSION}

CATEGORIES =	x11
MASTER_SITES =	http://get.qt.nokia.com/qt/source/ \
		ftp://ftp.qt.nokia.com/qt/source/ \
		ftp://ftp.troll.no/qt/source/ \
		ftp://ftp.iasi.roedu.net/mirrors/ftp.trolltech.com/qt/source/ \
		ftp://ftp.ntua.gr/pub/X11/Qt/qt/source/ \
		ftp://ftp.tu-chemnitz.de/pub/Qt/qt/source/ \
		http://ftp.silug.org/pub/qt/source/


HOMEPAGE =	http://qt.nokia.com/

MAINTAINER =	Marc Espie <espie@openbsd.org>
 
FLAVORS =	debug
PSEUDO_FLAVORS =no_examples
FLAVOR ?=

# GPLv3, or LGPL.
# (GPLv2 not needed, since LGPL is more free)
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

MAKE_ENV =	QTDIR="${WRKDIST}" EXTRA_SAMPLES="${EXTRA_SAMPLES}" \
		SYS_CXX="${CXX}" SYS_CXXFLAGS="${CXXFLAGS}" \
		LD_LIBRARY_PATH="${WRKDIST}/lib"

# For qsettings to write its setup
PORTHOME =	${WRKDIST}

CONFIGURE_STYLE =	simple
SEPARATE_BUILD = 	Yes
CONFIGURE_ARGS =	-qt-gif -system-libpng -system-libjpeg -system-zlib \
			-sm -system-sqlite \
			-v -stl -xrender -fast \
			-no-sql-odbc \
			-xinput \
			-xinerama \
			-cups \
			-confirm-license \
			-opensource \
			-I${LOCALBASE}/include/libpng \
			-I${X11BASE}/include/freetype2 \
			-I${X11BASE}/include \
			-L${WRKBUILD}/lib \
			-L${X11BASE}/lib

CONFIGURE_ARGS +=	-prefix ${QT_BASEDIR}
CONFIGURE_ARGS +=	-libdir ${QT_BASEDIR}
CONFIGURE_ARGS +=	-bindir ${QT_BINDIR}
CONFIGURE_ARGS +=	-headerdir ${QT_INCDIR}
CONFIGURE_ARGS +=	-docdir ${QT_DOC}
CONFIGURE_ARGS +=	-plugindir ${QT_PLUGINSDIR}
CONFIGURE_ARGS +=	-datadir ${QT_BASEDIR}
CONFIGURE_ARGS +=	-sysconfdir ${SYSCONFDIR}
CONFIGURE_ARGS +=	-examplesdir ${QT_BASEDIR}/examples
CONFIGURE_ARGS +=	-demosdir ${QT_BASEDIR}/demos
CONFIGURE_ARGS +=	-no-separate-debug-info

CONFIGURE_ARGS += 	-I${LOCALBASE}/include/mysql -L${LOCALBASE}/lib/mysql \
			-plugin-sql-mysql
CONFIGURE_ARGS += 	-I${LOCALBASE}/include/postgresql \
	    		-I${LOCALBASE}/include/postgresql/server \
			-plugin-sql-psql

# XXX make sure those libraries gets written to libQtGui.la
QMAKE_LIBS_GUI =	freetype SM ICE Xi Xrender Xinerama fontconfig Xext X11
#QMAKE_LIBS_GUI =	

CONFIGURE_ENV =		LOCALBASE=${LOCALBASE} QTDIR="${WRKSRC}" \
			X11BASE=${X11BASE} QMAKE_LIBS_GUI="${QMAKE_LIBS_GUI:C/^/-l/}"
.if defined(MAKE_JOBS)
CONFIGURE_ENV +=	BOOTSTRAP_MAKE_FLAGS='-j${MAKE_JOBS}'
.endif

BUILD_DEPENDS +=	print/cups
BUILD_DEPENDS +=	x11/dbus
BUILD_DEPENDS +=	databases/postgresql,-server

MULTI_PACKAGES =	-main -examples \
			-html -mysql -postgresql -sqlite2 -sqlite -tds

.if ${FLAVOR:L:Mdebug}
CONFIGURE_ARGS +=	-debug
MULTI_PACKAGES +=	-debug
.else
CONFIGURE_ARGS +=-release
.endif

.include <bsd.port.arch.mk>

.if !${BUILD_PACKAGES:M-examples}
SUBTARGETS = 		sub-tools-bootstrap \
			sub-moc \
			sub-rcc \
			sub-uic \
			sub-corelib \
			sub-xml \
			sub-network \
			sub-sql \
			sub-testlib \
			sub-dbus \
			sub-gui \
			sub-qt3support \
			sub-uic3 \
			sub-opengl \
			sub-xmlpatterns \
			sub-phonon \
			sub-multimedia \
			sub-svg \
			sub-script \
			sub-declarative \
			sub-javascriptcore \
			sub-webkit \
			sub-scripttools \
			sub-plugins \
			sub-imports \
			sub-webkitdeclarative \
			sub-tools \
			sub-translations

ALL_TARGET =		${SUBTARGETS}
INSTALL_TARGET =	${SUBTARGETS:S/$/-install_subtargets/} \
			install_htmldocs install_qchdocs install_docimages \
			install_qmake install_mkspecs
.else
PROGRAMS +=		qtdemo pixeltool
.endif

MODULES =		devel/gettext

LIB_DEPENDS =
WANTLIB =
RUN_DEPENDS =

commonWANTLIB =		c GLU pthread GL m

sqlWANTLIB =		m lib/qt4/QtCore>=4 QtSql

RUN_DEPENDS-main=	${MODGETTEXT_RUN_DEPENDS}
LIB_DEPENDS-main =	${LIB_DEPENDS} \
			devel/glib2 \
			graphics/jpeg \
			graphics/libmng \
			multimedia/gstreamer-0.10/plugins-base \
			graphics/png
WANTLIB-main =		${commonWANTLIB} jpeg mng \
			lcms tiff gobject-2.0 gstvideo-0.10 \
			gstbase-0.10 gstreamer-0.10 xml2 \
			gobject-2.0 gmodule-2.0 gstinterfaces-0.10 \
			${MODGETTEXT_WANTLIB} glib-2.0 gthread-2.0 \
			gstaudio-0.10 ICE SM X11>=10 Xext Xi Xinerama \
			Xrender expat fontconfig freetype png>=2 z


LIB_DEPENDS-mysql =	${BUILD_PKGPATH} \
			databases/mysql
WANTLIB-mysql =		${sqlWANTLIB} \
			crypto ssl pthread z mysqlclient_r


LIB_DEPENDS-postgresql =${BUILD_PKGPATH} \
			databases/postgresql
WANTLIB-postgresql =	${sqlWANTLIB}  pq
			

LIB_DEPENDS-sqlite2 =	${BUILD_PKGPATH} \
			databases/sqlite
WANTLIB-sqlite2 =	${sqlWANTLIB} sqlite


LIB_DEPENDS-sqlite =	${BUILD_PKGPATH} \
			databases/sqlite3
WANTLIB-sqlite =	${sqlWANTLIB} sqlite3


LIB_DEPENDS-tds =	${BUILD_PKGPATH} \
			databases/freetds
WANTLIB-tds =		${sqlWANTLIB} sybdb

LIB_DEPENDS-examples =	${BUILD_PKGPATH}
WANTLIB-examples =	${commonWANTLIB} lib/qt4/QtDesigner \
			lib/qt4/QtCore lib/qt4/QtGui lib/qt4/QtNetwork \
			lib/qt4/QtOpenGL lib/qt4/QtSql lib/qt4/QtXml \
			lib/qt4/QtSvg lib/qt4/QtTest lib/qt4/Qt3Support \
			lib/qt4/QtDBus \
			lib/qt4/QtScript lib/qt4/QtScriptTools \
			lib/qt4/QtHelp lib/qt4/phonon \
			lib/qt4/QtMultimedia lib/qt4/QtDeclarative

LIB_DEPENDS-html =
WANTLIB-html =
RUN_DEPENDS-html =
PKG_ARCH-html =	*

.if ${COMPILER_VERSION:L:Mgcc4*}
CONFIGURE_ARGS +=	-platform openbsd-g++4
PKG_ARGS += 		-DGCC4=1
commonWANTLIB += 	stdc++
sqlWANTLIB += 		stdc++
WANTLIB-examples +=	lib/qt4/QtWebKit lib/qt4/QtXmlPatterns
LIB_DEPENDS-main += 	databases/sqlite3
WANTLIB-main += 	sqlite3
.else
PKG_ARGS += 		-DGCC4=0
.endif

commonWANTLIB += 	stdc++

QT_BASEDIR =	${PREFIX}/lib/qt4
QT_INCDIR =	${PREFIX}/include/X11/qt4
QT_EXAMPLES =	${QT_BASEDIR}/examples
QT_DOC =	${PREFIX}/share/doc/qt4
QT_PLUGINSDIR =	${QT_BASEDIR}/plugins
QT_BINDIR =	${QT_BASEDIR}/bin
QT_PKGCFGDIR =	${QT_BASEDIR}/pkgconfig

DOCS =	README

VMEM_WARNING =	Yes
NO_REGRESS =	Yes

PROGRAMS4 =	assistant designer findtr linguist lrelease lupdate moc qmake \
		qtconfig uic uic3
PROGRAMS += 	rcc qt3to4 syncqt qdbus


QMAKE =		${WRKBUILD}/bin/qmake

MAKE_FLAGS +=	INSTALL_PROGRAM='${INSTALL_PROGRAM}' \
		INSTALL_FILE='${INSTALL_DATA}'
.for l v in $(SHARED_LIBS)
MAKE_FLAGS +=	LIB$l_VERSION=$v
.endfor

DESTDIRNAME =	INSTALL_ROOT

pre-patch:
	cd ${WRKDIST} && cp -R mkspecs/openbsd-g++ mkspecs/openbsd-g++4

post-build:
.for l v in ${SHARED_LIBS}
	-${SUBST_CMD} ${WRKBUILD}/lib/lib$l.la
.endfor

post-install:
	# extra doc
	cd ${WRKSRC}; ${INSTALL_DATA} ${DOCS} ${QT_DOC}
	# programs
	${INSTALL_PROGRAM_DIR} ${QT_BINDIR} 
	${INSTALL_PROGRAM} ${WRKSRC}/bin/{findtr,syncqt} ${QT_BINDIR}
	${INSTALL_PROGRAM} ${WRKBUILD}/bin/qdoc3 ${QT_BINDIR}
.for p in ${PROGRAMS4} 
	@ln -sf ${TRUEPREFIX}/lib/qt4/bin/$p ${PREFIX}/bin/$p4
.endfor
	@ln -sf assistant ${PREFIX}/lib/qt4/bin/assistant4
.for p in ${PROGRAMS}
	@ln -sf ${TRUEPREFIX}/lib/qt4/bin/$p ${PREFIX}/bin/$p
.endfor
	# fix pkgconfig stuff
	@for i in ${QT_PKGCFGDIR}/*.pc; do \
	    perl -pi.bak -e 's,-L${WRKBUILD}/lib,,g;' $$i; \
	    rm $$i.bak; \
	done
	# this helps qdbuscpp2xml
	cd ${QT_BINDIR} && ln -sf moc moc4
.for l v in ${SHARED_LIBS}
	-test -f ${PREFIX}/lib/qt4/lib$l.so.$v && \
	    ln -sf qt4/lib$l.so.$v ${PREFIX}/lib
.endfor
# cleanup
	cd ${PREFIX}/lib/qt4 && ln -sf ../../include/X11/qt4 include

.include <bsd.port.mk>