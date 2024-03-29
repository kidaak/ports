# $OpenBSD$

COMMENT=		next generation GNOME shell

GNOME_PROJECT=		gnome-shell
GNOME_VERSION=		3.4.2
REVISION=		1

HOMEPAGE=		http://live.gnome.org/GnomeShell

# GPLv2+
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB += GL ICE SM X11 X11-xcb Xau Xcomposite Xcursor Xdamage
WANTLIB += Xdmcp Xext Xfixes Xi Xinerama Xrandr Xrender Xxf86vm
WANTLIB += asn1 atk-1.0 c cairo cairo-gobject camel-1.2 canberra
WANTLIB += canberra-gtk3 clutter-1.0 cogl cogl-pango com_err croco-0.6
WANTLIB += crypto dbus-1 dbus-glib-1 drm ebook-1.2 ecal-1.2 edataserver-1.2
WANTLIB += edataserverui-3.0 execinfo expat ffi folks fontconfig
WANTLIB += freetype gck-1 gconf-2 gcr-3 gcr-base-3 gcrypt gdbm
WANTLIB += gdk-3 gdk_pixbuf-2.0 gee gio-2.0 girepository-1.0 gjs
WANTLIB += glib-2.0 gmodule-2.0 gnome-keyring gnome-menu-3 gobject-2.0
WANTLIB += gpg-error gssapi gstbase-0.10 gstreamer-0.10 gthread-2.0
WANTLIB += gtk-3 ical icalss icalvcal json json-glib-1.0 krb5
WANTLIB += ltdl m mozjs185 mutter ncurses nspr4 nss3 ogg p11-kit
WANTLIB += pango-1.0 pangocairo-1.0 pangoft2-1.0 pcre pixman-1
WANTLIB += plc4 plds4 png polkit-agent-1 polkit-gobject-1 pthread
WANTLIB += pthread-stubs pulse pulse-mainloop-glib smime3 sndfile
WANTLIB += softokn3 soup-2.4 sqlite3 ssl3 startup-notification-1
WANTLIB += stdc++ telepathy-glib telepathy-logger vorbis vorbisfile
WANTLIB += xcb xcb-aux xcb-render xcb-shm xml2 z

MODULES=		devel/dconf \
			devel/gettext \
			lang/python \
			x11/gnome

MODGNOME_TOOLS=		goi

LIB_DEPENDS=		audio/pulseaudio \
			net/telepathy/folks \
			net/telepathy/telepathy-logger \
			sysutils/polkit \
			www/libcroco \
			x11/gnome/gcr \
			x11/gnome/gjs \
			x11/gnome/menus \
			x11/gnome/mutter
RUN_DEPENDS=		devel/py-gobject3 \
			x11/dbus-python \
			x11/gnome/caribou

# Don't depend on evolution to lower down the amount of dependencies and
# because most users want to be able to choose their PIM. Evolution can
# be installed separately or as part of the "gnome-extra" meta-package.
#RUN_DEPENDS +=		mail/evolution

MODGNOME_DESKTOP_FILE=	Yes

LIBTOOL_FLAGS= 		--tag=disable-static

CONFIGURE_STYLE=	autoconf
CONFIGURE_ARGS=		--disable-static \
			--with-ca-certificates=/etc/ssl/cert.pem \
			--without-systemd

AUTOCONF_VERSION=	2.69
AUTOMAKE_VERSION=	1.11
BUILD_DEPENDS +=	devel/autoconf/${AUTOCONF_VERSION} \
			devel/automake/${AUTOMAKE_VERSION} \
			devel/libtool \
			x11/gnome/common

pre-configure:
	cd ${WRKSRC} && env AUTOCONF_VERSION=${AUTOCONF_VERSION} \
		AUTOMAKE_VERSION=${AUTOMAKE_VERSION} aclocal -I m4
	cd ${WRKSRC} && env AUTOCONF_VERSION=${AUTOCONF_VERSION} \
		AUTOMAKE_VERSION=${AUTOMAKE_VERSION} autoconf
	cd ${WRKSRC} && env AUTOCONF_VERSION=${AUTOCONF_VERSION} \
		AUTOMAKE_VERSION=${AUTOMAKE_VERSION} autoheader
	cd ${WRKSRC} && env AUTOCONF_VERSION=${AUTOCONF_VERSION} \
		AUTOMAKE_VERSION=${AUTOMAKE_VERSION} automake

.include <bsd.port.mk>
