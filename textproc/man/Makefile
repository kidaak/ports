# $OpenBSD$

COMMENT =		display manual pages
DISTNAME =		man-20120505
CATEGORIES =		sysutils textproc

#HOMEPAGE =		???	URL

# ISC and 3-clause BSD
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

#WANTLIB =		???

MASTER_SITES =		${MASTER_SITE_OBSCURE}

#MODULES =		???
BUILD_DEPENDS =		textproc/mdocml
#RUN_DEPENDS =		???
#LIB_DEPENDS =		???
#REGRESS_DEPENDS =	???

MAKE_FLAGS =		LDFLAGS="${LDFLAGS}"
#MAKE_ENV =		???

NO_REGRESS =		Yes

CFLAGS +=		-DMACHINE=\"${MACHINE}\"
CFLAGS +=		-DMACHINE_ARCH=\"${MACHINE_ARCH}\"
CFLAGS +=		-D__BSD_VISIBLE
CFLAGS !+=		pkg-config --cflags libbsd
LDFLAGS !=		pkg-config --libs libbsd

do-install:
	${INSTALL_PROGRAM} ${WRKBUILD}/man ${PREFIX}/bin/
	ln ${PREFIX}/bin/man ${PREFIX}/bin/help
	${INSTALL_MAN} ${WRKBUILD}/man.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKBUILD}/man.conf.5 ${PREFIX}/man/man5/
	${INSTALL_MAN} ${WRKBUILD}/help.1 ${PREFIX}/man/man1/

.include <bsd.port.mk>
