# $OpenBSD$

COMMENT=		Apache LDAP based virtual hosts module

REVISION=		9
DISTNAME=		mod_ldapvhost-1.0.2
CATEGORIES=		www

HOMEPAGE=		https://www.msys.ch/products/unix/mod_ldapvhost/

MASTER_SITES=		http://www.etc.msys.ch/software/mod_ldapvhost/
EXTRACT_SUFX=		.tgz
MODULES+=		apache-module

# BSD
PERMIT_PACKAGE_CDROM=   Yes
PERMIT_PACKAGE_FTP=     Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=   Yes

WANTLIB += lber ldap

MODAPACHE_NAME=		ldapvhost

NO_REGRESS=		Yes

LIB_DEPENDS=		databases/openldap

do-build:
	(cd ${WRKBUILD}; make)

post-build:
	@${MODAPACHE_CREATE_ENABLE_SCRIPT}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mod_ldapvhost
	${INSTALL_DATA} ${WRKBUILD}/*.schema ${PREFIX}/share/doc/mod_ldapvhost/
	${INSTALL_DATA} ${WRKBUILD}/mod_ldapvhost.conf \
	    ${PREFIX}/share/doc/mod_ldapvhost/
	${MODAPACHE_INSTALL}

.include <bsd.port.mk>
