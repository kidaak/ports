# $OpenBSD$

SHARED_ONLY=	Yes

COMMENT=	groupware plugin for Claws-mail

VERSION=	2.0.13
DISTNAME=	vcalendar-${VERSION}
PKGNAME=	claws-mail-vcalendar-${VERSION}
MASTER_SITES=	http://www.claws-mail.org/downloads/plugins/
CATEGORIES=	mail
DIST_SUBDIR=	claws

HOMEPAGE=	http://www.claws-mail.org/plugin.php?plugin=vcalendar

# GPLv3
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

USE_LIBTOOL=	Yes
LIBTOOL_FLAGS=	--tag=disable-static

MODULES=	devel/gettext

LIB_DEPENDS=	x11/gtk+2 \
		net/curl

RUN_DEPENDS=	mail/claws-mail>=3.8.1
BUILD_DEPENDS=	${RUN_DEPENDS}

WANTLIB += X11 Xau Xcomposite Xcursor Xdamage Xdmcp Xext Xfixes
WANTLIB += Xi Xinerama Xrandr Xrender atk-1.0 cairo crypto expat
WANTLIB += fontconfig freetype gio-2.0 glib-2.0 gmodule-2.0
WANTLIB += gobject-2.0 gthread-2.0 idn m pango-1.0 pangocairo-1.0
WANTLIB += pangoft2-1.0 pcre pixman-1 png pthread-stubs ssl xcb
WANTLIB += xcb-render z gdk_pixbuf-2.0 GL Xxf86vm drm xcb-shm
WANTLIB += gdk-x11-2.0 gtk-x11-2.0 curl

CONFIGURE_STYLE=gnu
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-static

.include <bsd.port.mk>
