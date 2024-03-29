# $OpenBSD$

REVISION-main =		0

COMMENT-main =		network monitoring system (improved fork of Nagios)
COMMENT-cgi =		cgi scripts for Icinga (classic Nagios-style UI)
COMMENT-ido =		store Icinga configuration and events in a database

DISTNAME =		icinga-$V
PKGNAME-main =		icinga-$V
PKGNAME-cgi =		icinga-cgi-$V
PKGNAME-ido =		icinga-idoutils-$V

WANTLIB =		c crypto m pthread ssl

MULTI_PACKAGES =	-main -cgi -ido
PREFIX-cgi =		/var/www
SUBST_VARS +=		PREFIX-cgi

RUN_DEPENDS =		${BASE_PKGPATH},-main

WANTLIB-main =		${WANTLIB} ltdl>=4 perl util
RUN_DEPENDS-main =	net/nagios/plugins
LIB_DEPENDS-main =	devel/libtool,-ltdl

WANTLIB-ido =		${WANTLIB} dbi
LIB_DEPENDS-ido =	databases/libdbi
RUN_DEPENDS-ido =	${BASE_PKGPATH},-main \
			libdbi-drivers-mysql-*|libdbi-drivers-pgsql-*:databases/libdbi-drivers,-pgsql

MODULES =		lang/php

# the cgi binaries are linked -static to simplify use in chroot,
# but listed as dependency anyway to help pkg_add -u find updates.
# these will show as "extra".
WANTLIB-cgi =		c m gd jpeg png z
LIB_DEPENDS-cgi =	graphics/gd
RUN_DEPENDS-cgi =

FAKE_FLAGS =		CFGDIR=${TRUEPREFIX}/share/examples/icinga

LOCALSTATEDIR =		${BASELOCALSTATEDIR}/icinga
SYSCONFDIR =		${BASESYSCONFDIR}/icinga

CONFIGURE_STYLE =	gnu
CONFIGURE_ARGS += \
	--datarootdir=/var/www/icinga-cgi \
	--libexecdir=${PREFIX}/libexec/nagios \
	--sbindir=/var/www/cgi-bin/icinga \
	--with-command-group=www \
	--with-cgiurl=/cgi-bin/icinga \
	--with-checkresult-dir=/var/spool/icinga \
	--with-htmurl=/icinga \
	--with-httpd-conf=/var/www/conf/modules.sample \
	--with-icinga-group=_icinga \
	--with-icinga-user=_icinga \
	--with-lockfile=/var/run/icinga/icinga.pid \
	--with-log-dir=/var/log/icinga \
	--with-p1-file-dir=${PREFIX}/bin \
	--enable-embedded-perl \
	--enable-idoutils \
	--enable-ssl

CFLAGS +=	-fPIC \
		-I${LOCALBASE}/include \
		-L${X11BASE}/lib -L${LOCALBASE}/lib

CFGDIR =	${SYSCONFDIR}/icinga
MAKE_FLAGS =	CFGDIR=${CFGDIR} SYSCONFDIR=${CFGDIR}
INSTALL_TARGET = install-unstripped install-idoutils \
		install-config install-webconf

# perl tests work; C tests require --enable-libtap in configure and
# fixing up WRKSRC/tap/configure
REGRESS_TARGET = test
REGRESS_DEPENDS = devel/p5-IPC-Run3
# devel/p5-Test-Most

post-install:
	${INSTALL_DATA_DIR} ${WRKINST}${PREFIX-cgi}/conf/modules.sample
	${INSTALL_DATA_DIR} \
	    ${PREFIX}/share/examples/icinga/db/{mysql,pgsql,queries,scripts}
	cd ${WRKINST}${PREFIX-cgi}; \
	mv conf/modules.sample/icinga.conf \
	    conf/modules.sample/icinga-cgi.conf.dist; \
	chown -R ${SHAREOWN}:${SHAREGRP} icinga-cgi conf
	cd ${WRKSRC}/module/idoutils; \
	pax -rw db ${PREFIX}/share/examples/icinga/

.include <bsd.port.mk>
