# $OpenBSD$

SHARED_ONLY =		Yes

COMMENT =		high-performance HTTP accelerator

DISTNAME =		varnish-3.0.2
CATEGORIES =		www

SHARED_LIBS =		varnishapi	1.0

MAINTAINER =		Jim Razmus II <jim@openbsd.org>

HOMEPAGE =		http://www.varnish-cache.org/

# BSD
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

WANTLIB = 		c curses edit m pcre pthread

LIB_DEPENDS = 		devel/pcre

MASTER_SITES =		http://repo.varnish-cache.org/source/

USE_LIBTOOL =		Yes
USE_GROFF =		Yes
CONFIGURE_STYLE =	autoconf
AUTOCONF_VERSION =	2.68

REGRESS_TARGET =	check

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/varnish
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/varnish
	mv ${WRKINST}${SYSCONFDIR}/varnish/default.vcl \
	    ${PREFIX}/share/examples/varnish
	@find ${PREFIX}/lib/varnish -name '*.a' -print | xargs rm
	@find ${PREFIX}/lib/varnish -name '*.la' -print | xargs rm

.include <bsd.port.mk>
