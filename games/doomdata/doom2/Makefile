# $OpenBSD$

COMMENT =		DOOM II data files

DISTFILES =		doom2.wad
PKGNAME =		doom2data-1.0
REVISION =		0
CATEGORIES =		games

EXTRACT_ONLY =

HOMEPAGE =		http://www.idsoftware.com/games/doom/doom-collectors/

MAINTAINER =		Paul de Weerd <weerd@weirdnet.nl>

PKG_ARCH =		*

# Commercial game data files (for GPL'ed game)
PERMIT_PACKAGE_CDROM =	Commercial game data files 
PERMIT_PACKAGE_FTP =	Commercial game data files 
PERMIT_DISTFILES_CDROM =Commercial game data files 
PERMIT_DISTFILES_FTP =	Commercial game data files 

FETCH_MANUALLY =	"You must copy the original DOOM2.WAD from your"
FETCH_MANUALLY +=	"original distribution media and copy it to"
FETCH_MANUALLY +=	"${FULLDISTDIR}."

do-build:

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doom/
	${INSTALL_DATA} ${FULLDISTDIR}/doom2.wad ${PREFIX}/share/doom/doom2.wad

.include <bsd.port.mk>
