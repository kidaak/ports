# $OpenBSD$

SHARED_ONLY=	Yes

COMMENT-main=	viewer for multiple document formats
COMMENT-djvu=	evince document viewer backend for djvu documents
COMMENT-dvi=	evince document viewer backend for dvi documents
COMMENT-nautilus= evince plugin for nautilus

GNOME_PROJECT=	evince
GNOME_VERSION=	3.6.0

MAJ_V=		3.0
SUBST_VARS=	MAJ_V

CATEGORIES=	graphics print

PKGNAME-main=	${DISTNAME}
PKGNAME-djvu=	evince-djvu-${GNOME_VERSION}
PKGNAME-dvi=	evince-dvi-${GNOME_VERSION}
PKGNAME-nautilus= nautilus-evince-${GNOME_VERSION}

SHARED_LIBS +=  evdocument3               0.0 # 3.0
SHARED_LIBS +=  evview3                   0.0 # 3.0

HOMEPAGE=	http://www.gnome.org/projects/evince/

MAINTAINER=	Jasper Lievisse Adriaanse <jasper@openbsd.org>, \
		Antoine Jacoutot <ajacoutot@openbsd.org>

# GPLv2
PERMIT_PACKAGE_FTP=	Yes
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes

MODULES=	devel/gettext \
		x11/gnome \
		devel/dconf

USE_GROFF =	Yes

BUILD_DEPENDS=	x11/gnome/icon-theme \
		devel/gsettings-desktop-schemas

WANTLIB += X11 Xcomposite Xcursor Xdamage Xext Xfixes drm stdc++
WANTLIB += Xi Xinerama Xrandr Xrender atk-1.0 cairo expat fontconfig
WANTLIB += freetype gdk-3 gdk_pixbuf-2.0 gio-2.0 glib-2.0
WANTLIB += gmodule-2.0 gobject-2.0 gtk-3 pango-1.0 Xau Xdmcp Xxf86vm
WANTLIB += pangocairo-1.0 pangoft2-1.0 pcre pixman-1 png pthread-stubs
WANTLIB += GL xcb-shm xcb xcb-render z gthread-2.0 cairo-gobject m ffi
WANTLIB += atk-bridge-2.0 atspi harfbuzz icudata icule icuuc

MODGNOME_TOOLS= goi yelp

LIB_DEPENDS=	x11/gtk+3

WANTLIB-main=	${WANTLIB} ICE SM c dbus-1 gailutil-3 \
		gnome-keyring gs gcrypt gpg-error \
		jpeg pthread tiff xml2 lcms2 openjpeg \
		poppler poppler-glib spectre gnome-keyring
LIB_DEPENDS-main= print/poppler \
		print/libspectre \
		x11/gnome/libgnome-keyring \
		${LIB_DEPENDS}
RUN_DEPENDS-main= ${RUN_DEPENDS} \
		devel/gsettings-desktop-schemas \
		misc/shared-mime-info \
		print/ghostscript/gnu \
		x11/gnome/icon-theme \
		${MODGNOME_RUN_DEPENDS_yelp}

WANTLIB-djvu=	${WANTLIB} jpeg evdocument3 djvulibre ICE SM \
		 dbus-1 pthread
# port-lib-depends-check misses these ones because the depending lib
# is under lib/evince/3/backends/
LIB_DEPENDS-djvu= ${LIB_DEPENDS} \
		${BASE_PKGPATH} \
		graphics/djvulibre

WANTLIB-dvi=	${WANTLIB} gs evdocument3 kpathsea spectre ICE SM \
		jpeg
# port-lib-depends-check misses these ones because the depending lib
# is under lib/evince/3/backends/
LIB_DEPENDS-dvi= ${LIB_DEPENDS} \
		${BASE_PKGPATH} \
		print/texlive/base \
		print/libspectre

WANTLIB-nautilus= ${WANTLIB} gthread-2.0 nautilus-extension evdocument3 \
		ICE SM dbus-1 pthread
LIB_DEPENDS-nautilus= ${BASE_PKGPATH} \
		${LIB_DEPENDS} \
		x11/gnome/nautilus
RUN_DEPENDS-nautilus=

MODGNOME_DESKTOP_FILE=	Yes
MODGNOME_ICON_CACHE=	Yes

LIBTOOL_FLAGS=	--tag=disable-static

CONFIGURE_STYLE=gnu
CONFIGURE_ARGS+= --disable-static \
		--disable-comics

MODGNOME_CPPFLAGS=${CFLAGS}
CONFIGURE_ENV=	CXXFLAGS="${CXXFLAGS} -I${LOCALBASE}/include"

MULTI_PACKAGES=	-main -djvu -dvi -nautilus
PSEUDO_FLAVORS=	no_djvu no_dvi no_nautilus light
FLAVOR?=
.if ${FLAVOR:Mlight}
FLAVOR += no_djvu no_dvi no_nautilus
.endif

.include <bsd.port.arch.mk>

.for s in -nautilus -djvu -dvi
.  if ${BUILD_PACKAGES:M$s}
CONFIGURE_ARGS+= --enable$s
.  else
CONFIGURE_ARGS+= --disable$s
.  endif
.endfor

.include <bsd.port.mk>
