# $OpenBSD$

COMMENT=		tool for producing computational artwork
DISTNAME=		fyre-1.0.1
REVISION=		13
CATEGORIES=		graphics

HOMEPAGE=		http://fyre.navi.cx/

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB += GL Half Iex IlmImf IlmThread Imath X11 Xcomposite Xcursor
WANTLIB += Xdamage Xext Xfixes Xi Xinerama Xrandr Xrender atk-1.0
WANTLIB += c cairo expat fontconfig freetype gdk-x11-2.0 gdk_pixbuf-2.0
WANTLIB += gio-2.0 glade-2.0 glib-2.0 gobject-2.0 gtk-x11-2.0
WANTLIB += m pango-1.0 pangocairo-1.0 pangoft2-1.0 pixman-1 png
WANTLIB += pthread pthread-stubs stdc++ xcb xcb-render xcb-shm
WANTLIB += xml2 z

MASTER_SITES=		http://releases.navi.cx/fyre/ \
			http://distfiles.nl/

MODULES=		devel/gettext

BUILD_DEPENDS=		textproc/rarian
LIB_DEPENDS=		devel/libglade2 \
			graphics/openexr
RUN_DEPENDS=		devel/desktop-file-utils \
			misc/shared-mime-info \
			x11/gtk+2,-guic

USE_GMAKE=		Yes

CONFIGURE_STYLE=	gnu
CONFIGURE_ARGS= 	--enable-openexr \
			--disable-gnet

# quirky, but prevents a patch
post-patch:
	@ln -s /usr/bin/true ${WRKDIR}/bin/update-mime-database
	@ln -s /usr/bin/true ${WRKDIR}/bin/update-desktop-database

.include <bsd.port.mk>
