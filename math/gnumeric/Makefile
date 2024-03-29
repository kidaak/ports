# $OpenBSD$

COMMENT=		spreadsheet application for GNOME

GNOME_PROJECT=		gnumeric
GNOME_VERSION=		1.10.17
REVISION=		4

CATEGORIES=    		math

HOMEPAGE=		http://www.gnome.org/projects/gnumeric/

API_VERSION=		0.8.17 # from devel/goffice

# GPLv2
# Some tools: LGPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

EXTRACT_SUFX=		.tar.bz2

WANTLIB += GL X11 Xau Xcomposite Xcursor Xdamage Xdmcp
WANTLIB += Xext Xfixes Xi Xinerama Xrandr Xrender Xxf86vm atk-1.0
WANTLIB += bz2 c cairo drm expat fontconfig freetype gdk-x11-2.0
WANTLIB += gdk_pixbuf-2.0 gio-2.0 glib-2.0 gmodule-2.0 gobject-2.0
WANTLIB += goffice-0.8 gsf-1 gthread-2.0 gtk-x11-2.0 m pango-1.0
WANTLIB += pangocairo-1.0 pangoft2-1.0 pcre perl pixman-1 png
WANTLIB += pthread pthread-stubs util xcb xcb-render xcb-shm xml2
WANTLIB += z dbus-1 dbus-glib-1 ffi stdc++

MODULES=		devel/gconf2 \
			devel/gettext \
			x11/gnome

LIB_DEPENDS=		goffice->=0.8.17,<0.8.18:devel/goffice \
			devel/libgsf \
			x11/gtk+2

MODGNOME_DESKTOP_FILE=	Yes
MODGNOME_ICON_CACHE=	Yes
MODGNOME_TOOLS= 	yelp
MODGCONF2_SCHEMAS_DIR=	gnumeric

USE_LIBTOOL=		Yes
USE_GROFF=		Yes
CONFIGURE_STYLE=	gnu
CONFIGURE_ARGS=		--without-gnome \
			--without-gda \
			--without-psiconv \
			--without-paradox \
			--without-long-double \
			--without-python

SUBST_VARS=		VERSION API_VERSION

.include <bsd.port.mk>
