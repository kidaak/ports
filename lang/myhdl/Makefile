# $OpenBSD$

COMMENT=	Python as a hardware description and verification language

MODPY_EGG_VERSION=0.7
DISTNAME=	myhdl-${MODPY_EGG_VERSION}
CATEGORIES=	lang

HOMEPAGE=	http://www.myhdl.org/

# LGPLv2.1
PERMIT_PACKAGE_FTP=	Yes
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes
PERMIT_DISTFILES_CDROM= Yes

MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=myhdl/}

MODULES+=	lang/python

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/myhdl/
	cd ${WRKSRC}/example/ && umask 022 && pax -rw . \
		${PREFIX}/share/examples/myhdl/

do-regress: fake
	cd ${WRKSRC}/myhdl/test/core && \
		env PYTHONPATH="${WRKINST}${MODPY_LIBDIR}/site-packages/" \
			${MODPY_BIN} test_all.py
.include <bsd.port.mk>
