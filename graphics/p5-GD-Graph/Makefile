# $OpenBSD$

COMMENT =	module for graph plotting

VERSION =	1.44
DISTNAME =	GDGraph-${VERSION}
PKGNAME =	p5-GD-Graph-${VERSION}
REVISION =	0
CATEGORIES =	graphics

MAINTAINER =	Kevin Lo <kevlo@openbsd.org>

MASTER_SITES =	${MASTER_SITE_PERL_CPAN:=GD/}

RUN_DEPENDS =	graphics/p5-GD>=1.18 \
		graphics/p5-GD-TextUtil
BUILD_DEPENDS =	${RUN_DEPENDS}

# Perl
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

MODULES =	cpan
USE_GROFF =	Yes

.include <bsd.port.mk>
