# $OpenBSD$

COMMENT =	dungeon explorin', hackin', game.  Hard
DISTNAME =	se007e7f1
PKGNAME =	slash-em-3.4.3.7e7f1
REVISION =	3
V =		3.4.3.7e7f1
CATEGORIES =	games

HOMEPAGE =	http://slashem.sourceforge.net
MASTER_SITES =	http://avrc.city.ac.uk/nethack/slashem/

MAINTAINER =	Marc Espie <espie@openbsd.org>

# GPL
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes
WANTLIB =		c termlib

WRKDIST =		${WRKDIR}/slashem-0.0.7E7F1

FAKE_FLAGS =		PREFIX=${PREFIX}

GAMEDIR =		lib/slashemdir-$V
NHDIR =			${PREFIX}/${GAMEDIR}
MAKE_ENV += 		NHDIR=${NHDIR} NETHACKCONFIG=${NETHACKCONFIG}
SUBST_VARS =		GAMEDIR V
USE_GROFF =		Yes

# qt flavor is apparently not working yet
FLAVORS =		no_x11 #qt
FLAVOR ?=
# ... but let fragments work
PKG_ARGS +=		-Dqt=0

.if ${FLAVOR} == "no_x11"
NETHACKCONFIG =		${FILESDIR}/simple-config
.elif ${FLAVOR} == "qt"
NETHACKCONFIG =		${FILESDIR}/qt-config
PORTPATH =	${LOCALBASE}/lib/qt2/bin:/usr/bin:/bin:/usr/sbin:/sbin:${LOCALBASE}/bin
LIB_DEPENDS =		x11/qt2
WANTLIB +=		qt.=2
.else
NETHACKCONFIG =		${FILESDIR}/x-config
WANTLIB +=		X11 Xaw Xext Xmu Xpm Xt pthread-stubs xcb
.endif

RUN_DEPENDS =		games/hackdata

NO_REGRESS =		Yes

do-configure:
	@cd ${WRKSRC}/sys/unix; /bin/sh setup.sh symlinks

post-build:
	@cd ${WRKSRC}/util && ${MAKE_ENV} make recover
	@cd ${WRKSRC}/util && ln -f recover strecover
	@cd ${WRKSRC}/doc && perl -p ${FILESDIR}/substitute <recover.6 >strecover.6

post-install:
	${INSTALL_PROGRAM} ${PREFIX}/bin/slashem ${PREFIX}/bin/slashem-$V
	${INSTALL_PROGRAM} ${WRKBUILD}/util/strecover ${PREFIX}/bin/strecover-$V
	${INSTALL_MAN} ${WRKSRC}/doc/slashem.6 ${PREFIX}/man/man6/slashem-$V.6
	${INSTALL_MAN} ${WRKSRC}/doc/strecover.6 ${PREFIX}/man/man6/strecover-$V.6
.if ${FLAVOR} == ""
	${INSTALL_DATA_DIR} ${PREFIX}/lib/X11/app-defaults
	@cd ${WRKSRC}/win/X11 && \
	    ${INSTALL_DATA} SlashEM.ad ${PREFIX}/lib/X11/app-defaults/SlashEM-$V
.endif

.include <bsd.port.mk>
