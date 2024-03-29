# $OpenBSD$

SHARED_ONLY =	Yes

COMMENT =	smart common input method platform

DISTNAME =	scim-1.4.9
REVISION =	11

SHARED_LIBS +=  scim-1.0           0.0           # .10.4
SHARED_LIBS +=  scim-x11utils-1.0  0.0           # .10.4
SHARED_LIBS +=  scim-gtkutils-1.0  0.0           # .10.4

CATEGORIES =	inputmethods chinese japanese korean

HOMEPAGE =	http://www.scim-im.org/

MAINTAINER =	Kevin Lo <kevlo@openbsd.org>

# GPLv2
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM = Yes
PERMIT_DISTFILES_FTP =	Yes

WANTLIB =	X11 Xau Xcomposite Xcursor Xdamage Xdmcp Xext Xfixes \
		Xi Xinerama Xrandr Xrender atk-1.0 c cairo expat fontconfig \
		freetype glib-2.0 gmodule-2.0 gobject-2.0 gthread-2.0 \
		gio-2.0 m pango-1.0 pangocairo-1.0 pangoft2-1.0 pcre pixman-1 \
		png pthread pthread-stubs stdc++ xcb z gtk-x11-2.0 \
		gdk-x11-2.0 gdk_pixbuf-2.0 xcb-render \
		GL Xxf86vm drm ffi xcb-shm

MASTER_SITES =	${MASTER_SITE_SOURCEFORGE:=scim/}

MODULES =	devel/gettext \
		textproc/intltool
RUN_DEPENDS =	devel/desktop-file-utils
LIB_DEPENDS =	x11/gtk+2

FAKE_FLAGS =	sysconfdir=${PREFIX}/share/examples/scim 

USE_GMAKE =	Yes
USE_LIBTOOL =	Yes
LIBTOOL_FLAGS =	--tag=disable-static
CONFIGURE_STYLE = gnu
CONFIGURE_ARGS = ${CONFIGURE_SHARED} \
		--with-gtk-im-module-dir="${LOCALBASE}/lib/gtk-2.0/2.10.0/immodules"
CONFIGURE_ENV =	LIBS="-pthread"

.include <bsd.port.mk>
