# $OpenBSD$

COMMENT=	open source standalone flash(tm) player

DISTNAME=	flash-0.4.10
REVISION =	0
CATEGORIES=	graphics	
EXTRACT_SUFX=	.tgz

HOMEPAGE=	http://www.swift-tools.net/Flash/

MAINTAINER=	Peter Valchev <pvalchev@openbsd.org>

# GPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes
WANTLIB=		X11 Xext c m ossaudio pthread-stubs stdc++ xcb

MASTER_SITES=	${HOMEPAGE}

MAKE_ENV=	CC="${CC}" CXX="${CXX}"
FAKE_FLAGS=	PREFIX="${WRKINST}${PREFIX}"

NO_REGRESS=	Yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/swfplayer ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/flash
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/flash

.include <bsd.port.mk>
