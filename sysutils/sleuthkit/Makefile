# $OpenBSD$

COMMENT=		forensic toolkit based on TCT

DISTNAME=		sleuthkit-3.0.1
REVISION =		0
CATEGORIES=		sysutils security

SHARED_LIBS=		tsk3 4.3

HOMEPAGE=		http://www.sleuthkit.org/

MAINTAINER=		Nigel Taylor <nigel@openbsd.org>

# CPLv1 & IBM & GPLv2
PERMIT_PACKAGE_CDROM=	commercial contributor must indemnify all others
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	commercial contributor must indemnify all others
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=sleuthkit/}

WANTLIB=		c m stdc++

CONFIGURE_STYLE=        simple
USE_GROFF =		Yes

RUN_DEPENDS=		converters/p5-DateManip

NO_REGRESS=		Yes

pre-configure:
	@perl -pi -e "s:%%PREFIX%%:${PREFIX}:" ${WRKSRC}/man/sorter.1

.include <bsd.port.mk>
