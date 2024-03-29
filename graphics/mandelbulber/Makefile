# $OpenBSD$

COMMENT =		3D fractal renderer

V =			1.11
DISTNAME =		mandelbulber${V}
PKGNAME =		mandelbulber-${V}

CATEGORIES =		graphics

HOMEPAGE =		https://sites.google.com/site/mandelbulber/

# GPLv3
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

WANTLIB += atk-1.0 cairo gdk-x11-2.0 gdk_pixbuf-2.0 gio-2.0 glib-2.0
WANTLIB += gobject-2.0 gthread-2.0 gtk-x11-2.0 jpeg
WANTLIB += pango-1.0 pangocairo-1.0 pangoft2-1.0 png z
WANTLIB += GL X11 Xcomposite Xcursor Xdamage Xext Xfixes Xi Xinerama
WANTLIB += Xrandr Xrender c expat fontconfig freetype m pixman-1
WANTLIB += pthread pthread-stubs stdc++ xcb xcb-render xcb-shm

MASTER_SITES =		${MASTER_SITE_SOURCEFORGE:=mandelbulber/}

MODULES =		devel/gettext
LIB_DEPENDS =		graphics/png \
			x11/gtk+2

NO_REGRESS =		Yes

MAKE_FLAGS =		CXXFLAGS="${CXXFLAGS} -I${LOCALBASE}/include"

USE_GMAKE =		Yes

MAKE_FILE =		makefile
WRKSRC =		${WRKDIST}/makefiles

post-extract:
	perl -pi -e 's#/usr/share/#${PREFIX}/share/#;' \
		${WRKDIST}/usr/share/defaults ${WRKDIST}/mandelbulber.desktop \
		${WRKDIST}/usr/share/examples/*.fract \
		${WRKDIST}/src/interface.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mandelbulber ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/mandelbulber
	${INSTALL_DATA_DIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKDIST}/usr/share/defaults \
		${PREFIX}/share/mandelbulber
	${INSTALL_DATA} ${WRKDIST}/mandelbulber.desktop \
		${PREFIX}/share/applications
.for dir in exampleKeyframes examples icons textures
	${INSTALL_DATA_DIR} ${PREFIX}/share/mandelbulber/${dir}
	${INSTALL_DATA} ${WRKDIST}/usr/share/${dir}/* \
	${PREFIX}/share/mandelbulber/${dir}
.endfor

.include <bsd.port.mk>
