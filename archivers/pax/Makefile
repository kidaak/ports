# $OpenBSD$

COMMENT =		read and write file archives and copy directories
DISTNAME =		pax-20120507
CATEGORIES =		archivers sysutils

#HOMEPAGE =		???	URL

# 3-clause BSD
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

#MAKE_FLAGS =		???
MAKE_ENV =		LDADD="${LDFLAGS}"

NO_REGRESS =		Yes

CFLAGS !+=		pkg-config --cflags libbsd
LDFLAGS !+=		pkg-config --libs libbsd

do-install:
	${INSTALL_PROGRAM} ${WRKBUILD}/pax ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKBUILD}/pax.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKBUILD}/tar.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKBUILD}/cpio.1 ${PREFIX}/man/man1/
	ln ${PREFIX}/bin/pax ${PREFIX}/bin/tar
	ln ${PREFIX}/bin/pax ${PREFIX}/bin/cpio

.include <bsd.port.mk>
