# $OpenBSD$

COMMENT =		enhanced Tk console

DISTNAME =		tkcon-2.5
REVISION =		0
CATEGORIES =		x11 x11/tk
HOMEPAGE =		http://sourceforge.net/projects/tkcon/
MAINTAINER =		Stuart Cassoff <stwo@users.sourceforge.net>

# BSD-like
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

MODULES =		x11/tk
MASTER_SITES =		${MASTER_SITE_SOURCEFORGE:=tkcon/}
BUILD_DEPENDS =		devel/tcllib>=1.11.1
RUN_DEPENDS =		${MODTK_RUN_DEPENDS}
USE_GROFF =		Yes
NO_BUILD =		Yes
NO_REGRESS =		Yes
PKG_ARCH =		*

DOCDIR =		${PREFIX}/share/doc/tkcon
MODDIR =		${DESTDIR}${MODTCL_MODDIR}/${MODTCL_VERSION}

do-configure:
	@${MODTCL_WISH_ADJ} ${WRKSRC}/tkcon.tcl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tkcon.tcl ${PREFIX}/bin/tkcon
	# Enable loading as a 'Tcl Module' via [package require]
	${INSTALL_DATA_DIR} ${MODDIR}
	ln -sf ${TRUEPREFIX}/bin/tkcon ${MODDIR}/tkcon-2.5.tm
	${INSTALL_DATA_DIR} ${DOCDIR}
.for i in README.txt index.html
	${INSTALL_DATA} ${WRKSRC}/$i ${DOCDIR}/$i
.endfor
	${INSTALL_DATA_DIR} ${DOCDIR}/docs
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCDIR}/docs/
	rm -f ${DOCDIR}/docs/*.man ${DOCDIR}/docs/*.orig
.for s in 1 5 n
	for i in ${WRKSRC}/docs/*.$s.man ; do \
		ofn=`basename $$i | sed -e 's/\..*$$/.$s/'` ; \
		dtplite -o ${PREFIX}/man/man$s/$$ofn nroff $$i ; \
	done
.endfor

.include <bsd.port.mk>
