# $OpenBSD$

COMMENT=	GTK client and libraries for SPICE remote desktop servers

DISTNAME=	spice-gtk-0.14
CATEGORIES=	x11 net

SHARED_LIBS +=  spice-client-glib-2.0     0.0 # 8.0
SHARED_LIBS +=  spice-client-gtk-3.0      0.0 # 4.0
SHARED_LIBS +=  spice-controller          0.0 # 0.0

HOMEPAGE=	http://spice-space.org/page/Spice-Gtk

MAINTAINER=	Jasper Lievisse Adriaanse <jasper@openbsd.org>

# LGPLv2.1
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=	${HOMEPAGE}/../../download/gtk/
EXTRACT_SUFX=	.tar.bz2

WANTLIB += GL X11 Xau Xcomposite Xcursor Xdamage Xdmcp Xext Xfixes
WANTLIB += Xi Xinerama Xrandr Xrender Xxf86vm atk-1.0 c cairo
WANTLIB += cairo-gobject celt051 crypto drm expat ffi fontconfig
WANTLIB += freetype gdk-3 gdk_pixbuf-2.0 gio-2.0 glib-2.0 gmodule-2.0
WANTLIB += gobject-2.0 gstapp-0.10 gstaudio-0.10 gstbase-0.10
WANTLIB += gstinterfaces-0.10 gstpbutils-0.10 gstreamer-0.10 gthread-2.0
WANTLIB += gtk-3 jpeg m pango-1.0 pangocairo-1.0 pangoft2-1.0
WANTLIB += pcre pixman-1 png pthread pthread-stubs sasl2 ssl stdc++
WANTLIB += xcb xcb-render xcb-shm xml2 z dbus-1 dbus-glib-1
WANTLIB += ICE SM atk-bridge-2.0 atspi harfbuzz icudata icule
WANTLIB += icuuc

MODULES=	devel/gettext \
		lang/python \
		textproc/intltool

MODPY_RUNDEP=	No

BUILD_DEPENDS=	lang/vala \
		devel/gobject-introspection \
		devel/py-parsing \
		devel/spice-protocol
RUN_DEPENDS=	devel/spice-protocol
LIB_DEPENDS=	audio/celt051 \
		multimedia/gstreamer-0.10/plugins-base \
		security/cyrus-sasl2 \
		x11/dbus-glib \
		x11/gtk+3

USE_GMAKE=	Yes
USE_LIBTOOL=	Yes

CONFIGURE_STYLE=gnu
CONFIGURE_ARGS=	${CONFIGURE_SHARED} \
		--disable-smartcard \
		--disable-usbredir \
		--enable-introspection \
		--with-audio=gstreamer \
		--with-gtk=3.0 \
		--with-sasl \
		--disable-gtk-doc
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MODPY_ADJ_FILES=spice-common/spice_codegen.py

.include <bsd.port.mk>
