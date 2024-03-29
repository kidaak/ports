# $OpenBSD$

COMMENT=		library for powerful image loading capabilities

DISTNAME=		DevIL-1.7.8
REVISION=		5
SHARED_LIBS+=		IL	0.0 # 2.0

CATEGORIES=		graphics devel

HOMEPAGE=		http://openil.sourceforge.net/

# LGPLv2.1
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=openil/}
EXTRACT_SUFX=		.zip

WANTLIB += Half Iex IlmImf IlmThread Imath jasper jpeg lcms m
WANTLIB += mng png pthread stdc++ tiff z

LIB_DEPENDS=		graphics/ilmbase \
			graphics/jasper \
			graphics/libmng \
			graphics/lcms \
			graphics/openexr \
			graphics/openjpeg \
			graphics/tiff \
			graphics/png

USE_LIBTOOL=		Yes

AUTOCONF_VERSION=	2.61
CONFIGURE_STYLE=	autoconf
CONFIGURE_ARGS+=	--with-squish=no \
			--with-zlib=yes
# This would only install three binary examples, we'll install it manually.
CONFIGURE_ARGS+=	--with-examples=no
CONFIGURE_ENV=  	CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/libpng/ -I${X11BASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib -lm -lz"

WRKDIST=		${WRKDIR}/${DISTNAME:L}

# Too many Linuxisms in testing tools
NO_REGRESS=		Yes

post-extract:
	chmod +x ${WRKSRC}/configure
	${SUBST_CMD} ${WRKSRC}/test/Makefile.in

post-configure:
	chmod +x ${WRKDIST}/build-aux/install-sh

post-install:
	@cd ${WRKSRC}; tar cf - examples | tar xf - -C \
		${PREFIX}/share/devil/

.include <bsd.port.mk>
