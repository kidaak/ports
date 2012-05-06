# $OpenBSD$

COMMENT =		file type guesser
DISTNAME =		file-5.11
CATEGORIES =		sysutils devel

SHARED_LIBS +=		magic 0.0 # .1.0.0

HOMEPAGE =		http://www.darwinsys.com/file/

# 2-clause BSD
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

#WANTLIB =		???

MASTER_SITES =		ftp://ftp.astron.com/pub/file/

#MODULES =		???
#BUILD_DEPENDS =	???
#RUN_DEPENDS =		???
#LIB_DEPENDS =		???
#REGRESS_DEPENDS =	???

MAKE_FLAGS =		libmagic_la_LDFLAGS="-no-undefined -version-info ${LIBmagic_VERSION:S/./:/}"
#MAKE_ENV =		???

SEPARATE_BUILD =	Yes
#USE_GROFF =		Yes
USE_LIBTOOL =		Yes
CONFIGURE_STYLE =	gnu
CONFIGURE_ARGS +=	${CONFIGURE_SHARED}
#CONFIGURE_ENV =	???

NO_REGRESS =		Yes

#CFLAGS =		???
#LDFLAGS =		???

.include <bsd.port.mk>
