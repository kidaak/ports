# $OpenBSD$

COMMENT=	puzzle game resembling the arcade game Qix
DISTNAME=	late-0.1.0
REVISION=	0
EXTRACT_SUFX=	.tar.bz2
CATEGORIES=	games x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=late/}

HOMEPAGE=	http://late.sourceforge.net/

# GPL
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
WANTLIB=		SDL X11 Xext c m pthread pthread-stubs stdc++ \
			usbhid xcb SDL_image

LIB_DEPENDS=	devel/sdl-image


CONFIGURE_STYLE=gnu
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/late/
	${INSTALL_DATA} /dev/null ${PREFIX}/share/examples/late/late.scores

.include <bsd.port.mk>
