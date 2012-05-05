# $OpenBSD$

PREFIX =		/usr

COMMENT =		public domain korn shell
DISTNAME =		ksh-20120505
CATEGORIES =		sysutils shells

#HOMEPAGE =		???	URL

# Public domain
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

#MAKE_FLAGS =		???
#MAKE_ENV =		???
#FAKE_FLAGS =		???

#CFLAGS =		???
#LDFLAGS =		???

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/ksh
	${INSTALL_PROGRAM} ${WRKBUILD}/ksh ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKBUILD}/ksh.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKBUILD}/sh.1 ${PREFIX}/man/man1/
	ln ${PREFIX}/bin/ksh ${PREFIX}/bin/sh
	ln ${PREFIX}/bin/ksh ${PREFIX}/bin/rksh
	ln ${PREFIX}/man/man1/ksh.1 ${PREFIX}/man/man1/rksh.1
	${INSTALL_DATA} ${WRKBUILD}/etc/ksh.kshrc ${PREFIX}/share/examples/ksh

.include <bsd.port.mk>
