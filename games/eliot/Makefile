# $OpenBSD$

COMMENT =	scrabble game
DISTNAME =	eliot-1.14
CATEGORIES =	games

HOMEPAGE =	http://nongnu.org/eliot/
MASTER_SITES =	${MASTER_SITE_SAVANNAH:=eliot/releases/}

EXTRACT_ONLY =	${DISTNAME}${EXTRACT_SUFX}
DISTFILES +=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR =	eliot
DICTS =		danosc eliot-dic-cs eliot-dic-fr lex-fise rak sowpods06 twl06
.for dict in ${DICTS}
DISTFILES+=	${dict}.dawg:0
.endfor
MASTER_SITES0 =	${MASTER_SITE_SAVANNAH:=eliot/dict/}

# GPLv2
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

MODULES =	x11/qt4 devel/gettext

CONFIGURE_STYLE =	gnu
CONFIGURE_ENV +=	CPPFLAGS="-I${LOCALBASE}/include" \
			 LDFLAGS="-L${X11BASE}/lib -pthread -L${LOCALBASE}/lib -liconv"
USE_GMAKE =	Yes

BUILD_DEPENDS =	devel/boost
RUN_DEPENDS =	devel/desktop-file-utils
LIB_DEPENDS =	textproc/arabica devel/libconfig
WANTLIB +=	QtGui c m pthread stdc++
WANTLIB +=	arabica config++ expat ncursesw

post-configure:
	${SUBST_CMD} ${WRKSRC}/qt/main_window.cpp

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/eliot
.for dict in ${DICTS}
	${INSTALL_DATA} ${FULLDISTDIR}/${dict}.dawg ${PREFIX}/share/eliot
.endfor

.include <bsd.port.mk>
