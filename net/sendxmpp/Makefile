# $OpenBSD$

COMMENT=	perl script to send xmpp messages

DISTNAME=	sendxmpp-0.0.8
CATEGORIES=	net

HOMEPAGE=	http://sendxmpp.platon.sk/

MAINTAINER=	Pierre-Emmanuel Andre <pea@openbsd.org>

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=	${HOMEPAGE}

MODULES=        perl
RUN_DEPENDS=	net/p5-Net-XMPP

CONFIGURE_STYLE=perl

USE_GROFF =	Yes
NO_REGRESS=	yes
PKG_ARCH=	*

.include <bsd.port.mk>
