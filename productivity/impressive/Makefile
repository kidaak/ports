# $OpenBSD$

COMMENT =		stylish PDF presentation generator

MODPY_EGG_VERSION =	0.10.2
DISTNAME =		Impressive-${MODPY_EGG_VERSION}
PKGNAME =		impressive-${MODPY_EGG_VERSION}
REVISION =		5

CATEGORIES =		productivity
HOMEPAGE =		http://impressive.sourceforge.net/
MASTER_SITES =		${MASTER_SITE_SOURCEFORGE:=impressive/}

# GPLv2
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

MODULES =		lang/python

# Set NO_BUILD to prevent python.port.mk from adding Python to
# BUILD_DEPENDS.
NO_BUILD =		Yes
USE_GROFF =		Yes
RUN_DEPENDS =		graphics/py-opengl \
			devel/pygame \
			graphics/py-Imaging \
			devel/xdg-utils

# pdftoppm(1)
RUN_DEPENDS +=		print/poppler,-utils

MODPY_ADJ_FILES =	impressive.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/impressive.py ${PREFIX}/bin/impressive
	${INSTALL_MAN} ${WRKSRC}/impressive.1 ${PREFIX}/man/man1/impressive.1
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/impressive
	${INSTALL_DATA} ${WRKSRC}/demo.pdf ${PREFIX}/share/examples/impressive/.

.include <bsd.port.mk>
