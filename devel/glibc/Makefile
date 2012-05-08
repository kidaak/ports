# $OpenBSD$

COMMENT =		GNU C library
DISTNAME =		glibc-2.15

#SHARED_LIBS =		???

CATEGORIES =		devel

HOMEPAGE =		http://www.gnu.org/software/libc/

# LGPL 2.1 
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

#WANTLIB =		???

MASTER_SITES =		${MASTER_SITE_GNU:=glibc/}
EXTRACT_SUFX =		.tar.xz

#MODULES =		???
#BUILD_DEPENDS =	???
#RUN_DEPENDS =		???
#LIB_DEPENDS =		???
#REGRESS_DEPENDS =	???

#MAKE_FLAGS =		???
#MAKE_ENV =		???
#FAKE_FLAGS =		???
#REGRESS_FLAGS =	???

SEPARATE_BUILD =	Yes
USE_GMAKE =		Yes
#USE_GROFF =		Yes
CONFIGURE_STYLE =	gnu
# --disable-sanity-checks can probably be removed once
# PREFIX is correctly set
CONFIGURE_ARGS +=	${CONFIGURE_SHARED}			\
			--disable-sanity-checks			\
			--enable-stackguard-randomization	\
#CONFIGURE_ENV =	???

#AUTOCONF_VERSION =	??? (defaults to 2.13)
#AUTOMAKE_VERSION =	??? (defaults to 1.4)

#CFLAGS =		???
#LDFLAGS =		???

.include <bsd.port.mk>
