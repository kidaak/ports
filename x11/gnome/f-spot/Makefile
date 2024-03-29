# $OpenBSD$

SHARED_ONLY=		Yes

COMMENT=		personal photo management application for GNOME

GNOME_VERSION=		0.8.2
GNOME_PROJECT=		f-spot
REVISION=		5

CATEGORIES=		graphics

HOMEPAGE=		http://www.f-spot.org/

# GPLv2
# gio-sharp: LGPLv2.1
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

EXTRACT_SUFX=		.tar.bz2

WANTLIB += ICE ORBit-2 ORBitCosNaming-2 SM X11 Xau Xcomposite
WANTLIB += Xcursor Xdamage Xdmcp Xext Xfixes Xi Xinerama Xrandr
WANTLIB += Xrender art_lgpl_2 atk-1.0
WANTLIB += bonobo-2 bonobo-activation bonoboui-2 cairo
WANTLIB += crypto dbus-1 dbus-glib-1 expat fontconfig
WANTLIB += freetype gailutil gcrypt gdk-x11-2.0 gdk_pixbuf-2.0
WANTLIB += gio-2.0 glib-2.0 gmodule-2.0 gnome-2 gnome-keyring
WANTLIB += gnomecanvas-2 gnomeui-2 gnomevfs-2 gobject-2.0 gpg-error
WANTLIB += gthread-2.0 gtk-x11-2.0 jpeg m pango-1.0 pangocairo-1.0
WANTLIB += pangoft2-1.0 pcre pixman-1 png popt pthread-stubs ssl
WANTLIB += util xcb xcb-render xml2 z lcms xcb-shm ffi stdc++
WANTLIB += GL Xxf86vm canberra drm ltdl ogg pthread vorbis vorbisfile

MODULES=		devel/gettext \
			lang/mono \
			x11/gnome \
			devel/gconf2

MODGNOME_DESKTOP_FILE=	Yes
MODGNOME_ICON_CACHE=	Yes
MODGNOME_TOOLS= 	yelp

BUILD_DEPENDS=		${RUN_DEPENDS} \
			shells/bash \
			x11/gnome/screensaver
RUN_DEPENDS=		devel/mono-addins \
			x11/gnome/mono-gnome \
			sysutils/ndesk-dbus-glib \
			devel/mono-flickrnet \
			x11/gnome/mono-keyring \
			devel/libunique
LIB_DEPENDS+=		graphics/lcms

MODGCONF2_SCHEMAS_DIR=	f-spot

LIBTOOL_FLAGS=		--tag=disable-static

CONFIGURE_ARGS+=	--disable-shave \
			--disable-static

DLLMAP_FILES=		lib/unique-sharp/unique/unique-sharp.dll.config \
			lib/gtk-sharp-beans/gtk-sharp-beans.dll.config \
			lib/gio-sharp/gio/gio-sharp.dll.config \
			lib/Hyena/Hyena.Gui/Hyena.Gui.dll.config \
			lib/Hyena/Hyena/Hyena.dll.config \
			src/Clients/MainApp/f-spot.exe.config \
			src/Core/FSpot.Cms/FSpot.Cms.dll.config \
			src/Core/FSpot.Gui/FSpot.Gui.dll.config \
			src/Core/FSpot.Core/FSpot.Core.dll.config \
			src/Core/FSpot.Utils/FSpot.Utils.dll.config

FAKE_FLAGS=		schemadir=${PREFIX}/${SCHEMAS_INSTDIR}

pre-configure:
	${SUBST_CMD} ${WRKSRC}/icon-theme-installer \
		${WRKSRC}/src/Clients/MainApp/f-spot.in \
		${WRKSRC}/src/Clients/MainApp/FSpot/ColorManagement.cs \
		${WRKSRC}/src/Clients/MainApp/FSpot.UI.Dialog/PreferenceDialog.cs

post-install:
	rm ${PREFIX}/lib/f-spot/*.la

.include <bsd.port.mk>
