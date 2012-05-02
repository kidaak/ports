# $OpenBSD: ports/games/alephone/weland/Makefile,v 1.4 2010/11/16 11:23:25 espie Exp $

COMMENT =		marathon / alephone map editor

V =			211
DISTNAME =		weland-r${V}-src
PKGNAME =		weland-${V}
REVISION =		1

CATEGORIES =		games

HOMEPAGE =		http://sourceforge.net/projects/weland/

# GPL v2-only
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

MASTER_SITES =		${MASTER_SITE_SOURCEFORGE:=weland/}
EXTRACT_SUFX =		.zip

MODULES =		lang/mono

BUILD_DEPENDS =		${RUN_DEPENDS}
RUN_DEPENDS =		x11/mono-gtk2

WRKDIST =		${WRKDIR}/weland

pre-configure:
	@cp ${FILESDIR}/weland.sh ${WRKSRC}
	@${SUBST_CMD} ${WRKSRC}/weland.sh

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/libexec/weland/
	${INSTALL_SCRIPT} ${WRKSRC}/Weland.exe ${PREFIX}/libexec/weland/
	${INSTALL_SCRIPT} ${WRKSRC}/weland.sh ${PREFIX}/bin/weland

NO_REGRESS =		Yes

.include <bsd.port.mk>