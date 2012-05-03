# $OpenBSD$

COMMENT =		print sequential or random data
DISTNAME =		jot-20120501
CATEGORIES =		sysutils

#HOMEPAGE =		???	URL

# 3-clause BSD
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

# "make port-lib-depends-check" can help
#WANTLIB =		???

MASTER_SITES =		${MASTER_SITE_OBSCURE}

BUILD_DEPENDS =		textproc/mdocml

CFLAGS !+=		pkg-config --cflags libbsd
LDFLAGS !+=		pkg-config --libs libbsd

do-build:
	cd ${WRKSRC} && \
		${CC} ${CFLAGS} -c jot.c -o jot.o && \
		${CC} ${LDFLAGS} jot.o -o jot
	cd ${WRKSRC} && \
		mandoc -Tlint -Wfatal jot.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jot ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/jot.1 ${PREFIX}/man/man1/

	
.include <bsd.port.mk>
