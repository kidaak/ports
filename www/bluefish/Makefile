# $OpenBSD$

COMMENT=	HTML editor for experienced web designers

DISTNAME=	bluefish-1.0.7
REVISION=	10
CATEGORIES=	www
HOMEPAGE=	http://bluefish.openoffice.nl/

MASTER_SITES=	http://www.bennewitz.com/bluefish/stable/source/

# GPLv2+
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB += ICE ORBit-2 SM X11 Xau Xcomposite Xcursor Xdamage Xdmcp
WANTLIB += Xext Xfixes Xi Xinerama Xrandr Xrender art_lgpl_2 atk-1.0
WANTLIB += bonobo-2 bonobo-activation bonoboui-2 c cairo
WANTLIB += expat fontconfig freetype gconf-2 gio-2.0 glib-2.0 gdk_pixbuf-2.0
WANTLIB += gmodule-2.0 gnome-2 gnome-keyring gnomecanvas-2
WANTLIB += gnomevfs-2 gobject-2.0 gthread-2.0 m pango-1.0 pangocairo-1.0
WANTLIB += pangoft2-1.0 pixman-1 png popt pthread pthread-stubs xcb xml2 z
WANTLIB += gailutil gtk-x11-2.0>=0.14 gdk-x11-2.0>=0.14 pcre gnomeui-2
WANTLIB += GL Xxf86vm canberra drm xcb-render xcb-shm aspell

MODULES=	devel/gettext

RUN_DEPENDS=	devel/desktop-file-utils \
		misc/shared-mime-info
BUILD_DEPENDS=	misc/shared-mime-info
LIB_DEPENDS=	x11/gtk+2 \
		devel/pcre \
		x11/gnome/libgnomeui \
		textproc/aspell/core

CONFIGURE_STYLE=gnu
CONFIGURE_ARGS=	--with-freedesktop_org-menu='${PREFIX}/share/applications/' \
		--disable-update-databases
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

USE_GMAKE=	Yes
USE_GROFF =	Yes

NO_REGRESS=	Yes

.include <bsd.port.mk>
