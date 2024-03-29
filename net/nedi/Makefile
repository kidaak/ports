# $OpenBSD$

COMMENT =			network discovery tool

DISTNAME =			nedi-bsd-1.0.7
PKGNAME =			nedi-1.0.7
REVISION =			1
EXTRACT_SUFX =			.tgz
CATEGORIES =			net

HOMEPAGE =			http://www.nedi.ch/
MAINTAINER =			Marcus Glocker <marcus@nazgul.ch>

# GPLv3+
PERMIT_PACKAGE_CDROM =		Yes
PERMIT_PACKAGE_FTP =		Yes
PERMIT_DISTFILES_CDROM =	Yes
PERMIT_DISTFILES_FTP =		Yes

MASTER_SITES =			${HOMEPAGE}/pub/

MODULES =			lang/php

RUN_DEPENDS =			databases/mysql,-server \
				databases/p5-DBD-mysql \
				databases/p5-DBI \
				devel/p5-Algorithm-Diff \
				devel/p5-IO-Tty \
				lang/php/${MODPHP_VERSION},-bz2 \
				lang/php/${MODPHP_VERSION},-gd \
				lang/php/${MODPHP_VERSION},-mysql \
				lang/php/${MODPHP_VERSION},-snmp \
				net/p5-Net-SNMP \
				net/p5-Net-Telnet \
				net/rrdtool,-perl \
				www/p5-LWP-UserAgent-Determined \
				www/p5-PHP-Session

NO_BUILD =			Yes
PKG_ARCH =			*

PREFIX =			/var/www
INSTDIR =			${PREFIX}/nedi

post-extract:
	cd ${WRKSRC}; perl -pi -e 's/\r/\n/g' contrib/* html/log/msg.txt

pre-configure:
	cd ${WRKSRC}; ${SUBST_CMD} inc/crontab html/log/msg.txt nedi.conf

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/nedi
	cd ${WRKSRC} && cp -rp * ${PREFIX}/nedi
	chown -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/nedi
	find ${PREFIX}/nedi -type f -name '*.orig' -exec rm {} +
	cd ${PREFIX}/nedi; chmod +x *.pl contrib/*.pl contrib/*.sh
.for i in nedi.conf seedlist html/log inc/crontab
	cd ${PREFIX}/nedi; mv $i $i.dist
.endfor

.include <bsd.port.mk>
