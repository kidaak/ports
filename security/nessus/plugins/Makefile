# $OpenBSD$

COMMENT=	plugins for Nessus
DISTNAME=	nessus-plugins-GPL-${V}
PKGNAME=	${DISTNAME:S/-GPL//}
REVISION =	1

WANTLIB=	crypto hosts_gatherer m nessus pcap ssl util

USE_GROFF =	Yes
BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	security/nessus/core	\
		security/hydra	\
		security/nikto	\
		net/nmap

.include <bsd.port.mk>
