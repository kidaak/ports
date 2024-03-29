# $OpenBSD$

COMMENT =		official Last.fm client

VER =			1.5.4.27091
DISTNAME =		lastfm-${VER}+dfsg
PKGNAME =		last.fm-${VER}
REVISION =		7

SHARED_ONLY =		Yes

SHARED_LIBS =		Moose 0.0 \
			LastFmTools 0.0

CATEGORIES =		audio

MAINTAINER =		David Coppa <dcoppa@openbsd.org>

HOMEPAGE =		http://www.last.fm/

MASTER_SITES =		http://dev.gentoo.org/~hwoarang/distfiles/ \
			http://ftp.pardus.org.tr/pub/source/corporate2/

# GPLv2
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

WANTLIB =		ICE QtGui>=8 QtNetwork>=7 QtSql>=7 \
			QtXml>=7 SM X11 Xext Xi Xinerama Xrender \
			c fontconfig freetype gpod>=700 m mad \
			portaudio pthread sndio stdc++ z

MODULES =		x11/qt4

LIB_DEPENDS =		audio/libgpod \
			audio/libmad \
			audio/portaudio-svn \
			${MODQT4_LIB_DEPENDS}>=4.7.2

RUN_DEPENDS =		devel/desktop-file-utils \
			devel/xdg-utils

NO_REGRESS =		Yes

LASTFM_LIBDIR = ${PREFIX}/lib/last.fm
LASTFM_DATADIR = ${PREFIX}/share/last.fm
MOOSELIB = ${WRKBUILD}/bin/libMoose.so.${LIBMoose_VERSION}
TOOLSLIB = ${WRKBUILD}/bin/libLastFmTools.so.${LIBLastFmTools_VERSION}

pre-patch:
	cd ${WRKSRC}; perl -pi -e "s/\r$$//"\
	 `find . -type f -name *.h -or -name *.cpp -or -name '*.pro*'`

pre-configure:
	${SUBST_CMD} \
	${WRKSRC}/src/libMoose/libMoose.pro \
	${WRKSRC}/src/libMoose/MooseCommon.cpp \
	${WRKSRC}/src/libUnicorn/libUnicorn.pro \
	${WRKSRC}/src/mediadevices/ipod/ipod.pro \
	${WRKSRC}/src/output/portAudio/portAudio.pro \
	${WRKSRC}/src/src.pro \
	${WRKSRC}/src/transcode/mad/mad.pro

do-configure:
	perl -pi -e "s/!!CXXFLAGS!!/${CXXFLAGS}/" \
		${WRKSRC}/src/libUnicorn/unicorn.pro.inc
	cd ${WRKDIST} && ${LOCALBASE}/bin/qmake4 -config release

do-install:
	${INSTALL_PROGRAM} ${WRKBUILD}/bin/last.fm ${PREFIX}/bin/last.fm
	${INSTALL_DATA} ${MOOSELIB} ${PREFIX}/lib/
	${INSTALL_DATA} ${TOOLSLIB} ${PREFIX}/lib/
	${INSTALL_DATA_DIR} ${LASTFM_LIBDIR}/extensions
	${INSTALL_DATA_DIR} ${LASTFM_LIBDIR}/services
	${INSTALL_DATA} ${WRKBUILD}/bin/services/*.so \
		${LASTFM_LIBDIR}/services/
	${INSTALL_DATA_DIR} ${LASTFM_DATADIR}
	${INSTALL_DATA_DIR} ${LASTFM_DATADIR}/buttons
	${INSTALL_DATA_DIR} ${LASTFM_DATADIR}/icons
	${INSTALL_DATA_DIR} ${LASTFM_DATADIR}/i18n
	${INSTALL_DATA} ${WRKBUILD}/bin/data/*.{gif,mng,png} \
		${LASTFM_DATADIR}/
	${INSTALL_DATA} ${WRKBUILD}/bin/data/buttons/*.png \
		${LASTFM_DATADIR}/buttons/
	${INSTALL_DATA} ${WRKBUILD}/bin/data/icons/*.png \
		${LASTFM_DATADIR}/icons/
	${INSTALL_DATA} ${FILESDIR}/*.png ${LASTFM_DATADIR}/icons/
	cd ${WRKBUILD}/i18n && ${LOCALBASE}/bin/lrelease4 *.ts
	${INSTALL_DATA} ${WRKBUILD}/i18n/*.qm \
		${LASTFM_DATADIR}/i18n/
	${INSTALL_DATA_DIR} ${PREFIX}/share/applications
	${SUBST_CMD} -o ${SHAREOWN} -g ${SHAREGRP} \
		-c ${FILESDIR}/lastfm.desktop \
		${PREFIX}/share/applications/lastfm.desktop

.include <bsd.port.mk>
