# $OpenBSD$

SHARED_ONLY=	Yes

COMMENT=	music management and playback application for GNOME

GNOME_VERSION=	2.4.1
GNOME_PROJECT=	banshee
REVISION=	3

CATEGORIES=	audio

HOMEPAGE=	http://banshee.fm/

# MIT/X11
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB += GL ICE SM X11 Xau Xcomposite Xcursor Xdamage Xdmcp
WANTLIB += Xext Xfixes Xi Xinerama Xrandr Xrender Xt Xxf86vm atk-1.0
WANTLIB += cairo dbus-1 dbus-glib-1 drm enchant expat ffi fontconfig
WANTLIB += freetype gailutil gcrypt gdk-x11-2.0 gdk_pixbuf-2.0
WANTLIB += geoclue gio-2.0 glib-2.0 gmodule-2.0 gnome-keyring
WANTLIB += gobject-2.0 gpg-error gstapp-0.10 gstaudio-0.10 gstbase-0.10
WANTLIB += gstcdda-0.10 gstcontroller-0.10 gstdataprotocol-0.10
WANTLIB += gstfft-0.10 gstinterfaces-0.10 gstpbutils-0.10 gstreamer-0.10
WANTLIB += gsttag-0.10 gstvideo-0.10 gthread-2.0 gtk-x11-2.0 icudata
WANTLIB += icui18n icuuc javascriptcoregtk-1.0 jpeg m orc-0.4
WANTLIB += pango-1.0 pangocairo-1.0 pangoft2-1.0 pcre pixman-1
WANTLIB += png pthread-stubs soup-2.4 soup-gnome-2.4 sqlite3 stdc++
WANTLIB += webkitgtk-1.0 xcb xcb-render xcb-shm xml2 xslt z

MODULES=	x11/gnome \
		lang/mono \
		devel/gettext

BUILD_DEPENDS=	${RUN_DEPENDS}

RUN_DEPENDS=	devel/mono-notify \
		audio/mono-taglib \
		devel/dbus-sharp-glib \
		devel/libmtp \
		devel/mono-addins \
		devel/mono-gdata \
		lang/boo \
		net/mono-zeroconf \
		shells/bash \
		multimedia/gstreamer-0.10/plugins-good # libgstgconfelements

# MP3 support
RUN_DEPENDS +=	multimedia/gstreamer-0.10/plugins-ugly

LIB_DEPENDS=	www/webkit \
		multimedia/gstreamer-0.10/plugins-base

MODGNOME_DESKTOP_FILE=	Yes
MODGNOME_ICON_CACHE=	Yes
MODGNOME_TOOLS=		yelp

LIBTOOL_FLAGS=	--tag=disable-static

CONFIGURE_ARGS=	--disable-static \
		--enable-release \
		--enable-gapless-playback \
		--enable-user-help \
		--with-vendor-build-id="OpenBSD Ports" \
		--disable-upnp \
		--disable-gst-sharp \
		--disable-gio-hardware \
		--disable-moonlight \
		--disable-appledevice \
		--disable-karma \
		--disable-torrent \
		--disable-meego \
		--disable-ubuntuone \
		--disable-shave

# requires gio-sharp
CONFIGURE_ARGS += --disable-gio

DLLMAP_FILES=	src/Hyena/Hyena/Hyena.dll.config \
		src/Hyena/Hyena.Gui/Hyena.Gui.dll.config \
		src/Libraries/Mtp/Mtp.dll.config.in \
		src/Libraries/Mtp/Mtp.dll.config \
		src/Core/Banshee.Core/Banshee.Core.dll.config \
		src/Core/Banshee.Services/Banshee.Services.dll.config \
		src/Core/Banshee.Widgets/Banshee.Widgets.dll.config \
		src/Extensions/Banshee.NotificationArea/Banshee.NotificationArea.dll.config \
		src/Extensions/Banshee.MeeGo/Banshee.MeeGo.dll.config \
		src/Backends/Banshee.GStreamer/Banshee.GStreamer.dll.config \
		src/Backends/Banshee.Unix/Banshee.Unix.dll.config

# XXX the theme-icons target uses INSTALL_DATA during build which will
# fail when running as a non priviledge user (install -o/-g)
.if !target(do-install)
MAKE_FLAGS +=	INSTALL_DATA='/usr/bin/install -c -m 444'
.endif

post-install:
	rm ${PREFIX}/lib/banshee/Backends/*.la
	rm ${PREFIX}/lib/banshee/*.la

.include <bsd.port.mk>
