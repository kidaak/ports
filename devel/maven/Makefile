# $OpenBSD$

COMMENT=	software project management and comprehension tool

DISTNAME=	apache-maven-2.2.1
PKGNAME=	${DISTNAME:S/apache-//}
REVISION=	2
CATEGORIES=	devel

HOMEPAGE=	http://maven.apache.org/

# Apache Software License 2.0
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=	${MASTER_SITE_APACHE:=maven/binaries/} \
		http://archive.apache.org/dist/maven/binaries/


EXTRACT_SUFX=	-bin.tar.gz

MODULES=	java
MODJAVA_VER=	1.5+
RUN_DEPENDS=	java/javaPathHelper

NO_BUILD=	Yes
NO_REGRESS=	Yes

MAVEN_HOME=	${LOCALBASE}/${DISTNAME}
SAMPLEDIR=	${PREFIX}/share/examples/maven
SUBST_VARS+=	DISTNAME

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${DISTNAME}
	${INSTALL_DATA_DIR} ${SAMPLEDIR}
	cd ${WRKDIST} && \
		tar -cf - bin boot lib `find * -prune -type f` | \
		tar -C ${PREFIX}/${DISTNAME} -xf -
	find ${WRKINST} -name \*.orig -or -name \*.bat -or -name \*.exe | \
		xargs rm
	${INSTALL_DATA} ${WRKSRC}/conf/settings.xml ${SAMPLEDIR}/
	ln -s ${SYSCONFDIR}/maven ${PREFIX}/${DISTNAME}/conf
	@perl -pi -e 's,%%SYSCONFDIR%%,${SYSCONFDIR},' \
		${PREFIX}/${DISTNAME}/bin/mvn
	@sed -e 's,%%MAVEN_HOME%%,${MAVEN_HOME},' \
		< ${FILESDIR}/maven.rc \
		> ${SAMPLEDIR}/maven.rc
	@sed -e 's,%%DISTNAME%%,${DISTNAME},' \
		-e 's,%%LOCALBASE%%,${LOCALBASE},' \
		< ${FILESDIR}/mvn \
		> ${WRKSRC}/bin/mvn
	${INSTALL_SCRIPT} ${WRKSRC}/bin/mvn ${PREFIX}/bin/

.include <bsd.port.mk>
