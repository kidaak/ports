# $OpenBSD$

COMMENT-main=	BitTorrent command line and daemon client
COMMENT-gtk=	BitTorrent client with GTK+ interface
COMMENT-qt=	BitTorrent client with Qt interface

VER=		2.52
DISTNAME=	transmission-${VER}
PKGNAME-main=	transmission-${VER}
PKGNAME-gtk=	transmission-gtk-${VER}
PKGNAME-qt=	transmission-qt-${VER}
CATEGORIES=	net
HOMEPAGE=	http://www.transmissionbt.com/

REVISION-gtk=	0

MAINTAINER=	Christian Weisgerber <naddy@openbsd.org>

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=	http://download.m0k.org/transmission/files/
EXTRACT_SUFX=	.tar.xz

MULTI_PACKAGES=	-main -gtk -qt

ONLY_FOR_ARCHS-qt=${GCC4_ARCHS}

PSEUDO_FLAVORS=	no_gtk no_qt
FLAVOR?=

# Reminder:
# MODULES adds to WANTLIB and LIB_DEPENDS
# WANTLIB-main and LIB_DEPENDS-main default to WANTLIB and LIB_DEPENDS

WANTLIB=	c crypto curl event_core event_extra idn m miniupnpc \
		natpmp pthread ssl z
WANTLIB-gtk=	${WANTLIB} X11 Xau Xcomposite Xcursor Xdamage Xdmcp Xext \
		Xfixes Xi Xinerama Xrandr Xrender Xxf86vm GL atk-1.0 cairo \
		cairo-gobject drm expat ffi fontconfig freetype \
		gdk-3 gdk_pixbuf-2.0 gio-2.0 glib-2.0 gmodule-2.0 \
		gobject-2.0 gthread-2.0 gtk-3 pango-1.0 pangoft2-1.0 \
		pangocairo-1.0 pixman-1 png pcre pthread-stubs stdc++ xcb \
		xcb-render xcb-shm
WANTLIB-qt=	${WANTLIB} ICE SM QtCore QtDBus QtGui QtNetwork QtXml \
		X11 Xext Xi Xinerama Xrender \
		expat fontconfig freetype stdc++

MODULES=	devel/gettext textproc/intltool

LIB_DEPENDS=	devel/libevent2 \
		net/curl \
		net/miniupnp/libnatpmp \
		net/miniupnp/miniupnpc
LIB_DEPENDS-gtk=${LIB_DEPENDS} \
		x11/gtk+3
LIB_DEPENDS-qt=	${LIB_DEPENDS} \
		x11/qt4

RUN_DEPENDS-gtk=${PKGNAME-main}:net/transmission,-main \
		devel/desktop-file-utils \
		x11/gtk+2,-guic
RUN_DEPENDS-qt=	${PKGNAME-main}:net/transmission,-main \
		devel/desktop-file-utils

BUILD_DEPENDS=	archivers/gtar
TAR=		${LOCALBASE}/bin/gtar

USE_GMAKE=	Yes
USE_LIBTOOL=	Yes
CONFIGURE_STYLE=gnu
CONFIGURE_ARGS=	--disable-shared \
		--enable-external-natpmp
# unaligned accesses throughout
CONFIGURE_ARGS+=--disable-utp

# -I$(top_builddir)/third-party is required, but configure fails to
# set it if we use external miniupnp libs.

CONFIGURE_ENV=	CPPFLAGS="-I${WRKSRC}/third-party -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

QMAKE_ARGS=	QMAKE_CXX="${CXX}" \
		QMAKE_CXXFLAGS="${CXXFLAGS}"

.include <bsd.port.arch.mk>

.if !${BUILD_PACKAGES:M-gtk}
CONFIGURE_ARGS+=--without-gtk
.endif

.if ${BUILD_PACKAGES:M-qt}
post-build:
	cd ${WRKSRC}/qt; qmake4 ${QMAKE_ARGS} qtr.pro; make ${MAKE_FLAGS}

post-install:
	cd ${WRKSRC}/qt; make ${MAKE_FLAGS} install INSTALL_ROOT=${PREFIX} \
	    INSTALL_FILE="${INSTALL_DATA}" \
	    INSTALL_PROGRAM="${INSTALL_PROGRAM}"
	${INSTALL_DATA_DIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/qt/transmission-qt.desktop \
	    ${PREFIX}/share/applications/
	${INSTALL_DATA_DIR} ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/qt/icons/transmission.png \
	    ${PREFIX}/share/pixmaps/transmission-qt.png
.endif

.include <bsd.port.mk>
