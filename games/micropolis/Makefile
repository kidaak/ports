# $OpenBSD$

COMMENT=	city-building simulation

DISTNAME=	micropolis-20080211
REVISION=	4
WRKDIST=	${WRKDIR}/micropolis

CATEGORIES=	games

HOMEPAGE=	http://www.donhopkins.com/home/micropolis/
MASTER_SITES=	http://freedaemon.com/~deanna/

# GPLv3
# beware of SimCity, tm of Electronic Arts
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB += SDL SDL_mixer X11 Xext Xpm c m pthread

NO_REGRESS=	Yes
RUN_DEPENDS=	devel/desktop-file-utils
LIB_DEPENDS=	devel/sdl-mixer

CFLAGS+=	-I${LOCALBASE}/include -I${X11BASE}/include

do-configure:
	@perl -pi -e s,%%PREFIX%%,${PREFIX}, ${WRKDIST}/Micropolis
	@perl -pi -e s,%%PREFIX%%,${PREFIX}, ${WRKDIST}/res/micropolis.tcl
	@perl -pi -e s,%%LOCALBASE%%,${LOCALBASE}, ${WRKDIST}/res/micropolis.tcl
	@perl -pi -e s,%%X11BASE%%,${X11BASE},g ${WRKSRC}/src/tclx/config.mk
	@perl -pi -e s,%%X11BASE%%,${X11BASE},g ${WRKSRC}/src/tk/makefile

.include <bsd.port.mk>
