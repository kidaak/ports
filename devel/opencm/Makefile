# $OpenBSD$

COMMENT=		OpenCM change management system

V=			0.1.2alpha8
sV=			-2
DISTFILES=		opencm-${V}${sV}-src.tgz
DISTNAME=		opencm-${V}
PKGNAME=		opencm-${V}
REVISION =		2
CATEGORIES=		devel

HOMEPAGE=		http://www.opencm.org/

MAINTAINER=		Todd T. Fries <todd@openbsd.org>

# BSD/(GPL for diff3)
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=	Yes
WANTLIB=		c crypto ncurses pthread readline ssl z gc>=3

MASTER_SITES=		${HOMEPAGE}releases/

USE_GMAKE=		Yes
AUTOCONF_VERSION=	2.57
CONFIGURE_STYLE=	autoconf

LDFLAGS+= -L${LOCALBASE}/lib -lgc -pthread

CONFIGURE_ENV=		LDFLAGS="${LDFLAGS}" \
			CPPFLAGS="${CPPFLAGS} \
			-I${LOCALBASE}/include -I${LOCALBASE}/include/gc \
			-DUSE_SYSTEM_ZLIB" \
			vl_cv_lib_kerberos=1

MAKE_ENV= LDFLAGS="${LDFLAGS}"

NO_REGRESS=	Yes

MAKE_FLAGS+=		TEXI2DVI=: DVIPS=:
MAKE_FLAGS+= LIBZ=-lz USOURCE_SUBDIRS="libgdiff src"
MAKE_FLAGS+= LIBGC=
MAKE_FLAGS+=		infodir=${PREFIX}/info
MAKE_FLAGS+=		mandir=${PREFIX}/man

post-install:
	gunzip ${PREFIX}/info/opencm.info.gz


LIB_DEPENDS=		devel/boehm-gc

WRKSRC=			${WRKDIST}/base

.include <bsd.port.mk>
