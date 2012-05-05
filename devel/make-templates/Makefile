# $OpenBSD$

PREFIX =		/usr

COMMENT =		OpenBSD makefile templates
DISTNAME =		make-templates-20120504
CATEGORIES =		devel

#HOMEPAGE =		???	URL

# 2 and 3 clause BSD licensing
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

MASTER_SITES =		${MASTER_SITE_OBSCURE}

NO_BUILD =		Yes
NO_REGRESS =		Yes

PKG_ARCH =		*

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/mk
	find "${WRKSRC}" -name "*.mk" -print0 | \
		xargs -0r -ifiles ${INSTALL_DATA} files ${PREFIX}/share/mk

.include <bsd.port.mk>
