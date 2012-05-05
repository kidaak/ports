# $OpenBSD$

COMMENT =		arch and machine reporting tools
DISTNAME =		arch-20120505
CATEGORIES =		sysutils

#HOMEPAGE =		???	URL

# 2-clause BSD
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

#WANTLIB =		???

MASTER_SITES =		${MASTER_SITE_OBSCURE}

#MODULES =		???
BUILD_DEPENDS =		textproc/mdocml
RUN_DEPENDS =		textproc/man
#LIB_DEPENDS =		???
#REGRESS_DEPENDS =	???

#MAKE_FLAGS =		???
#MAKE_ENV =		???

#SEPARATE_BUILD =	Yes (build in a directory other than WRKSRC)
#SEPARATE_BUILD =	flavored (distinct flavors may share a common WRKSRC)

NO_REGRESS =		Yes

CFLAGS +=		-DMACHINE=\"${MACHINE}\"
CFLAGS +=		-DMACHINE_ARCH=\"${MACHINE_ARCH}\"
#LDFLAGS =		???

do-install:
	${INSTALL_PROGRAM} ${WRKBUILD}/arch ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKBUILD}/arch.1 ${PREFIX}/man/man1/
	ln -f ${PREFIX}/bin/arch ${PREFIX}/bin/machine
	ln -f ${PREFIX}/man/man1/arch.1 ${PREFIX}/man/man1/machine.1

.include <bsd.port.mk>
