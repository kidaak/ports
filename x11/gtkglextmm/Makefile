# $OpenBSD$

COMMENT =		C++ bindings for gtkglext

DISTNAME =		gtkglextmm-1.2.0
REVISION =		1

SHARED_LIBS +=		gdkglextmm-x11-1.2        0.0 # 0.0
SHARED_LIBS +=		gtkglextmm-x11-1.2        0.0 # 0.0

CATEGORIES =		x11

HOMEPAGE =		http://projects.gnome.org/gtkglext/

# LGPLv2.1+
PERMIT_PACKAGE_CDROM =		Yes
PERMIT_PACKAGE_FTP =		Yes
PERMIT_DISTFILES_CDROM =	Yes
PERMIT_DISTFILES_FTP =		Yes

MASTER_SITES =		${MASTER_SITE_SOURCEFORGE:=gtkglext/}

MODULES =	devel/gettext

WANTLIB +=	GL GLU ICE SM X11 Xau Xcomposite Xcursor Xdamage Xdmcp
WANTLIB +=	Xext Xfixes Xi Xinerama Xmu Xrandr Xrender Xt Xxf86vm
WANTLIB +=	atk-1.0 atkmm-1.6 cairo cairomm-1.0 drm expat ffi fontconfig
WANTLIB +=	freetype gdk-x11-2.0 gdk_pixbuf-2.0 gdkglext-x11-1.0
WANTLIB +=	gdkmm-2.4 gio-2.0 giomm-2.4 glib-2.0 glibmm-2.4 gmodule-2.0
WANTLIB +=	gobject-2.0 gthread-2.0 gtk-x11-2.0 gtkglext-x11-1.0
WANTLIB +=	gtkmm-2.4 m pango-1.0 pangocairo-1.0 pangoft2-1.0
WANTLIB +=	pangomm-1.4 pangox-1.0 pcre pixman-1 png pthread-stubs
WANTLIB +=	sigc-2.0 stdc++ xcb xcb-render xcb-shm z

LIB_DEPENDS =		x11/gtk2mm \
			x11/gtkglext

USE_GMAKE =		Yes
USE_LIBTOOL =		Yes
CONFIGURE_STYLE =	gnu

.include <bsd.port.mk>
