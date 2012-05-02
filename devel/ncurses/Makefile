# $OpenBSD$

COMMENT =		emulation of curses in System V Release 4.0
DISTNAME =		ncurses-5.9

# so.5.9
MAJOR = 0
MINOR = 0
SHARED_LIBS +=  form       ${MAJOR}.${MINOR}
SHARED_LIBS +=  menu       ${MAJOR}.${MINOR}
SHARED_LIBS +=  ncurses    ${MAJOR}.${MINOR}
SHARED_LIBS +=  panel      ${MAJOR}.${MINOR}

CATEGORIES =		devel

HOMEPAGE =		http://www.gnu.org/software/ncurses/

# MIT 
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

#WANTLIB =		???

MASTER_SITES =		${MASTER_SITE_GNU:=ncurses/}

#MODULES =		???
#BUILD_DEPENDS =	???
#LIB_DEPENDS =		???

#MAKE_FLAGS =
#MAKE_ENV =

SEPARATE_BUILD =	Yes
#USE_GROFF =		Yes
CONFIGURE_STYLE =	gnu
CONFIGURE_ARGS +=	${CONFIGURE_SHARED} \
			--with-shared \
			--with-shlib-version=abi \
			--with-abi-version=${MAJOR}.${MINOR}

#CONFIGURE_ENV =	???

NO_REGRESS =		Yes

#CFLAGS =		???
#LDFLAGS =		???

.include <bsd.port.mk>
