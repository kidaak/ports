# $OpenBSD$

COMMENT=	video DVDs and CDs creation tool

DISTNAME=	devede-3.22.0
REVISION=	0

CATEGORIES=	multimedia x11

EXTRACT_SUFX=	.tar.bz2

HOMEPAGE=	http://www.rastersoft.com/programas/devede.html

# GPLv3
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=	http://www.rastersoft.com/descargas/

MODULES=	lang/python

RUN_DEPENDS=	x11/py-gtk2 \
		multimedia/dvdauthor \
		graphics/vcdimager \
		sysutils/cdrtools \
		x11/mplayer \
		devel/xdg-utils \
		devel/desktop-file-utils \
		x11/dbus-python

PKG_ARCH=	*
NO_BUILD=	Yes
NO_REGRESS=	Yes

MODPY_ADJ_FILES=devede

SUBST_VARS=	^MODPY_SITEPKG

pre-configure:
	@find ${WRKSRC} -name \*.py | \
		xargs perl -pi -e 's,/usr/bin/env python,${MODPY_BIN},g'
	${SUBST_CMD} \
		${WRKSRC}/{devede_other,devede_executor,devede,devede_fonts}.py

do-install:
	cd ${WRKSRC} && \
		/bin/sh install.sh prefix=${TRUEPREFIX} uninstall=no
	find ${PREFIX} -name \*.orig -or -name \*~ | xargs rm

.include <bsd.port.mk>
