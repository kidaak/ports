# $OpenBSD$

COMMENT=	remake of Konami's Road Fighter

DISTNAME=	roadfighter.src_1.0.1269
PKGNAME=	${DISTNAME:S/.src_/-/}
REVISION =	0
WRKDIST=	${WRKDIR}/${DISTNAME:S/.src_/-/}

EXTRACT_SUFX=	.tgz
CATEGORIES=	games

HOMEPAGE=	http://roadfighter.jorito.net/
MASTER_SITES=	http://braingames.jorito.net/roadfighter/downloads/

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=	Yes

NO_REGRESS=	Yes
USE_GMAKE=	Yes

RUN_DEPENDS=	devel/desktop-file-utils
LIB_DEPENDS=	devel/sdl-sound \
		devel/sdl-image \
		devel/sdl-ttf \
		devel/sdl-mixer
WANTLIB=	SDL c stdc++ m pthread SDL_sound SDL_image SDL_ttf SDL_mixer

.include <bsd.port.mk>
