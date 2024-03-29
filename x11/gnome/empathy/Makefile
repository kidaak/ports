# $OpenBSD$

COMMENT= 		Telepathy based messenger for GNOME

GNOME_PROJECT=		empathy
GNOME_VERSION=		3.4.2
REVISION=		6

CATEGORIES=		net

HOMEPAGE=		http://live.gnome.org/Empathy

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB += GL ICE SM X11 Xau Xcomposite Xcursor Xdamage Xdmcp
WANTLIB += Xext Xfixes Xi Xinerama Xrandr Xrender Xt Xxf86vm asn1
WANTLIB += atk-1.0 c cairo cairo-gobject camel-1.2 canberra canberra-gtk3
WANTLIB += com_err crypto dbus-1 dbus-glib-1 drm ebook-1.2 edataserver-1.2
WANTLIB += enchant execinfo expat ffi folks folks-telepathy fontconfig
WANTLIB += freetype gailutil-3 gck-1 gconf-2 gcr-3 gcr-base-3
WANTLIB += gcrypt gdbm gdk-3 gdk_pixbuf-2.0 gee geoclue gio-2.0
WANTLIB += glib-2.0 gmodule-2.0 gmp gnome-keyring gnutls goa-1.0
WANTLIB += gobject-2.0 gpg-error gssapi gstapp-0.10 gstaudio-0.10
WANTLIB += gstbase-0.10 gstfft-0.10 gstinterfaces-0.10
WANTLIB += gstpbutils-0.10 gstreamer-0.10 gstvideo-0.10 gthread-2.0
WANTLIB += gtk-3 hogweed icudata icui18n icuuc javascriptcoregtk-3.0
WANTLIB += jpeg json krb5 ltdl m mission-control-plugins nettle
WANTLIB += notify nspr4 nss3 ogg orc-0.4 p11-kit pango-1.0 pangocairo-1.0
WANTLIB += pangoft2-1.0 pcre pixman-1 plc4 plds4 png pthread pthread-stubs
WANTLIB += pulse pulse-mainloop-glib smime3 sndfile softokn3 soup-2.4
WANTLIB += sqlite3 ssl3 stdc++ tasn1 telepathy-farstream telepathy-glib
WANTLIB += telepathy-logger vorbis vorbisfile webkitgtk-3.0 xcb
WANTLIB += xcb-render xcb-shm xml2 xslt z farstream-0.1
WANTLIB += champlain-0.12 champlain-gtk-0.12 clutter-1.0 clutter-gst-1.0
WANTLIB += clutter-gtk-1.0 cogl cogl-pango gsttag-0.10
WANTLIB += json-glib-1.0 soup-gnome-2.4 memphis-0.2

MODULES=		devel/dconf \
			devel/gettext \
			lang/python \
			x11/gnome

BUILD_DEPENDS=		devel/gsettings-desktop-schemas \
			devel/iso-codes \
			x11/gnome/nautilus-sendto
LIB_DEPENDS=		audio/libcanberra,-gtk3 \
			audio/pulseaudio>=2.0 \
			geo/geoclue \
			geo/libchamplain>=0.12.2 \
			graphics/clutter/clutter-gst>=1.6.0 \
			net/telepathy/folks \
			net/telepathy/telepathy-farstream \
			net/telepathy/telepathy-logger \
			textproc/enchant \
			x11/gnome/gcr \
			x11/gnome/online-accounts
RUN_DEPENDS=		devel/gsettings-desktop-schemas \
			devel/iso-codes \
			net/telepathy/telepathy-mission-control \
			net/telepathy/telepathy-gabble \
			net/telepathy/telepathy-idle \
			net/telepathy/telepathy-salut \
			x11/gnome/contacts \
			x11/gnome/icon-theme

# gst-pulse (src/empathy-audio-sink.c)
#RUN_DEPENDS +=		multimedia/gstreamer1/plugins-good,-pulse

MODGNOME_DESKTOP_FILE=	Yes
MODGNOME_ICON_CACHE=	Yes
MODGNOME_TOOLS= 	yelp

MODGNOME_LDFLAGS=	-Wl,-rpath,${LOCALBASE}/lib/pulseaudio

CONFIGURE_ARGS+=	--disable-gudev \
			--disable-Werror \
			--with-eds \
			--without-cheese

# XXX needs geocode-glib
CONFIGURE_ARGS +=	--disable-geocode

# needs connman or network-manager
CONFIGURE_ARGS+=	--without-connectivity

post-install:
	rm ${PREFIX}/lib/mission-control-plugins.0/*.{a,la}
	rm ${PREFIX}/lib/lib/nautilus-sendto/plugins/*.{a,la}

.include <bsd.port.mk>
