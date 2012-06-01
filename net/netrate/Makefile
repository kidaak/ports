# $OpenBSD$

COMMENT=		FreeBSD's tcp/udp traffic generator

DISTNAME=		netrate-20070208
CATEGORIES=		benchmarks net

# BSD
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes
WANTLIB += c

MASTER_SITES=		http://spacehopper.org/mirrors/

MAKE_ENV=		BINDIR=${PREFIX}/bin NOMAN=Yes
NO_REGRESS=		Yes

.include <bsd.port.mk>
