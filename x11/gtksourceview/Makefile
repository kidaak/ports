# $OpenBSD$

COMMENT=		text widget that extends GTK2's GtkTextView widget

MAJOR_VERSION=		2.0
GNOME_PROJECT=		gtksourceview
GNOME_VERSION=		2.10.5
REVISION=	1

SHARED_LIBS +=	gtksourceview-2.0    5.0      # .0.0
CATEGORIES=		x11

SUBST_VARS=		MAJOR_VERSION

HOMEPAGE=		http://gtksourceview.sourceforge.net/

MAINTAINER=		Giovanni Bechis <giovanni@openbsd.org>

# GPLv2/LGPLv2.1
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

EXTRACT_SUFX=		.tar.bz2

WANTLIB += X11 Xau Xcomposite Xcursor Xdamage Xdmcp Xext Xfixes
WANTLIB += Xi Xinerama Xrandr Xrender atk-1.0 cairo expat fontconfig
WANTLIB += freetype gio-2.0 glib-2.0 gmodule-2.0 gobject-2.0
WANTLIB += m pango-1.0 pangocairo-1.0 pangoft2-1.0 pcre pixman-1
WANTLIB += gthread-2.0 xcb-render xcb-render-util
WANTLIB += png pthread-stubs xcb z xml2
WANTLIB += gtk-x11-2.0 gdk_pixbuf-2.0 gdk-x11-2.0

MODULES=		devel/gettext \
			x11/gnome

LIB_DEPENDS=		textproc/libxml \
			x11/gtk+2

USE_GMAKE=		Yes
CONFIGURE_STYLE=	gnu

REGRESS_IS_INTERACTIVE=	x11

.include <bsd.port.mk>
