# $OpenBSD$

COMMENT=		small and easy to use graphical MPD client

DISTNAME=		gimmix-0.5.7.1
REVISION=		2
CATEGORIES=		audio x11

HOMEPAGE=		http://gimmix.berlios.de/

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB += X11 Xau Xcomposite Xcursor Xdamage Xdmcp Xext Xfixes
WANTLIB += Xi Xinerama Xrandr Xrender atk-1.0 c cairo expat fontconfig
WANTLIB += freetype gdk-x11-2.0 gdk_pixbuf-2.0 gio-2.0 glib-2.0
WANTLIB += gmodule-2.0 gobject-2.0 gtk-x11-2.0 m pango-1.0
WANTLIB += pangocairo-1.0 pangoft2-1.0 pcre pixman-1 png stdc++
WANTLIB += xml2 z gthread-2.0 pthread xcb-render
WANTLIB += pthread-stubs xcb crypto ssl curl idn
WANTLIB += mpd nxml tag tag_c glade-2.0 GL Xxf86vm drm ffi xcb-shm

MASTER_SITES=		${MASTER_SITE_BERLIOS:=gimmix/}
EXTRACT_SUFX=		.tar.bz2

MODULES=		devel/gettext textproc/intltool

USE_LIBTOOL=		Yes
CONFIGURE_STYLE=	gnu
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"

LIB_DEPENDS=		audio/libmpd>=0.17 \
			textproc/libnxml \
			audio/taglib \
			devel/libglade2
RUN_DEPENDS=		devel/desktop-file-utils \
			x11/gnome/icon-theme

post-extract:
	rm ${WRKSRC}/po/Makefile.in.in
	ln -s ${LOCALBASE}/share/intltool/Makefile.in.in ${WRKSRC}/po

.include <bsd.port.mk>
