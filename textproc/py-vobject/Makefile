# $OpenBSD$

COMMENT=		iCalendar library for Python

MODPY_EGG_VERSION=	0.8.1c
DISTNAME=		vobject-${MODPY_EGG_VERSION}
PKGNAME=		py-vobject-${MODPY_EGG_VERSION}

CATEGORIES=		textproc devel

HOMEPAGE=		http://vobject.skyhouseconsulting.com/

# Apache 1.1
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=		${HOMEPAGE}

MODULES=		lang/python

MODPY_SETUPTOOLS=	Yes

BUILD_DEPENDS=		${RUN_DEPENDS}
RUN_DEPENDS=		devel/py-dateutil

NO_REGRESS=		Yes

.include <bsd.port.mk>
