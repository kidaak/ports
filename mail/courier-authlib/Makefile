# $OpenBSD$

COMMENT-main=		authentication library for courier
COMMENT-ldap=		ldap authentication module for courier-authLib
COMMENT-mysql=		mysql authentication module for courier-authLib
COMMENT-pgsql=		pgsql authentication module for courier-authLib
COMMENT-userdb=		userdb authentication module for courier-authLib

DISTNAME=		courier-authlib-0.63.0
PKGNAME-main=		${DISTNAME}
PKGNAME-ldap=		${DISTNAME:S/lib-/lib-ldap-/}
PKGNAME-mysql=		${DISTNAME:S/lib-/lib-mysql-/}
PKGNAME-pgsql=		${DISTNAME:S/lib-/lib-pgsql-/}
PKGNAME-userdb=		${DISTNAME:S/lib-/lib-userdb-/}

REVISION-main=		6
REVISION-ldap=		3
REVISION-mysql=		3
REVISION-pgsql=		3
REVISION-userdb=	3

SHARED_LIBS +=  courierauth          1.0      # .0.0
SHARED_LIBS +=  courierauthsasl      1.0      # .0.0
SHARED_LIBS +=  courierauthsaslclient 0.0     # .0.0
SHARED_LIBS +=  courierauthcommon    1.0      # .0.0
SHARED_LIBS +=  authuserdb           0.0      # .0.0
SHARED_LIBS +=  authpwd              0.0      # .0.0
SHARED_LIBS +=  authpgsql            0.0      # .0.0
SHARED_LIBS +=  authldap             1.0      # .0.0
SHARED_LIBS +=  authmysql            0.0      # .0.0
SHARED_LIBS +=  authpipe             0.0      # .0.0

CATEGORIES=		mail security
HOMEPAGE=		http://www.courier-mta.org/authlib/

MAINTAINER=		Giovanni Bechis <giovanni@openbsd.org>

# GPLv3
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=courier/}
EXTRACT_SUFX=		.tar.bz2

USE_GMAKE=		Yes
USE_LIBTOOL=		Yes
CONFIGURE_STYLE=	gnu

CONFIGURE_ENV=		LIBS="-L${LOCALBASE}/lib" \
			LDFLAGS="-L${LOCALBASE}/lib" \
			CPPFLAGS="-I${LOCALBASE}/include"

COURIERSTATE=		/var/run/courier-auth
EXAMPLE_DIR=		${PREFIX}/share/examples/courier-authlib
SUBST_VARS=		COURIERSTATE EXAMPLE_DIR

CONFIGURE_ARGS+=	${CONFIGURE_SHARED}
CONFIGURE_ARGS+=	--enable-static \
			--without-authpam \
			--without-authvchkpw \
			--without-authcustom \
			--with-authpwd \
			--with-authshadow \
			--with-mailuser=_courier \
			--with-mailgroup=_courier \
			--with-pkgconfdir=${SYSCONFDIR}/courier \
			--with-authdaemonvar=${COURIERSTATE} \
			--libdir=${PREFIX}/lib \
			--includedir=${PREFIX}/include \
			--enable-ltdl-install=no \
			--with-ltdl-lib=${LOCALBASE}/lib \
			--with-ltdl-include=${LOCALBASE}/include \
			--cache-file=${WRKDIR}/courier-authlib.cache

RUN_DEPENDS-main=	lang/expect,no_tk
BUILD_DEPENDS=		${RUN_DEPENDS-main}

DOCS=			COPYING COPYING.GPL INSTALL NEWS README

MULTI_PACKAGES=		-main -ldap -mysql -pgsql -userdb
PSEUDO_FLAVORS=		no_ldap no_mysql no_pgsql no_userdb
FLAVOR?=

WANTLIB-main=		c ltdl

LIB_DEPENDS-main=	devel/libtool,-ltdl

WANTLIB-ldap=		crypto ssl asn1 com_err gssapi krb5 \
			courierauthcommon courierauth ldap lber sasl2
LIB_DEPENDS-ldap=	${BUILD_PKGPATH} \
			databases/openldap \
			security/cyrus-sasl2

WANTLIB-mysql=		crypto m ssl z courierauthcommon courierauth mysqlclient
LIB_DEPENDS-mysql=	${BUILD_PKGPATH} \
			databases/mysql

WANTLIB-pgsql=		m courierauthcommon courierauth pq
LIB_DEPENDS-pgsql=	${BUILD_PKGPATH} \
			databases/postgresql

WANTLIB-userdb=		c courierauthcommon courierauth gdbm>=3
LIB_DEPENDS-userdb=	${BUILD_PKGPATH} \
			databases/gdbm

.include <bsd.port.arch.mk>

.if ${BUILD_PACKAGES:M-ldap}
CONFIGURE_ARGS+=	--with-authldap
DOCS+=			README.ldap
.else
CONFIGURE_ARGS+=	--without-authldap
.endif

.if ${BUILD_PACKAGES:M-mysql}
CONFIGURE_ARGS+=	--with-authmysql \
			--with-mysql-libs=${LOCALBASE}/lib/mysql \
			--with-mysql-includes=${LOCALBASE}/include/mysql
DOCS+=			README.authmysql.myownquery
.else
CONFIGURE_ARGS+=	--without-authmysql
.endif

.if ${BUILD_PACKAGES:M-pgsql}
CONFIGURE_ARGS+=	--with-authpgsql \
			--with-pgsql-libs=${LOCALBASE}/lib \
			--with-pgsql-includes=${LOCALBASE}/include/postgresql
.else
CONFIGURE_ARGS+=	--without-authpgsql
.endif

.if ${BUILD_PACKAGES:M-userdb}
CONFIGURE_ARGS+=	--with-makedatprog=${PREFIX}/libexec/courier-authlib/makedatprog \
			--with-authuserdb \
			--with-db=gdbm
.else
CONFIGURE_ARGS+=	--without-authuserdb \
			--without-makedatprog
.endif

post-install:
	mv ${PREFIX}/lib/courier-authlib/lib* ${PREFIX}/lib

	${INSTALL_SCRIPT} ${WRKSRC}/sysconftool \
	    ${PREFIX}/libexec/courier-authlib/sysconftool
	${INSTALL_SCRIPT} ${WRKSRC}/authmigrate \
	    ${PREFIX}/libexec/courier-authlib/authmigrate
	${INSTALL_DATA_DIR} ${EXAMPLE_DIR}
	@mv ${WRKINST}${SYSCONFDIR}/courier/*.dist ${EXAMPLE_DIR}
	@chown root:wheel ${EXAMPLE_DIR}/*
.if ${BUILD_PACKAGES:M-ldap}
	${INSTALL_DATA} ${WRKSRC}/authldap.schema ${EXAMPLE_DIR}
.endif
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/courier-authlib
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/doc/courier-authlib
.endfor

.include <bsd.port.mk>
