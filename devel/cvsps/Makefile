# $OpenBSD$

COMMENT=	generate patchsets from CVS repositories

DISTNAME=	cvsps-2.1
REVISION=	0
CATEGORIES=     devel
HOMEPAGE=	http://www.cobite.com/cvsps/

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes 
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB=	c z
MASTER_SITES=	${HOMEPAGE}

do-install:
	${INSTALL_PROGRAM} ${WRKBUILD}/cvsps ${PREFIX}/bin
	${INSTALL_MAN} ${WRKBUILD}/cvsps.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
