# $OpenBSD$

COMMENT=	highly flexible sniffer/NIDS

V=		1.4
DISTNAME=	bro-${V}-release
PKGNAME=	bro-${V}

REVISION=	0

SHARED_LIBS= 	broccoli	0.0	# .2.0

CATEGORIES=	net security

HOMEPAGE=	http://www.bro-ids.org/

MAINTAINER=	Kevin Lo <kevlo@openbsd.org>

# BSD
PERMIT_PACKAGE_CDROM= 	Yes
PERMIT_PACKAGE_FTP=   	Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP= 	Yes

WANTLIB=	c crypto m pcap ssl stdc++ termcap z GeoIP>=5 magic>=1

MASTER_SITES=	ftp://bro-ids.org/

LIB_DEPENDS=	net/GeoIP \
		devel/libmagic

USE_LIBTOOL=	Yes
CONFIGURE_STYLE=autoconf
AUTOCONF_VERSION=2.59

WRKDIST=	${WRKDIR}/bro-${V}

FAKE_FLAGS=	sysconfdir=${PREFIX}/share/examples/bro

NO_REGRESS=	Yes

.include <bsd.port.mk>
