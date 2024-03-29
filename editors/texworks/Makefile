# $OpenBSD$

COMMENT-main =		easy to use LaTeX and ConTeXt editor
COMMENT-python =	Python scripting for TeXworks
COMMENT-lua =		Lua scripting for TeXworks

V =			0.4.4
R =			1004
DISTNAME =		texworks-${V}-r${R}

PKGNAME-main =		texworks-${V}
PKGNAME-lua =		texworks-lua-${V}
PKGNAME-python =	texworks-python-${V}

REVISION-lua =		0

WRKDIST =		${WRKDIR}/texworks-${V}

CATEGORIES =		editors print
HOMEPAGE =		http://www.tug.org/texworks/
MAINTAINER =		Edd Barrett <edd@openbsd.org>

# GPLv2
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

CONFIGURE_STYLE =	simple
MODULES =		x11/qt4 \
			lang/python \
			lang/lua

SHARED_ONLY =		Yes

WANTLIB += ICE QtDBus QtGui QtScript QtScriptTools QtXml SM X11
WANTLIB += Xext Xi Xinerama Xrender c fontconfig freetype hunspell-1.2
WANTLIB += m poppler-qt4 pthread stdc++ z

WANTLIB-lua =	${MODLUA_WANTLIB}
WANTLIB-lua +=	ICE QtCore QtGui QtXml SM X11 Xext Xi Xinerama Xrender
WANTLIB-lua +=	fontconfig freetype m stdc++

WANTLIB-python =  ${MODPY_WANTLIB}
WANTLIB-python += ICE QtCore QtGui QtXml SM X11 Xext Xi Xinerama Xrender
WANTLIB-python += fontconfig freetype m stdc++

MULTI_PACKAGES =	-main -lua -python

MASTER_SITES =		http://texworks.googlecode.com/files/

LIB_DEPENDS-main =	qt4->=4.8.2:${MODQT4_LIB_DEPENDS} \
			textproc/hunspell \
			x11/dbus \
			print/poppler,,-qt4
LIB_DEPENDS-lua =	${MODQT4_LIB_DEPENDS} \
			${MODLUA_LIB_DEPENDS}
LIB_DEPENDS-python =	${MODQT4_LIB_DEPENDS} \
			${MODPY_LIB_DEPENDS}

RUN_DEPENDS-main = 	print/texlive/base \
			devel/desktop-file-utils
RUN_DEPENDS-lua =	editors/texworks,-main
RUN_DEPENDS-python =	editors/texworks,-main

MODLUA_SA =		Yes

USE_GMAKE =		Yes
NO_REGRESS =		Yes
VMEM_WARNING = 		Yes

SUBST_VARS +=		WRKINST

PLUGIN_SRC =		${WRKSRC}/plugins-src
pre-configure:
	${SUBST_CMD} ${WRKSRC}/TeXworks.pro
	${SUBST_CMD} ${PLUGIN_SRC}/TWLuaPlugin/TWLuaPlugin.pro
	${SUBST_CMD} ${PLUGIN_SRC}/TWPythonPlugin/TWPythonPlugin.pro

do-configure:
	cd ${PLUGIN_SRC}/TWPythonPlugin && qmake4
	cd ${PLUGIN_SRC}/TWLuaPlugin && qmake4
	cd ${WRKSRC} && qmake4

# build plugins first
pre-build:
	cd ${PLUGIN_SRC}/TWPythonPlugin && ${MAKE_PROGRAM}
	cd ${PLUGIN_SRC}/TWLuaPlugin && ${MAKE_PROGRAM}

# install main stuff and then plugins
PLUGIN_INSTALLS =	${PLUGIN_SRC}/TWPythonPlugin \
			${PLUGIN_SRC}/TWLuaPlugin

FAKE_FLAGS +=	INSTALL_ROOT=${WRKINST}
post-install:
	for i in ${PLUGIN_INSTALLS}; do \
		cd $$i && ${MAKE_PROGRAM} -f ${MAKE_FILE} ${FAKE_TARGET} INSTALL_ROOT=${WRKINST}; \
	done

.include <bsd.port.mk>
