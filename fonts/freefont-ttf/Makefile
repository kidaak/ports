# $OpenBSD$

COMMENT=		free UCS outline fonts

V=			20100919
DISTNAME=		freefont-ttf-$V
REVISION=		0
CATEGORIES=		fonts x11

HOMEPAGE=		http://savannah.gnu.org/projects/freefont/

# GPLv2+
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=		${MASTER_SITE_SAVANNAH:=freefont/}

WRKDIST=		${WRKDIR}/freefont-$V
NO_BUILD=		Yes
PKG_ARCH=		*
NO_REGRESS=		Yes
FONTSDIR=		${PREFIX}/lib/X11/fonts/freefont

do-install:
	${INSTALL_DATA_DIR} ${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${FONTSDIR}

.include <bsd.port.mk>
