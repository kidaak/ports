# $OpenBSD$

COMMENT=	pop password changing daemon using KerberosV

DISTNAME=	kpoppassd-0.5
REVISION =	2
CATEGORIES=	mail

HOMEPAGE=	http://kpoppassd.sourceforge.net/

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kpoppassd/}

WANTLIB=	c com_err crypto krb5

WRKDIST=	${WRKDIR}/kpoppassd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/kpoppassd ${PREFIX}/libexec
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/kpoppassd
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/kpoppassd

.include <bsd.port.mk>
