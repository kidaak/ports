# $OpenBSD$

COMMENT=	free implementation of Cisco VMPS

V=		1.4.03
DISTNAME=	vmpsd-${V}
PKGNAME=	openvmps-${V}
CATEGORIES=	net

HOMEPAGE=	http://vmps.sourceforge.net/

MAINTAINER=	Antoine Jacoutot <ajacoutot@openbsd.org>

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB += c

MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=vmps/}

CONFIGURE_STYLE=gnu
USE_GROFF=	Yes

pre-configure:
	${SUBST_CMD} ${WRKSRC}/vmpsd.1

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/openvmps
	${INSTALL_DATA} ${WRKSRC}/vlan.db ${PREFIX}/share/examples/openvmps

.include <bsd.port.mk>
