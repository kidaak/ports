# $OpenBSD$

COMMENT =	GTK+2 widget to display large amounts of numerical data

DISTNAME =	gtkdatabox-0.9.1.1
REVISION =	4

SHARED_LIBS =	gtkdatabox 0.0

CATEGORIES =	x11

HOMEPAGE =	http://www.eudoxos.de/gtk/gtkdatabox/

MAINTAINER =	Pierre-Emmanuel Andre <pea@openbsd.org>

# GPLv2
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

WANTLIB = 	X11 Xau Xcomposite Xcursor Xdamage Xdmcp Xext Xfixes \
		Xi Xinerama Xrandr Xrender expat fontconfig freetype \
		m pixman-1 z gio-2.0 atk-1.0 cairo glib-2.0 \
		pango-1.0 pangocairo-1.0 pangoft2-1.0 gmodule-2.0 \
		gobject-2.0 png pthread-stubs xcb pcre gthread-2.0 \
		xcb-render xcb-render-util gdk-x11-2.0 gdk_pixbuf-2.0 \
		gtk-x11-2.0

MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtkdatabox/}

MODULES =	devel/gettext

LIB_DEPENDS =	x11/gtk+2


USE_LIBTOOL = 	Yes

CONFIGURE_STYLE=gnu

.include <bsd.port.mk>
