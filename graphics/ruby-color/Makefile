# $OpenBSD$

COMMENT =	color value conversion and modification

DISTNAME =	color-1.4.0
REVISION =	5
CATEGORIES =	graphics

HOMEPAGE =	http://color.rubyforge.org/

# MIT
PERMIT_PACKAGE_CDROM =		Yes
PERMIT_PACKAGE_FTP =		Yes
PERMIT_DISTFILES_CDROM =	Yes
PERMIT_DISTFILES_FTP =		Yes

MODULES =		lang/ruby

CONFIGURE_STYLE =	ruby gem

BUILD_DEPENDS =		${RUN_DEPENDS}
RUN_DEPENDS =		archivers/ruby-archive-tar-minitar,${MODRUBY_FLAVOR}>=0.5.0 \
			devel/ruby-hoe,${MODRUBY_FLAVOR}

do-regress:
	@cd ${WRKBUILD}/test && ${RUBY} test_all.rb

.include <bsd.port.mk>
