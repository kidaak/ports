# $OpenBSD$

COMMENT=	implementation of Gadu-Gadu IM protocol

DISTNAME=	libgadu-1.11.2
EPOCH=		0
CATEGORIES=	net
MASTER_SITES=	${HOMEPAGE}/files/

SHARED_LIBS=	gadu	6.0

HOMEPAGE=	http://toxygen.net/libgadu/

# LGPLv2.1
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB=	pthread z

USE_LIBTOOL=	Yes
CONFIGURE_STYLE=gnu
CONFIGURE_ARGS=	${CONFIGURE_SHARED} \
		--disable-tests \
		--without-bind \
		--without-gnutls \
		--without-openssl

NO_REGRESS=	Yes

.include <bsd.port.mk>
