# $OpenBSD$

COMMENT =	system to automate the compile/test cycle

MODPY_EGG_VERSION =	0.8.6p1
DISTNAME =	buildbot-${MODPY_EGG_VERSION}
PKGNAME =	py-${DISTNAME:S/p1/pl1/}

CATEGORIES =	devel

HOMEPAGE =	http://buildbot.net/

MAINTAINER =	Piotr Sikora <piotr.sikora@frickle.com>

# GPLv2
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM = Yes
PERMIT_DISTFILES_FTP =	Yes

MASTER_SITES =	http://buildbot.googlecode.com/files/

MODULES =	lang/python

MODPY_SETUPTOOLS = Yes
MODPY_BADEGGS =	buildbot

RUN_DEPENDS =	databases/py-sqlalchemy \
		databases/py-sqlalchemy-migrate \
		devel/py-twisted/core \
		devel/py-twisted/conch \
		devel/py-twisted/mail \
		devel/py-twisted/web \
		devel/py-twisted/words \
		www/py-jinja2 \
		${MODPY_JSON}

REGRESS_DEPENDS =	${RUN_DEPENDS} \
			devel/py-mock

HOMEDIR =		/var/buildbot

SUBST_VARS +=		HOMEDIR

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/py-buildbot
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/py-buildbot
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/py-buildbot
	${INSTALL_DATA} ${WRKSRC}/docs/examples/*.cfg \
	    ${PREFIX}/share/examples/py-buildbot
	cd ${WRKSRC} && pax -rw contrib ${PREFIX}/share/doc/py-buildbot
	${INSTALL_MAN} ${WRKSRC}/docs/buildbot.1 ${PREFIX}/man/man1

do-regress:
	@${MAKE_ENV} PYTHONPATH=${WRKSRC} \
	    ${LOCALBASE}/bin/trial --temp-directory=${WRKBUILD}/regress \
	    buildbot.test

.include <bsd.port.mk>
