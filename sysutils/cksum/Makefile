# $OpenBSD$

COMMENT =		display file checksums and block counts
DISTNAME =		cksum-20120509
CATEGORIES =		sysutils

#HOMEPAGE =		???	URL

# MIT
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

MAKE_FLAGS =		CC="${CC}" SYSCONFDIR="${PREFIX}/share/examples/cksum"
#MAKE_ENV =		???

USE_GMAKE =		Yes

#CFLAGS =		???
#LDFLAGS =		???
WRKSRC =		${WRKDIST}/rhash
REGRESS_TARGET =	test

post-install:
	${INSTALL_SCRIPT} "${WRKDIST}/cksum" "${PREFIX}/bin"

.include <bsd.port.mk>
