# $OpenBSD$

COMMENT =	Audit Record Generation and Utilization System

DISTNAME =	argus-3.0.6.1
CATEGORIES =	net

HOMEPAGE =	http://qosient.com/argus/
MASTER_SITES =	http://qosient.com/argus/src/

MAINTAINER =	Steven Mestdagh <steven@openbsd.org>

# GPLv2
PERMIT_PACKAGE_CDROM =		Yes
PERMIT_PACKAGE_FTP =		Yes
PERMIT_DISTFILES_CDROM =	Yes
PERMIT_DISTFILES_FTP =		Yes

WANTLIB =	c m pcap z

USE_GROFF =	Yes
NO_REGRESS =	Yes

CONFIGURE_STYLE = 	gnu
MODGNU_CONFIG_GUESS_DIRS = ${WRKSRC}/config
BUILD_DEPENDS =		devel/bison

MAKE_FLAGS =		CCOPT="${CFLAGS}"
INSTALL_TARGET =	install

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/argus/
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/argus/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/argus/events
	find ${WRKSRC}/support -type f -name '*.orig' -exec rm -f {} \;
	cd ${WRKSRC}/support && tar cf - . | \
		tar -C ${PREFIX}/share/examples/argus/ -xf - 
	cd ${PREFIX}/bin && mv argus-snmp argus-lsof argus-vmstat \
		${PREFIX}/share/examples/argus/events

.include <bsd.port.mk>
