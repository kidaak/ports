# $OpenBSD$

COMMENT=	screen saver that displays a countdown to a selected date

DISTNAME=	kountdown-0.4.1
REVISION=	5

CATEGORIES=	x11

HOMEPAGE=	http://www.lysator.liu.se/~erre/kountdown.html

MAINTAINER=	Kevin Lo <kevlo@openbsd.org>

# GPL
PERMIT_PACKAGE_CDROM=  Yes
PERMIT_PACKAGE_FTP=    Yes
PERMIT_DISTFILES_CDROM=Yes
PERMIT_DISTFILES_FTP=  Yes

WANTLIB += ICE SM X11 Xau Xdmcp Xext Xrender art_lgpl_2 c fam
WANTLIB += idn jpeg m png pthread rpcsvc stdc++ util z
WANTLIB += pthread-stubs xcb kdecore DCOP kdefx kdesu kdeui kio
WANTLIB += kscreensaver kwalletclient

MASTER_SITES=	http://www.lysator.liu.se/~erre/download/kountdown/

LIB_DEPENDS=	x11/kde/libs3

AUTOCONF_VERSION= 2.52
MODKDE_VERSION= 3.1
MODULES=	devel/gettext \
		x11/kde

PORTHOME=	${WRKDIR}

MAKE_ENV=	KDEDIR="${LOCALBASE}"
MAKE_ENV+= 	UIC_PATH="${MODQT_UIC}" UIC="${MODQT_UIC}"
MAKE_FLAGS=	${MODKDE_MAKE_FLAGS}

USE_LIBTOOL=	Yes
USE_GMAKE=	Yes
CONFIGURE_STYLE= autoconf
MODGNU_CONFIG_GUESS_DIRS= ${MODKDE_CONFIG_GUESS_DIRS}
CONFIGURE_ARGS+= ${MODKDE_CONFIGURE_ARGS}
CONFIGURE_ENV=	${MODKDE_CONFIGURE_ENV}

.include <bsd.port.mk>
