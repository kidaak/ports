# $OpenBSD$

COMMENT=	SDL C++ GUI widget library

DISTNAME=	GUIlib-1.2.1
PKGNAME=	${DISTNAME:L}

SHARED_LIBS +=	GUI                  2.0      # .0.1

CATEGORIES=	devel graphics
MASTER_SITES=	${HOMEPAGE}/src/

HOMEPAGE=	http://www.libsdl.org/projects/GUIlib/

# Public Domain
PERMIT_PACKAGE_CDROM=   Yes
PERMIT_PACKAGE_FTP=     Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=   Yes

WANTLIB += SDL m sndio stdc++ usbhid

LIB_DEPENDS=	devel/sdl

MODULES=	converters/libiconv

USE_LIBTOOL=		Yes
SEPARATE_BUILD=		Yes
CONFIGURE_STYLE=	gnu
CONFIGURE_ENV+=		LDFLAGS="-L${X11BASE}/lib"
CONFIGURE_ARGS+=	${CONFIGURE_SHARED}

.include <bsd.port.arch.mk>

.if ${PROPERTIES:Mgcc[34]}
MAKE_FLAGS+=libGUI_la_LIBADD=-lsupc++
.endif

.include <bsd.port.mk>
