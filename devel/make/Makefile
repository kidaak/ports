# $OpenBSD$

COMMENT =		OpenBSD make: maintain program dependencies
DISTNAME =		make-20120505
CATEGORIES =		devel sysutils

#HOMEPAGE =		???	URL

# 2 and 3 clause BSD licensing
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

#WANTLIB =		???

MASTER_SITES =		${MASTER_SITE_OBSCURE}

#MODULES =		???
#BUILD_DEPENDS =	???
#RUN_DEPENDS =		???
#LIB_DEPENDS =		???
#REGRESS_DEPENDS =	???

#MAKE_FLAGS =		???
#MAKE_ENV =		???
#FAKE_FLAGS =		???
#REGRESS_FLAGS =	???

#CFLAGS =		???
#LDFLAGS =		???
#MAKE_FILE =		???
#PKG_ARCH =		??? (* for arch-independent packages)
#WRKDIST =		??? if other than ${WRKDIR}/${DISTNAME}
#WRKSRC =		??? if other than ${WRKDIST}
#WRKBUILD =		??? if other than ${WRKSRC}
#WRKCONF =		??? if other than ${WRKBUILD}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/make ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/make.1 ${PREFIX}/man/man1/
.include <bsd.port.mk>
