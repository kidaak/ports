# $OpenBSD$

COMMENT=	suite of educational games for young children

DISTNAME=	childsplay-0.85.1
REVISION =	6
EXTRACT_SUFX=	.tgz

CATEGORIES=	games education

HOMEPAGE=	http://childsplay.sourceforge.net/

MAINTAINER=	Antoine Jacoutot <ajacoutot@openbsd.org>

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=childsplay/}

MODULES=	lang/python
RUN_DEPENDS=	devel/pygame>=1.7

PKG_ARCH=	*
NO_BUILD=	Yes
NO_REGRESS=	Yes
USE_GROFF =	Yes

do-install:
	perl -pi -e 's,!!LOCALBASE!!,${LOCALBASE},g;' \
		-e 's,!!DESTDIR!!,${DESTDIR},g;' \
		-e 's,!!MODPY_BIN!!,${MODPY_BIN},g' \
		${WRKSRC}/INSTALL.sh
	perl -pi -e 's,/usr/local/lib/games,${LOCALBASE}/share,g' \
		${WRKSRC}/childsplay.sh
	perl -pi -e 's,/usr/bin/env python,${MODPY_BIN},g' \
		${WRKSRC}/childsplay.py ${WRKSRC}/letters-trans.py \
		${WRKSRC}/pyassetmlcreator.py
	cd ${WRKSRC} && /bin/sh INSTALL.sh
	${INSTALL_DATA} ${WRKSRC}/README-MEMORY \
		${PREFIX}/share/doc/childsplay

.include <bsd.port.mk>
