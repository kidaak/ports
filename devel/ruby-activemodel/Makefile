# $OpenBSD$

COMMENT =	toolkit for building modeling frameworks

VERSION =	3.1.3
DISTNAME =	activemodel-${VERSION}
REVISION =	0
CATEGORIES =	devel

# MIT License
PERMIT_PACKAGE_CDROM =		Yes
PERMIT_PACKAGE_FTP =		Yes
PERMIT_DISTFILES_CDROM =	Yes
PERMIT_DISTFILES_FTP =		Yes

MODULES =	lang/ruby

BUILD_DEPENDS =	${RUN_DEPENDS}
RUN_DEPENDS =	devel/ruby-i18n,${MODRUBY_FLAVOR}>=0.6,<1.0 \
		textproc/ruby-builder,${MODRUBY_FLAVOR}>=3.0.0,<3.1 \
		devel/ruby-activesupport,${MODRUBY_FLAVOR}=${VERSION}

CONFIGURE_STYLE =	ruby gem

.include <bsd.port.mk>
