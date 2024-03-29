# $OpenBSD$

COMMENT-main=	Java servlet 2.5 and Java server pages 2.1 server
COMMENT-examples=example applications and full documentation

V=		6.0.35
DISTNAME=	apache-tomcat-${V}
PKGNAME=	tomcat-${V}
PKGNAME-main=	tomcat-${V}
PKGNAME-examples=tomcat-examples-${V}
CATEGORIES=	www

DISTFILES=	${DISTNAME}.tar.gz \
		${DISTNAME}-fulldocs.tar.gz

MASTER_SITES=	${MASTER_SITE_APACHE:=tomcat/tomcat-6/v$V/bin/} \
		http://archive.apache.org/dist/tomcat/tomcat-6/archive/v${V}/bin/

HOMEPAGE=	http://tomcat.apache.org/

MULTI_PACKAGES=	-main -examples

MODULES=	java
MODJAVA_VER=	1.5+
MODJAVA_JRERUN=	Yes

BUILD_DEPENDS=	archivers/gtar

RUN_DEPENDS=	java/javaPathHelper

RUN_DEPENDS-examples=	tomcat->=6,<7:www/tomcat/v6,-main
PREFIX-examples=	${CATALINA_BASE}

# Apache Software License 2.0
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

TAR=		${LOCALBASE}/bin/gtar

NO_BUILD=	Yes
NO_REGRESS=	Yes

CONFDIR=	${SYSCONFDIR}/tomcat
CATALINA_BASE=	/var/tomcat
SAMPLEDIR=	${PREFIX}/share/examples/tomcat
SUBST_VARS+=	CONFDIR CATALINA_BASE

post-extract:
	@rm -rf ${WRKDIST}/webapps/docs
	mv ${WRKDIR}/tomcat-6.0-doc ${WRKDIST}/webapps/docs

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/tomcat \
		${PREFIX}/tomcat/webapps \
		${SAMPLEDIR} \
		${WRKINST}/${CATALINA_BASE} \
		${WRKINST}/${CATALINA_BASE}/webapps
	cd ${WRKDIST} && \
		tar cf - bin lib `find * -prune -type f` | \
		tar -C ${PREFIX}/tomcat -xf -
	cd ${WRKDIST}/webapps && \
		tar cf - host-manager manager | \
		tar -C ${PREFIX}/tomcat/webapps -xf -
	${INSTALL_DATA} `find ${WRKDIST}/conf/* -prune -type f` ${SAMPLEDIR}
	${SUBST_CMD} ${SAMPLEDIR}/server.xml
	${INSTALL_DATA} ${WRKDIST}/webapps/host-manager/manager.xml \
		${SAMPLEDIR}
	${INSTALL_DATA} ${WRKDIST}/webapps/host-manager/manager.xml \
		${SAMPLEDIR}/host-manager.xml
	@perl -pi -e 's/manager/host-manager/' ${SAMPLEDIR}/host-manager.xml
	cd ${WRKDIST}/webapps && \
		tar cf - ROOT docs examples | \
		tar -C ${WRKINST}/${CATALINA_BASE}/webapps -xf -
	${INSTALL_DATA_DIR} ${WRKINST}/${CONFDIR}/Catalina/localhost
	${INSTALL_DATA} ${WRKDIST}/webapps/host-manager/manager.xml \
		${WRKINST}/${CONFDIR}/Catalina/localhost
	${INSTALL_DATA} ${WRKDIST}/webapps/host-manager/manager.xml \
		${WRKINST}/${CONFDIR}/Catalina/localhost/host-manager.xml
	@perl -pi -e 's/manager/host-manager/' \
		${WRKINST}/${CONFDIR}/Catalina/localhost/host-manager.xml
	find ${WRKINST} \
		-name \*.beforesubst -or \
		-name \*.orig -or \
		-name \*.bat -or \
		-name \*.exe -or \
		-name \*.dll \
		| xargs rm

.include <bsd.port.mk>
