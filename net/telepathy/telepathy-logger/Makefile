# $OpenBSD$

COMMENT=	flexible communications framework, logger component

DISTNAME=	telepathy-logger-0.4.0
REVISION =	1

SHARED_LIBS +=  telepathy-logger     3.1      # 4.1
SHARED_LIBS +=  tpl-extensions       0.0      # 2.0

HOMEPAGE=	${HOMEPAGE_TP:=Logger}

MASTER_SITES=	${MASTER_SITES_TP:=telepathy-logger/}
EXTRACT_SUFX=	.tar.bz2

MODULES=	devel/gettext \
		lang/python \
		textproc/intltool \
		devel/dconf

WANTLIB += c dbus-1 dbus-glib-1 gio-2.0 glib-2.0 gmodule-2.0 gobject-2.0
WANTLIB += gthread-2.0 m pcre pthread sqlite3 telepathy-glib xml2
WANTLIB += z ffi

BUILD_DEPENDS=	devel/gobject-introspection \
		devel/py-twisted/words \
		x11/gnome/doc-utils
LIB_DEPENDS=	net/telepathy/telepathy-glib \
		textproc/libxml \
		x11/dbus-glib

MODGCONF2_SCHEMAS_DIR=	telepathy-logger
MODPY_RUNDEP=		No

CONFIGURE_ARGS+=	--disable-call \
			--enable-public-extensions

REGRESS_IS_INTERACTIVE=x11

.include <bsd.port.mk>
