# $OpenBSD$

SHARED_ONLY=	Yes

COMMENT=	XMMS input plugin to play bonk files

VERSION=	0.12
DISTNAME=	bonk-xmms-${VERSION}
PKGNAME=	xmms-bonk-${VERSION}
REVISION=	2
CATEGORIES=	audio

MAINTAINER=	Christian Weisgerber <naddy@openbsd.org>

# GPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB=		m stdc++

MASTER_SITES=	http://www.proustmedia.de/bonk-xmms/

RUN_DEPENDS=	audio/xmms
BUILD_DEPENDS=	${RUN_DEPENDS}

MAKE_ENV=	CXX="${CXX}"
ALL_TARGET=

NO_REGRESS=	Yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/xmms/Input/
	${INSTALL_DATA} ${WRKBUILD}/libbonk.so ${PREFIX}/lib/xmms/Input/

.include <bsd.port.mk>
