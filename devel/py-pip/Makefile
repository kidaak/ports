# $OpenBSD$

COMMENT =		Python easy_install replacement

MODPY_EGG_VERSION =	1.1
DISTNAME =		pip-${MODPY_EGG_VERSION}
PKGNAME =		py-${DISTNAME}
CATEGORIES =		devel
REVISION =		0

MAINTAINER =		Wen Heping <wenheping@gmail.com>

HOMEPAGE =		http://www.pip-installer.org/

# MIT
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM = Yes
PERMIT_DISTFILES_FTP =	Yes

MASTER_SITES =		${MASTER_SITE_PYPI:=p/pip/}

MODULES =		lang/python
MODPY_SETUPTOOLS =	Yes
NO_REGRESS =		Yes

FLAVORS =		python3
FLAVOR ?=

.include <bsd.port.mk>
