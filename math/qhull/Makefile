# $OpenBSD$

COMMENT =		computing the convex hull

VERSION =		2011.1
DISTNAME =		qhull-${VERSION}

SHARED_LIBS =		qhull6		0.0 # 6.2

CATEGORIES =		math

HOMEPAGE =		http://www.qhull.org/

# BSD
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

WANTLIB =		c m stdc++

MASTER_SITES =		${HOMEPAGE}download/
DISTFILES =		${DISTNAME}-src${EXTRACT_SUFX}
EXTRACT_SUFX =		.tgz

MODULES =		devel/cmake

NO_REGRESS =		Yes

CFLAGS +=		-fno-strict-aliasing
CONFIGURE_ARGS +=	-DDOC_INSTALL_DIR=${PREFIX}/share/doc/qhull

.include <bsd.port.mk>
