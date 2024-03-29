# $OpenBSD$

SHARED_ONLY=	Yes

COMMENT=	plugins for Grilo

GNOME_PROJECT=	grilo-plugins
GNOME_VERSION=	0.2.0
API=		0.2

REVISION=	0

TRACKER_VERSION=0.14
SUBST_VARS=	API TRACKER_VERSION

CATEGORIES+=	multimedia

HOMEPAGE=	http://live.gnome.org/Grilo

# LGPLv2.1
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB += archive bz2 crypto curl dbus-1 e2fs-uuid expat ffi
WANTLIB += gcrypt gdata gio-2.0 glib-2.0 gmime-2.6 gmodule-2.0
WANTLIB += gnome-keyring gobject-2.0 gpg-error grilo-0.2 grlnet-0.2
WANTLIB += gssdp-1.0 gthread-2.0 gupnp-1.0 gupnp-av-1.0 idn kvm
WANTLIB += lua5.1 lzma m nspr4 nss3 oauth pcre plc4 plds4 quvi
WANTLIB += rest-0.7 smime3 softokn3 soup-2.4 soup-gnome-2.4 sqlite3
WANTLIB += ssl ssl3 totem-plparser xml2 z pthread unistring 
WANTLIB += gck-1 gcr-base-3 goa-1.0 p11-kit
WANTLIB += tracker-sparql-${TRACKER_VERSION}
WANTLIB += lib/tracker-${TRACKER_VERSION}/tracker-common
WANTLIB += lib/tracker-${TRACKER_VERSION}/tracker-data

MODULES=	devel/gettext \
		x11/gnome

LIB_DEPENDS=	devel/libgdata \
		mail/gmime \
		net/gupnp/av \
		net/librest \
		net/quvi/libquvi \
		security/nss \
		x11/gnome/grilo>=0.1.20 \
		x11/gnome/tracker>=0.14.0

LIBTOOL_FLAGS=	--tag=disable-static

MODGNOME_LDFLAGS=-Wl,-rpath,${TRUEPREFIX}/lib/tracker-${TRACKER_VERSION}

CONFIGURE_ARGS=	${CONFIGURE_SHARED} \
		--disable-static

post-install:
	rm ${PREFIX}/lib/grilo-${API}/*.la

.include <bsd.port.mk>
