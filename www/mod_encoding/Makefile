# $OpenBSD$

COMMENT=	Apache module for non-ascii filename interoperability

REVISION=	2
DISTNAME=	mod_encoding-20021209
CATEGORIES=	www converters

HOMEPAGE=	http://webdav.todo.gr.jp/

# Apache-like
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=	${HOMEPAGE}download/

SUBST_VARS=	PKGNAME

MODULES=	apache-module \
		converters/libiconv

MODAPACHE_NAME=	encoding

NO_REGRESS=	Yes

do-build:
	cd ${WRKSRC} && /usr/sbin/apxs -Wc,"${CFLAGS}" -I${LOCALBASE}/include -c mod_encoding.c \
		-L${LOCALBASE}/lib -liconv -o ${WRKBUILD}/mod_encoding.so
	@${MODAPACHE_CREATE_ENABLE_SCRIPT}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mod_encoding
	${INSTALL_DATA} ${WRKSRC}/README \
		${PREFIX}/share/doc/mod_encoding
	${MODAPACHE_INSTALL}

.include <bsd.port.mk>
