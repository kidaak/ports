# $OpenBSD$

COMMENT=		I18N/L10N tools for Python

MODPY_EGG_VERSION=	0.9.6
DISTNAME=		Babel-${MODPY_EGG_VERSION}
PKGNAME=		py-${DISTNAME:L}
REVISION=		0
CATEGORIES=    		devel

HOMEPAGE=		http://babel.edgewall.org/
MASTER_SITES=		http://ftp.edgewall.com/pub/babel/

MAINTAINER=		Damien Miller <djm@openbsd.org>

MODULES=		lang/python
PKG_ARCH=		*

# BSD
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=	Yes

MODPY_SETUPTOOLS=	Yes

REGRESS_DEPENDS=	devel/py-tz

.include <bsd.port.mk>
