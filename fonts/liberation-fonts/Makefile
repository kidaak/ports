# $OpenBSD$

PKG_ARCH =	*

COMMENT =	substitute for MS TTF core fonts

DISTNAME =	liberation-fonts-ttf-1.07.2
PKGNAME =	${DISTNAME:S/-ttf//}
CATEGORIES =	fonts x11

HOMEPAGE =	https://fedorahosted.org/liberation-fonts

MAINTAINER =	Benoit Lecocq <benoit@openbsd.org>

# GPLv2+exception license
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

MASTER_SITES =	https://fedorahosted.org/releases/l/i/liberation-fonts/

NO_BUILD =	Yes
NO_REGRESS =	Yes

INST_DIR =	${PREFIX}/lib/X11/fonts/Liberation

do-install:
	${INSTALL_DATA_DIR} ${INST_DIR}
	${INSTALL_DATA} ${WRKSRC}/{*.ttf,*.txt} ${INST_DIR}

.include <bsd.port.mk>
