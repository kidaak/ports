# $OpenBSD$

COMMENT=	Xfce4 cpu usage graph panel plugin

XFCE_VERSION=	1.0.5
XFCE_PLUGIN=	cpugraph

# GPLv2+
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes

MODULES=	x11/xfce4

MODXFCE_ICON_CACHE=	Yes

WANTLIB += GL X11 Xcomposite Xcursor Xdamage Xext Xfixes Xi Xinerama
WANTLIB += Xrandr Xrender atk-1.0 cairo expat fontconfig freetype
WANTLIB += gdk-x11-2.0 gdk_pixbuf-2.0 gio-2.0 glib-2.0 gmodule-2.0
WANTLIB += gobject-2.0 gthread-2.0 gtk-x11-2.0 m pango-1.0 pangocairo-1.0
WANTLIB += pangoft2-1.0 pixman-1 png pthread-stubs xcb
WANTLIB += xcb-render xcb-shm xfce4util z stdc++ xcb-aux xfce4ui-1
WANTLIB += ICE SM X11-xcb Xau Xdmcp Xxf86vm drm ffi pcre startup-notification-1

.include <bsd.port.mk>
