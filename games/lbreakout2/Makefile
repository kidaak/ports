# $OpenBSD$

COMMENT =	breakout game with many levels, powerups, good graphics

DISTNAME =	lbreakout2-2.6.3
CATEGORIES =	games x11

HOMEPAGE =	http://lgames.sourceforge.net/index.php?action=show_project&project=LBreakout2

MAINTAINER =	Benoit Lecocq <benoit@openbsd.org>

# GPLv2
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

WANTLIB =	SDL c m pthread z png>=9.0 SDL_mixer

MASTER_SITES =	${MASTER_SITE_SOURCEFORGE:=lgames/}

MODULES =	devel/gettext

LIB_DEPENDS =	devel/sdl-mixer \
		graphics/png
RUN_DEPENDS =	devel/desktop-file-utils

USE_GMAKE =	Yes

LOCALSTATEDIR=	${BASELOCALSTATEDIR}/games

CONFIGURE_STYLE =	gnu
CONFIGURE_ARGS +=	--with-docdir=${PREFIX}/share/doc
CONFIGURE_ENV =		CPPFLAGS="-I${LOCALBASE}/include/libpng" \
			LDFLAGS="-L${LOCALBASE}/lib" \
			LIBS="-lintl -liconv"

.include <bsd.port.mk>
