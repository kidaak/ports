# $OpenBSD$

COMMENT=		load balancer for simple TCP-based protocols

DISTNAME=		pen-0.18.0
CATEGORIES=		net
HOMEPAGE=		http://siag.nu/pen/

MASTER_SITES=		http://siag.nu/pub/pen/

# GPLv2+
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB=		c

CONFIGURE_STYLE=	gnu
CONFIGURE_ARGS=		--with-docdir=${PREFIX}/share/doc/pen
USE_GROFF =		Yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pen

.include <bsd.port.mk>
