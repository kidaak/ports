# $OpenBSD$

SHARED_ONLY=	Yes

COMMENT=	input method data tables for scim

DISTNAME=	scim-tables-0.5.8
REVISION=	5

CATEGORIES=	inputmethods chinese japanese korean

HOMEPAGE=	http://www.scim-im.org/

MAINTAINER=	Kevin Lo <kevlo@openbsd.org>

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB=	X11 Xau Xcomposite Xcursor Xdamage Xdmcp Xext Xfixes \
		Xi Xinerama Xrandr Xrender atk-1.0 c cairo expat fontconfig \
		freetype glib-2.0 gmodule-2.0 gobject-2.0 m pango-1.0 \
		pangocairo-1.0 pangoft2-1.0 pcre pixman-1 png stdc++ z \
		gio-2.0 pthread-stubs xcb gtk-x11-2.0 gdk-x11-2.0 \
		gdk_pixbuf-2.0 scim-1.0 scim-gtkutils-1.0 scim-x11utils-1.0 \
		gthread-2.0 xcb-render GL Xxf86vm drm ffi pthread xcb-shm

MODULES=	devel/gettext

MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scim/}

LIB_DEPENDS=	x11/gtk+2 \
		inputmethods/scim

USE_LIBTOOL=	Yes
USE_GROFF =	Yes
LIBTOOL_FLAGS=	--tag=disable-static

CONFIGURE_STYLE=gnu
CONFIGURE_ARGS=	${CONFIGURE_SHARED} \
		--disable-static \
		--disable-skim-support

.include <bsd.port.mk>
