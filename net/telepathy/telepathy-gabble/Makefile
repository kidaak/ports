# $OpenBSD$

COMMENT=		flexible communications framework, xmpp component

DISTNAME=		telepathy-gabble-0.16.3
REVISION=		0

MASTER_SITES=		${MASTER_SITES_TP:=telepathy-gabble/}

WANTLIB += c dbus-1 dbus-glib-1 e2fs-uuid ffi gio-2.0 glib-2.0
WANTLIB += gmodule-2.0 gmp gnutls gobject-2.0 gssdp-1.0 gthread-2.0
WANTLIB += gupnp-1.0 gupnp-igd-1.0 hogweed m nettle nice p11-kit
WANTLIB += pcre pthread soup-2.4 sqlite3 tasn1 telepathy-glib
WANTLIB += xml2 z

MODULES=		devel/gettext \
			lang/python

BUILD_DEPENDS=		textproc/libxslt

LIB_DEPENDS=		devel/libsoup \
			net/libnice>=0.1.2 \
			net/telepathy/telepathy-glib>=0.18.0

# needed for the tests
BUILD_DEPENDS +=	devel/py-twisted/words \
			x11/dbus-python

# bin/telepathy-gabble-xmpp-console
RUN_DEPENDS +=		devel/py-gobject3

MODPY_ADJ_FILES=	plugins/telepathy-gabble-xmpp-console

CONFIGURE_ARGS=		--with-ca-certificates=/etc/ssl/cert.pem \
			--disable-gtk-doc \
			--disable-Werror \
			--enable-plugins

MODGNU_CONFIG_GUESS_DIRS= ${WRKSRC} ${WRKSRC}/lib/ext/wocky

# If one of these tools is found at configure stage, it might be used,
# no matter whether we use --disable-gtk-doc or not.
CONFIGURE_ENV +=ac_cv_path_GTKDOC_CHECK="" \
		ac_cv_path_GTKDOC_REBASE="" \
		ac_cv_path_GTKDOC_MKPDF=""

.include <bsd.port.mk>
