# $OpenBSD$

COMMENT =	declarative mapper for SQLAlchemy

MODPY_EGG_VERSION =	0.7.0
DISTNAME =	Elixir-${MODPY_EGG_VERSION}
PKGNAME =	py-${DISTNAME:L}
REVISION =	2

CATEGORIES =	databases

HOMEPAGE =	http://elixir.ematia.de/trac/wiki

# MIT
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM = Yes
PERMIT_DISTFILES_FTP =	Yes

MASTER_SITES =	${MASTER_SITE_PYPI:=E/Elixir/}

MODULES =	lang/python
MODPY_SETUPTOOLS =	Yes

RUN_DEPENDS =		databases/py-sqlalchemy \
			security/py-crypto
REGRESS_DEPENDS =	databases/py-sqlite2 \
			${RUN_DEPENDS}
MAKE_ENV +=	PYTHONPATH='${WRKSRC}'

do-regress:
	@${_MODPY_CMD} develop -d.; \
	cd ${WRKSRC}/tests; for i in `echo test_*.py`; do \
	    echo $$i; ${MAKE_ENV} ${MODPY_BIN} $$i; \
	done

.include <bsd.port.mk>
