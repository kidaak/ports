# $OpenBSD$

COMMENT=	library for packing and unpacking binary data
DISTNAME=	luapack-20061124
REVISION =	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_BACKUP}

HOMEPAGE=	http://www.tecgraf.puc-rio.br/~lhf/ftp/lua/

# PD
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes

MODULES=	lang/lua
SHARED_ONLY=	Yes
REGRESS_DEPENDS=${BUILD_PKGPATH}

do-build:
	${CC} ${CFLAGS} -fPIC -I${MODLUA_INCL_DIR} -shared \
		${WRKSRC}/lpack.c -o ${WRKDIST}/pack.so

do-install:
	${INSTALL_DATA_DIR} ${MODLUA_LIBDIR} ${MODLUA_DOCDIR} ${MODLUA_EXAMPLEDIR}
	${INSTALL_DATA} ${WRKBUILD}/pack.so ${MODLUA_LIBDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${MODLUA_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/test.lua ${MODLUA_EXAMPLEDIR}

do-regress:
	lua ${WRKSRC}/test.lua

.include <bsd.port.mk>
