# $OpenBSD$

COMMENT=	graphical hard drive inspection tool (smartctl front-end)

DISTNAME=	gsmartcontrol-0.8.6
EXTRACT_SUFX=	.tar.bz2
REVISION=	2

CATEGORIES=	sysutils x11

HOMEPAGE=	http://gsmartcontrol.berlios.de/

# GPLv2 or GPLv3
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB += GL X11 Xcomposite Xcursor Xdamage Xext Xfixes Xi Xinerama
WANTLIB += Xrandr Xrender atk-1.0 atkmm-1.6 c cairo cairomm-1.0
WANTLIB += expat fontconfig freetype gdk-x11-2.0 gdk_pixbuf-2.0
WANTLIB += gdkmm-2.4 gio-2.0 giomm-2.4 glib-2.0 glibmm-2.4 gmodule-2.0
WANTLIB += gobject-2.0 gthread-2.0 gtk-x11-2.0 gtkmm-2.4 m pango-1.0
WANTLIB += pangocairo-1.0 pangoft2-1.0 pangomm-1.4 pcre pixman-1
WANTLIB += png pthread pthread-stubs sigc-2.0 stdc++ util xcb
WANTLIB += xcb-render xcb-shm z

MASTER_SITES=	${MASTER_SITE_BERLIOS:=gsmartcontrol/}

MODULES=	devel/gettext
RUN_DEPENDS=	devel/desktop-file-utils \
		sysutils/smartmontools \
		x11/gtk+2,-guic
LIB_DEPENDS=	x11/gtk2mm

CONFIGURE_STYLE=	gnu

pre-configure:
	${SUBST_CMD} ${WRKSRC}/src/gsc_settings.h

.include <bsd.port.mk>
