# $OpenBSD$

# This port currently only works with archs supporting dynamic loading
# and has Apache that supports DSO's.
NOT_FOR_ARCHS=		${NO_SHARED_ARCHS}

COMMENT-main=		server-side HTML-embedded scripting language
COMMENT-fastcgi=	stand-alone FastCGI version of PHP

PKGNAME-main?=		php-${V}
PKGNAME-fastcgi?=	php-fastcgi-${V}

DISTFILES=		php-${V}.tar.gz

DISTNAME?=		php-${V}
CATEGORIES=		lang www

MAINTAINER=		Robert Nagy <robert@openbsd.org>
HOMEPAGE=		http://www.php.net/

SUHOSIN_V=		0.9.33
SUHOSIN_PHPV?=		${V}

MASTER_SITES=		http://se.php.net/distributions/ \
			http://us.php.net/distributions/ \
			http://no.php.net/distributions/ \
			http://uk.php.net/distributions/
MASTER_SITES0=		http://download.suhosin.org/ \
			http://blade2k.humppa.hu/ \
			${_MASTER_SITE_FREEBSD}

# UPGRADERS: please read BOTH the PHP and Zend licenses
# and make sure they are safe before an upgrade
PERMIT_PACKAGE_CDROM=   Yes
PERMIT_PACKAGE_FTP=     Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=   Yes

SHARED_ONLY=		Yes

MODPHP_CONFIG_PATH=	/var/www/conf

# where the main php module is stored (outside the chroot)
APACHE_MODULE_SUBDIR=	lib/php-${PV}
APACHE_MODULE_DIR=	${LOCALBASE}/${APACHE_MODULE_SUBDIR}

# where the PEAR and extension modules are (inside the chroot)
CHROOT_DIR?=		/var/www
MODULES_SUBDIR=		lib/php-${PV}/modules
MODULES_DIR=		${LOCALBASE}/${MODULES_SUBDIR}

FLAVORS=		ap2 no_suhosin
FLAVOR?=

USE_GROFF=		Yes
PATCHORIG=		.orig.port
CONFIGURE_STYLE=	autoconf
AUTOCONF_VERSION=	2.13
CONFIGURE_ENV=          CFLAGS="${CFLAGS} -I${LOCALBASE}/include -pthread" \
                        LDFLAGS="-L${LOCALBASE}/lib -pthread" \
			EXTENSION_DIR=${MODULES_DIR} lt_cv_path_SED=/usr/bin/sed
MAKE_ENV=               ${CONFIGURE_ENV}

CONFIGURE_ARGS+=	--enable-shared \
			--disable-static \
			--disable-rpath \
			--with-config-file-path=${SYSCONFDIR} \
			--enable-inline-optimization \
			--with-pic \
			--with-pear=${LOCALBASE}/share/php-${PV} \
			--with-config-file-scan-dir=${SYSCONFDIR}/php-${PV} \
			--program-suffix=-${PV} \
			--with-pdo-sqlite \
			--enable-sqlite-utf8

.if ${FLAVOR:L:Map2}
CONFIGURE_ARGS+=	--with-apxs2=${LOCALBASE}/sbin/apxs2
BUILD_DEPENDS=		www/apache-httpd
.else
CONFIGURE_ARGS+=	--with-apxs=/usr/sbin/apxs
.endif

# default included extensions
CONFIGURE_ARGS+= 	--with-openssl \
			--with-zlib \
			--enable-xml \
			--enable-wddx \
			--enable-cli \
			--with-iconv=${LOCALBASE} \
			--with-gettext=${LOCALBASE} \
			--enable-bcmath \
			--enable-session \
			--enable-calendar \
			--enable-ctype \
			--enable-ftp \
			--with-pcre-regex \
			--enable-sockets \
			--enable-sysvmsg \
			--enable-sysvsem \
			--enable-sysvshm \
			--enable-mbstring \
			--enable-exif \
			--enable-zend-multibyte \
			--enable-fastcgi

REGRESS_TARGET=		test
REGRESS_FLAGS=		NO_INTERACTION=1

MULTI_PACKAGES+=	-main -fastcgi

#
# Loadable php extensions by name that are included in all versions
#

# bz2
MULTI_PACKAGES+=	-bz2
COMMENT-bz2=		bzip2 compression extensions for php5
CONFIGURE_ARGS+=	--with-bz2=shared,${LOCALBASE}
LIB_DEPENDS-bz2=	archivers/bzip2
WANTLIB-bz2=		bz2>=10 c pthread

# curl
MULTI_PACKAGES+=	-curl
COMMENT-curl=		curl URL library extensions for php5
CONFIGURE_ARGS+=	--with-curl=shared,${LOCALBASE}
LIB_DEPENDS-curl=	net/curl
WANTLIB-curl=		c pthread crypto idn ssl z curl>=2 ${MODGETTEXT_WANTLIB}

# dba
MULTI_PACKAGES+=	-dba
COMMENT-dba=		dba GDBM access extensions for php5
CONFIGURE_ARGS+=	--enable-dba=shared --with-gdbm=${LOCALBASE}
LIB_DEPENDS-dba=	databases/gdbm
WANTLIB-dba=		c gdbm>=2 pthread

# gd
MULTI_PACKAGES+=	-gd
COMMENT-gd=		image manipulation extensions for php5
LIB_DEPENDS-gd=		graphics/jpeg \
			graphics/png \
			devel/t1lib
WANTLIB-gd=		z jpeg>=62 png>=3 t1>=5 c pthread X11 Xpm freetype
CONFIGURE_ENV+=		CPPFLAGS="-I${LOCALBASE}/include/libpng"
CONFIGURE_ARGS+=	--with-gd=shared \
			--with-jpeg-dir=${LOCALBASE} \
			--with-png-dir=${LOCALBASE} \
			--with-zlib-dir=/usr \
			--with-t1lib=${LOCALBASE} \
			--with-freetype-dir=${X11BASE} \
			--with-xpm-dir=${X11BASE}

# gmp
MULTI_PACKAGES+=	-gmp
COMMENT-gmp=		gmp math library support for php5
CONFIGURE_ARGS+=	--with-gmp=shared,${LOCALBASE}
LIB_DEPENDS-gmp=	devel/gmp
WANTLIB-gmp=		c gmp>=4 pthread

# imap
MULTI_PACKAGES+=	-imap
COMMENT-imap=		imap, pop3 and nntp extensions for php5
CONFIGURE_ARGS+=	--with-imap=shared,${LOCALBASE} \
			--with-kerberos=/usr --with-imap-ssl
LIB_DEPENDS-imap=	mail/re-alpine,-c-client
WANTLIB-imap=		c pthread crypto gssapi krb5 ssl c-client>=5

# ldap
MULTI_PACKAGES+=	-ldap
COMMENT-ldap=		ldap protocol extensions for php5
CONFIGURE_ARGS+=	--with-ldap=shared,${LOCALBASE}
LIB_DEPENDS-ldap=	databases/openldap
WANTLIB-ldap=		c pthread ldap>=2 lber

# mcrypt
MULTI_PACKAGES+=	-mcrypt
COMMENT-mcrypt=		mcrypt encryption/decryption extensions for php5
CONFIGURE_ARGS+=	--with-mcrypt=shared,${LOCALBASE}
LIB_DEPENDS-mcrypt=	security/libmcrypt devel/libtool,-ltdl
WANTLIB-mcrypt=		c mcrypt ltdl>=1 pthread

# mysql
MULTI_PACKAGES+=	-mysql
COMMENT-mysql=		mysql database access extensions for php5
CONFIGURE_ARGS+=	--with-mysql=shared,${LOCALBASE}
LIB_DEPENDS-mysql=	databases/mysql
WANTLIB-mysql=		c pthread lib/mysql/mysqlclient>=10

# mysqli
MULTI_PACKAGES+=	-mysqli
COMMENT-mysqli=		mysql database access extensions for php5
CONFIGURE_ARGS+=	--with-mysqli=shared,${LOCALBASE}/bin/mysql_config
LIB_DEPENDS-mysqli=	databases/mysql
WANTLIB-mysqli=		c crypto m pthread ssl z lib/mysql/mysqlclient>=10

# odbc
MULTI_PACKAGES+=	-odbc
COMMENT-odbc=		odbc database access extensions for php5
CONFIGURE_ARGS+=        --with-iodbc=shared,${LOCALBASE}
LIB_DEPENDS-odbc=	databases/iodbc
WANTLIB-odbc=		c iodbc>=2 pthread

# pdo-mysql
MULTI_PACKAGES+=	-pdo_mysql
COMMENT-pdo_mysql=	PDO mysql database access extensions for php5
CONFIGURE_ARGS+=	--with-pdo-mysql=shared,${LOCALBASE}
LIB_DEPENDS-pdo_mysql=	databases/mysql
WANTLIB-pdo_mysql=	c crypto m pthread ssl z lib/mysql/mysqlclient>=10

# pdo-pgsql
MULTI_PACKAGES+=	-pdo_pgsql
COMMENT-pdo_pgsql=	PDO database access extensions for php5
CONFIGURE_ARGS+=        --with-pdo-pgsql=shared,${LOCALBASE}
LIB_DEPENDS-pdo_pgsql=	databases/postgresql
WANTLIB-pdo_pgsql=	c pq>=2 pthread

# pgsql
MULTI_PACKAGES+=	-pgsql
COMMENT-pgsql=		pgsql database access extensions for php5
CONFIGURE_ARGS+=	--with-pgsql=shared,${LOCALBASE}
LIB_DEPENDS-pgsql=	databases/postgresql
WANTLIB-pgsql=		c pq>=2 pthread

# pspell
MULTI_PACKAGES+=	-pspell
COMMENT-pspell=		pspell library extensions for php5
CONFIGURE_ARGS+=	--with-pspell=shared,${LOCALBASE}
LIB_DEPENDS-pspell=	textproc/aspell/core
WANTLIB-pspell=		aspell>=16 c pspell>=16 pthread

# shmop
MULTI_PACKAGES+=	-shmop
COMMENT-shmop=		shared memory extensions for php5
CONFIGURE_ARGS+=	--enable-shmop=shared,${LOCALBASE}
LIB_DEPENDS-shmop=
WANTLIB-shmop=		c pthread

# soap
MULTI_PACKAGES+=	-soap
COMMENT-soap=		SOAP functions for php5
CONFIGURE_ARGS+=	--enable-soap=shared,${LOCALBASE}
LIB_DEPENDS-soap=	textproc/libxml
WANTLIB-soap=		${MODLIBICONV_WANTLIB} c m pthread z xml2>=8

# snmp
MULTI_PACKAGES+=	-snmp
COMMENT-snmp=		snmp protocol extensions for php5
CONFIGURE_ARGS+=	--with-snmp=shared,${LOCALBASE} --enable-ucd-snmp-hack
LIB_DEPENDS-snmp=	net/net-snmp
WANTLIB-snmp=		c crypto m netsnmp>=6.2 pthread

# sqlite
MULTI_PACKAGES+=	-sqlite
COMMENT-sqlite=		sqlite database access extensions for php5
CONFIGURE_ARGS+=	--with-sqlite=shared,${LOCALBASE} --enable-sqlite-utf8
LIB_DEPENDS-sqlite=	databases/sqlite
WANTLIB-sqlite=		sqlite>=8 c pthread

# pdo-dblib
MULTI_PACKAGES+=	-pdo_dblib
COMMENT-pdo_dblib=	PDO DB-LIB support for php5
CONFIGURE_ARGS+=        --with-pdo-dblib=shared,${LOCALBASE}
LIB_DEPENDS-pdo_dblib=	databases/freetds
WANTLIB-pdo_dblib=	sybdb>=6 c pthread

# mssql
MULTI_PACKAGES+=	-mssql
COMMENT-mssql=		microsoft sql access extensions for php5
CONFIGURE_ARGS+=        --with-mssql=shared,${LOCALBASE}
LIB_DEPENDS-mssql=	databases/freetds
WANTLIB-mssql=		sybdb>=6 c pthread

# tidy
MULTI_PACKAGES+=	-tidy
COMMENT-tidy=		tidy HTML cleaner bindings
CONFIGURE_ARGS+=	--with-tidy=shared,${LOCALBASE}
LIB_DEPENDS-tidy=	www/tidyp
WANTLIB-tidy=		tidyp c pthread

# xml-rpc
MULTI_PACKAGES+=	-xmlrpc
COMMENT-xmlrpc=		XML RPC functions for php5
CONFIGURE_ARGS+=	--with-xmlrpc=shared
LIB_DEPENDS-xmlrpc=	textproc/libxml
WANTLIB-xmlrpc=		${MODLIBICONV_WANTLIB} m z xml2>=8 c pthread

# xsl
MULTI_PACKAGES+=	-xsl
COMMENT-xsl=		XSL functions for php5
CONFIGURE_ARGS+=	--with-xsl=shared --enable-dom
LIB_DEPENDS-xsl=	textproc/libxslt
WANTLIB-xsl=		${MODLIBICONV_WANTLIB} m xml2 z xslt>=3 exslt c pthread

# zip
MULTI_PACKAGES+=	-zip
COMMENT-zip=		zip functions for php5
CONFIGURE_ARGS+=	--enable-zip=shared,${LOCALBASE}
LIB_DEPENDS-zip=
WANTLIB-zip=		z c pthread

# some variables to substitute
SUBST_VARS=	MODPHP_CONFIG_PATH PV ^MODULE_NAME
PHP_VERSION=	${V}

.for i in TRUEPREFIX MODULES_DIR PHP_VERSION APACHE_MODULE_DIR
PHPXS_SUBST+= -e 's,${i},${${i}},'
.endfor

MODULES=		converters/libiconv devel/gettext

WANTLIB-main=		c crypto ssl z pthread gssapi krb5 xml2>=8 \
			m ${MODGETTEXT_WANTLIB}
WANTLIB-fastcgi=	${WANTLIB-main}
LIB_DEPENDS-main=	textproc/libxml
RUN_DEPENDS-main=	${MODGETTEXT_RUN_DEPENDS} \
			mail/femail,-chroot
LIB_DEPENDS-fastcgi=	${LIB_DEPENDS-main}

.if ${FLAVOR:L:Mno_suhosin}
SUPDISTFILES=		suhosin-${SUHOSIN_V}.tgz:0 \
			suhosin-patch-${SUHOSIN_PHPV}-${SUHOSIN_P_V}.patch.gz:0
.else
DISTFILES+=		suhosin-${SUHOSIN_V}.tgz:0
PATCHFILES=		suhosin-patch-${SUHOSIN_PHPV}-${SUHOSIN_P_V}.patch.gz:0
PATCH_DIST_STRIP=	-p1
CONFIGURE_ARGS+=	--enable-suhosin

pre-patch:
	@mv ${WRKDIR}/suhosin-${SUHOSIN_V} ${WRKSRC}/ext/suhosin
.endif

pre-fake:
	${INSTALL_DATA_DIR} ${PREFIX}/${APACHE_MODULE_SUBDIR}/modules
INSTALL_TARGET= install-headers install-build install-programs
DESTDIRNAME=	INSTALL_ROOT

pre-configure:
	${SUBST_CMD} ${WRKSRC}/main/php_ini.c
	@perl -pi -e "s,OPENBSD_PEAR_ROOT,'${CHROOT_DIR}/pear',g;" \
		-e "s,OPENBSD_PREFIX,${TRUEPREFIX},;" \
		${WRKSRC}/scripts/phpize.in \
		${WRKSRC}/scripts/php-config.in

.for i in ${MULTI_PACKAGES:N-main:N-fastcgi:N-fpm:N-pcntl:S/-//g}
MODULE_NAME-${i}=	${i}
DESCR-${i}=		${.CURDIR}/../files/DESCR-${i}
MESSAGE-${i}=		${.CURDIR}/../files/MESSAGE-ext
UNMESSAGE-${i}=		${.CURDIR}/../files/UNMESSAGE-ext
PKGNAME-${i}=		php-${i}-${V}
.if ${V:M5.2*}
PKGSPEC-${i}=		php-${i}->=5.2,<5.3
.else if ${V:M5.3*}
PKGSPEC-${i}=		php-${i}->=5.3,<5.4
.endif
RUN_DEPENDS-${i}+=	php-${V}:lang/php/${PV}
.endfor

DESCR-main=		${.CURDIR}/../files/DESCR-main
DESCR-fastcgi=		${.CURDIR}/../files/DESCR-fastcgi
MESSAGE-main=		${.CURDIR}/../files/MESSAGE-main
UNMESSAGE-main=		${.CURDIR}/../files/UNMESSAGE-main

post-install:
	${INSTALL_DATA} ${WRKBUILD}/.libs/libphp5.so \
		${PREFIX}/${APACHE_MODULE_SUBDIR}/
	${INSTALL_DATA_DIR} ${WRKINST}/${CHROOT_DIR}/conf/php-${PV}.sample
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/php-${PV}
	${INSTALL_PROGRAM} ${WRKBUILD}/sapi/cli/php ${PREFIX}/bin/php-${PV}
	${INSTALL_PROGRAM} ${WRKBUILD}/sapi/cgi/php-cgi ${PREFIX}/bin/php-fastcgi-${PV}
.if ${V:M5.3*}
	${INSTALL_DATA} ${WRKBUILD}/sapi/fpm/php-fpm.conf \
		${PREFIX}/share/examples/php-${PV}/php-fpm.conf
.endif
	${INSTALL_DATA} ${.CURDIR}/../files/php.conf \
		${PREFIX}/share/examples/php-${PV}/php.conf
	@perl -pi -e "s,!!PREFIX!!,${TRUEPREFIX},g;s,!!PV!!,${PV},g" \
		${PREFIX}/share/examples/php-${PV}/php.conf

.for m in ${MULTI_PACKAGES:N-main:N-fastcgi:N-fpm:S/-//g}
	${INSTALL_DATA} ${WRKBUILD}/modules/${m}.so \
		${PREFIX}/${MODULES_SUBDIR}/${m}.so
	echo "extension=${m}.so" > \
		${PREFIX}/share/examples/php-${PV}/${m}.ini
.endfor
	${INSTALL_DATA_DIR} ${WRKINST}/${CHROOT_DIR}/etc
	echo "www:*:67:67::0:0:dummy user to appease c-client:/nonexistent:/sbin/nologin" > \
		${WRKINST}/${CHROOT_DIR}/etc/master.passwd.imap
	pwd_mkdb -d ${WRKINST}/${CHROOT_DIR}/etc master.passwd.imap

.for i in ${INI_TEMPLATES}
	@sed -e 's,MODULES_DIR,${MODULES_DIR},' \
	     -e 's,OPENBSD_INCLUDE_PATH,/pear/lib:${CHROOT_DIR}/pear/lib,' \
		<${WRKSRC}/php.ini-${i} \
		>${PREFIX}/share/examples/php-${PV}/php.ini-${i}
.endfor
	${INSTALL_MAN} ${WRKSRC}/sapi/cli/php.1 ${PREFIX}/man/man1/php-${PV}.1
