# $OpenBSD$

COMMENT=	Xfce4 extension library

XFCE_VERSION=	0.8.0
XFCE_PROJECT=	exo
REVISION=	0

SHARED_LIBS=	exo-1		0.1

HOMEPAGE=	http://www.xfce.org/projects

# GPLv2/LGPLv2
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes

MODULES=	x11/xfce4
MODXFCE_DESKTOP_FILE=	Yes
MODXFCE_ICON_CACHE=	Yes

CONFIGURE_ARGS=	--disable-linker-opts
CONFIGURE_ENV=	ac_cv_header_sys_ucred_h=yes \
		ac_cv_header_sys_mount_h=yes

BUILD_DEPENDS=	www/p5-URI
LIB_DEPENDS=	x11/xfce4/libxfce4ui>=4.9.0 \
		x11/xfce4/libxfce4util>=4.8.0

FAKE_FLAGS=	defaultsdir=${PREFIX}/share/examples/exo

WANTLIB=	ICE SM X11 Xau Xcomposite Xcursor Xdamage Xdmcp Xext \
		Xfixes Xi Xinerama Xrandr Xrender atk-1.0 c cairo expat \
		fontconfig freetype gdk-x11-2.0 gdk_pixbuf-2.0 gio-2.0 glib-2.0 \
		gmodule-2.0 gobject-2.0 gthread-2.0 gtk-x11-2.0 stdc++ xcb-aux xfce4ui-1\
		m pango-1.0 pangocairo-1.0 pangoft2-1.0 pcre pixman-1 \
		png pthread z pthread-stubs xcb X11-xcb startup-notification-1 \
		xcb-render xfce4util GL Xxf86vm drm xcb-shm ffi

.include <bsd.port.mk>
