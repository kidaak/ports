# $OpenBSD$

COMMENT=	jump'n run game with unique video effects

VERSION=	0.8.10
DVERSION=	0.8.6
DISTNAME=	amphetamine-${VERSION}
PKGNAME=	amph-${VERSION}
REVISION =	2
CATEGORIES=	games x11
EXTRACT_SUFX=	.tar.bz2

HOMEPAGE=	http://n.ethz.ch/student/loehrerl/amph/amph.html

MASTER_SITES=	http://n.ethz.ch/student/loehrerl/amph/files/

MAINTAINER=	Peter Valchev <pvalchev@openbsd.org>

PERMIT_PACKAGE_CDROM=   Yes
PERMIT_PACKAGE_FTP=     Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=   Yes
WANTLIB=		X11 Xext Xpm Xt c m pthread pthread-stubs stdc++ \
			usbhid xcb SDL

DISTFILES=	amphetamine-data-${DVERSION}${EXTRACT_SUFX} \
		${DISTNAME}${EXTRACT_SUFX}

LIB_DEPENDS=	devel/sdl

NO_REGRESS=	Yes
USE_GMAKE=	Yes
MAKE_ENV=	CC="${CC}" CXX="${CXX}" CFLAGS="${CFLAGS}" \
		CXXFLAGS="${CXXFLAGS}" PREFIX="${PREFIX}" X11BASE="${X11BASE}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/amph ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/amph
	${INSTALL_DATA_DIR} ${PREFIX}/share/amph
	@cp -Rp ${WRKDIR}/amph/* ${PREFIX}/share/amph/
	@chown -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/amph
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/amph

.include <bsd.port.mk>
