# $OpenBSD$

COMMENT=		DNS toolkit for Python

MODPY_EGG_VERSION=	1.9.4
DISTNAME=		dnspython-${MODPY_EGG_VERSION}
PKGNAME=		py-${DISTNAME}
REVISION=		1
CATEGORIES=		net

HOMEPAGE=		http://www.dnspython.org/

MAINTAINER=		Will Maier <wcmaier@openbsd.org>

# BSD
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=		${HOMEPAGE}/kits/${MODPY_EGG_VERSION}/

MODULES=		lang/python
MODPY_ADJ_FILES=	examples/*.py

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/py-dnspython
	${INSTALL_SCRIPT} ${WRKSRC}/examples/* \
		${PREFIX}/share/examples/py-dnspython

do-regress:
	@cd ${WRKSRC}/tests && env PYTHONPATH=../ \
		make check PYTHON=${MODPY_BIN} 

.include <bsd.port.mk>
