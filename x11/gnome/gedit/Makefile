# $OpenBSD$

COMMENT=		lightweight GNOME text editor

GNOME_PROJECT=		gedit
GNOME_VERSION=		3.6.0
REVISION=		0

CATEGORIES=		editors

HOMEPAGE=		http://projects.gnome.org/gedit/

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB += GL ICE SM X11 Xau Xcomposite Xcursor Xdamage Xdmcp
WANTLIB += Xext Xfixes Xi Xinerama Xrandr Xrender Xxf86vm atk-1.0
WANTLIB += c cairo cairo-gobject drm enchant expat ffi fontconfig
WANTLIB += freetype gdk-3 gdk_pixbuf-2.0 gio-2.0 girepository-1.0
WANTLIB += glib-2.0 gmodule-2.0 gobject-2.0 gthread-2.0 gtk-3
WANTLIB += gtksourceview-3.0 m pango-1.0 pangocairo-1.0 pangoft2-1.0
WANTLIB += pcre peas-1.0 peas-gtk-1.0 pixman-1 png pthread pthread-stubs
WANTLIB += stdc++ xcb xcb-render xcb-shm xml2 z
WANTLIB += atk-bridge-2.0 atspi dbus-1 harfbuzz icudata icule
WANTLIB += icuuc

MODULES=		devel/dconf \
			devel/gettext \
			lang/python \
			x11/gnome

BUILD_DEPENDS=		devel/gsettings-desktop-schemas \
			devel/iso-codes

LIB_DEPENDS=		devel/libpeas>=1.1.4p1 \
			textproc/enchant \
			x11/gtksourceview3

RUN_DEPENDS=		devel/gsettings-desktop-schemas \
			x11/gnome/gvfs # --enable-gvfs-metadata

MODGNOME_TOOLS= 	goi yelp
MODGNOME_DESKTOP_FILE=	Yes
LIBTOOL_FLAGS=		--tag=disable-static

CONFIGURE_ARGS=		--disable-static \
			--enable-python \
			--enable-spell \
			--enable-gvfs-metadata \
			--disable-updater \
			--disable-zeitgeist

REGRESS_IS_INTERACTIVE=	X11

post-install:
	rm ${PREFIX}/lib/gedit/plugins/*.la

.include <bsd.port.mk>
