# $OpenBSD$

SHARED_ONLY=		Yes

COMMENT=		NetBeans Java IDE

V=			6.9.1
DISTNAME=		netbeans-${V}
CATEGORIES=		devel
REVISION=		4

HOMEPAGE=		http://www.netbeans.org/

# CDDL and GPLv2 dual-licensed
#
# For external components see:
#   http://www.netbeans.info/downloads/licence/netbeans-3rd-party.txt
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=		http://download.netbeans.org/netbeans/${V}/final/zip/
EXTRACT_SUFX=		-201007282301-ml.zip

MODULES=		java
MODJAVA_VER=		1.6+

RUN_DEPENDS=		java/javaPathHelper \
			devel/desktop-file-utils

NO_BUILD=		Yes
NO_REGRESS=		Yes

WRKDIST=		${WRKDIR}/netbeans

NB=			${PREFIX}/netbeans

pre-configure:
	@${SUBST_CMD} ${WRKSRC}/platform/lib/nbexec

do-install:
	${INSTALL_DATA_DIR} ${NB}
	@tar -czf - -C ${WRKDIR}/netbeans . | tar xzf - -C ${NB}
	@rm -rf ${NB}/profiler3
	@find ${NB} -name "*.dll" -o -name "*.exe" -o -name "*.cmd" \
		-o -name "*.bat" -o -name "*.orig" | xargs rm
	@${SUBST_CMD} -o ${BINOWN} -g ${BINGRP} -c \
		${FILESDIR}/netbeans \
		${PREFIX}/bin/netbeans
	@chmod ${BINMODE} ${PREFIX}/bin/netbeans
	@${INSTALL_DATA_DIR} ${PREFIX}/share/applications
	@${SUBST_CMD} -o ${SHAREOWN} -g ${SHAREGRP} -c \
		${FILESDIR}/netbeans.desktop \
		${PREFIX}/share/applications/netbeans.desktop

.include <bsd.port.mk>
