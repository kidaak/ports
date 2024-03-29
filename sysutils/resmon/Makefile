# $OpenBSD$

COMMENT-main =		system monitoring tool
COMMENT-nagios =	nagios plugin for resmon

V =			20090802
DISTNAME =		resmon-$V
PKGNAME-main =		${DISTNAME}
PKGNAME-nagios =	nagios-plugins-resmon-$V
CATEGORIES =		sysutils
HOMEPAGE =		http://labs.omniti.com/trac/resmon

MAINTAINER =		Jason Dixon <jdixon@openbsd.org>

MULTI_PACKAGES =	-main -nagios

# BSD
PERMIT_PACKAGE_CDROM =		Yes
PERMIT_PACKAGE_FTP =		Yes
PERMIT_DISTFILES_CDROM =	Yes
PERMIT_DISTFILES_FTP =		Yes

MASTER_SITES =	http://www.dixongroup.net/
NO_BUILD =	Yes
NO_REGRESS =	Yes
PKG_ARCH =	*

RUN_DEPENDS-nagios =	net/nagios/plugins,-main

INSTDIR =	${PREFIX}/libdata/perl5/site_perl
RESMONCONF =	${SYSCONFDIR}/resmon
RESMONSTATE =	/var/resmon
SUBST_VARS =	INSTDIR RESMONCONF RESMONSTATE

DOCSDIR =	${PREFIX}/share/doc/resmon
EXAMPLESDIR =	${PREFIX}/share/examples/resmon


pre-configure:
	${SUBST_CMD} ${WRKDIST}/resmon ${WRKDIST}/resmon.conf.sample

do-install:
	@find ${WRKDIST} -name \*.bak -or -name \*.orig | xargs rm
	${INSTALL_SCRIPT} ${WRKSRC}/resmon ${PREFIX}/sbin
	@cp -R ${WRKDIST}/lib/Resmon ${INSTDIR}
	${INSTALL_DATA_DIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCSDIR}
	${INSTALL_DATA_DIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/resmon.conf.sample ${EXAMPLESDIR}
	${INSTALL_SCRIPT_DIR} ${PREFIX}/libexec/nagios
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/check_resmon_xml_part \
		${PREFIX}/libexec/nagios

.include <bsd.port.mk>
