# $OpenBSD$

SHARED_ONLY=	Yes

COMMENT=	lua binding to OpenSSL to provide TLS/SSL communication
DISTNAME=	luasec-0.4.1
REVISION=	3
CATEGORIES=	security
MASTER_SITES=	${HOMEPAGE}/download/

HOMEPAGE=	http://www.inf.puc-rio.br/~brunoos/luasec/

MAINTAINER=	Gleydson Soares <gsoares@openbsd.org>

# MIT
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes

MODULES=	lang/lua
NO_REGRESS=	Yes
MODLUA_RUN_DEPENDS+=	net/luasocket
WANTLIB+=	crypto ssl

MAKE_ENV+=	INCDIR="-I${MODLUA_INCL_DIR}" SAVECFLAGS="${CFLAGS}"
ALL_TARGET=	bsd

do-install:
	${INSTALL_DATA_DIR} ${MODLUA_LIBDIR} ${MODLUA_DATADIR} ${MODLUA_EXAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/src/ssl.so ${MODLUA_LIBDIR}
	${INSTALL_DATA} ${WRKSRC}/src/ssl.lua ${MODLUA_DATADIR}
	cd ${WRKSRC}/samples && \
		find . -type d \
			-exec ${INSTALL_DATA_DIR} ${MODLUA_EXAMPLEDIR}/{} \; && \
		find . ! -type d \
			-exec ${INSTALL_DATA} -m 644 {} ${MODLUA_EXAMPLEDIR}/{} \;

.include <bsd.port.mk>
