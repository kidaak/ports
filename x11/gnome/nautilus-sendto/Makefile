# $OpenBSD$

SHARED_ONLY=	Yes

COMMENT=	applications integration into Nautilus

GNOME_PROJECT=	nautilus-sendto
GNOME_VERSION=	3.6.0

CATEGORIES=	misc net

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB += GL ICE SM X11 Xau Xcomposite Xcursor Xdamage Xdmcp
WANTLIB += Xext Xfixes Xi Xinerama Xrandr Xrender Xxf86vm asn1
WANTLIB += atk-1.0 atk-bridge-2.0 atspi c cairo cairo-gobject
WANTLIB += camel-1.2 com_err crypto db dbus-1 dbus-glib-1 drm
WANTLIB += e2fs-uuid ebackend-1.2 ebook-1.2 ecal-1.2 edataserver-1.2
WANTLIB += edataserverui-3.0 expat ffi fontconfig freetype gck-1
WANTLIB += gcr-base-3 gcrypt gdk-3 gdk_pixbuf-2.0 gio-2.0 glib-2.0
WANTLIB += gmodule-2.0 gnome-keyring gobject-2.0 gpg-error gssapi
WANTLIB += gssdp-1.0 gthread-2.0 gtk-3 gupnp-1.0 harfbuzz ical
WANTLIB += icalss icalvcal icudata icule icuuc krb5 m nspr4 nss3
WANTLIB += nssutil3 p11-kit pango-1.0 pangocairo-1.0 pangoft2-1.0
WANTLIB += pcre pixman-1 plc4 plds4 png pthread pthread-stubs
WANTLIB += smime3 softokn3 soup-2.4 sqlite3 ssl3 stdc++ xcb xcb-render
WANTLIB += xcb-shm xml2 z

MODULES=	devel/dconf \
		devel/gettext \
		x11/gnome

BUILD_DEPENDS=	net/gajim \
		x11/gnome/nautilus>=3.6.0
RUN_DEPENDS=	archivers/zip \
		archivers/bzip2 \
		x11/gnome/nautilus>=3.6.0
LIB_DEPENDS=	databases/evolution-data-server>=3.6.0 \
		net/gupnp/core

CONFIGURE_ARGS+= --disable-static \
		--with-gajim=${LOCALBASE}

LIBTOOL_FLAGS=	--tag=disable-static

# XXX nautilus-burn requires brasero which has not been ported to OpenBSD yet
CONFIGURE_ARGS+= --with-plugins="evolution gajim pidgin removable-devices upnp"

FAKE_FLAGS=	schemadir=${PREFIX}/share/schemas/nautilus-sendto

post-install:
	rm ${PREFIX}/lib/nautilus-sendto/plugins/*.la
# Remove these files as they are provided by nautilus itself now.
	rm ${PREFIX}/lib/nautilus/extensions-3.0/libnautilus-sendto.*

.include <bsd.port.mk>
