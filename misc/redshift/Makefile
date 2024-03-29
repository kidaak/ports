# $OpenBSD$

COMMENT=	automatic color temperature adjustment

V=		1.7
DISTNAME=	redshift-${V}
REVISION=	3
EXTRACT_SUFX=	.tar.bz2

CATEGORIES=	misc

HOMEPAGE=	http://jonls.dk/redshift/

# GPLv3
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB += X11 Xxf86vm c dbus-1 dbus-glib-1 gconf-2 geoclue glib-2.0
WANTLIB += gobject-2.0 gthread-2.0 m pthread xcb xcb-randr xml2

MASTER_SITES=	http://launchpad.net/redshift/trunk/${V:C/^([0-9]+\.[0-9]+).*/\1/}/+download/

RUN_DEPENDS=	devel/desktop-file-utils \
		x11/py-gtk2 \
		devel/py-xdg \
		x11/gtk+2,-guic
LIB_DEPENDS=	devel/gconf2 \
		geo/geoclue

MODULES=	devel/gettext \
		lang/python

# nothing in the dep chain provides librsvg, so explicitely depend on it
# so that the icon is correctly displayed
RUN_DEPENDS+=	x11/gnome/librsvg

USE_GMAKE=	Yes

CONFIGURE_STYLE=gnu
CONFIGURE_ARGS=	--enable-randr \
		--enable-vidmode \
		--enable-geoclue \
		--enable-gnome-clock \
		--enable-gui

MODPY_ADJ_FILES= src/gtk-redshift/gtk-redshift

.include <bsd.port.mk>
