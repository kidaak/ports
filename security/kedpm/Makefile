# $OpenBSD$

COMMENT=	application for managing passwords

MODPY_EGG_VERSION=	0.4.0
DISTNAME=	kedpm-${MODPY_EGG_VERSION}
REVISION=	7
CATEGORIES=	security

HOMEPAGE=	http://kedpm.sourceforge.net/

MAINTAINER=	Joerg Zinke <mail@umaxx.net>

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kedpm/}

RUN_DEPENDS=	x11/py-gtk2 \
		security/py-crypto
REGRESS_DEPENDS=${RUN_DEPENDS}

MODULES=	lang/python

do-regress:
	@cd ${WRKSRC} && ${MODPY_BIN} ./run_tests

.include <bsd.port.mk>
