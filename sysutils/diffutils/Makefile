# $OpenBSD$

COMMENT =		tools to find differences between files
DISTNAME =		diffutils-3.2

CATEGORIES =		sysutils

HOMEPAGE =		http://www.gnu.org/software/diffutils/

# GPLv3+
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

#WANTLIB =		???

MASTER_SITES =		${MASTER_SITE_GNU:=diffutils/}

MODULES =		devel/gettext
#BUILD_DEPENDS =	???
#RUN_DEPENDS =		???
#LIB_DEPENDS =		devel/libbsd
REGRESS_DEPENDS =	devel/gmake

#MAKE_FLAGS =		???
#MAKE_ENV =		???

SEPARATE_BUILD =	Yes
#USE_GROFF =		Yes
CONFIGURE_STYLE =	gnu

#CFLAGS =		???
#LDFLAGS =		???

do-regress:
	cd ${WRKBUILD} && gmake ${REGRESS_TARGET}

.include <bsd.port.mk>
