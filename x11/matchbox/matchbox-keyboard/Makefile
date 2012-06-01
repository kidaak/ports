# $OpenBSD$

COMMENT=	on-screen virtual keyboard
DISTNAME=	matchbox-keyboard-0.1
REVISION=	6

MASTER_SITES=	${MASTER_SITES_MATCHBOX:=matchbox-keyboard/0.1/}

LIB_DEPENDS=	x11/matchbox/libfakekey
RUN_DEPENDS=	x11/matchbox/matchbox-common \
		devel/desktop-file-utils

WANTLIB=	X11 Xau Xdmcp Xext Xft Xrender Xtst c expat fontconfig freetype z \
		pthread-stubs xcb fakekey

CONFIGURE_STYLE=gnu
CONFIGURE_ARGS+=--enable-nls
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/libpng" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
