# $OpenBSD$

COMMENT-main =	graphical tools for the MetaGeek Wi-spy spectrum analyser
COMMENT-utils =	tools for the MetaGeek Wi-spy spectrum analyser

V =		2011-08-R1
DISTNAME =	spectools-$V
PKGNAME =	spectrum-tools-$V

FULLPKGNAME-main =  spectrum-tools-${V:S/-//g}
FULLPKGNAME-utils = spectrum-tools-utils-${V:S/-//g}

CATEGORIES =	net

MASTER_SITES =	http://www.kismetwireless.net/code/

HOMEPAGE =	http://www.kismetwireless.net/spectools/

MAINTAINER =	Chris Kuethe <ckuethe@openbsd.org>

# GPLv2+
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

MULTI_PACKAGES =	-main -utils

cWANTLIB =	c m pthread usb
MODULES =	devel/gettext

WANTLIB-main =	${cWANTLIB} ${MODGETTEXT_WANTLIB} \
		GL X11 Xcomposite Xcursor Xdamage Xext Xfixes \
		Xi Xinerama Xrandr Xrender atk-1.0 cairo expat \
		fontconfig freetype gio-2.0 glib-2.0 gmodule-2.0 gobject-2.0 \
		pango-1.0 pangocairo-1.0 pangoft2-1.0 pixman-1 \
		png pthread-stubs xcb z gdk_pixbuf-2.0 gdk-x11-2.0 \
		gtk-x11-2.0 gthread-2.0 xcb-render xcb-shm

WANTLIB-utils =	${cWANTLIB} ncurses

LIB_DEPENDS-utils =	devel/libusb-compat

LIB_DEPENDS-main +=	${LIB_DEPENDS} \
			devel/libusb-compat \
			x11/gtk+2

RUN_DEPENDS-main =	net/spectrum-tools,-utils
RUN_DEPENDS-utils =	# empty

CONFIGURE_STYLE =	gnu
CONFIGURE_ENV +=	CPPFLAGS="-I${LOCALBASE}/include" \
			CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"
USE_GMAKE =		Yes

NO_REGRESS =		Yes

pre-configure:
	perl -pi -e 's,-lpthread,-pthread,g' ${WRKSRC}/configure

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/spectrum-tools
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/spectrum-tools

.include <bsd.port.mk>
