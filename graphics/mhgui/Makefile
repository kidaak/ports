# $OpenBSD$

COMMENT=	GUI widget library used in MakeHuman

DISTNAME=	mhgui-0.2
CATEGORIES=	graphics
REVISION=	0

SHARED_LIBS +=  mhgui                1.0      # unknown

HOMEPAGE=	http://www.dedalo-3d.com/

# LGPLv2.1
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB += GL GLU ICE SM X11 Xdamage Xext Xfixes Xi Xmu Xt Xxf86vm
WANTLIB += animorph drm glut m png stdc++ xcb z

MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=makehuman/}

LIB_DEPENDS=	graphics/animorph>=0.3 \
		graphics/freeglut \
		graphics/png

USE_LIBTOOL=	Yes
CONFIGURE_STYLE=gnu
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include \
			-I${LOCALBASE}/include/GL \
			-I${LOCALBASE}/include/libpng" \
		LDFLAGS="-L${LOCALBASE}/lib -lz -lm"

CONFIGURE_ARGS=	${CONFIGURE_SHARED}

pre-configure:
	perl -pi -e 's,packagedocdir=doc,packagedocdir=share/doc,g' \
		${WRKSRC}/configure
	perl -pi -e 's,doc/mhgui,share/doc/mhgui,g' \
		${WRKSRC}/Makefile.in

# remove useless files (ChangeLog, INSTALL...)
post-install:
	rm -rf ${PREFIX}/share/doc

.include <bsd.port.mk>
