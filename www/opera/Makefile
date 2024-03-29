# $OpenBSD$

ONLY_FOR_ARCHS=	i386
SHARED_ONLY=	Yes

COMMENT=	fast and customizable WWW browser

V=		10.11
OPERA_BUILD=	4791
DISTNAME=	opera-${V}.gcc4-shared-qt3.i386
PKGNAME=	opera-${V}
REVISION=	4
CATEGORIES=	www

MAINTAINER=	Antoine Jacoutot <ajacoutot@openbsd.org>

HOMEPAGE=	http://www.opera.com/

PERMIT_PACKAGE_CDROM=	Commercial software
PERMIT_PACKAGE_FTP=	Commercial software
PERMIT_DISTFILES_CDROM=	Commercial software
PERMIT_DISTFILES_FTP=	Commercial software

MASTER_SITES_OPERA=	ftp://ftp.opera.com/pub/opera/ \
			ftp://gd.tuwien.ac.at/infosys/browsers/opera/ \
			ftp://ftp.hu-berlin.de/pub/www/opera/ \
			ftp://sunsite.cnlab-switch.ch/mirror/opera/ \
			ftp://ftp.planetmirror.com/pub/opera/ \
			ftp://ftp.sunet.se/pub/www/clients/Opera/ \
			ftp://ftp.task.gda.pl/pub/opera/ \
			ftp://opera.mirror.stop.hu/opera/ \
			http://www.panix.com/opera/files/ \
			ftp://ftp.rge.com/pub/infosystems/opera/ \
			http://www.rge.com/pub/infosystems/opera/

MASTER_SITES=	${MASTER_SITES_OPERA:=linux/${V:S/.//}/final/en/i386/shared/}
EXTRACT_SUFX=	.tar.bz2

RUN_DEPENDS=	devel/desktop-file-utils \
		emulators/fedora/base \
		x11/gtk+2,-guic

USE_GROFF =	Yes
NO_BUILD=	Yes
NO_REGRESS=	Yes

WRKDIST=	${WRKDIR}/opera-$V-${OPERA_BUILD}.gcc4-shared-qt3.i386

do-install:
	cd ${WRKBUILD} && ./install.sh \
	    --DESTDIR=${DESTDIR} \
	    --docdir=${TRUEPREFIX}/share/doc/opera \
	    --exec_prefix=${TRUEPREFIX}/libexec \
	    --mandir=${TRUEPREFIX}/man \
	    --plugindir=${TRUEPREFIX}/lib/opera/plugins \
	    --sharedir=${TRUEPREFIX}/share/opera \
	    --wrapperdir=${TRUEPREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/opera
	${INSTALL_DATA} ${FILESDIR}/operaprefs_default.ini \
	    ${PREFIX}/share/examples/opera/operaprefs_default.ini
	${INSTALL_DATA} ${FILESDIR}/operaprefs_fixed.ini \
	    ${PREFIX}/share/examples/opera/operaprefs_fixed.ini
	${INSTALL_DATA_DIR} ${PREFIX}/share/icons
	cd ${WRKSRC}/usr/share/icons/; tar cf - * | tar xf - -C ${PREFIX}/share/icons/
	${INSTALL_DATA_DIR} ${PREFIX}/share/applications
	${SUBST_CMD} -c ${FILESDIR}/opera.desktop \
		${PREFIX}/share/applications/opera.desktop
	chown ${SHAREOWN}:${SHAREGRP} \
		${PREFIX}/share/applications/opera.desktop

.include <bsd.port.mk>
