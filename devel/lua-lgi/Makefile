# $OpenBSD$

SHARED_ONLY=	Yes

COMMENT=	lua bindings to libraries using GObject-Introspection

DISTNAME=	lgi-0.6.2
PKGNAME=	lua-${DISTNAME}
REVISION=	2
CATEGORIES=	devel

HOMEPAGE=	https://github.com/pavouk/lgi

# MIT
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MODULES=	devel/gettext \
		lang/lua

WANTLIB += ffi girepository-1.0 glib-2.0 gmodule-2.0 gobject-2.0
WANTLIB += gthread-2.0

LIB_DEPENDS=	devel/gobject-introspection

MASTER_SITES=	https://github.com/downloads/pavouk/lgi/ \
		http://distfiles.nl/

USE_GMAKE=	Yes
MAKE_ENV=	MAKE=${MAKE_PROGRAM} LUA_CFLAGS="-I${MODLUA_INCL_DIR}" \
		LUA_LIBDIR="${MODLUA_LIBDIR}" LUA_SHAREDIR="${MODLUA_DATADIR}"

REGRESS_TARGET= check
REGRESS_IS_INTERACTIVE=x11

pre-configure:
	${SUBST_CMD} ${WRKSRC}/lgi/Makefile

post-install:
	${INSTALL_DATA_DIR} ${MODLUA_EXAMPLEDIR}
	cd ${WRKSRC}/samples/ && umask 022 && \
		pax -rw . ${MODLUA_EXAMPLEDIR}

pre-regress:
	${SUBST_CMD} ${WRKSRC}/tests/Makefile

.include <bsd.port.mk>
