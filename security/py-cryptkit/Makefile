# $OpenBSD$

SHARED_ONLY=	Yes

COMMENT=	Python Cryptographic Toolkit

MODPY_EGG_VERSION= 0.9
DISTNAME=	cryptkit-${MODPY_EGG_VERSION}
PKGNAME=	py-${DISTNAME}
REVISION=	8
CATEGORIES=    	security devel

HOMEPAGE=	http://sourceforge.net/projects/cryptkit/

# BSD
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cryptkit/}

WANTLIB=	${MODPY_WANTLIB}

MODULES=	lang/python

NO_REGRESS=	Yes

.include <bsd.port.mk>
