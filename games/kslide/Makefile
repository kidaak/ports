# $OpenBSD$

COMMENT=	puzzle game for KDE

DISTNAME=	kslide-0.90
REVISION =	3
CATEGORIES=	games

HOMEPAGE=	http://perso.wanadoo.fr/coquelle/taquin/

MAINTAINER=	Kevin Lo <kevlo@openbsd.org>

PERMIT_PACKAGE_CDROM=  Yes
PERMIT_PACKAGE_FTP=    Yes
PERMIT_DISTFILES_CDROM=Yes
PERMIT_DISTFILES_FTP=  Yes

WANTLIB=	ICE SM X11 Xau Xdmcp Xext Xrender art_lgpl_2 c fam idn jpeg \
		m png pthread pthread-stubs rpcsvc stdc++ util xcb z \
		kdecore>=4 DCOP kdefx kdesu kdeui kio kwalletclient

MASTER_SITES=	http://david.bieder.free.fr/eric/taquin/ \
		http://perso.wanadoo.fr/coquelle/taquin/
EXTRACT_SUFX=	.tar.bz2

LIB_DEPENDS=	x11/kde/libs3

MODULES=	x11/qt3 devel/gettext

MAKE_ENV=	${CONFIGURE_ENV}
# Ensure qt2 will always be at the front
MAKE_FLAGS=	CXXLD='--tag CXX ${CXX} -L${MODQT_LIBDIR}'

USE_GMAKE=	Yes
CONFIGURE_STYLE= gnu
CONFIGURE_ARGS=	 ${MODQT_CONFIGURE_ARGS}
CONFIGURE_ARGS+= --with-extra-libs=${LOCALBASE}/lib
CONFIGURE_ARGS+= --with-extra-includes=${LOCALBASE}/include/libpng:${LOCALBASE}/include
CONFIGURE_ENV=	KDEDIR=${LOCALBASE} 
USE_LIBTOOL=	Yes

MODGNU_CONFIG_GUESS_DIRS=	${WRKSRC}/admin

WRKDIST=	${WRKDIR}/kslide

.include <bsd.port.mk>
