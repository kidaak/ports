# $OpenBSD$

COMMENT=	next generation web interface for Zarafa

WAPP_BUILD=	35292
WAPP_VERSION=	1.1
EPOCH=		0
REVISION=	0

DISTNAME=	zarafa-webapp-${WAPP_VERSION}-${WAPP_BUILD}.noarch.rpm
PKGNAME=	zarafa-webapp-${WAPP_VERSION}

EXTRACT_SUFX=	# empty

MASTER_SITES=	http://download.zarafa.com/community/final/WebApp/${WAPP_VERSION}/rhel/

CATEGORIES=	mail www

MODULES=	lang/php

MODPHP_BUILDDEP=No
MODPHP_RUNDEP=	No

BUILD_DEPENDS=	rpm-*|rpm2cpio-*:converters/rpm2cpio
RUN_DEPENDS=	mail/zarafa/zarafa,-web # php-mapi

NO_BUILD=	Yes
NO_REGRESS=	Yes
PKG_ARCH=	*

WRKDIST=	${WRKDIR}
PREFIX=		/var/www
INSTDIR=	${PREFIX}/zarafa-webapp
TINSTDIR=	${TRUEPREFIX}/zarafa-webapp

SUBST_VARS=	INSTDIR TINSTDIR

do-extract:
	cd ${WRKDIR} && \
		${LOCALBASE}/bin/rpm2cpio ${FULLDISTDIR}/${DISTNAME} | cpio -id

pre-configure:
	${SUBST_CMD} ${WRKSRC}/etc/zarafa/webapp/config.php

do-install:
	cp -Rp ${WRKSRC}/usr/share/zarafa-webapp ${PREFIX}
	${SUBST_CMD} -c ${FILESDIR}/zarafa-webapp.conf \
		${INSTDIR}/zarafa-webapp.conf.dist
	cat ${WRKSRC}/etc/zarafa/webapp/config.php > \
		${INSTDIR}/config.php.dist
	rm ${INSTDIR}/config.php
	chown -R ${SHAREOWN}:${SHAREGRP} ${INSTDIR}

.include <bsd.port.mk>
