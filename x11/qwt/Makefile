# $OpenBSD$

SHARED_ONLY =		Yes

COMMENT =		Qt Widgets for Technical Applications
DISTNAME =		qwt-5.2.1
SHARED_LIBS =		qwt 6.0
CATEGORIES =		x11
EXTRACT_SUFX =		.tar.bz2
REVISION =		1

HOMEPAGE =		http://qwt.sourceforge.net/
MASTER_SITES =		${MASTER_SITE_SOURCEFORGE:=qwt/}

# Qwt License, Version 1.0
# http://qwt.sourceforge.net/qwtlicense.html
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

MODULES =		x11/qt4
NO_REGRESS =		Yes
USE_GMAKE =		Yes

MAKE_FLAGS =		LIBqwt_VERSION=${LIBqwt_VERSION}

WANTLIB +=		m stdc++ QtDesigner QtGui QtScript QtXml

# svgmap example not included to prevent the need of svg dependencies
EXAMPLES =	bode realtime_plot cpuplot dials radio event_filter \
		data_plot sliders histogram spectrogram sysinfo \
		curvdemo1 curvdemo2 simple_plot

SUBST_VARS =	WRKINST EXAMPLES

pre-configure:
	@${SUBST_CMD} ${WRKSRC}/qwtconfig.pri ${WRKSRC}/designer/designer.pro \
		${WRKSRC}/examples/examples.pri

do-configure:
	@cd ${WRKSRC} && qmake4

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/man/man3/* ${PREFIX}/man/man3/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/qwt
	${SUBST_CMD} -c -o ${SHAREOWN} -g ${SHAREGRP} \
		${FILESDIR}/Makefile.examples \
		${PREFIX}/share/examples/qwt/Makefile
	${INSTALL_DATA} ${WRKSRC}/examples/examples.pri \
		${PREFIX}/share/examples/qwt/

.for i in ${EXAMPLES}
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/qwt/${i}
	${INSTALL_DATA} ${WRKSRC}/examples/${i}/* \
		${PREFIX}/share/examples/qwt/${i}/
.endfor

.include <bsd.port.mk>
