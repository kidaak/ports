# $OpenBSD$

COMMENT=		file copying over the OBEX protocol
DISTNAME=		obexftp-0.10.4
REVISION=		1

SHARED_LIBS +=	bfb                  0.4      # .0.4
SHARED_LIBS +=	cobexbfb             0.8      # .0.8
SHARED_LIBS +=	obexftp              0.11     # .0.11

CATEGORIES=		comms
HOMEPAGE=		http://triq.net/obex/

# GPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB=		c openobex>=1

MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=openobex/}

LIB_DEPENDS=		comms/openobex
CONFIGURE_STYLE=	gnu

USE_LIBTOOL=		Yes
USE_GROFF =		Yes

.include <bsd.port.mk>
