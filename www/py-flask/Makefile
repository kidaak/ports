# $OpenBSD$

COMMENT = 	microframework based on Werkzeug and Jinja 2

MODPY_EGG_VERSION =	0.9
DISTNAME =	Flask-${MODPY_EGG_VERSION}
PKGNAME =	py-${DISTNAME:L}

CATEGORIES =	www devel

HOMEPAGE =	http://flask.pocoo.org/

# BSD
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM = Yes
PERMIT_DISTFILES_FTP =	Yes

MASTER_SITES =	${MASTER_SITE_PYPI:=F/Flask/}

MODULES =	lang/python

MODPY_SETUPTOOLS =	Yes

RUN_DEPENDS =	devel/py-blinker \
		www/py-jinja2>=2.4 \
		www/py-werkzeug>=0.7 \
		${MODPY_JSON}
REGRESS_DEPENDS = ${RUN_DEPENDS}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/${MODPY_PY_PREFIX}flask
	cd ${WRKSRC}/examples && \
	    pax -rw * ${PREFIX}/share/examples/${MODPY_PY_PREFIX}flask

.include <bsd.port.mk>
