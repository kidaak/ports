# $OpenBSD$

COMMENT =	lightweight mail user agent

DISTNAME =	geary-0.1.20120901

MAINTAINER =	Landry Breuil <landry@openbsd.org>
CATEGORIES =	mail

# LGPLv2.1
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

HOMEPAGE =	http://redmine.yorba.org/projects/geary/wiki
MASTER_SITES =	http://rhaalovely.net/stuff/
MODULES =	devel/cmake devel/dconf x11/gnome

MODGNOME_TOOLS =	yelp vala
MODGNOME_DESKTOP_FILE =	Yes
MODGNOME_ICON_CACHE =	Yes

CONFIGURE_ARGS =-DGSETTINGS_COMPILE=OFF \
		-DGSETTINGS_COMPILE_IN_PLACE=OFF \
		-DICON_UPDATE=OFF \
		-DDESKTOP_UPDATE=OFF

LIB_DEPENDS =	mail/gmime \
		www/webkit,gtk3 \
		audio/libcanberra \
		devel/libnotify \
		devel/libunique3 \
		devel/libgee06

WANTLIB += GL X11 Xrender atk-1.0 c cairo cairo-gobject expat sqlite3
WANTLIB += fontconfig freetype gdk-3 gdk_pixbuf-2.0 gio-2.0 glib-2.0
WANTLIB += gnome-keyring gobject-2.0 gthread-2.0 gtk-3 iconv intl
WANTLIB += javascriptcoregtk-3.0 m pango-1.0 pangocairo-1.0 pangoft2-1.0
WANTLIB += pixman-1 png pthread-stubs soup-2.4 webkitgtk-3.0 xcb gee
WANTLIB += xcb-render xcb-shm z canberra gmime-2.6 notify unique-3.0

.include <bsd.port.mk>
