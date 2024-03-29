# $OpenBSD$

SHARED_ONLY =	Yes

COMMENT-main =		bundle of plugins for gmpc
COMMENT-wikipedia =	wikipedia plugin for gmpc

VERSION =	11.8.16
DISTNAME =	gmpc-plugins-${VERSION}
PKGNAME-main =		${DISTNAME}
PKGNAME-wikipedia =	gmpc-wikipedia-${VERSION}
REVISION-main =		1
REVISION-wikipedia =	0

CATEGORIES =	audio

MAINTAINER =	Landry Breuil <landry@openbsd.org>

HOMEPAGE =	http://gmpclient.org/plugins
MASTER_SITES =	${MASTER_SITE_SOURCEFORGE:=musicpd/}

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

# XXX give it a chance to build on systems where webkit is not built
MULTI_PACKAGES =	-main -wikipedia
ONLY_FOR_ARCHS-wikipedia = alpha i386 powerpc amd64 hppa sparc64

.include <bsd.port.arch.mk>
.if !${BUILD_PACKAGES:M-wikipedia}
CONFIGURE_ARGS+=	--disable-wikipedia
.endif

MODULES =	devel/gettext \
		textproc/intltool

LIB_DEPENDS-main =	${LIB_DEPENDS} \
			audio/taglib>=1.5 \
			x11/dbus-glib \
			net/avahi
WANTLIB-main = ${WANTLIB} dbus-1 tag tag_c dbus-glib-1 pthread
WANTLIB-main += avahi-client avahi-common avahi-glib

LIB_DEPENDS-wikipedia =	${LIB_DEPENDS} \
			www/webkit>=1.6.1v0
WANTLIB-wikipedia =	${WANTLIB} \
			ICE SM Xt enchant gailutil gstapp-0.10 gstbase-0.10 \
			gstinterfaces-0.10 gstpbutils-0.10 gstreamer-0.10 gstvideo-0.10 \
			icudata icui18n icuuc jpeg soup-2.4 webkitgtk-1.0 xslt \
			javascriptcoregtk-1.0

WANTLIB += GL X11 Xau Xcomposite Xcursor Xdamage Xdmcp Xext Xfixes
WANTLIB += Xi Xinerama Xrandr Xrender Xxf86vm atk-1.0 cairo drm
WANTLIB += expat fontconfig freetype gdk-x11-2.0 gdk_pixbuf-2.0
WANTLIB += gio-2.0 glib-2.0 gmodule-2.0 gobject-2.0 gthread-2.0
WANTLIB += gtk-x11-2.0 m mpd pango-1.0 pangocairo-1.0 pangoft2-1.0
WANTLIB += pcre pixman-1 png pthread-stubs sqlite3 stdc++ xcb
WANTLIB += xcb-render xcb-shm xml2 z ffi

RUN_DEPENDS =	audio/gmpc>=${VERSION} \
		audio/vorbis-tools

BUILD_DEPENDS =	${RUN_DEPENDS} \
		x11/gob2
USE_LIBTOOL =	Yes
USE_GMAKE =	Yes

CONFIGURE_STYLE =gnu
CONFIGURE_ARGS+=--disable-mserver \
		--disable-mmkeys \
		--disable-libnotify \
		--disable-lirc

CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -liconv"

.include <bsd.port.mk>
