# $OpenBSD$

COMMENT=	stand-alone client/server 9P library

DISTNAME=	libixp-0.4
REVISION =	1
CATEGORIES=	devel

HOMEPAGE=	http://www.suckless.org

# MIT/X, except intmap.c under Plan 9 License
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=	${HOMEPAGE}/download/

WANTLIB=	c

NO_REGRESS=	Yes
USE_GROFF =	Yes

pre-configure:
	@perl -pi -e 's,!!CFLAGS!!,${CFLAGS},g;' \
		-e 's,!!CC!!,${CC},g' ${WRKSRC}/config.mk

.include <bsd.port.mk>
