# $OpenBSD$

COMMENT =	network library for easy and scalable concurrency

MODPY_EGG_VERSION =	0.13.7
DISTNAME =	gevent-${MODPY_EGG_VERSION}
PKGNAME =	py-${DISTNAME}

CATEGORIES =	devel
HOMEPAGE =	http://www.gevent.org/

# MPL
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

MASTER_SITES =	${MASTER_SITE_PYPI:=g/gevent/}

MODULES =	lang/python

MODPY_SETUPTOOLS =	Yes
MODPY_DISTUTILS_BUILD=	build --build-base=${WRKSRC} --libevent ${LOCALBASE}

LIB_DEPENDS =	devel/libeventextra
WANTLIB =	${MODPY_WANTLIB} event
RUN_DEPENDS =	devel/py-greenlet

.include <bsd.port.mk>
