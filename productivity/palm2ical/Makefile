# $OpenBSD$

COMMENT =	Palm Databook/Calendar export to iCalendar

DISTNAME =	palm2ical-1.8
REVISION =	1
CATEGORIES =	productivity textproc

HOMEPAGE =	http://hepunx.rl.ac.uk/~adye/software/palm/palm2ical/
MASTER_SITES =	${HOMEPAGE}

EXTRACT_SUFX =	.zip

# Artistic
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

WRKDIST =	${WRKDIR}
NO_BUILD =	Yes
PKG_ARCH =	*

RUN_DEPENDS =	databases/p5-Palm \
		devel/p5-Data-ICal \
		devel/p5-DateTime-Format-ICal \
		devel/p5-Data-ICal-TimeZone

NO_REGRESS =	Yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/fixpdb ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/palm2ical ${PREFIX}/bin/

.include <bsd.port.mk>
