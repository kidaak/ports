# $OpenBSD$

COMMENT=	multimedia player

DISTNAME=	xine-ui-0.99.7
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xine/}
EXTRACT_SUFX=	.tar.xz

HOMEPAGE=	http://www.xine-project.org/

# GPLv2+
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB=	X11 Xext Xft Xinerama Xss Xtst Xv Xxf86vm c curl jpeg m ncurses \
		png pthread readline xine z

MODULES=	devel/gettext
RUN_DEPENDS=	devel/desktop-file-utils \
		misc/shared-mime-info \
		x11/gtk+2,-guic
LIB_DEPENDS=	graphics/jpeg \
		graphics/png \
		multimedia/xine-lib \
		net/curl

MAKE_FLAGS=	V=1

USE_GMAKE=	Yes
USE_LIBTOOL=	Yes
USE_GROFF=	Yes
CONFIGURE_STYLE= gnu
CONFIGURE_ARGS+=--disable-lirc \
		--disable-nvtvsimple \
		--disable-vdr-keys \
		--without-aalib \
		--without-caca
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include -I${LOCALBASE}/include -I${LOCALBASE}/include/libpng" \
		LDFLAGS="-L${X11BASE}/lib -L${LOCALBASE}/lib"

.include <bsd.port.mk>
