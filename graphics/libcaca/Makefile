# $OpenBSD$

COMMENT=		color ascii art library

DISTNAME=		libcaca-0.99.beta17
PKGNAME=		libcaca-0.99.17
REVISION=		0
SHARED_LIBS +=  caca           1.0               # .0.99
CATEGORIES=		graphics

# LGPLv2.1/Do What The Fuck You Want To Public License
PERMIT_PACKAGE_CDROM=   Yes
PERMIT_PACKAGE_FTP=     Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=   Yes

WANTLIB=		c ncursesw m z

HOMEPAGE=		http://caca.zoy.org/
MASTER_SITES=		${HOMEPAGE}/files/libcaca/ \
			http://distfiles.nl/

BUILD_DEPENDS=		${RUN_DEPENDS}
RUN_DEPENDS=		misc/zzuf
REGRESS_DEPENDS=	devel/cppunit

USE_LIBTOOL=		Yes
USE_GROFF =		Yes

FLAVORS=		no_x11
FLAVOR?=

.if ${FLAVOR:Mno_x11}
CONFIGURE_ARGS+=	--disable-x11 \
			--disable-imlib2
.else
LIB_DEPENDS =    	graphics/imlib2
WANTLIB +=		X11 Xext freetype xcb Imlib2>=1
.endif

CONFIGURE_STYLE= 	gnu
CONFIGURE_ARGS+=	--disable-doc \
			--disable-slang \
			--disable-ruby \
			--disable-java \
			--disable-csharp \
			--disable-cxx

.include <bsd.port.mk>
