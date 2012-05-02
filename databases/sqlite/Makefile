# $OpenBSD: ports/databases/sqlite/Makefile,v 1.18 2010/11/15 00:22:54 espie Exp $

COMMENT=	Embedded SQL implementation
DISTNAME=	sqlite-2.8.17
PKGNAME=	${DISTNAME}
REVISION =	1
CATEGORIES=	databases
SHARED_LIBS +=	sqlite               8.6      # .0.0

MASTER_SITES=	${HOMEPAGE}

HOMEPAGE=	http://www.sqlite.org/

# PD
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes

AUTOCONF_VERSION=2.59
USE_GMAKE=	Yes
USE_LIBTOOL=	Yes

WANTLIB=	c ncurses readline

FLAVORS=no_tcl
FLAVOR?=

CONFIGURE_STYLE=autoconf no-autoheader
CONFIGURE_ARGS=	${CONFIGURE_SHARED}
.if ${FLAVOR:Mno_tcl}
NO_REGRESS=	Yes
CONFIGURE_ARGS+=--disable-tcl
.else
REGRESS_TARGET=	test
BUILD_DEPENDS+=	lang/tcl/8.4
CONFIGURE_ENV+=	config_TARGET_TCL_LIBS="-L${LOCALBASE}/lib -ltcl84 -lm"
CONFIGURE_ENV+=	config_TARGET_TCL_INC="-I${LOCALBASE}/include/tcl8.4"
.endif

.include <bsd.port.mk>