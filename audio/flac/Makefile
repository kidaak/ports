# $OpenBSD$

COMMENT=	free lossless audio codec

DISTNAME=	flac-1.2.1
REVISION=	1
CATEGORIES=	audio archivers
HOMEPAGE=	http://flac.sourceforge.net/
SHARED_LIBS +=  FLAC                 9.0      # .10.0
SHARED_LIBS +=  FLAC++               8.0      # .8.0

MAINTAINER=	Christian Weisgerber <naddy@openbsd.org>

# BSD, GPL, GFDL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=flac/}

WANTLIB=	c m ogg>=5 stdc++

MODULES=	converters/libiconv
LIB_DEPENDS=	audio/libogg

.if ${MACHINE_ARCH} == "i386"
BUILD_DEPENDS+=	devel/nasm
.endif

USE_LIBTOOL=	Yes
CONFIGURE_STYLE=gnu
CONFIGURE_ARGS=	${CONFIGURE_SHARED} \
		--enable-sse \
		--with-libiconv-prefix="${LOCALBASE}" \
		--with-ogg="${LOCALBASE}" \
		--disable-thorough-tests \
		--disable-xmms-plugin
CONFIGURE_ENV=	CPPFLAGS="-I${WRKSRC}/include"
MAKE_ENV=	MAKEOBJDIR=/nonexistent		# ignore ${WRKSRC}/obj

post-install:
	cd ${PREFIX}/share/doc && mv ${DISTNAME} flac
	perl -i -pe 's:%%PREFIX%%:${TRUEPREFIX}:' ${PREFIX}/man/man1/flac.1

.include <bsd.port.mk>
