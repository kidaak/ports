# $OpenBSD$

SHARED_ONLY=	Yes

COMMENT=	Patricia Trie perl module for fast IP address lookups

MODULES=	cpan
DISTNAME=	Net-Patricia-1.19
REVISION=	0
CATEGORIES=	net

MAINTAINER =	Benoit Lecocq <benoit@openbsd.org>

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB += c

USE_GROFF =	Yes

RUN_DEPENDS =	net/p5-Net-CIDR-Lite \
		net/p5-Socket6

.include <bsd.port.mk>
