# $OpenBSD$

PKG_ARCH=	*

COMMENT=	rubber stamps collection for Tux Paint

DISTNAME=	tuxpaint-stamps-2009.06.28
PKGNAME=	tuxpaint-stamps-20090628
CATEGORIES=	games graphics

HOMEPAGE=	http://www.tuxpaint.org/

MAINTAINER=	Antoine Jacoutot <ajacoutot@openbsd.org>

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tuxpaint/}

NO_BUILD=	Yes
NO_REGRESS=	Yes

RUN_DEPENDS=	games/tuxpaint

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/tuxpaint/stamps/
	cp -R ${WRKSRC}/stamps/* ${PREFIX}/share/tuxpaint/stamps/
	@find ${PREFIX}/share/tuxpaint/stamps/ -type f ! -perm 644 -exec chmod 644 {} \;
	@chown -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/tuxpaint/stamps/

.include <bsd.port.mk>
