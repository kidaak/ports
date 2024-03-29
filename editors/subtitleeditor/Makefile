# $OpenBSD$

ONLY_FOR_ARCHS=	${GCC4_ARCHS}

SHARED_ONLY=   	Yes

COMMENT=	GTK+2 subtitles editor

V=		0.40.0
DISTNAME=	subtitleeditor-${V}
REVISION=	1

CATEGORIES=	graphics editors

SHARED_LIBS +=  subtitleeditor 0.0     # .0.0

HOMEPAGE=	http://home.gna.org/subtitleeditor/

# GPLv3
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB += GL X11 Xau Xcomposite Xcursor Xdamage Xdmcp Xext Xfixes
WANTLIB += Xi Xinerama Xrandr Xrender Xxf86vm atk-1.0 atkmm-1.6
WANTLIB += c cairo cairomm-1.0 drm enchant expat ffi fontconfig
WANTLIB += freetype gdk-x11-2.0 gdk_pixbuf-2.0 gdkmm-2.4 gio-2.0
WANTLIB += giomm-2.4 glib-2.0 glibmm-2.4 gmodule-2.0 gobject-2.0
WANTLIB += gstaudio-0.10 gstbase-0.10 gstcdda-0.10 gstcontroller-0.10
WANTLIB += gstdataprotocol-0.10 gstinterfaces-0.10 gstnet-0.10
WANTLIB += gstnetbuffer-0.10 gstpbutils-0.10 gstreamer-0.10 gstreamermm-0.10
WANTLIB += gstrtp-0.10 gsttag-0.10 gstvideo-0.10 gthread-2.0 gtk-x11-2.0
WANTLIB += gtkmm-2.4 m pango-1.0 pangocairo-1.0 pangoft2-1.0 pangomm-1.4
WANTLIB += pcre pixman-1 png pthread pthread-stubs sigc-2.0 stdc++
WANTLIB += xcb xcb-render xcb-shm xml++-2.6 xml2 z orc-0.4

MASTER_SITES=	http://download.gna.org/subtitleeditor/${V:R}/

BUILD_DEPENDS=	multimedia/gstreamer-0.10/plugins-good \
		devel/iso-codes
LIB_DEPENDS=	textproc/enchant \
		multimedia/gstreamer-0.10/mm \
		multimedia/gstreamer-0.10/plugins-base \
		x11/gtk2mm
RUN_DEPENDS=	multimedia/gstreamer-0.10/plugins-good \
		multimedia/gstreamer-0.10/plugins-ffmpeg \
		devel/iso-codes \
		devel/desktop-file-utils \
		x11/gtk+2,-guic

MODULES+=	devel/gettext \
		textproc/intltool

USE_GMAKE=	Yes
USE_LIBTOOL=	Yes
USE_GROFF=	Yes

LIBTOOL_FLAGS= --tag=disable-static

CONFIGURE_STYLE=gnu
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		GST_REGISTRY=${WRKDIR}/registry.${MACHINE_ARCH}.bin
CONFIGURE_ARGS=	${CONFIGURE_SHARED} \
		--disable-static \
		--with-default-video-sink=autovideosink \
		--with-default-audio-sink=autoaudiosink \
		--enable-ccache=no \
		--enable-gl=no

.include <bsd.port.mk>
