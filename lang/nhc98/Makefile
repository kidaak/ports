# $OpenBSD$

COMMENT=	portable Haskell compiler

# not for 64 bits, broken on ppc
NOT_FOR_ARCHS=	${LP64_ARCHS} powerpc

V=		1.22
DISTNAME=	nhc98-$V
CATEGORIES=	lang
HOMEPAGE=	http://www.haskell.org/nhc98/
MAINTAINER=	Matthias Kilian <kili@openbsd.org>

MASTER_SITES=	${HOMEPAGE}

DISTFILES=	nhc98src-$V.tar.gz

# BSDish
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB=		c m

USE_GMAKE=		Yes
USE_GROFF =		Yes
MAKE_FLAGS=		OPT="${CFLAGS}"
CONFIGURE_STYLE=	simple
CONFIGURE_ARGS=		--prefix=${PREFIX} \
			--docdir=${PREFIX}/share/doc/nhc98 +docs

# it does compile with ghc-6.6.1, but about 20 testcases seem to run
# worse than with a cc-built nhc, so still stick with cc.
CONFIGURE_ARGS+=--buildwith=cc

REGRESS_TARGET=	test

.include <bsd.port.mk>
