# $OpenBSD$ 

COMMENT=		Qt Cryptographic Architecture, TLS plugin

DISTNAME=		qca-tls-1.0
REVISION=		10
CATEGORIES=		security

HOMEPAGE=		http://delta.affinix.com/qca/

RUN_DEPENDS=		security/qca

PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes
WANTLIB=		crypto m ssl stdc++

SHARED_ONLY=		Yes
MODULES=		x11/qt3
MASTER_SITES=		${HOMEPAGE}
EXTRACT_SUFX=		.tar.bz2

NO_REGRESS=		Yes

USE_GMAKE=		Yes
CONFIGURE_STYLE=	simple
CONFIGURE_ENV=		LOCALBASE=${LOCALBASE}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${MODQT_PLUGINS}/crypto 
	${INSTALL_DATA} ${WRKSRC}/libqca-tls.so ${PREFIX}/${MODQT_PLUGINS}/crypto

SUBST_VARS+= MODQT_PLUGINS

.include <bsd.port.mk>
