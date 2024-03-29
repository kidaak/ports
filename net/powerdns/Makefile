# $OpenBSD$

SHARED_ONLY=		Yes

COMMENT-main=		modern authoritative nameserver
COMMENT-mysql=		MySQL database access module for PowerDNS
COMMENT-pgsql=		PGSQL database access module for PowerDNS
COMMENT-ldap=		LDAP module for PowerDNS

V=			2.9.22.6
DISTNAME=		pdns-${V}
PKGNAME=		powerdns-${V}
PKGNAME-main=		powerdns-${V}
PKGNAME-mysql=		powerdns-mysql-${V}
PKGNAME-pgsql=		powerdns-pgsql-${V}
PKGNAME-ldap=		powerdns-ldap-${V}
CATEGORIES=		net
HOMEPAGE=		http://www.powerdns.com/

REVISION-main=		0

MULTI_PACKAGES=		-main

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB=		m stdc++ z
WANTLIB-main=		c pthread sqlite3>=8 ${WANTLIB}

MASTER_SITES=		http://downloads.powerdns.com/releases/

NO_REGRESS=		Yes

BUILD_DEPENDS=		devel/boost

PSEUDO_FLAVORS+=	no_mysql no_pgsql
FLAVOR?=

BACKENDS=		gsqlite3

# MySQL
.if ${FLAVOR:L:Mno_mysql}
CONFIGURE_ARGS+=	--without-mysql
.else
MULTI_PACKAGES+=	-mysql
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}
LIB_DEPENDS-mysql=	databases/mysql
RUN_DEPENDS-mysql=	${FULLPKGNAME-main}:net/powerdns
WANTLIB-mysql+=		crypto lib/mysql/mysqlclient>=10 ssl ${WANTLIB}
BACKENDS+=		gmysql
.endif

# PostgreSQL
.if ${FLAVOR:L:Mno_pgsql}
CONFIGURE_ARGS+=	--without-pgsql
.else
MULTI_PACKAGES+=	-pgsql
CONFIGURE_ARGS+=	--with-pgsql=${LOCALBASE} \
			--with-pgsql-includes=${LOCALBASE}/include/postgresql
LIB_DEPENDS-pgsql=	databases/postgresql,-main
RUN_DEPENDS-pgsql=	${FULLPKGNAME-main}:net/powerdns
WANTLIB-pgsql=		com_err crypto pq>=2 ssl ${WANTLIB}
BACKENDS+=		gpgsql
.endif

# LDAP
.if ${FLAVOR:L:Mno_ldap}
CONFIGURE_ARGS+=	--without-ldap
.else
MULTI_PACKAGES+=	-ldap
LIB_DEPENDS-ldap=	databases/openldap
RUN_DEPENDS-ldap=	${FULLPKGNAME-main}:net/powerdns
CONFIGURE_ARGS+=	--with-ldap=${LOCALBASE} \
			--with-ldap-includes=${LOCALBASE}/include
WANTLIB-ldap+=		asn1 com_err crypto gssapi krb5 lber-2.4 ldap_r-2.4 sasl2 ssl ${WANTLIB}
BACKENDS+=		ldap
.endif

BUILD_DEPENDS+=		${MODGNU_AUTOCONF_DEPENDS}

SYSCONFDIR=		${BASESYSCONFDIR}/pdns

USE_LIBTOOL=		Yes
CONFIGURE_STYLE=	autoconf
AUTOCONF_VERSION=	2.65
CONFIGURE_ARGS+=	--disable-shared \
			--libdir="${PREFIX}/lib/powerdns" \
			--with-modules="geo" \
			--with-dynmodules="${BACKENDS}" \
			--with-sqlite3=/usr \
			--with-sqlite3-includes=/usr/include \
			--without-sqlite \
			--disable-recursor # OpenBSD lacks ucontext.h, see PR 5099
CONFIGURE_ENV+=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"

EXAMPLE_TABLES=		tables-mysql.sql \
			tables-pgsql.sql \
			tables-sqlite.sql
EXAMPLE_DIR=		${PREFIX}/share/examples/powerdns/

post-install:
	${INSTALL_DATA_DIR} ${EXAMPLE_DIR}
.for t in ${EXAMPLE_TABLES}
	${INSTALL_DATA} ${FILESDIR}/$t ${EXAMPLE_DIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/pdns/pdns.conf-dist ${EXAMPLE_DIR}
	${INSTALL_DATA} ${FILESDIR}/pdns.conf ${EXAMPLE_DIR}

.include <bsd.port.mk>
