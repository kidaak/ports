# $OpenBSD$

COMMENT=		SNMP audit scanner

DISTNAME=       	ADMsnmp.0.1
PKGNAME=		ADMsnmp-0.1
REVISION =		0
CATEGORIES=		security
EXTRACT_SUFX=		.tgz

MAINTAINER=		Jason Peel <jsyn@openbsd.org>

PERMIT_PACKAGE_CDROM=   no license
PERMIT_PACKAGE_FTP=     no license
PERMIT_DISTFILES_CDROM= no license
PERMIT_DISTFILES_FTP=   no license
WANTLIB=		c

MASTER_SITES=		ftp://adm.freelsd.net/pub/ADM/ \
			http://adm.freelsd.net/ADM/ \
			${MASTER_SITE_PACKETSTORM:=groups/ADM/}

WRKDIST=		${WRKDIR}/ADMsnmp

NO_REGRESS=		Yes

do-build:
	cd ${WRKSRC} ; ${CC} ${CFLAGS} \
		-DPORTSHAREDIR="${TRUEPREFIX}/share/ADMsnmp" \
		-o ADMsnmp snmp.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ADMsnmp ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/ADMsnmp
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ADMsnmp
	${INSTALL_DATA} ${WRKSRC}/snmp.passwd ${PREFIX}/share/ADMsnmp
	${INSTALL_DATA} ${WRKSRC}/ADMsnmp.README ${PREFIX}/share/doc/ADMsnmp

.include <bsd.port.mk>
