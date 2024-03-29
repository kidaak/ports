# $OpenBSD$

COMMENT=	simulation of a true AI

MODPY_EGG_VERSION= 0.30
MUSIC_V=	006
V=		${MODPY_EGG_VERSION}b
DISTNAME=	singularity-${V}-src
PKGNAME=	singularity-${V}
REVISION =	1

CATEGORIES=	games

DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		endgame-singularity-music-${MUSIC_V}.zip

HOMEPAGE=	http://emhsoft.com/singularity/

# GPLv2
# music under CC Attribution-ShareAlike 3.0 Unported
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=	http://endgame-singularity.googlecode.com/files/

WRKDIST=	${WRKDIR}/singularity-${V}
NO_REGRESS=	Yes

MODULES=	lang/python
RUN_DEPENDS=	devel/pygame \
		math/py-numpy

NO_BUILD=	Yes

do-install:
	find ${WRKSRC} -name \*.py -exec \
		perl -pi -e 's,/usr/bin/env python,${MODPY_BIN},g' {} \;
	${INSTALL_DATA_DIR} ${PREFIX}/share/singularity/music
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/singularity
	cp -R ${WRKSRC}/code/ ${PREFIX}/share/singularity/
	cp -R ${WRKSRC}/data/ ${PREFIX}/share/singularity/
	mv ${PREFIX}/share/singularity/data/*.html \
		${PREFIX}/share/doc/singularity/
	${INSTALL_DATA} ${WRKDIR}/endgame-singularity-music-${MUSIC_V}/music/*.ogg \
		${PREFIX}/share/singularity/music
	${INSTALL_DATA} ${WRKSRC}/singularity.py ${PREFIX}/share/singularity/
	${SUBST_CMD} -c ${FILESDIR}/singularity ${PREFIX}/bin/singularity
	chown -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/singularity
	chown -R ${BINOWN}:${BINGRP} ${PREFIX}/bin/singularity
	chmod a+x ${PREFIX}/bin/singularity

.include <bsd.port.mk>
