# $OpenBSD$

COMMENT =		C library implementing server and client side
DISTNAME =		libssh-0.5.2
REVISION =		0

SHARED_LIBS +=  	ssh		0.0 # 4.2
SHARED_LIBS +=  	ssh_threads	0.0 # 4.2

CATEGORIES =		security devel

HOMEPAGE =		http://www.libssh.org/
MASTER_SITES =		${HOMEPAGE}files/0.5/

MAINTAINER =		Remi Pointel <rpointel@openbsd.org>

# LGPL v2.1
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

WANTLIB += crypto ssl z

MODULES =		devel/cmake

WRKBUILD =		${WRKDIST}/build/

BUILD_DEPENDS =		devel/cmockery

CONFIGURE_ARGS +=	-DWITH_TESTING=ON

.include <bsd.port.mk>
