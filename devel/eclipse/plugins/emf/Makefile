# $OpenBSD$

COMMENT=		Eclipse Modeling Framework (EMF)

V=			2.2.3
DISTNAME=		emf-sdo-xsd-SDK-${V}
PKGNAME=		eclipse-plugin-emf-sdk-${V}
CATEGORIES=		devel/eclipse/plugins java
REVISION =		0

HOMEPAGE=		http://www.eclipse.org/emf/

MAINTAINER=		Kurt Miller <kurt@openbsd.org>

EXTRACT_SUFX=           .zip

# Eclipse Public License Version 1.0 (http://www.eclipse.org/legal/epl-v10.html)
PERMIT_PACKAGE_CDROM=	commercial distribution defend and indemnify clauses
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	commercial distribution defend and indemnify clauses
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=		http://download.eclipse.org/modeling/emf/emf/downloads/drops/${V}/R200705141058/

RUN_DEPENDS=		devel/eclipse/sdk>=3.2

NO_BUILD=		Yes
NO_REGRESS=		Yes

WRKDIST=		${WRKDIR}

do-install:
	cd ${WRKDIST} && tar cfL - eclipse | \
		(cd ${PREFIX} && tar -xf -)
	cd ${PREFIX}/eclipse && rm epl-v10.html notice.html

.include <bsd.port.mk>
