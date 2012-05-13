# $OpenBSD$

#ONLY_FOR_ARCHS =	???
#NOT_FOR_ARCHS =	???
#SHARED_ONLY =		???

COMMENT =		*BSD compat lib

DISTNAME =		libbsd-0.3.0

MAJOR =			0
MINOR =			0
SHARED_LIBS +=		bsd ${MAJOR}.${MINOR}

CATEGORIES =		devel

HOMEPAGE =		http://libbsd.freedesktop.org/

# New BSD / MIT / other permissive
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

MAKE_FLAGS =		LIB_SONAME=libbsd.so.${MAJOR}		\
			LIB_SHARED=libbsd.so.${MAJOR}.${MINOR}	\
			prefix=${TRUEPREFIX}			\
			exec_prefix=${TRUEPREFIX}

#MAKE_ENV =		
#FAKE_FLAGS =		???

USE_GMAKE =		Yes
#USE_GROFF =		Yes
USE_LIBTOOL =		Yes

NO_REGRESS =		Yes

#CFLAGS =		???
#LDFLAGS =		???

ALL_TARGET =		libs

.include <bsd.port.mk>
