# $OpenBSD$

COMMENT =	helper functions focused on web applications

MODPY_EGG_VERSION = 1.3
DISTNAME =	WebHelpers-${MODPY_EGG_VERSION}
PKGNAME =	py-${DISTNAME:L}

CATEGORIES =	www devel

# BSD
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM = Yes
PERMIT_DISTFILES_FTP =	Yes

MASTER_SITES =	${MASTER_SITE_PYPI:=W/WebHelpers/}

MODULES =	lang/python

RUN_DEPENDS =	www/py-routes \
		textproc/py-MarkupSafe
REGRESS_DEPENDS = ${RUN_DEPENDS} \
		  devel/py-nose

MODPY_SETUPTOOLS =	Yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/py-webhelpers
	${INSTALL_DATA} ${WRKSRC}/README.txt \
	    ${PREFIX}/share/doc/py-webhelpers

do-regress:
	cd ${WRKSRC} && ${LOCALBASE}/bin/nosetests \
	    -v --with-doctest --exclude webhelpers.feedgenerator lib

.include <bsd.port.mk>
