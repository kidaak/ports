# $OpenBSD$

COMMENT=	specific Python bindings for OpenBSD

V=		0.1.2
DISTNAME=	pyopenbsd-${V}
PKGNAME=	py-openbsd-${V}
REVISION=	11
CATEGORIES=	devel

HOMEPAGE=	http://dev.nullcube.com/

MAINTAINER=	Aldo Cortesi <aldo@nullcube.com>

# BSD
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes
WANTLIB=		kvm pcap
WANTLIB+=		${MODPY_WANTLIB}

MASTER_SITES=	http://spacehopper.org/mirrors/
EXTRACT_SUFX=	.tgz

MODULES=	lang/python

DOCSDIR=	${PREFIX}/share/doc/py-openbsd
EXAMPLESDIR=	${PREFIX}/share/examples/py-openbsd

post-install:
	${INSTALL_DATA_DIR} ${DOCSDIR}
	cd ${WRKSRC}/doc; tar cf - * | tar xf - -C ${DOCSDIR}
	${INSTALL_DATA_DIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.py ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/README ${EXAMPLESDIR}

do-regress: fake
	@cd ${WRKSRC}/test && ${MAKE_ENV} \
		PYTHONPATH=${WRKINST}${MODPY_SITEPKG} ${MODPY_BIN} ./run_all.py

.include <bsd.port.mk>
