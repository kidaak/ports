# $OpenBSD$

COMMENT=		flexible communications framework, IRC component

DISTNAME=		telepathy-idle-0.1.12

MASTER_SITES=		${MASTER_SITES_TP:=telepathy-idle/}

WANTLIB += c crypto dbus-1 dbus-glib-1 ffi gio-2.0 glib-2.0 gmodule-2.0
WANTLIB += gobject-2.0 gthread-2.0 pcre pthread ssl telepathy-glib
WANTLIB += z

MODULES=		devel/gettext \
			lang/python
MODPY_RUNDEP=		No

BUILD_DEPENDS=		${RUN_DEPENDS} \
			devel/py-twisted/words
RUN_DEPENDS=		textproc/libxslt
LIB_DEPENDS=		net/telepathy/telepathy-glib

.include <bsd.port.mk>
