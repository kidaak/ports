# $OpenBSD$

SHARED_ONLY=		Yes

COMMENT=		Clearlooks based GTK+ 2.x engine

V=			0.6
DISTNAME=		39179-rezlooks-$V
PKGNAME=		gtk2-rezlooks-engine-$V
REVISION=		1
CATEGORIES=		x11

# GPLv2
PERMIT_PACKAGE_CDROM =	Yes 
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

THEMES_DISTNAME=rezlooks-themes-0.1

MASTER_SITES=	http://gnome-look.org/CONTENT/content-files/
MASTER_SITES0=	http://distfiles.nl/
DIST_SUBDIR=	rezlooks
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${THEMES_DISTNAME}${EXTRACT_SUFX}:0

MODULES=	devel/gettext

WANTLIB += X11 Xau Xcomposite Xcursor Xdamage Xdmcp Xext Xfixes
WANTLIB += Xi Xinerama Xrandr Xrender expat fontconfig freetype
WANTLIB += m pixman-1 pthread-stubs xcb xcb-render xcb-render-util
WANTLIB += z gtk-x11-2.0 gdk-x11-2.0
WANTLIB += atk-1.0 cairo gdk_pixbuf-2.0 gio-2.0 glib-2.0
WANTLIB += gmodule-2.0 gobject-2.0 gthread-2.0 pango-1.0 pangocairo-1.0
WANTLIB += pangoft2-1.0 pcre png

LIB_DEPENDS =	x11/gtk+2

USE_LIBTOOL =	Yes

WRKDIST= 	${WRKDIR}/rezlooks-$V

LIBTOOL_FLAGS=	--tag=disable-static
CONFIGURE_STYLE=gnu 
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS= ${CONFIGURE_SHARED} \
		--disable-static

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/themes/
	cp -R ${WRKDIR}/${THEMES_DISTNAME}/* ${PREFIX}/share/themes/
	@chown -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/themes/*


.include <bsd.port.mk>
