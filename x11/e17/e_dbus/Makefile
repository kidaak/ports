# $OpenBSD$

COMMENT =		enlightenment DBus component
DISTNAME =		e_dbus-1.0.0

REVISION =		0
EPOCH = 		1

SO_VERSION =		1.0
.for _lib in edbus enotify econnman ehal eofono ebluez eukit
SHARED_LIBS +=		${_lib} ${SO_VERSION}
.endfor

# BSD
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

USE_LIBTOOL =		Yes

WANTLIB += c crypto dbus-1 ecore eet eina evas expat fontconfig
WANTLIB += freetype fribidi glib-2.0 jpeg m pcre pthread ssl z

MODULES =		devel/gettext

LIB_DEPENDS =		x11/dbus \
			devel/fribidi \
			x11/e17/ecore>=1.0

CONFIGURE_ARGS =	--disable-doc

CONFIGURE_ENV =		CPPFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
			LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

.include <bsd.port.mk>
