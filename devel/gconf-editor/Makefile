# $OpenBSD$

COMMENT=	editor for the GConf configuration system

GNOME_PROJECT=	gconf-editor
GNOME_VERSION=	3.0.1
REVISION=	1

CATEGORIES=	devel x11

HOMEPAGE=	http://www.gnome.org/projects/gconf/

MAINTAINER=	Jasper Lievisse Adriaanse <jasper@openbsd.org>, \
		Antoine Jacoutot <ajacoutot@openbsd.org>

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB += GL X11 Xau Xcomposite Xcursor Xdamage Xdmcp Xext Xfixes
WANTLIB += Xi Xinerama Xrandr Xrender Xxf86vm atk-1.0 c cairo
WANTLIB += cairo-gobject dbus-1 dbus-glib-1 drm expat ffi fontconfig
WANTLIB += freetype gdk-3 gdk_pixbuf-2.0 gio-2.0 glib-2.0 gmodule-2.0
WANTLIB += gobject-2.0 gthread-2.0 gtk-3 m pango-1.0 pangocairo-1.0
WANTLIB += pangoft2-1.0 pcre pixman-1 png pthread pthread-stubs
WANTLIB += stdc++ xcb xcb-render xcb-shm z

MODULES=	devel/gettext \
		x11/gnome \
		devel/gconf2

LIB_DEPENDS=	x11/gtk+3

RUN_DEPENDS=	devel/gconf2,-polkit

USE_GROFF=	Yes
MODGNOME_DESKTOP_FILE=	Yes
MODGNOME_ICON_CACHE=	Yes
MODGNOME_TOOLS= yelp
MODGCONF2_SCHEMAS_DIR=	gconf-editor

CONFIGURE_STYLE=gnu

# the devel/gconf2 MODULE overrides the path to gconftool-2
CONFIGURE_ARGS += --with-gconf-defaults-source="xml:merged:/var/db/gconf/gconf.xml.defaults" \
	--with-gconf-mandatory-source="xml:merged:/var/db/gconf/gconf.xml.mandatory"

.include <bsd.port.mk>
