# $OpenBSD$

COMMENT=	simplified-traditional chinese translate tool

DISTNAME=	cconv-0.6.2
REVISION=	0

CATEGORIES=	chinese converters

SHARED_LIBS=	cconv		0.0

HOMEPAGE=	http://code.google.com/p/cconv/

MAINTAINER=	Kevin Lo <kevlo@openbsd.org>

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB= 	c

MASTER_SITES=	http://cconv.googlecode.com/files/

MODULES=	converters/libiconv

USE_LIBTOOL=	Yes
CONFIGURE_STYLE=gnu

FAKE_FLAGS=	includedir=${PREFIX}/include/cconv/

post-patch:
	@perl -i -pe 's:UTF-TW:UTF8-TW:g' ${WRKSRC}/main.c
	
.include <bsd.port.mk>
