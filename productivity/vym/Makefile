# $OpenBSD$

COMMENT=	generate and manipulate maps of your thoughts

DISTNAME=	vym-2.2.2
CATEGORIES=	productivity x11

HOMEPAGE=	http://www.insilmaril.de/vym/

# modified GPLv2
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=vym/}
EXTRACT_SUFX=	.tar.bz2

WANTLIB += ICE QtDBus QtGui QtNetwork QtSvg QtXml SM X11 Xext
WANTLIB += Xi Xinerama Xrender c fontconfig freetype m pthread
WANTLIB += stdc++

MODULES=	devel/gettext \
		x11/qt4

RUN_DEPENDS=	archivers/zip \
		archivers/unzip \
		textproc/libxslt

PORTHOME=	${WRKDIR}
NO_REGRESS=	Yes

SHARE_DIRS=	flags flags/freemind icons scripts styles

pre-configure:
	${SUBST_CMD} ${WRKSRC}/mainwindow.cpp ${WRKSRC}/main.cpp

do-configure:
	@echo "QMAKE_CXXFLAGS_RELEASE=${CXXFLAGS}" \
		>> ${WRKSRC}/vym.pro
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${LOCALBASE}/bin/qmake4 DOCDIR="${PREFIX}/share/doc/vym" vym.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vym ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/vym/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/vym/
	${INSTALL_DATA} ${WRKSRC}/doc/*.pdf ${PREFIX}/share/doc/vym/
	${INSTALL_DATA} ${WRKSRC}/demos/* ${PREFIX}/share/examples/vym/
.for i in ${SHARE_DIRS}
	${INSTALL_DATA_DIR} ${PREFIX}/share/vym/${i}
	find ${WRKSRC}/${i}/ -type f -exec \
		${INSTALL_DATA} {} ${PREFIX}/share/vym/${i} \;
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/vym.1.gz ${PREFIX}/man/man1
	gunzip ${PREFIX}/man/man1/vym.1.gz

.include <bsd.port.mk>
