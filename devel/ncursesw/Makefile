# $OpenBSD$

COMMENT =		emulation of curses in System V Release 4.0
V =			5.9
DISTNAME =		ncurses-$V
PKGNAME =		ncursesw-$V

# so.5.9
MAJOR = 0
MINOR = 0
SHARED_LIBS +=  formw       ${MAJOR}.${MINOR}
SHARED_LIBS +=  menuw       ${MAJOR}.${MINOR}
SHARED_LIBS +=  ncursesw    ${MAJOR}.${MINOR}
SHARED_LIBS +=  panelw      ${MAJOR}.${MINOR}

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
RUN_DEPENDS =		devel/ncurses
#LIB_DEPENDS =		???

#MAKE_FLAGS =
#MAKE_ENV =

SEPARATE_BUILD =	Yes
#USE_GROFF =		Yes
CONFIGURE_STYLE =	gnu
CONFIGURE_ARGS +=	${CONFIGURE_SHARED} \
			--with-shared \
			--with-shlib-version=abi \
			--with-abi-version=${MAJOR}.${MINOR} \
			--enable-widec

#CONFIGURE_ENV =	???

NO_REGRESS =		Yes

#CFLAGS =		???
#LDFLAGS =		???

do-install:
.for I in formw menuw ncursesw panelw
	${INSTALL_DATA} \
		${WRKBUILD}/lib/lib${I}.a \
		${WRKBUILD}/lib/lib${I}.so.* \
		${PREFIX}/lib/
.endfor

.include <bsd.port.mk>
