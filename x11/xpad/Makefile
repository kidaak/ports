# $OpenBSD$

COMMENT=	virtual sticky pad system

DISTNAME=	xpad-4.0
REVISION=	5
CATEGORIES=	x11

MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xpad/}
MASTER_SITES=	http://launchpad.net/xpad/trunk/4.0/+download/
EXTRACT_SUFX=	.tar.bz2

HOMEPAGE=	http://xpad.sourceforge.net/

MODULES=	devel/gettext \
		textproc/intltool

LIB_DEPENDS=	x11/gtk+2
RUN_DEPENDS=	devel/desktop-file-utils \
		x11/gtk+2,-guic

# nothing in the dep chain provides librsvg, so explicitely depend on it
# so that the icon is correctly displayed
RUN_DEPENDS+=	x11/gnome/librsvg

WANTLIB += ICE SM X11 Xau Xcomposite Xcursor Xdamage Xdmcp Xext
WANTLIB += Xfixes Xi Xinerama Xrandr Xrender atk-1.0 c cairo expat
WANTLIB += fontconfig freetype gio-2.0 glib-2.0 gmodule-2.0
WANTLIB += gobject-2.0 m pango-1.0 pangocairo-1.0 pangoft2-1.0
WANTLIB += pixman-1 png z pthread-stubs xcb
WANTLIB += gthread-2.0 pthread xcb-render xcb-render-util
WANTLIB += gdk-x11-2.0 gdk_pixbuf-2.0 gtk-x11-2.0

# GPLv3+
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

USE_GMAKE=	Yes
USE_GROFF =	Yes

CONFIGURE_STYLE=	gnu
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
