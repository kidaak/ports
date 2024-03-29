# $OpenBSD$

SHARED_ONLY=	Yes

COMMENT=	advanced general purpose calculator

GNOME_PROJECT=	genius
GNOME_VERSION=	1.0.15
REVISION=	2

HOMEPAGE=	http://www.jirka.org/genius.html

CATEGORIES=	math

# GPLv3
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB += xcb-render X11 Xau Xcomposite Xcursor Xdamage Xdmcp
WANTLIB += Xext Xfixes Xi Xinerama Xrandr Xrender atk-1.0
WANTLIB += c cairo expat fontconfig GL Xxf86vm drm xcb-shm
WANTLIB += freetype gdk-x11-2.0 gdk_pixbuf-2.0 gio-2.0
WANTLIB += glib-2.0 gmodule-2.0 gobject-2.0 gthread-2.0
WANTLIB += gtk-x11-2.0 m ncurses pango-1.0 pangocairo-1.0 pangoft2-1.0
WANTLIB += pcre pixman-1 png pthread readline pthread-stubs xcb
WANTLIB += termcap xml2 z ffi stdc++ util
WANTLIB += gtksourceview-2.0 gmp mpfr vte

MODULES=	devel/gettext \
		x11/gnome

RUN_DEPENDS +=	misc/shared-mime-info
# needs to run ps2epsi for EPS output
RUN_DEPENDS +=	print/ghostscript/gnu
LIB_DEPENDS=	x11/gtksourceview \
		devel/gmp \
		devel/mpfr \
		devel/vte

MODGNOME_TOOLS= 	yelp
MODGNOME_DESKTOP_FILE=	Yes
MODGNOME_ICON_CACHE=	Yes

MODGNOME_LDFLAGS=	-L${X11BASE}/lib -lgmp
CONFIGURE_ARGS=	--disable-update-mimedb \
		--disable-extra-gcc-optimization

post-install:
	rm ${PREFIX}/lib/genius/*.{a,la}

.include <bsd.port.mk>
