# $OpenBSD: ports/archivers/libshrink/Makefile,v 1.6 2011/11/18 11:16:23 espie Exp $

COMMENT=	compression wrapper library

DISTNAME=	shrink-0.3.0
PKGNAME=	lib${DISTNAME}
CATEGORIES=    	archivers devel
SHARED_LIBS=	shrink	1.0

HOMEPAGE=	http://opensource.conformal.com/wiki/Shrink	
MASTER_SITES=	http://opensource.conformal.com/snapshots/shrink/

MAINTAINER=	David Hill <dhill@openbsd.org>

WANTLIB=	c crypto lzma lzo2 ssl util z
LIB_DEPENDS=	archivers/lzo2 \
		archivers/xz

NO_REGRESS=	Yes

# ISC
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

FAKE_FLAGS=	MANDIR=${PREFIX}/man/man

do-configure:
	printf "major=${LIBshrink_VERSION:R}\nminor=${LIBshrink_VERSION:E}\n" \
            > ${WRKSRC}/libshrink/shlib_version

.include <bsd.port.mk>