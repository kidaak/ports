# $OpenBSD$

BROKEN =		dynamic linking not working, needs polishing

COMMENT =		musl C library
DISTNAME =		musl-0.9.0

MAJOR =			0
MINOR =			0
SHARED_LIBS +=		c	${MAJOR}.${MINOR}

CATEGORIES =		devel

HOMEPAGE =		http://www.etalabs.net/musl/

# MIT
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

#WANTLIB =		???

MASTER_SITES =		${HOMEPAGE}releases/

#MODULES =		???
#BUILD_DEPENDS =	???
#RUN_DEPENDS =		???
#LIB_DEPENDS =		???

#MAKE_FLAGS =		???
MAKE_ENV =		LIBC_MAJOR="${MAJOR}" LIBC_MINOR="${MINOR}"

USE_GMAKE =		Yes

CONFIGURE_STYLE =	gnu
CONFIGURE_ARGS +=	${CONFIGURE_SHARED} \
			--enable-gcc-wrapper=no
#CONFIGURE_ENV =	???

NO_REGRESS =		Yes

#CFLAGS =		???
#LDFLAGS =		???
#WRKDIST =		??? if other than ${WRKDIR}/${DISTNAME}
#WRKSRC =		??? if other than ${WRKDIST}
#WRKBUILD =		??? if other than ${WRKSRC}
#WRKCONF =		??? if other than ${WRKBUILD}

#ALL_TARGET =		???
#INSTALL_TARGET =	???

.include <bsd.port.mk>
