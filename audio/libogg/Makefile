# $OpenBSD$

COMMENT=	Ogg bitstream library

DISTNAME=	libogg-1.3.0
CATEGORIES=    	audio
HOMEPAGE=	http://www.xiph.org/ogg/
SHARED_LIBS=	ogg	6.2	# 8.0

MAINTAINER=	Christian Weisgerber <naddy@openbsd.org>

# BSD
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=	http://downloads.xiph.org/releases/ogg/

USE_LIBTOOL=	Yes
CONFIGURE_STYLE=gnu
CONFIGURE_ARGS=	${CONFIGURE_SHARED}
SEPARATE_BUILD=	Yes

.include <bsd.port.mk>
