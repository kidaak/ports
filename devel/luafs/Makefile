# $OpenBSD$
SHARED_ONLY=	Yes

COMMENT=	file system library for the lua language
V=		1.5.0
DISTNAME=	luafilesystem-${V}
PKGNAME=	luafs-${V}
REVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://github.com/downloads/keplerproject/luafilesystem/

HOMEPAGE=	http://www.keplerproject.org/luafilesystem/

# MIT
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MODULES=	lang/lua
ALL_TARGET=	lib

MAKE_ENV+=	LUA_LIBDIR=${MODLUA_LIBDIR} LUA_INC=${MODLUA_INCL_DIR}

do-install:
	${INSTALL_DATA_DIR} ${MODLUA_LIBDIR} ${MODLUA_DOCDIR} ${MODLUA_EXAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/lfs.so ${MODLUA_LIBDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/us/*.html ${WRKSRC}/doc/us/*.png \
		${MODLUA_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/tests/*.lua ${MODLUA_EXAMPLEDIR}

do-regress:
	cp ${WRKDIST}/*.so ${WRKDIST}/tests
	cd ${WRKDIST}/tests && ${MODLUA_BIN} test.lua

.include <bsd.port.mk>
