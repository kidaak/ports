# $OpenBSD$

COMMENT =	GVfs mountpoint manager

XFCE_VERSION =	0.4.1
XFCE_GOODIE =	gigolo
REVISION=	3

CATEGORIES =	x11

MAINTAINER =	Landry Breuil <gaston@gcu.info>

HOMEPAGE =	http://www.uvena.de/gigolo/

# GPLv2
PERMIT_DISTFILES_CDROM =	Yes
PERMIT_DISTFILES_FTP =	Yes
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes

MODULES =	x11/xfce4 devel/waf
CONFIGURE_ARGS =	--mandir=${PREFIX}/man
NO_REGRESS =	Yes
MODXFCE_DESKTOP_FILE =	Yes
USE_GROFF =	Yes

BUILD_DEPENDS +=devel/waf>=1.5.18
RUN_DEPENDS +=	x11/gnome/gvfs
LIB_DEPENDS =	x11/gtk+2

WANTLIB += X11 Xau Xcomposite Xcursor Xdamage Xdmcp Xext Xfixes
WANTLIB += Xi Xinerama Xrandr Xrender atk-1.0 c cairo expat fontconfig
WANTLIB += freetype gio-2.0 glib-2.0 gmodule-2.0 gobject-2.0
WANTLIB += m pango-1.0 pangocairo-1.0 pangoft2-1.0 pixman-1 png
WANTLIB += pthread-stubs xcb z gdk-x11-2.0 gdk_pixbuf-2.0 gtk-x11-2.0

.include <bsd.port.mk>
