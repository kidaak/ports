# $OpenBSD$

COMMENT = 			seam-carving smart rescale gimp plugin
CATEGORIES =			graphics

HOMEPAGE = 			http://liquidrescale.wikidot.com/
DISTNAME = 			gimp-lqr-plugin-0.4.0-4
PKGNAME = 			gimp-lqr-plugin-0.4.0.4
REVISION =			5
WRKDIST =			${WRKDIR}/gimp-lqr-plugin-0.4.0
MASTER_SITES =			${HOMEPAGE}local--files/en:download-page/

# GPLv2
PERMIT_PACKAGE_FTP = 		Yes
PERMIT_PACKAGE_CDROM =		Yes
PERMIT_DISTFILES_FTP =		Yes
PERMIT_DISTFILES_CDROM =	Yes

MODULES =			textproc/intltool \
				devel/gettext

CONFIGURE_STYLE =		gnu

LIB_DEPENDS =			graphics/liblqr \
				graphics/gimp/stable

WANTLIB += X11 Xcomposite Xcursor Xdamage Xext Xfixes
WANTLIB += Xi Xinerama Xrandr Xrender c expat fontconfig freetype
WANTLIB += glib-2.0 gmodule-2.0 gobject-2.0 gthread-2.0 m pixman-1 pthread z
WANTLIB += atk-1.0 cairo gdk-x11-2.0 gdk_pixbuf-2.0 gtk-x11-2.0
WANTLIB += pango-1.0 pangocairo-1.0 pangoft2-1.0 png pthread-stubs xcb
WANTLIB += gio-2.0 lqr-1 gimp-2.0 gimpbase-2.0 gimpcolor-2.0 gimpconfig-2.0 
WANTLIB += gimpmath-2.0 gimpmodule-2.0 gimpui-2.0 gimpwidgets-2.0
WANTLIB += GL xcb-render xcb-shm

.include <bsd.port.mk>
