# $OpenBSD$

COMMENT=	graphical front-end to the diff program

V=		4.1.4
DISTNAME=	tkdiff-${V}-unix
PKGNAME=	${DISTNAME:S/-unix//}
REVISION =	0
CATEGORIES=	devel sysutils

HOMEPAGE=	http://tkdiff.sourceforge.net/

MAINTAINER=	Vlad Glagolev <stealth@sourcemage.org> 

# GPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tkdiff/}

MODULES=	x11/tk
RUN_DEPENDS=	${MODTK_RUN_DEPENDS}

NO_BUILD=	Yes
NO_REGRESS=	Yes

do-configure:
	@${MODTCL_WISH_ADJ} ${WRKSRC}/tkdiff

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tkdiff ${PREFIX}/bin

.include <bsd.port.mk>
