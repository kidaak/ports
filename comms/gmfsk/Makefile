# $OpenBSD$

COMMENT=	GNOME multimode HF terminal

GNOME_PROJECT=	gmfsk
GNOME_VERSION=	0.6
REVISION=	18
CATEGORIES=    	comms hamradio

HOMEPAGE=	http://gmfsk.connect.fi/
MASTER_SITES=	${HOMEPAGE}	\
		http://he.fi/pub/ham/unix/linux/hfmodems/
EXTRACT_SUFX=	.tar.gz

# GPLv2 - FDL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB += GL ICE ORBit-2 SM X11 Xcomposite Xcursor Xdamage Xext
WANTLIB += Xfixes Xi Xinerama Xrandr Xrender art_lgpl_2 atk-1.0
WANTLIB += bonobo-2 bonobo-activation bonoboui-2 c cairo expat
WANTLIB += fftw fontconfig freetype gdk-x11-2.0 gdk_pixbuf-2.0
WANTLIB += gio-2.0 glib-2.0 gmodule-2.0 gnome-2 gnomecanvas-2
WANTLIB += gnomeui-2 gnomevfs-2 gobject-2.0 gthread-2.0 gtk-x11-2.0
WANTLIB += hamlib m pango-1.0 pangocairo-1.0 pangoft2-1.0 pixman-1
WANTLIB += png popt pthread pthread-stubs sndio stdc++ xcb xcb-render
WANTLIB += xcb-shm z

MODULES=		devel/gettext \
			x11/gnome \
			devel/gconf2

MODGNOME_TOOLS= 	yelp
USE_GMAKE=		No
MODGCONF2_SCHEMAS_DIR=	gmfsk

BUILD_DEPENDS=		textproc/rarian
LIB_DEPENDS=		comms/hamlib \
			math/fftw \
			x11/gtk+2 \
			x11/gnome/libgnomeui

CONFIGURE_STYLE=	gnu
CONFIGURE_ARGS=		--enable-hamlib
CONFIGURE_ENV=		LIBS="-lsndio"

.include <bsd.port.mk>
