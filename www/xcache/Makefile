# $OpenBSD$

SHARED_ONLY=	Yes

COMMENT=	fast and stable PHP opcode cacher

VERSION=	2.0.1
DISTNAME=	xcache-${VERSION}
CATEGORIES=	www
MASTER_SITES=	http://xcache.lighttpd.net/pub/Releases/${VERSION}/

HOMEPAGE=	http://xcache.lighttpd.net/

MAINTAINER=	Brad Smith <brad@comstyle.com>

# BSD
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

AUTOCONF_VERSION=	2.59

MODULES=		lang/php

BUILD_DEPENDS+=		${MODGNU_AUTOCONF_DEPENDS} \
			devel/re2c>=0.13.4 \
			devel/gindent

WEBROOT=		/var/www
SUBST_VARS=		WEBROOT

USE_LIBTOOL=		Yes
LIBTOOL_FLAGS=		--tag=disable-static
CONFIGURE_STYLE=	gnu
CONFIGURE_ARGS+=	--enable-xcache
CONFIGURE_ENV=		AUTOCONF_VERSION=${AUTOCONF_VERSION}

DESTDIRNAME=	INSTALL_ROOT

NO_REGRESS=	Yes

FLAVORS=	coverager
FLAVOR?=

.if ${FLAVOR:L:Mcoverager}
CONFIGURE_ARGS+=	--enable-xcache-coverager
.endif

MODPHP_DO_PHPIZE=	Yes
MODPHP_DO_SAMPLE=	xcache
MESSAGE=		${PKGDIR}/MESSAGE

post-extract:
	@ln -sf ${LOCALBASE}/bin/gindent ${WRKDIR}/bin/indent

post-install:
	${INSTALL_DATA_DIR} ${WRKINST}${WEBROOT}/xcache
	${INSTALL_DATA_DIR} ${WRKINST}${WEBROOT}/xcache/admin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/php-${MODPHP_VERSION}
	cd ${WRKSRC}/admin && ${INSTALL_DATA} * ${WRKINST}${WEBROOT}/xcache/admin
	${INSTALL_DATA} ${WRKSRC}/xcache.ini \
		${PREFIX}/share/examples/php-${MODPHP_VERSION}

.if ${FLAVOR:L:Mcoverager}
	${INSTALL_DATA_DIR} ${WRKINST}${WEBROOT}/xcache/coverager
	cd ${WRKSRC}/coverager && ${INSTALL_DATA} * ${WRKINST}${WEBROOT}/xcache/coverager
.endif

.include <bsd.port.mk>
