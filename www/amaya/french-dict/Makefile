# $OpenBSD$
#
# Many variables moved to ../Makefile.inc

COMMENT=	French dictionary for the Amaya browser/page composer

PKGNAME=		amaya-french-dict-20040223
DISTNAME=		French
REVISION=	0

RUN_DEPENDS=		${DICT_RUN_DEPENDS}

NO_BUILD=		Yes
NO_REGRESS=		Yes
PKG_ARCH=		*

DICNAME=		Fprinc

do-install:
	${dict_install_frag}

.include <bsd.port.mk>
