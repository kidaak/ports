# $OpenBSD$

ONLY_FOR_ARCHS= ${APM_ARCHS}

COMMENT=	Advanced Power Management monitor utility for X

DISTNAME=	asapm-2.13
REVISION=	1

HOMEPAGE=	http://www.tigr.net/afterstep/

CATEGORIES=	x11

MASTER_SITES=	http://www.tigr.net/afterstep/download/asapm/

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB=		ICE SM X11 Xext Xpm c jpeg

LIB_DEPENDS=		graphics/jpeg

USE_GROFF =		Yes

CONFIGURE_STYLE=	gnu
CONFIGURE_ARGS+=	${CONFIGURE_SHARED}
CONFIGURE_ARGS+=	--with-afterdir=${PREFIX}/bin --enable-jpeg
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"

MAKE_FLAGS=		LIBS_JPEG="-ljpeg -L${LOCALBASE}/lib"
NO_REGRESS=		Yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/asapm ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/asapm.man ${PREFIX}/man/man1/asapm.1
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/asapm
	${INSTALL_DATA} ${WRKSRC}/asapmrc ${PREFIX}/share/examples/asapm/

.include <bsd.port.mk>
