# $OpenBSD$

COMMENT=		mastering tools for DVD+RW/+R/-R/-RW

DISTNAME=		dvd+rw-tools-7.0
REVISION =		1
CATEGORIES=		sysutils
HOMEPAGE=		http://fy.chalmers.se/~appro/linux/DVD+RW/

# GPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=		${HOMEPAGE}tools/

RUN_DEPENDS=		sysutils/cdrtools>=1.10
WANTLIB=		c m pthread stdc++

# allow growisofs to work under sudo(8)
CFLAGS+=		-DI_KNOW_ALL_ABOUT_SUDO

MAKE_FLAGS+=		CFLAGS="${CFLAGS}" \
			CXXFLAGS="${CXXFLAGS} -fno-exceptions"

USE_GROFF =		Yes
NO_REGRESS=		Yes

do-install:
.for prog in growisofs dvd+rw-format dvd+rw-booktype dvd+rw-mediainfo
	${INSTALL_PROGRAM} ${WRKBUILD}/${prog} ${PREFIX}/bin
.endfor
	${INSTALL_MAN} ${WRKSRC}/growisofs.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dvd+rw-tools
	${INSTALL_DATA} ${WRKSRC}/index.html ${PREFIX}/share/doc/dvd+rw-tools

.include <bsd.port.mk>
