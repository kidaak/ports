# $OpenBSD$

COMMENT=	DNS debugger

PKGNAME=	drill-${VERSION}

WANTLIB=	c crypto ldns>=4.10
LIB_DEPENDS+=	net/ldns/libldns>=1.6.11

WRKSRC=		${WRKDIST}/drill

USE_GMAKE=	Yes
CONFIGURE_ARGS+=--with-ldns=${LOCALBASE}

.include <bsd.port.mk>
