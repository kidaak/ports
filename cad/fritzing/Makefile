# $OpenBSD$

COMMENT=	interactive electronics designing software

V=		0.7.7
DISTNAME=	fritzing-$Vb.source
PKGNAME=	fritzing-$V
CATEGORIES=	cad

HOMEPAGE=	http://fritzing.org/

# Code: GPLv3+
# Rest: CreativeCommons:BY-SA
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

MASTER_SITES=	${HOMEPAGE}download/$Vb/source-tarball/
EXTRACT_SUFX=	.tar.bz2

WANTLIB += QtGui QtNetwork QtSql QtSvg QtXml c m pthread stdc++ z
WANTLIB += ICE SM X11 Xext Xi Xinerama Xrender fontconfig freetype

MODULES=        x11/qt4
NO_REGRESS=	Yes

BUILD_DEPENDS=	devel/boost
RUN_DEPENDS=	devel/desktop-file-utils

# XXX: Sigh...words fail me.
WRKDIST=	${WRKDIR}/fritzing-0.7.6b.source

pre-configure:
	${SUBST_CMD} ${WRKSRC}/phoenix.pro ${WRKSRC}/src/fapplication.cpp
	cd ${WRKSRC} && rm -r src/lib/boost_1_43_0

# -DLINUX_32 gets added to CFLAGS, though it's only used to figure out
# if there is a newer version of the 32-bit Linux binary on the upstream
# webpage. So it's safe to set it on all arches (for now).
do-configure:
	cd ${WRKSRC} && \
		${LOCALBASE}/bin/qmake4 -o Makefile phoenix.pro

do-install:
	${SUBST_CMD} -o ${BINOWN} -g ${BINGRP} -c ${FILESDIR}/fritzing.sh \
		${PREFIX}/bin/fritzing
	chmod ${BINMODE} ${PREFIX}/bin/fritzing
	${INSTALL_PROGRAM} ${WRKSRC}/Fritzing ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/fritzing/
	cd ${WRKSRC}; tar cf - bins parts resources sketches tools translations | \
		tar xf - -C ${PREFIX}/share/fritzing/
	${INSTALL_DATA_DIR} ${PREFIX}/share/applications/
	${SUBST_CMD} -o ${SHAREOWN} -g ${SHAREGRP} -c ${FILESDIR}/fritzing.desktop \
		${PREFIX}/share/applications/fritzing.desktop

.include <bsd.port.mk>
