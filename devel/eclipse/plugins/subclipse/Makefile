# $OpenBSD$

COMMENT=		SubVersion (CVS replacement) plug-in for Eclipse IDE

V=			1.2.1
DISTNAME=		site-${V}
PKGNAME=		eclipse-plugin-subclipse-${V}
CATEGORIES=		devel/eclipse/plugins java
EXTRACT_SUFX=		.zip
REVISION =		0

MAINTAINER=		Ian Darwin <ian@openbsd.org>

# SubClipse itself is CPL 1.0, but
# JavaSVN, which it uses, has a bizarro hybrid: BSD but "no redist w/o source code"
PERMIT_PACKAGE_CDROM=	Stupid license
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Stupid license
PERMIT_DISTFILES_FTP=	Yes

HOMEPAGE=		http://subclipse.tigris.org/

MASTER_SITES=		http://subclipse.tigris.org/files/documents/906/37653/

# Try to use in-tree lynx since tigris' brain-dead web site insists
# on doing a redirection loop if you don't handle cookes, which default
# FETCH_CMD does not.
FETCH_CMD=		lynx -accept_all_cookies -source >${DISTDIR}/$$f

RUN_DEPENDS=		devel/eclipse/sdk>=3.2

NO_BUILD=		Yes
NO_REGRESS=		Yes

WRKDIST=		${WRKDIR}

# Distfile is an Update Site download, unpack features jar manually, 
# still tar plugins over into ${PREFIX}
do-install:
		${INSTALL_DATA_DIR} ${PREFIX}/eclipse
		cd ${WRKDIST} && tar cfL - features plugins | \
			(cd ${PREFIX}/eclipse && tar -xf -)

.include <bsd.port.mk>
