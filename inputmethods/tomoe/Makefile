# $OpenBSD$

COMMENT=	japanese handwriting recognition library

DISTNAME=	tomoe-0.2.1
REVISION=	0

HOMEPAGE= 	http://tomoe.sourceforge.jp/
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=tomoe/16048/}

CATEGORIES=	inputmethods japanese

SHARED_LIBS=	tomoe 0.0

# LGPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_FTP=	Yes

CONFIGURE_STYLE=gnu
USE_LIBTOOL=	Yes
WANTLIB=	c m

.include <bsd.port.mk>
