# $OpenBSD$

COMMENT=		calculate Levenshtein distance between two strings

MODPY_EGG_VERSION=	0.3
DISTNAME=		py-editdist-${MODPY_EGG_VERSION}
REVISION =		4
CATEGORIES=    		devel

HOMEPAGE=		http://www.mindrot.org/projects/py-editdist/

MAINTAINER=		Damien Miller <djm@openbsd.org>

# ISC
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=		http://www.mindrot.org/files/py-editdist/

MODULES=		lang/python

WANTLIB += 		${MODPY_WANTLIB}

do-regress: fake
	@cd ${WRKSRC} && ${MAKE_ENV} \
		PYTHONPATH=${WRKINST}${MODPY_SITEPKG} \
		${MODPY_BIN} ./test.py

.include <bsd.port.mk>
