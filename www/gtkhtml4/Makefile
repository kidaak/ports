# $OpenBSD$

SHARED_ONLY=		Yes

COMMENT=		lightweight HTML rendering/printing/editing engine

GNOME_PROJECT=		gtkhtml
GNOME_VERSION=		4.6.0

API_VERSION=		4.0
SUBST_VARS=		API_VERSION

PKGNAME=		gtkhtml4-${VERSION}

HOMEPAGE=		http://www.gnome.org/

SHARED_LIBS +=  gtkhtml-4.0               0.0 # 0.0
SHARED_LIBS +=  gtkhtml-editor-4.0        0.0 # 0.0

CATEGORIES=    		www

MAINTAINER=		Jasper Lievisse Adriaanse <jasper@openbsd.org>, \
			Antoine Jacoutot <ajacoutot@openbsd.org>

# GPLv2/LGPLv2
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB += GL X11 Xau Xcomposite Xcursor Xdamage Xdmcp Xext Xfixes
WANTLIB += Xi Xinerama Xrandr Xrender Xxf86vm atk-1.0 c cairo
WANTLIB += cairo-gobject drm enchant expat fontconfig freetype
WANTLIB += gailutil-3 gdk-3 gdk_pixbuf-2.0 gio-2.0 glib-2.0 gmodule-2.0
WANTLIB += gobject-2.0 gthread-2.0 gtk-3 m pango-1.0 pangocairo-1.0
WANTLIB += pangoft2-1.0 pcre pixman-1 png pthread pthread-stubs
WANTLIB += stdc++ xcb xcb-render xcb-shm z ffi
WANTLIB += ICE SM atk-bridge-2.0 atspi dbus-1 harfbuzz icudata
WANTLIB += icule icuuc

MODULES=		devel/gettext \
			x11/gnome

LIB_DEPENDS=		textproc/enchant \
			x11/gtk+3

BUILD_DEPENDS=		${RUN_DEPENDS}
# libsoup is only used by testgtkhtml, but since libsoup may be around during
# configure, and can have disappeared afterwards, the build can fail. so
# register it as a dependency instead of axing the Makefiles..
BUILD_DEPENDS+=		devel/libsoup
RUN_DEPENDS=		devel/gsettings-desktop-schemas \
			devel/iso-codes \
			x11/gnome/icon-theme

CONFIGURE_STYLE=	gnu
MODGNOME_CPPFLAGS=	-I${X11BASE}/include
MODGNOME_LDFLAGS=	-L${X11BASE}/lib

.include <bsd.port.mk>
