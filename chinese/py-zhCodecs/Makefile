# $OpenBSD$

COMMENT=	Python Unicode codecs for Chinese charsets

VERSION=	1.2.0
DISTNAME=	ChineseCodecs${VERSION}
PKGNAME=	py-zhCodecs-${VERSION}
REVISION=	5
CATEGORIES=    	chinese devel

HOMEPAGE=	http://sourceforge.net/projects/python-codecs/

# GPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=	Yes

MODULES=	lang/python

MODPY_DISTUTILS_INSTALLARGS=	-O1

WRKSRC=	${WRKDIST}/Python

NO_REGRESS=	Yes

post-extract:
	@chmod 711 ${WRKSRC}/chinesetw

.include <bsd.port.mk>
