# $OpenBSD$

COMMENT =	postfix greylist daemon

DISTNAME =	sqlgrey-1.7.6
REVISION =	0
CATEGORIES =	mail

HOMEPAGE =	http://sqlgrey.sf.net/
MASTER_SITES =	${MASTER_SITE_SOURCEFORGE:=sqlgrey/}

# GPLv2
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

PKG_ARCH =		*
EXTRACT_SUFX =		.tar.bz2

NO_BUILD =		Yes
NO_REGRESS =		Yes
USE_GROFF =		Yes

RUN_DEPENDS =		devel/p5-Net-Server \
			devel/p5-IO-Multiplex \
			devel/p5-Date-Calc \
			net/wget \
			p5-DBD-SQLite-*|p5-DBD-mysql-*|p5-DBD-Pg-*:databases/p5-DBD-SQLite

.include <bsd.port.mk>
