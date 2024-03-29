# $OpenBSD$

COMMENT =	Xfce4 media player

XFCE_VERSION =	0.3.0.3
XFCE_GOODIE =	parole
CATEGORIES +=	audio

# GPLv2
PERMIT_DISTFILES_CDROM =	Yes
PERMIT_DISTFILES_FTP =	Yes
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes

MODULES =	x11/xfce4
MODXFCE_DESKTOP_FILE =	Yes
MODXFCE_ICON_CACHE=	Yes

LIB_DEPENDS =	multimedia/gstreamer-0.10/core \
		multimedia/gstreamer-0.10/plugins-base \
		x11/xfce4/libxfce4ui \
		audio/taglib \
		devel/libnotify

# plugins-ffmpeg needed to play mpeg vidz
# plugins-ugly needed to play mp3
RUN_DEPENDS +=	multimedia/gstreamer-0.10/plugins-good \
		multimedia/gstreamer-0.10/plugins-ugly \
		multimedia/gstreamer-0.10/plugins-ffmpeg

WANTLIB += ICE SM X11 Xau Xcomposite Xcursor Xdamage Xdmcp Xext
WANTLIB += Xfixes Xi Xinerama Xrandr Xrender atk-1.0 c cairo dbus-1
WANTLIB += dbus-glib-1 expat fontconfig freetype gdk-x11-2.0
WANTLIB += gdk_pixbuf-2.0 gio-2.0 glib-2.0 gmodule-2.0 gobject-2.0
WANTLIB += gthread-2.0 gtk-x11-2.0 m pango-1.0 pangocairo-1.0
WANTLIB += pangoft2-1.0 pcre pixman-1 png pthread pthread-stubs
WANTLIB += startup-notification-1 stdc++ xcb xcb-aux
WANTLIB += xfce4util xml2 z notify tag tag_c xfce4ui-1 orc-0.4
WANTLIB += gstvideo-0.10 gstinterfaces-0.10 gstreamer-0.10 gstbase-0.10
WANTLIB += xcb-render GL Xxf86vm drm xcb-shm X11-xcb ffi

.include <bsd.port.mk>
