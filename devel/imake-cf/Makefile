# $OpenBSD$

PKG_ARCH = 	*
COMMENT =  	config files for imake
CATEGORIES =	devel x11
DISTNAME = 	xorg-cf-files-1.0.4
PKGNAME = 	imake-cf-1.0.4
MASTER_SITES = 	http://ftp.x.org/pub/individual/util/

REVISION =	2

PERMIT_DISTFILES_CDROM = 	Yes
PERMIT_DISTFILES_FTP = 		Yes
PERMIT_PACKAGE_CDROM = 		Yes
PERMIT_PACKAGE_FTP = 		Yes

SUBST += 	-e 's|@prefix@|${X11BASE}|'
SUBST += 	-e 's|@FONTROOTDIR@|${X11BASE}/lib/X11/fonts|'
SUBST += 	-e 's|@ENCODINGSDIR|$${FONTROOTDIR}/encodings|'

NO_REGRESS=	Yes

do-build:
	sed ${SUBST} <${WRKSRC}/site.def.in >${WRKSRC}/site.def

XCONFDIR =	${PREFIX}/lib/X11/config

pre-configure:
	${SUBST_CMD} ${WRKSRC}/OpenBSD.cf

do-install:
	${INSTALL_DATA_DIR} ${XCONFDIR}
	for f in ${WRKSRC}/*.{cf,def,rules,tmpl}; do \
		${INSTALL_DATA} $$f ${XCONFDIR}; \
	done
	rm -f ${XCONFIGDIR}/Motif.rules
	rm -f ${XCONFIGDIR}/Motif.tmpl
	touch ${XCONFDIR}/host.def
	touch ${XCONFDIR}/date.def
	touch ${XCONFDIR}/version.def

.include <bsd.port.mk>
