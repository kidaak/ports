# $OpenBSD$

COMMENT =		universal parsing tool & source code generator

V =			4.5.4
PKGNAME =		codeworker-${V}
REVISION =		0

CATEGORIES =		devel

HOMEPAGE =		http://codeworker.free.fr/

MAINTAINER =		Vincent Auclair <auclair.vincent@gmail.com>

# LGPL
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

WANTLIB =		c m stdc++

MASTER_SITES =		http://codeworker.googlecode.com/files/ \
			http://codeworker.free.fr/downloads/
DISTNAME =		CodeWorker_SRC${V:S/./_/g}
EXTRACT_SUFX =		.zip

MAKE_FLAGS =		CXXFLAGS='${CXXFLAGS}' CXX='${CXX}'

USE_GMAKE =		Yes

NO_REGRESS =		Yes

WRKDIST=${WRKDIR}/CodeWorker${V:S/./_/g}

do-install:
	${INSTALL_PROGRAM} ${WRKDIST}/codeworker ${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIST}/libcodeworker.a ${PREFIX}/lib
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/codeworker
	${INSTALL_DATA} ${WRKSRC}/Documentation/* ${PREFIX}/share/examples/codeworker

.include <bsd.port.mk>

