# $OpenBSD$

SHARED_ONLY=		Yes

COMMENT=		pangox compatibility library

GNOME_VERSION=		0.0.1
GNOME_PROJECT=		pangox-compat

SHARED_LIBS +=  pangox-1.0         2906.0   # 0.0

CATEGORIES=		devel x11

HOMEPAGE=		http://www.pango.org/

MAINTAINER=		Antoine Jacoutot <ajacoutot@openbsd.org>

# LGPLv2
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB += X11 ffi glib-2.0 gmodule-2.0 gobject-2.0 gthread-2.0
WANTLIB += m pango-1.0 pcre pthread xcb

MODULES=		devel/gettext \
			x11/gnome

LIB_DEPENDS=		devel/pango>=1.31.2

LIBTOOL_FLAGS=		--tag=disable-static

CONFIGURE_STYLE=	gnu
CONFIGURE_ARGS=		${CONFIGURE_SHARED} \
			--disable-static

FAKE_FLAGS=		sysconfdir=${PREFIX}/share/examples

.include <bsd.port.mk>
