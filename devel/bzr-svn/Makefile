# $OpenBSD$

COMMENT=	bzr plugin that adds support for foreign svn repositories

MODPY_EGG_VERSION= 1.1.2
DISTNAME=	bzr-svn-${MODPY_EGG_VERSION}
CATEGORIES=	devel

HOMEPAGE=	http://launchpad.net/bzr-svn

# GPL 
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=	http://launchpad.net/bzr-svn/${MODPY_EGG_VERSION:C/..$//}/${MODPY_EGG_VERSION}/+download/

MODULES=	lang/python

RUN_DEPENDS=	devel/bzr

.include <bsd.port.mk>
