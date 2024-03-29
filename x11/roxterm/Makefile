# $OpenBSD$

COMMENT=		terminal emulator for X

DISTNAME=		roxterm-2.0.1
REVISION=		6
CATEGORIES=		x11

HOMEPAGE=		http://roxterm.sourceforge.net/
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=roxterm/}

MAINTAINER=		Amit Kulkarni <amitkulz@gmail.com>

# GPLv3
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB += GL ICE SM X11 Xau Xcomposite Xcursor Xdamage Xdmcp
WANTLIB += Xext Xfixes Xi Xinerama Xrandr Xrender Xxf86vm atk-1.0
WANTLIB += c cairo cairo-gobject dbus-1 dbus-glib-1 drm expat
WANTLIB += ffi fontconfig freetype gdk-3 gdk_pixbuf-2.0 gio-2.0
WANTLIB += glib-2.0 gmodule-2.0 gobject-2.0 gthread-2.0 gtk-3
WANTLIB += m ncurses pango-1.0 pangocairo-1.0 pangoft2-1.0 pcre
WANTLIB += pixman-1 png pthread pthread-stubs stdc++ vte2_90 xcb
WANTLIB += xcb-render xcb-shm z

MODULES=		devel/gettext

LIB_DEPENDS=		devel/vte3 \
			x11/dbus-glib \
			devel/libglade2 

BUILD_DEPENDS=		textproc/docbook-xsl

RUN_DEPENDS=		devel/desktop-file-utils \
			x11/gnome/librsvg \
			x11/gtk+2,-guic

USE_LIBTOOL=		Yes
USE_GMAKE=		Yes

CONFIGURE_STYLE=	gnu
CONFIGURE_ARGS=		${CONFIGURE_SHARED}

.include <bsd.port.mk>
