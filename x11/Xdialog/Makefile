# $OpenBSD$

COMMENT=	X11 counterpart of curses-based misc/dialog

DISTNAME=	Xdialog-2.3.1
REVISION=	3
CATEGORIES=	x11 misc

HOMEPAGE=	http://xdialog.dyns.net/

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=	http://thgodef.nerim.net/xdialog/
EXTRACT_SUFX=	.tar.bz2

WANTLIB += X11 Xau Xcomposite Xcursor Xdamage Xdmcp Xext Xfixes
WANTLIB += Xi Xinerama Xrandr Xrender atk-1.0 c cairo expat fontconfig
WANTLIB += freetype gio-2.0 glib-2.0 gmodule-2.0 gobject-2.0
WANTLIB += m pango-1.0 pangocairo-1.0 pangoft2-1.0 pixman-1 png
WANTLIB += pthread-stubs xcb z gdk_pixbuf-2.0 gdk-x11-2.0 gtk-x11-2.0

LIB_DEPENDS=	x11/gtk+2
MODULES=	devel/gettext

USE_GROFF =	Yes
CONFIGURE_STYLE=gnu
CONFIGURE_ARGS+=--with-gtk2

.include <bsd.port.mk>
