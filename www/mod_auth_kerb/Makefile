# $OpenBSD$

COMMENT=	Apache Kerberos authentication module

REVISION=	8
DISTNAME=	mod_auth_kerb-5.3
CATEGORIES=	www

HOMEPAGE=	http://modauthkerb.sourceforge.net/

MODULES+=	apache-module
MAINTAINER=	Jason Meltzer <jmeltzer@openbsd.org>

# combination of 2- and 3-clause BSD, MIT, and export crypto warnings
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes
WANTLIB=		ssl gssapi krb5 crypto

MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=modauthkerb/}

NO_REGRESS=	Yes
USE_GMAKE=	Yes

MODAPACHE_NAME=	auth_kerb
MODAPACHE_LOCATION=	${WRKBUILD}/src

CONFIGURE_STYLE=gnu
CONFIGURE_ENV=	KRB5_CPPFLAGS="-I/usr/include/kerberosV" \
		KRB5_LDFLAGS="-lkrb5 -lgssapi -lssl -lcrypto"

post-build:
	@${MODAPACHE_CREATE_ENABLE_SCRIPT}

do-install:
	${MODAPACHE_INSTALL}

.include <bsd.port.mk>
