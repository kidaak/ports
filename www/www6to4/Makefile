# $OpenBSD$

COMMENT=		IPv6 to IPv4 web proxy

DISTNAME=		www6to4-1.5
REVISION=		1
CATEGORIES=		www
HOMEPAGE=		http://www.dillema.net/software/www6to4.html

# GPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes
WANTLIB=		c

MASTER_SITES=		http://www.dillema.net/software/www6to4/

ALL_TARGET=		www6to4
CFLAGS+=		-DSYSCONFDIR=\"${SYSCONFDIR}\"

do-install:
	${INSTALL_PROGRAM} ${WRKBUILD}/www6to4 ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/www6to4
	${INSTALL_DATA} ${WRKSRC}/*.conf ${PREFIX}/share/examples/www6to4
	perl -i -pe 's:/etc(/www6to4_forward.conf):${SYSCONFDIR}$$1:' \
		${PREFIX}/share/examples/www6to4/www6to4.conf

NO_REGRESS=		Yes

.include <bsd.port.mk>
