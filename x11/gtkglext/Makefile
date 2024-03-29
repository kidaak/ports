# $OpenBSD$

COMMENT=	OpenGL extension to GTK+ 2.0 and later

DISTNAME=	gtkglext-1.2.0
REVISION=	8
SHARED_LIBS=	gdkglext-x11-1.0	0.0 \
		gtkglext-x11-1.0	0.0
CATEGORIES=	x11 graphics devel

HOMEPAGE=	http://projects.gnome.org/gtkglext/

MAINTAINER=	Steven Mestdagh <steven@openbsd.org>

# LGPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtkglext/}

WANTLIB += GL GLU ICE SM X11 Xau Xcomposite Xcursor Xdamage Xdmcp
WANTLIB += Xext Xfixes Xi Xinerama Xmu Xrandr Xrender Xt Xxf86vm
WANTLIB += atk-1.0 cairo drm expat ffi fontconfig freetype gdk-x11-2.0
WANTLIB += gdk_pixbuf-2.0 gio-2.0 glib-2.0 gmodule-2.0 gobject-2.0
WANTLIB += gthread-2.0 gtk-x11-2.0 harfbuzz icudata icule icuuc
WANTLIB += m pango-1.0 pangocairo-1.0 pangoft2-1.0 pangox-1.0
WANTLIB += pcre pixman-1 png pthread pthread-stubs stdc++ xcb
WANTLIB += xcb-render xcb-shm z

MODULES=	devel/gettext

LIB_DEPENDS=	x11/gtk+2 \
		devel/pangox-compat

USE_GMAKE=	Yes
USE_LIBTOOL=	Yes
CONFIGURE_STYLE=gnu
CONFIGURE_ARGS=	${CONFIGURE_SHARED}

EXAMPLE_DIR=	${PREFIX}/share/examples/gtkglext

post-install:
	${INSTALL_DATA_DIR} ${EXAMPLE_DIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.{c,h,lwo,rgb} ${EXAMPLE_DIR}

.include <bsd.port.mk>
