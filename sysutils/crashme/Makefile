# $OpenBSD$

COMMENT =		test operating environment software robustness

# miod's modified version from cvs
DISTNAME =		crashme-2.4

REVISION =		1

CATEGORIES =		sysutils

# BSD
PERMIT_PACKAGE_CDROM =	without fee
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

MASTER_SITES =		http://distfiles.nl/
NO_REGRESS =		Yes
WANTLIB =		c

do-build:
	cd ${WRKSRC} && env -i ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} crashme

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/crashme ${PREFIX}/bin/crashme
	${INSTALL_MAN} ${WRKSRC}/crashme.man ${PREFIX}/man/man1/crashme.1

.include <bsd.port.mk>
