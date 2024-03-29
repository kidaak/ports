# $OpenBSD$

SHARED_ONLY=	Yes

COMMENT=	addressbook manager

DISTNAME=	rubrica2-2.0.7
REVISION=	5
EPOCH=		0

CATEGORIES=	productivity x11

EXTRACT_SUFX=	.tar.bz2

HOMEPAGE=	http://rubrica.berlios.de

SHARED_LIBS +=  ral                  0.0      # .1.0

# GPLv3
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=	${MASTER_SITE_BERLIOS:=rubrica/}

WANTLIB += GL X11 Xau Xcomposite Xcursor Xdamage Xdmcp
WANTLIB += Xext Xfixes Xi Xinerama Xrandr Xrender Xxf86vm atk-1.0
WANTLIB += c cairo drm expat fontconfig freetype gdk-x11-2.0 gdk_pixbuf-2.0
WANTLIB += gio-2.0 glade-2.0 glib-2.0 gmodule-2.0 gobject-2.0
WANTLIB += gthread-2.0 gtk-x11-2.0 m notify pango-1.0 pangocairo-1.0
WANTLIB += pangoft2-1.0 pcre pixman-1 png pthread pthread-stubs
WANTLIB += xcb xcb-render xcb-shm xml2 z
WANTLIB += dbus-1 dbus-glib-1 ffi stdc++

MODULES=	devel/gettext \
		textproc/intltool \
		devel/gconf2

USE_GMAKE=	Yes
USE_LIBTOOL=	Yes

MODGCONF2_SCHEMAS_DIR= rubrica2

CONFIGURE_STYLE=gnu
CONFIGURE_ARGS=	${CONFIGURE_SHARED} \
		--enable-gtk-doc=no
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include"

# If one of these tools is found at configure stage, it might be used,
# no matter whether we use --disable-gtk-doc or not.
CONFIGURE_ENV +=ac_cv_path_GTKDOC_CHECK="" \
		ac_cv_path_GTKDOC_REBASE="" \
		ac_cv_path_GTKDOC_MKPDF=""

RUN_DEPENDS=	devel/desktop-file-utils \
		misc/shared-mime-info \
		x11/gnome/icon-theme

LIB_DEPENDS=	devel/libnotify>=0.7.2 \
		devel/libglade2

pre-configure:
	${SUBST_CMD} ${WRKSRC}/configure
	@find ${WRKSRC} -name Makefile.in -exec perl -pi \
		-e 's,-Wall -g,-Wall,g;' \
		-e 's,-Wmissing-prototypes -g,-Wmissing-prototypes,g' {} \;

post-install:
	ln -sf ${LOCALBASE}/share/icons/gnome \
		${PREFIX}/share/pixmaps/rubrica2/22x22/hicolor

.include <bsd.port.mk>
