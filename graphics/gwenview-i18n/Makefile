# $OpenBSD$

COMMENT=	image viewer for KDE, translations

DISTNAME=	gwenview-i18n-1.4.2
REVISION=		0
CATEGORIES=	graphics x11 x11/kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gwenview/}
EXTRACT_SUFX=	.tar.bz2

HOMEPAGE=	http://gwenview.sourceforge.net/home/

# GPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

BUILD_DEPENDS = x11/kde/libs3
RUN_DEPENDS = x11/kde/libs3

MODULES=	x11/kde
MODKDE_VERSION= 3.5.7

PORTHOME=	${WRKDIR}

MAKE_ENV=	KDEDIR="${LOCALBASE}"
MAKE_FLAGS=	${MODKDE_MAKE_FLAGS}

USE_GMAKE=	Yes
CONFIGURE_STYLE= gnu
MODGNU_CONFIG_GUESS_DIRS= ${MODKDE_CONFIG_GUESS_DIRS}
CONFIGURE_ARGS=	${MODKDE_CONFIGURE_ARGS}
CONFIGURE_ENV=	${MODKDE_CONFIGURE_ENV}
REORDER_DEPENDENCIES=	${PORTSDIR}/infrastructure/mk/automake.dep

.include <bsd.port.mk>
