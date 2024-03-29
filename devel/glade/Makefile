# $OpenBSD$

COMMENT=	user interface builder for the gtk+3 toolkit

GNOME_VERSION=	3.14.0
GNOME_PROJECT= 	glade

CATEGORIES=	devel

SHARED_LIBS +=  gladeui-2                 1.0 # 0.0

HOMEPAGE=	http://glade.gnome.org/

MAINTAINER=	Jasper Lievisse Adriaanse <jasper@openbsd.org>, \
		Antoine Jacoutot <ajacoutot@openbsd.org>

# GPLv2 - LGPLv2
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB += GL X11 Xau Xcomposite Xcursor Xdamage Xdmcp Xext Xfixes
WANTLIB += Xi Xinerama Xrandr Xrender Xxf86vm atk-1.0 c cairo
WANTLIB += cairo-gobject drm expat ffi fontconfig freetype gdk-3
WANTLIB += gdk_pixbuf-2.0 gio-2.0 glib-2.0 gmodule-2.0 gobject-2.0
WANTLIB += gthread-2.0 gtk-3 m pango-1.0 pangocairo-1.0 pangoft2-1.0
WANTLIB += pcre pixman-1 png pthread pthread-stubs ${MODPY_WANTLIB} util
WANTLIB += xcb xcb-render xcb-shm xml2 z stdc++
WANTLIB += ICE SM atk-bridge-2.0 atspi dbus-1 harfbuzz icudata
WANTLIB += icule icuuc

MODULES=	devel/gettext \
		x11/gnome \
		lang/python

BUILD_DEPENDS=	devel/py-gobject3

LIB_DEPENDS=	x11/gtk+3>=3.5.18 \
		devel/libffi

RUN_DEPENDS=	x11/gnome/devhelp \
		devel/py-gobject3

MODGNOME_DESKTOP_FILE= 	Yes
MODGNOME_ICON_CACHE=	Yes
MODGNOME_TOOLS= goi yelp

CONFIGURE_STYLE=	gnu
MODGNOME_CPPFLAGS=	-pthread
MODGNOME_LDFLAGS=	-pthread -lutil

.include <bsd.port.mk>
