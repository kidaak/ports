# $OpenBSD$

COMMENT=		traceroute implementation using TCP packets

DISTNAME=		tcptraceroute-1.5beta7
REVISION=		2
CATEGORIES=    		net

HOMEPAGE=		http://michael.toren.net/code/tcptraceroute/

# GPL
PERMIT_PACKAGE_CDROM=	Yes 
PERMIT_PACKAGE_FTP=	Yes 
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB=		c pcap lib/libnet-1.1/net=11

CONFIGURE_STYLE=	gnu
CONFIGURE_ARGS=		--with-libnet=${PREFIX} \
			--enable-noselect-default

MASTER_SITES=		http://michael.toren.net/code/tcptraceroute/

LIB_DEPENDS=		net/libnet/1.1

MAKE_FLAGS=		CC="${CC}" \
			CFLAGS="${CFLAGS}"

USE_GROFF =		Yes
NO_REGRESS=		Yes
USE_GMAKE=		Yes

.include <bsd.port.mk>
