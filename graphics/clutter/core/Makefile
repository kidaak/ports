# $OpenBSD$

COMMENT=		OpenGL-based interactive canvas library

GNOME_PROJECT=		clutter
GNOME_VERSION=		${MAJOR}.0
REVISION=		0

SHARED_LIBS +=  clutter-1.0          1.0   # 1200.8

WANTLIB += GL X11 Xau Xcomposite Xcursor Xdamage Xdmcp Xext Xfixes
WANTLIB += Xi Xinerama Xrandr Xrender Xxf86vm atk-1.0 cairo cairo-gobject
WANTLIB += cogl cogl-pango drm expat ffi fontconfig freetype gdk-3
WANTLIB += gdk_pixbuf-2.0 gio-2.0 glib-2.0 gmodule-2.0 gobject-2.0
WANTLIB += gthread-2.0 harfbuzz icudata icule icuuc json-glib-1.0
WANTLIB += m pango-1.0 pangocairo-1.0 pangoft2-1.0 pcre pixman-1
WANTLIB += png pthread pthread-stubs stdc++ xcb xcb-render xcb-shm
WANTLIB += z

MODGNOME_TOOLS=		goi

LIB_DEPENDS=		devel/json-glib \
			graphics/clutter/cogl>=${MAJOR} \
			x11/gtk+3

MODGNOME_CPPFLAGS=	-I${X11BASE}/include
MODGNOME_LDFLAGS=	-L${X11BASE}/lib

CONFIGURE_ARGS=		--enable-x11-backend

REGRESS_IS_INTERACTIVE=	X11

pre-configure:
	${SUBST_CMD} ${WRKSRC}/clutter/Makefile.in

.include <bsd.port.mk>
