# $OpenBSD$

COMMENT-gui =		enhanced TightVNC client GUI and wrappers
COMMENT-main =		enhanced TightVNC client

V =			1.0.29

DISTNAME =		ssvnc-$V.src
PKGNAME =		ssvnc-$V
EPOCH =			0
FULLPKGNAME-gui =	ssvnc-$V
FULLPKGNAME-main =	ssvnc-viewer-$V
REVISION-gui =		0

CATEGORIES =		net x11

HOMEPAGE =		http://www.karlrunge.com/x11vnc/ssvnc.html

MAINTAINER =		Stuart Henderson <sthen@openbsd.org>

# GPLv2
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

MASTER_SITES =	${MASTER_SITE_SOURCEFORGE:=ssvnc/}

MULTI_PACKAGES =-main -gui

MAKE_ENV =	CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" \
		NO_SHARED_LIBS=${NO_SHARED_LIBS}

WRKDIST =	${WRKDIR}/ssvnc-$V
USE_GROFF =	Yes

NO_REGRESS =	Yes

MODULES =	x11/tk

WANTLIB-main =		ICE SM X11 Xau Xaw Xdmcp Xext Xpm Xmu Xt c z jpeg>=62
LIB_DEPENDS-main =	graphics/jpeg

WANTLIB-gui =		c crypto ssl
RUN_DEPENDS-gui =	devel/desktop-file-utils \
			net/avahi \
			net/ssvnc,-main \
			security/stunnel \
			${MODTK_RUN_DEPENDS}

CONFIGURE_STYLE =	imake noman
XMKMF =			xmkmf

VNCSRC =		${WRKSRC}/vnc_unixsrc/
VNCLIB =		${PREFIX}/lib/ssvnc/

pre-configure:
	${SUBST_CMD} ${WRKSRC}/scripts/ssvnc

do-configure:
	cd ${VNCSRC}/libvncauth; ${XMKMF}
	cd ${VNCSRC}/vncviewer; ${XMKMF}

do-build:
	cd ${VNCSRC}/libvncauth; ${SETENV} ${MAKE_ENV} ${MAKE}
	cd ${VNCSRC}/vncviewer; ${SETENV} ${MAKE_ENV} ${MAKE}
	cd ${WRKSRC}/vncstorepw; ${SETENV} ${MAKE_ENV} ${MAKE}

do-install:
	${INSTALL_PROGRAM_DIR} ${VNCLIB}
	cd ${WRKSRC}/scripts; tar cf - * | tar xf - -C ${VNCLIB}
	${INSTALL_MAN} ${WRKSRC}/man/man1/ssvnc.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/man1/ssvncviewer.1 ${PREFIX}/man/man1/vncviewer.1
	${INSTALL_DATA_DIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/ssvnc.desktop ${PREFIX}/share/applications
	${INSTALL_PROGRAM} ${VNCSRC}/vncviewer/vncviewer ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/vncstorepw/vncstorepw ${VNCLIB}
	${INSTALL_PROGRAM} ${WRKSRC}/vncstorepw/ultravnc_dsm_helper ${VNCLIB}
.for i in vncstorepw/lim_accept.so vncstorepw/unwrap.so
	if test -r ${WRKSRC}/$i; then ${INSTALL_DATA} ${WRKSRC}/$i ${VNCLIB}; fi
.endfor
.for i in ssvnc tsvnc sshvnc
	${WRKSRC}/wr_tool ${PREFIX}/bin/$i ${TRUEPREFIX}/lib/ssvnc/$i
.endfor

.include <bsd.port.mk>
