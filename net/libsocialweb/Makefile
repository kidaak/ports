# $OpenBSD$

SHARED_ONLY=		Yes

COMMENT=		social web services integration framework

GNOME_PROJECT=		libsocialweb
GNOME_VERSION=		0.25.20
REVISION=		1

SHARED_LIBS +=  socialweb-client          2.0 # 2.0
SHARED_LIBS +=  socialweb-keyfob          0.0 # 0.0
SHARED_LIBS +=  socialweb-keystore        0.0 # 0.0
SHARED_LIBS +=  socialweb                 0.0 # 0.0

CATEGORIES=		net

MAINTAINER=		Jasper Lievisse Adriaanse <jasper@openbsd.org>, \
			Antoine Jacoutot <ajacoutot@openbsd.org>

# LGPLv2
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=	Yes

MODULES=		devel/gettext \
			x11/gnome

WANTLIB += c dbus-1 dbus-glib-1 ffi gconf-2 gcrypt gio-2.0 glib-2.0
WANTLIB += gmodule-2.0 gnome-keyring gobject-2.0 gpg-error gthread-2.0
WANTLIB += json-glib-1.0 m pcre pthread rest-0.7 rest-extras-0.7
WANTLIB += soup-2.4 soup-gnome-2.4 xml2 z sqlite3

MODGNOME_TOOLS= 	goi vala
LIB_DEPENDS=		devel/json-glib \
			net/librest \
			devel/gconf2 \
			x11/dbus-glib

LIBTOOL_FLAGS=		--tag=disable-static

CONFIGURE_STYLE=	gnu
CONFIGURE_ARGS+=	--disable-static \
			--enable-all-services \
			--with-online=always # Other choices are ConnMan and NM

.include <bsd.port.mk>
