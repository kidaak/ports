# $OpenBSD$

COMMENT=		high-performance 2D graphics library

GNOME_PROJECT=		libart_lgpl
GNOME_VERSION=		2.3.21
PKGNAME=		libart-${VERSION}

SHARED_LIBS +=	art_lgpl_2           5.20     # .5.20

CATEGORIES=		graphics

HOMEPAGE=		http://www.levien.com/libart/

# LGPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

EXTRACT_SUFX=		.tar.bz2

WANTLIB=		m

MODULES=		x11/gnome

CONFIGURE_STYLE= 	gnu

.include <bsd.port.mk>
