# $OpenBSD$

COMMENT =	set of OpenType fonts designed for user interfaces
PKG_ARCH =	*
VERSION =	1.036
DISTNAME =	SourceSansPro_FontsOnly-${VERSION}
PKGNAME =	adobe-source-sans-pro-${VERSION}
CATEGORIES =	fonts x11
EXTRACT_SUFX =	.zip

HOMEPAGE =	http://sourceforge.net/projects/sourcesans.adobe/

#  OFL http://scripts.sil.org/OFL
PERMIT_PACKAGE_CDROM =		Yes
PERMIT_PACKAGE_FTP =		Yes
PERMIT_DISTFILES_CDROM =	Yes
PERMIT_DISTFILES_FTP =		Yes

MASTER_SITES =	${MASTER_SITE_SOURCEFORGE:=sourcesans.adobe/}

NO_BUILD =	Yes
NO_REGRESS =	Yes

INST_DIR =	${PREFIX}/lib/X11/fonts/adobe-source-sans-pro

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/adobe-source-sans-pro
	${INSTALL_DATA_DIR} ${INST_DIR}
	${INSTALL_DATA} ${WRKDIST}/*.ttf ${INST_DIR}
	${INSTALL_DATA} ${WRKDIST}/LICENSE.txt \
		${PREFIX}/share/doc/adobe-source-sans-pro
	${INSTALL_DATA} ${WRKDIST}/*.html \
		${PREFIX}/share/doc/adobe-source-sans-pro

.include <bsd.port.mk>
