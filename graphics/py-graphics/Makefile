# $OpenBSD$

COMMENT=	multimedia framework for Python

MODPY_EGG_VERSION= 1.5
DISTNAME=	PyGraphics-${MODPY_EGG_VERSION}
PKGNAME=	py-graphics-${MODPY_EGG_VERSION}
REVISION=	4
EPOCH=		0

CATEGORIES=	graphics

HOMEPAGE=	http://code.google.com/p/pygraphics/

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=	http://pygraphics.googlecode.com/files/

MODULES=	lang/python

WRKDIST=	${WRKDIR}
PKG_ARCH=	*
NO_REGRESS=	Yes

RUN_DEPENDS=	${MODPY_TKINTER_DEPENDS} \
		graphics/py-Imaging

.include <bsd.port.mk>
