# $OpenBSD$

COMMENT =	library to deal with Japanese kana-to-kanji conversion

DISTNAME =	libskk-1.0.0
REVISION =	0

SHARED_LIBS =	skk	0.0 # 0.0

CATEGORIES =	inputmethods japanese

HOMEPAGE =	https://github.com/ueno/libskk/

# GPLv3+
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM = Yes
PERMIT_DISTFILES_FTP =	Yes

WANTLIB =	c ffi gee gio-2.0 glib-2.0 gmodule-2.0 gobject-2.0 \
		gthread-2.0 json-glib-1.0 pcre pthread z

MASTER_SITES =	http://cloud.github.com/downloads/ueno/libskk/

MODULES =	devel/gettext \
		textproc/intltool
BUILD_DEPENDS =	devel/gobject-introspection \
		lang/vala
RUN_DEPENDS =	japanese/skk-jisyo
LIB_DEPENDS =	devel/libgee06 \
		devel/json-glib

USE_GMAKE =	Yes
USE_LIBTOOL =	Yes

CONFIGURE_STYLE =	gnu
CONFIGURE_ENV =	DATADIRNAME=share

.include <bsd.port.mk>
