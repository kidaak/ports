# $OpenBSD$

SHARED_ONLY=	Yes

COMMENT=	Python-alike language for writing Python extension modules

MODPY_EGG_VERSION=	0.9.9
DISTNAME=	Pyrex-${MODPY_EGG_VERSION}
PKGNAME=	${DISTNAME:L}
REVISION =	1
CATEGORIES=	devel

HOMEPAGE=	http://www.cosc.canterbury.ac.nz/greg.ewing/python/Pyrex/

# Free, check README.txt for details 
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=	http://distfiles.nl/ \
		${HOMEPAGE}

MODULES=	lang/python

REGRESS_DEPENDS=math/py-Numeric

pre-build:
	@perl -pi -e "s,/usr/bin/env python,${MODPY_BIN}," \
		${WRKSRC}/bin/pyrexc

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pyrex
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/pyrex
	@cd ${WRKSRC}/Demos && tar cvf - . | \
		(cd ${PREFIX}/share/examples/pyrex && tar xf -)
	@cd ${WRKSRC}/Doc && tar cvf - . | \
		(cd ${PREFIX}/share/doc/pyrex && tar xf -)

do-regress:
	@cd ${WRKSRC}/Demos && \
		make test PYTHON="PYTHONPATH=${WRKSRC} ${MODPY_BIN}"

.include <bsd.port.mk>
