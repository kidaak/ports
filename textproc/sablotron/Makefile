# $OpenBSD$

COMMENT =	fast, compact and portable XSL/XSLT processor

V =		1.0.3
DISTNAME =	Sablot-${V}
PKGNAME =	sablotron-${V}
REVISION =	0
SHARED_LIBS =	sablot	103.0	# .100.3
CATEGORIES =	textproc

HOMEPAGE =	http://freshmeat.net/projects/sablotron/

MAINTAINER =	Benoit Lecocq <benoit@openbsd.org>

# MPL1.1 / GPLv3
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

WANTLIB =	c expat m ncurses readline stdc++

MASTER_SITES =	http://www.arcane-labs.net/download/OpenBSD/

MODULES =	converters/libiconv

# required to build the documentation
BUILD_DEPENDS =	textproc/p5-XML-Parser

USE_LIBTOOL =			Yes
USE_GMAKE =			Yes
USE_GROFF =			Yes
AUTOCONF_VERSION = 		2.57
MODGNU_CONFIG_GUESS_DIRS =	${WRKSRC}/autocfg

CONFIGURE_STYLE =		gnu
CONFIGURE_ENV =			SABLOT_GPL=1
CONFIGURE_ARGS =	${CONFIGURE_SHARED} --enable-static \
		--enable-debugger \
		--with-iconv-prefix=${LOCALBASE} --with-readline \
		--with-html-dir=${PREFIX}/share/doc/sablotron

.include <bsd.port.mk>
