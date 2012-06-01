# $OpenBSD$

COMMENT=	provides abstract data types (ADTs)

VERSION=	0.0.7
DISTNAME=	vanessa_socket-${VERSION}

SHARED_LIBS=	vanessa_socket			0.4	# 0.4

MASTER_SITES=	${MASTER_SITE_VANESSA:=vanessa_socket/${VERSION}/}

WANTLIB=	c vanessa_logger>=0.3 popt

USE_GROFF =	Yes
LIB_DEPENDS=	devel/vanessa/logger \
		devel/popt

.include <bsd.port.mk>
