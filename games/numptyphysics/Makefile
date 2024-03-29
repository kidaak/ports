# $OpenBSD$

COMMENT-main =		physics-based drawing puzzle game
COMMENT-npcomplete =	extra levels for physics-based drawing puzzle game

DISTNAME =		numptyphysics-0.3.r20090104
PKGNAME-main =		${DISTNAME}
REVISION-main =		12
PKGNAME-npcomplete =	npcomplete-0.0.r20090116
REVISION-npcomplete =	3

MULTI_PACKAGES =	-main -npcomplete

EXTRACT_SUFX =	.tar.bz2
CATEGORIES =	games

MAINTAINER =	David Coppa <dcoppa@openbsd.org>

HOMEPAGE =	http://numptyphysics.garage.maemo.org/

MASTER_SITES =	http://mirror.amdmi3.ru/distfiles/

DISTFILES =	${DISTNAME}${EXTRACT_SUFX} \
		npcomplete-0.0.r20090116.tar.bz2

# GPLv3+
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

WANTLIB-main =		X11 c m pthread stdc++ z SDL SDL_image

RUN_DEPENDS-main =	devel/desktop-file-utils \
			x11/gtk+2,-guic
LIB_DEPENDS-main =	devel/sdl \
			devel/sdl-image

RUN_DEPENDS-npcomplete =${FULLPKGPATH-main}

CONFIGURE_STYLE =	autoconf automake no-autoheader
AUTOCONF_VERSION =	2.61
AUTOMAKE_VERSION =	1.9

CPPFLAGS =	-I${LOCALBASE}/include \
		-I${LOCALBASE}/include/libpng \
		-I${X11BASE}/include
LDFLAGS =	-pthread \
		-L${LOCALBASE}/lib \
		-L${X11BASE}/lib
CONFIGURE_ENV =	CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS =--disable-hildon

WRKDIST =	${WRKDIR}/numptyphysics

pre-patch:
	cd ${WRKSRC}/Box2D; perl -i -pe 's/\r$$//' `find . -type f`

post-patch:
	@cd ${WRKSRC}; AUTOCONF_VERSION=${AUTOCONF_VERSION} \
	    AUTOMAKE_VERSION=${AUTOMAKE_VERSION} aclocal

pre-configure:
	@cd ${WRKSRC}; AUTOCONF_VERSION=${AUTOCONF_VERSION} \
	    AUTOMAKE_VERSION=${AUTOMAKE_VERSION} /bin/sh ./autogen.sh
	@${SUBST_CMD} ${WRKSRC}/Config.h

post-install:
	${INSTALL_DATA} ${WRKDIR}/npcomplete/*.nph \
	    ${PREFIX}/share/numptyphysics/

.include <bsd.port.mk>
