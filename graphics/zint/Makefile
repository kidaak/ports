# $OpenBSD$

COMMENT-main =		library for encoding data in several barcode variants
COMMENT-x11 = 		graphical interface for the zint barcode generator

V = 			2.4.3
DISTNAME =		zint-${V}
PKGNAME-main = 		${DISTNAME}
PKGNAME-x11 = 		zint-gui-${V}

REVISION-main =		0
REVISION-x11 =		0

SHARED_ONLY = 		Yes

SHARED_LIBS += 		QZint	0.0 # 2.4
SHARED_LIBS += 		zint	0.0 # 2.4

CATEGORIES =		graphics

MAINTAINER =		Kirill Bychkov <yason@linklevel.net>

# GPLv3+
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

cWANTLIB = 		c m png z
WANTLIB-main = 		${cWANTLIB}
WANTLIB-x11 = 		${cWANTLIB} QtCore QtGui QtXml stdc++ zint

MASTER_SITES =		${MASTER_SITE_SOURCEFORGE:=zint/}

MODULES =		devel/cmake

CONFIGURE_ARGS =	-DCMAKE_BUILD_TYPE=RELEASE

LIB_DEPENDS-main = 		graphics/png

MULTI_PACKAGES = 	-main

PSEUDO_FLAVORS = 	no_x11
FLAVOR ?=

REGRESS_DEPENDS = 	${BASE_PKGPATH},-main

.if !${FLAVOR:Mno_x11}
MULTI_PACKAGES +=       -x11
MODULES +=		x11/qt4
LIB_DEPENDS-x11 += 	${BASE_PKGPATH},-main \
			${MODQT4_LIB_DEPENDS}
RUN_DEPENDS-x11 += 	devel/desktop-file-utils

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/applications/
	${INSTALL_DATA_DIR} ${PREFIX}/share/pixmaps/
	${INSTALL_DATA} ${WRKSRC}/zint-qt.desktop ${PREFIX}/share/applications/
	${INSTALL_DATA} ${WRKSRC}/zint.png ${PREFIX}/share/pixmaps/
.endif

do-regress:
	cd ${WRKSRC}/frontend/ && /bin/sh ./test.sh

.include <bsd.port.mk>
