# $OpenBSD$

SHARED_ONLY =		Yes

COMMENT =		SSL/TLS plugin for QCA2
DISTNAME =		qca-ossl-2.0.0-beta3
PKGNAME =		${DISTNAME:S/-beta/beta/}
REVISION =		1
CATEGORIES =		security
HOMEPAGE =		http://delta.affinix.com/qca/
MAINTAINER =		Vadim Zhukov <persgray@gmail.com>

# LGPLv2.1
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

MASTER_SITES =		http://delta.affinix.com/download/qca/2.0/plugins/
EXTRACT_SUFX =		.tar.bz2

WANTLIB +=		crypto m qca2 ssl stdc++

MODULES =		x11/qt4
LIB_DEPENDS =		security/qca2

NO_REGRESS =		Yes

QMAKE =			${LOCALBASE}/bin/qmake4
SUBST_VARS +=		MODQT4_LIBDIR WRKINST

do-configure:
	${SUBST_CMD} -c ${FILESDIR}/conf.pri ${WRKSRC}/conf.pri
	cd ${WRKSRC} && ${QMAKE} qca-ossl.pro

.include <bsd.port.mk>
