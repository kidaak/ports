# $OpenBSD$

COMMENT=		utility library including a imlib2 wrapper

DISTNAME=		giblib-1.2.4
REVISION =		5
SHARED_LIBS=		giblib	1.6	# .1.6

CATEGORIES=		devel

HOMEPAGE=		http://www.linuxbrit.co.uk/giblib/

MAINTAINER=		Victor Sahlstedt <salan@legonet.org>

# BSD
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=	Yes
WANTLIB=		X11 Xext freetype m xcb z

MASTER_SITES=		http://www.linuxbrit.co.uk/downloads/

LIB_DEPENDS=		graphics/imlib2
WANTLIB +=		Imlib2>=1

USE_LIBTOOL=		Yes
CONFIGURE_STYLE=	gnu
CONFIGURE_ENV=		CPPFLAGS="-I${X11BASE}/include" \
			LDFLAGS="-L${X11BASE}/lib"

FAKE_FLAGS+=		docsdir=${PREFIX}/share/doc/giblib/

.include <bsd.port.mk>
