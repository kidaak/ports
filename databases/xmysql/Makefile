# $OpenBSD$

COMMENT=	X11 front end to the MySQL database engine

DISTNAME=	xmysql-1.10
REVISION =	3
CATEGORIES=	databases

MASTER_SITES=	${MASTER_SITE_BACKUP}

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes
WANTLIB=		GL X11 Xext Xpm c m

LIB_DEPENDS=	x11/xforms \
		databases/mysql \
		graphics/jpeg
WANTLIB +=	forms mysqlclient>=10 jpeg>=62

NO_REGRESS=	Yes

.include <bsd.port.mk>
