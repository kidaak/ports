# $OpenBSD$

COMMENT =	medical image conversion

DISTNAME =	xmedcon-0.10.7
REVISION =	2
SHARED_LIBS =	mdc	2.1	# .2.1
CATEGORIES =	graphics

HOMEPAGE =	http://xmedcon.sourceforge.net

MAINTAINER =	Benoit Lecocq <benoit@openbsd.org>

# GPLv2 - LGPLv2.1
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM = Yes
PERMIT_DISTFILES_FTP =	Yes

WANTLIB += X11 Xau Xcomposite Xcursor Xdamage Xdmcp Xext Xfixes
WANTLIB += Xi Xinerama Xrandr Xrender atk-1.0 c cairo expat fontconfig
WANTLIB += freetype gio-2.0 glib-2.0 gmodule-2.0 gobject-2.0 stdc++
WANTLIB += m pango-1.0 pangocairo-1.0 pangoft2-1.0 pcre pixman-1 ffi
WANTLIB += png pthread-stubs xcb z gthread-2.0 pthread xcb-render
WANTLIB += gdk-x11-2.0 gdk_pixbuf-2.0 gtk-x11-2.0 GL Xxf86vm drm xcb-shm

MASTER_SITES =	${MASTER_SITE_SOURCEFORGE:=xmedcon/}

MODULES =	devel/gettext

LIB_DEPENDS =	x11/gtk+2

FAKE_FLAGS =	sysconfdir=${TRUEPREFIX}/share/examples/xmedcon

USE_GROFF =	Yes
USE_LIBTOOL =	Yes

CONFIGURE_STYLE = gnu
CONFIGURE_ARGS += ${CONFIGURE_SHARED} \
		 --enable-static \
		 --sysconfdir="${SYSCONFDIR}"
CONFIGURE_ENV = CFLAGS="${CFLAGS} -I${LOCALBASE}/include -I${LOCALBASE}/include/libpng" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"
                         
NO_REGRESS =	Yes

.include <bsd.port.mk>
