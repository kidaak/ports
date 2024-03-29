# $OpenBSD$

COMMENT =		python interface to subversion

MODPY_EGG_VERSION =	1.7.2
DISTNAME = 		pysvn-${MODPY_EGG_VERSION}
REVISION = 		3
PKGNAME = 		py-pysvn-${MODPY_EGG_VERSION}
CATEGORIES =		devel

HOMEPAGE =		http://pysvn.tigris.org

MAINTAINER = 		Stefan Sperling <stsp@openbsd.org>

# Apache v1.1, BSD-like
PERMIT_PACKAGE_CDROM = 		Yes
PERMIT_PACKAGE_FTP = 		Yes
PERMIT_DISTFILES_CDROM = 	Yes
PERMIT_DISTFILES_FTP = 		Yes

MASTER_SITES =	http://pysvn.barrys-emacs.org/source_kits/

MODULES = 	lang/python
LIB_DEPENDS = 	devel/subversion,-main
WANTLIB = 	com_err expat m neon stdc++ svn_client-1 svn_diff-1 svn_repos-1

USE_GMAKE = 	Yes
_PYSVN_PYVERSION = ${MODPY_VERSION:S/./_/}
SUBST_VARS += 	_PYSVN_PYVERSION

WRKSRC =  	${WRKDIST}/Source

CONFIGURE_FLAGS = 	--apr-inc-dir=${LOCALBASE}/include/apr-1 \
			--apr-lib-dir=${LOCALBASE}/lib \
			--svn-inc-dir=${LOCALBASE}/include/subversion-1 \
			--svn-lib-dir=${LOCALBASE}/lib

do-configure:
	cd ${WRKSRC} && ${MODPY_BIN} ./${MODPY_SETUP} configure ${CONFIGURE_FLAGS}

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM}

do-install:
	${INSTALL_DATA_DIR} ${WRKINST}/${MODPY_SITEPKG}/pysvn
	${INSTALL_SCRIPT} ${WRKSRC}/pysvn/__init__.py \
		${WRKINST}/${MODPY_SITEPKG}/pysvn/__init__.py
	${INSTALL_DATA} ${WRKSRC}/pysvn/_pysvn_${_PYSVN_PYVERSION}.so \
		${WRKINST}/${MODPY_SITEPKG}/pysvn/_pysvn_${_PYSVN_PYVERSION}.so

do-regress:
	cd ${WRKDIST}/Tests && ${MAKE_PROGRAM}

.include <bsd.port.mk>
