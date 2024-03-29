# $OpenBSD$

COMMENT-main=		screen saver and locker for the X Window System
COMMENT-data=		graphical demos (savers) for screensavers

V=			5.19
DISTNAME=		xscreensaver-${V}
PKGNAME-main=		${DISTNAME}
PKGNAME-data=		xscreensaver-data-${V}

CATEGORIES=		x11

HOMEPAGE=		http://www.jwz.org/xscreensaver/

# BSD
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=	Yes

MULTI_PACKAGES=	-main -data

WANTLIB=	GL GLU ICE SM X11 Xext Xmu Xpm Xt Xxf86vm c glib-2.0 \
		gmodule-2.0 gobject-2.0 m pthread

WANTLIB-main=	${WANTLIB} Xcomposite Xcursor Xdamage Xfixes \
		Xi Xinerama Xrandr Xrender Xxf86misc atk-1.0 cairo \
		expat fontconfig freetype gdk-x11-2.0 gdk_pixbuf-2.0 \
		gdk_pixbuf_xlib-2.0 gio-2.0 gtk-x11-2.0 jpeg \
		pango-1.0 pangocairo-1.0 pangoft2-1.0 pixman-1 png \
		pthread-stubs xcb xml2 z xcb-render glade-2.0 \
		xcb-shm

WANTLIB-data=	${WANTLIB} jpeg util gdk_pixbuf-2.0 gdk_pixbuf_xlib-2.0 \
		gle

MASTER_SITES=		${HOMEPAGE}

MODULES=		devel/gettext \
			textproc/intltool

# note that we don't need desktop-file-utils for the -data subpackage
# because the desktop files it installs are under a subdirectory of
# ${LOCALBASE}/share/applications/
RUN_DEPENDS-main=	devel/desktop-file-utils \
			x11/xscreensaver,-data

LIB_DEPENDS-main=	${MODGETTEXT_LIB_DEPENDS} \
			devel/libglade2

LIB_DEPENDS-data=	${MODGETTEXT_LIB_DEPENDS} \
			graphics/gdk-pixbuf2 \
			graphics/gle

# ${FILESDIR}/migrate-xscreensaver-config.sh needs xsltproc
BUILD_DEPENDS +=	textproc/libxslt

# see pre-configure
BUILD_DEPENDS +=	devel/xdg-utils
RUN_DEPENDS-main +=	devel/xdg-utils

USE_GMAKE=		Yes
USE_GROFF=		Yes
NO_REGRESS=		Yes

CONFIGURE_STYLE=	gnu
CONFIGURE_ARGS=		--with-hackdir="${PREFIX}/libexec/xscreensaver" \
			--with-x-app-defaults="${PREFIX}/lib/X11/app-defaults"
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib -liconv -lintl"

post-extract:
	cp ${FILESDIR}/migrate-xscreensaver-config.sh ${WRKSRC}/hacks/config
	cp ${FILESDIR}/xscreensaver-config.xsl ${WRKSRC}/hacks/config

pre-configure:
	perl -pi -e 's,gnome-open,xdg-open,g' ${WRKSRC}/configure

post-install:
# remove conflict on games/circuit, misc/deco
	for i in circuit deco ; do \
		mv ${PREFIX}/man/man6/$${i}.6 ${PREFIX}/man/man6/x$${i}.6 ; \
		mv ${PREFIX}/libexec/xscreensaver/$${i} \
			${PREFIX}/libexec/xscreensaver/x$${i} && \
		mv ${PREFIX}/share/xscreensaver/config/$${i}.xml \
			${PREFIX}/share/xscreensaver/config/x$${i}.xml && \
		mv ${WRKSRC}/hacks/config/$${i}.xml \
			${WRKSRC}/hacks/config/x$${i}.xml ; done
	cd ${WRKSRC}/hacks/config && \
		for i in ${WRKSRC}/hacks/config/*.xml; do \
			/bin/sh migrate-xscreensaver-config.sh $${i} ; done
# conflict with x11/gnome/screensaver and is not needed by xscreensaver per se
	rm ${WRKSRC}/hacks/config/popsquares.desktop
	${INSTALL_DATA_DIR} ${PREFIX}/share/applications/screensavers/
	${INSTALL_DATA} ${WRKSRC}/hacks/config/*.desktop \
		${PREFIX}/share/applications/screensavers/

.include <bsd.port.mk>
