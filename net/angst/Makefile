# $OpenBSD$

COMMENT=	active packet sniffer

DISTNAME=	angst-0.4b
REVISION=	1
CATEGORIES=	net

HOMEPAGE=	http://angst.sourceforge.net/

MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=angst/} \
		${MASTER_SITE_PACKETSTORM:=sniffers/angst/}	

# BSD
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB =	c pcap lib/libnet-1.0/net=0
LIB_DEPENDS=	net/libnet/1.0

ALL_TARGET=	angst

MAKE_FLAGS=	CC="${CC}" CFLAGS="${CFLAGS}" \
		DEFINE="`libnet-config-1.0 --defines`" \
		INCLUDE="-I${LOCALBASE}/include/libnet-1.0" \
		LIBS="`libnet-config-1.0 --libs` -lpcap"

USE_GROFF =	Yes
NO_REGRESS=	Yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/angst ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/angst.8 ${PREFIX}/man/man8/angst.8
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/angst
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/angst
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${PREFIX}/share/doc/angst

.include <bsd.port.mk>
