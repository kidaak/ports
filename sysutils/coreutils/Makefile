# $OpenBSD$

COMMENT =		file, shell and text manipulation utilities
DISTNAME =		coreutils-8.15

CATEGORIES =		sysutils

HOMEPAGE =		http://www.gnu.org/software/coreutils/coreutils.html

# GPLv3+
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

WANTLIB =		c pthread

MASTER_SITES =		${MASTER_SITE_GNU:=coreutils/}
EXTRACT_SUFX =		.tar.xz

MODULES =		devel/gettext

CONFIGURE_STYLE =	gnu
CONFIGURE_ARGS =	--without-gmp

.include <bsd.port.mk>
