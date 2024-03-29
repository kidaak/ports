# $OpenBSD$

COMMENT=		Free Unix Spectrum Emulator
DISTNAME=		fuse-0.10.0.2
REVISION=		6
CATEGORIES=		emulators
HOMEPAGE=		http://fuse-emulator.sourceforge.net/

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB += X11 Xext Xau Xdmcp audiofile gcrypt gpg-error pcre
WANTLIB += bz2 c m z pthread-stubs xcb glib-2.0 samplerate spectrum
WANTLIB += png xml2 ao

MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fuse-emulator/}

USE_GROFF=		Yes

MODULES=		devel/gettext
LIB_DEPENDS=		devel/glib2 \
			audio/libsamplerate \
			devel/libspectrum \
			graphics/png \
			textproc/libxml \
			audio/libao

CONFIGURE_STYLE=	gnu
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include/libpng" \
			LDFLAGS="-L${LOCALBASE}/lib" \
			LIBS="-lbz2"
CONFIGURE_ARGS=		--with-libao

FLAVORS=gtk
FLAVOR?=

.if ${FLAVOR:Mgtk}
LIB_DEPENDS+=		x11/gtk+2 \
			devel/glib2
CONFIGURE_ARGS+=	--with-gtk2
WANTLIB+=		Xcomposite Xcursor Xdamage Xfixes Xi Xinerama Xrandr \
			Xrender atk-1.0 cairo expat fontconfig freetype \
			pango-1.0 pangocairo-1.0 pangoft2-1.0 pixman-1 \
			gdk_pixbuf-2.0 gdk-x11-2.0 gtk-x11-2.0 gio-2.0 \
			gmodule-2.0 gobject-2.0
.else
CONFIGURE_ARGS+=	--without-gtk
WANTLIB+=		ICE SM
.endif

.include <bsd.port.mk>
