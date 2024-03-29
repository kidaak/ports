# $OpenBSD$

COMMENT =	PostgreSQL log analyzer

DISTNAME =	pgfouine-1.2
CATEGORIES =	databases

REVISION =	3

HOMEPAGE =	http://pgfouine.projects.postgresql.org/

MAINTAINER =	Pierre-Emmanuel Andre <pea@openbsd.org>

# GPLv2
PERMIT_PACKAGE_FTP =	Yes
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_DISTFILES_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes

MASTER_SITES =	http://pgfoundry.org/frs/download.php/2575/ \
		http://pgfouine.projects.postgresql.org/releases/

NO_BUILD =	Yes
NO_REGRESS =	Yes
PKG_ARCH =	*

MODULES =	lang/php
RUN_DEPENDS =	lang/php/${MODPHP_VERSION},-gd

pre-configure:
	@perl -pi -e 's,/usr/bin/php,${MODPHP_BIN},g;' \
		-e 's,!!PREFIX!!,${PREFIX},g' \
		 ${WRKSRC}/pgfouine.php ${WRKSRC}/pgfouine_vacuum.php
	@find ${WRKSRC} -type d -name CVS | xargs rm -fr

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pgfouine.php ${PREFIX}/bin/pgfouine
	${INSTALL_SCRIPT} ${WRKSRC}/pgfouine_vacuum.php ${PREFIX}/bin/pgfouine_vacuum
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pgfouine
	${INSTALL_DATA_DIR} ${PREFIX}/share/pgfouine/include
	${INSTALL_DATA} ${WRKSRC}/version.php ${PREFIX}/share/pgfouine/
	@cd ${WRKSRC}/include && \
		find . -type d -exec ${INSTALL_DATA_DIR} ${PREFIX}/share/pgfouine/include/{} \;
	@cd ${WRKSRC}/include && \
		find . ! -type d -exec ${INSTALL_DATA} {} ${PREFIX}/share/pgfouine/include/{} \;
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${PREFIX}/share/doc/pgfouine/
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${PREFIX}/share/doc/pgfouine/
	${INSTALL_DATA} ${WRKSRC}/THANKS ${PREFIX}/share/doc/pgfouine/
	${INSTALL_DATA} ${WRKSRC}/rpm-specific/sources/pgfouine-tutorial.txt \
		${PREFIX}/share/doc/pgfouine/pgfouine-tutorial.txt

.include <bsd.port.mk>
