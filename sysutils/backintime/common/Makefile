# $OpenBSD$

COMMENT=	simple backup tool -- common files

PKGNAME=	backintime-common-${V}
REVISION=	3

WRKSRC=		${WRKDIST}/common

BUILD_DEPENDS=	devel/gettext
RUN_DEPENDS=	sysutils/coreutils \
		net/rsync

SUBST_FILES=	backintime config.py

.include <bsd.port.mk>
