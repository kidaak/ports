# $OpenBSD$

COMMENT=	apache HTTP server

V=		2.2.22
PKGNAME=	apache-httpd-${V}
DISTNAME=	httpd-${V}

CATEGORIES=	www net

HOMEPAGE=	http://httpd.apache.org/

# Apache
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

SHARED_ONLY=		Yes
USE_GROFF =		Yes
NO_REGRESS=		Yes

WANTLIB += c crypto m ssl expat apr-1 db>=4 z pcre pthread aprutil-1>=2

LIB_DEPENDS=		devel/pcre

FLAVORS=		ldap
FLAVOR?=

.if ${FLAVOR:L:Mldap}
CONFIGURE_ARGS+=	--with-ldap --enable-ldap --enable-authnz-ldap
WANTLIB+=		asn1 com_err gssapi krb5 sasl2 ldap lber
LIB_DEPENDS+=		databases/openldap
LIB_DEPENDS+=		apr-util-*-ldap:devel/apr-util,ldap
.else
LIB_DEPENDS+=		apr-util-*-!ldap:devel/apr-util
.endif

MODULES=		converters/libiconv

USE_LIBTOOL=		Yes

MASTER_SITES=		${MASTER_SITE_APACHE:=httpd/}

HTTPD_DIR=		/var/apache2
CONFDIR=		${SYSCONFDIR}/apache2
SUBST_VARS=		CONFDIR

CONFIGURE_STYLE=	simple
CONFIGURE_ARGS+=	--enable-layout=OpenBSD \
			--prefix=${HTTPD_DIR} \
			--exec-prefix=${LOCALBASE} \
			--sysconfdir=${CONFDIR} \
			--with-apr=${LOCALBASE}/bin/apr-1-config  \
			--with-apr-util=${LOCALBASE}/bin/apu-1-config \
			--enable-ssl --with-ssl=/usr \
			--with-mpm=prefork \
			--with-program-name=httpd2 \
			--enable-modules=all \
			--enable-cache \
			--enable-disk-cache \
			--enable-proxy \
			--enable-mods-shared=all \
			--enable-suexec \
			--with-suexec-caller=_apache2 \
			--with-suexec-bin=${TRUEPREFIX}/sbin/suexec2 \
			--with-suexec-logfile=/var/log/suexec2_log \
			--with-pcre=${LOCALBASE} 

CONFIGURE_ENV+=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"

FAKE_FLAGS+=		rel_user=_apache2 rel_group=_apache2 \
			rel_datadir=${HTTPD_DIR} \
			datadir=${PREFIX}/share/examples/apache2 \
			sysconfdir=${PREFIX}/share/examples/apache2/conf

A2SBIN=			apachectl apxs dbmmanage htdigest htpasswd \
			logresolve rotatelogs suexec
A2MAN1=			apxs dbmmanage htdigest htpasswd logresolve
A2MAN8=			apachectl httpd rotatelogs suexec

pre-configure:
	@perl -pi -e 's,%%PREFIX%%,${PREFIX},' ${WRKSRC}/config.layout
	@perl -pi -e 's,%%CONFDIR%%,${CONFDIR},' ${WRKSRC}/config.layout \
	${WRKSRC}/configure
	@perl -pi -e 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/support/apxs.in

post-install:
	chown -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share
	chown -R ${MANOWN}:${MANGRP} ${PREFIX}/man
	chown -R ${BINOWN}:${BINGRP} ${PREFIX}/sbin
	chown -R ${LIBOWN}:${LIBGRP} ${PREFIX}/lib

.for i in ${A2MAN1}
	mv ${PREFIX}/man/man1/${i}.1 ${PREFIX}/man/man1/${i}2.1
.endfor

.for i in ${A2MAN8}
	mv ${PREFIX}/man/man8/${i}.8 ${PREFIX}/man/man8/${i}2.8
.endfor

.for i in ${A2SBIN}
	mv ${PREFIX}/sbin/${i} ${PREFIX}/sbin/${i}2
.endfor

.if ${FLAVOR:L:Mldap}
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ap2-mod_auth_ldap
.for i in mod_ldap.html mod_authnz_ldap.html.en \
	mod_authnz_ldap.html mod_ldap.html.en
	${INSTALL_DATA} ${WRKSRC}/docs/manual/mod/${i} \
		${PREFIX}/share/doc/ap2-mod_auth_ldap/
.endfor
.endif

.include <bsd.port.mk>
