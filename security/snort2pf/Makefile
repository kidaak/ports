# $OpenBSD$

COMMENT=		block "nasty" hosts with pf(4) based on Snort's rules

DISTNAME=		snort2pf-4.5
CATEGORIES=		security net
REVISION=		0

HOMEPAGE=		http://sourceforge.net/projects/snort2pf/

# BSD
PERMIT_DISTFILES_FTP=   Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_PACKAGE_FTP=     Yes
PERMIT_PACKAGE_CDROM=   Yes

MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=snort2pf/}

PKG_ARCH=		*
NO_BUILD=		Yes
NO_REGRESS=		Yes

RUN_DEPENDS=		net/p5-Net-Patricia

do-configure:
	@perl -pi -e 's,/usr/local,${TRUEPREFIX},g' \
		${WRKSRC}/snort2pf.8

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/snort2pf{,mon} ${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/*.8 ${PREFIX}/man/man8/

.include <bsd.port.mk>
