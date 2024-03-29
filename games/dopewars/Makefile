# $OpenBSD$

COMMENT=	game where you deal drugs on the streets of NY

DISTNAME=	dopewars-1.5.12
REVISION=	7
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dopewars/}

HOMEPAGE=	http://dopewars.sourceforge.net/

# GPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes
WANTLIB=		c ncurses

MODULES+=	devel/gettext

LIB_DEPENDS+=   devel/glib2
WANTLIB +=	gio-2.0 glib-2.0

LOCALSTATEDIR=	${BASELOCALSTATEDIR}/games

USE_LIBTOOL=	Yes
USE_GROFF =	Yes
CONFIGURE_STYLE= gnu
CONFIGURE_ARGS+= --enable-nls \
		 --enable-strict \
		 --without-esd \
		 --disable-gui-server \
		 --disable-plugins \
		 --disable-sdl
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

FLAVORS=	no_x11
FLAVOR?=

.if ${FLAVOR:Mno_x11}
CONFIGURE_ARGS+= --disable-gui-client
.else
LIB_DEPENDS+=	x11/gtk+2
WANTLIB+=	X11 Xext Xrender Xrandr expat fontconfig freetype m z cairo \
		Xau Xcomposite Xcursor Xdamage Xdmcp Xfixes Xi Xinerama \
		gmodule-2.0 gobject-2.0 atk-1.0 pango-1.0 \
		pangoft2-1.0 pangocairo-1.0 pixman-1 png pthread-stubs \
		xcb gdk_pixbuf-2.0 gdk-x11-2.0 gtk-x11-2.0
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/dopewars
	${INSTALL_DATA} ${WRKSRC}/doc/example-cfg \
		${PREFIX}/share/examples/dopewars/dopewars.cfg
	${INSTALL_DATA} /dev/null ${PREFIX}/share/examples/dopewars/dopewars.sco
	${PREFIX}/bin/dopewars -C ${PREFIX}/share/examples/dopewars/dopewars.sco

.include <bsd.port.mk>
