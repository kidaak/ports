# $OpenBSD$

COMMENT=	window manipulation tool

DISTNAME=	devilspie-0.22
REVISION=	3
CATEGORIES=	x11

HOMEPAGE=	http://www.burtonini.com/blog/computers/devilspie

MAINTAINER=	Olle Nilsson <olle@vexed.se>

# GPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB += X11 XRes Xau Xcomposite Xcursor Xdamage Xdmcp Xext
WANTLIB += Xfixes Xi Xinerama Xrandr Xrender atk-1.0 c cairo expat
WANTLIB += fontconfig freetype gdk-x11-2.0 gdk_pixbuf-2.0 gio-2.0
WANTLIB += glib-2.0 gmodule-2.0 gobject-2.0 gtk-x11-2.0
WANTLIB += m pango-1.0 pangocairo-1.0 pangoft2-1.0 pixman-1 png
WANTLIB += startup-notification-1 z pthread-stubs xcb wnck-1

MASTER_SITES=	http://www.burtonini.com/computing/

MODULES=	devel/gettext textproc/intltool

LIB_DEPENDS=	devel/libwnck

SEPARATE_BUILD=	Yes
USE_GMAKE=	Yes
USE_GROFF =	Yes

CONFIGURE_STYLE=gnu
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include/" \
		LDFLAGS="-L${LOCALBASE}/lib" 

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/devilspie
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/devilspie

.include <bsd.port.mk>
