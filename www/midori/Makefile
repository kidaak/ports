# $OpenBSD$

COMMENT =	lightweight web browser

XFCE_VERSION =	0.4.7
XFCE_GOODIE =	midori

MAINTAINER =	Landry Breuil <landry@openbsd.org>
CATEGORIES =	www

# LGPLv2.1
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

MODULES =	x11/xfce4 devel/waf

MODXFCE_DESKTOP_FILE =	Yes
MODXFCE_ICON_CACHE =	Yes
NO_REGRESS =	Yes

FLAVORS =	gtk3
FLAVOR ?=

.if ${FLAVOR:L:Mgtk3}
CONFIGURE_ARGS +=	--enable-gtk3
LIB_DEPENDS =	www/webkit,gtk3 \
		x11/gnome/gcr \
		devel/libunique3
WANTLIB += cairo-gobject gck-1 gcr-3 gcr-base-3 gdk-3 gtk-3 javascriptcoregtk-3.0
WANTLIB += p11-kit unique-3.0 webkitgtk-3.0

.else
LIB_DEPENDS =	www/webkit>=1.6.1v0 \
		devel/libunique
WANTLIB += gdk-x11-2.0 gtk-x11-2.0 javascriptcoregtk-1.0
WANTLIB += unique-1.0 webkitgtk-1.0
.endif

LIB_DEPENDS +=	devel/libnotify \
		devel/libsoup>=2.28.0

RUN_DEPENDS =	xfce4-icon-theme-*|tango-icon-theme-*|gnome-icon-theme-*:x11/tango-icon-theme

BUILD_DEPENDS =	textproc/py-docutils \
		lang/vala \
		x11/gnome/librsvg

WANTLIB += GL X11 Xau Xcomposite Xcursor Xdamage Xdmcp Xext Xfixes
WANTLIB += Xi Xinerama Xrandr Xrender Xss Xxf86vm atk-1.0 c cairo
WANTLIB += drm expat fontconfig freetype gdk_pixbuf-2.0
WANTLIB += gio-2.0 glib-2.0 gmodule-2.0 gobject-2.0 gthread-2.0
WANTLIB += m notify pango-1.0 xcb-shm xml2 z pcre
WANTLIB += pangocairo-1.0 pangoft2-1.0 pixman-1 png pthread pthread-stubs
WANTLIB += soup-2.4 sqlite3 xcb xcb-render

.include <bsd.port.mk>
