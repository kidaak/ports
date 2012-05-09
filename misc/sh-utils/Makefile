# $OpenBSD: ports/misc/sh-utils/Makefile,v 1.17 2012/03/29 13:38:40 sthen Exp $

COMMENT=		GNU command line utilities

DISTNAME=		sh-utils-2.0
REVISION=		0
CATEGORIES=		misc

# GPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB=		c m

MASTER_SITES=		${MASTER_SITE_GNU:=sh-utils/}

MODULES=		devel/gettext

SEPARATE_BUILD=		Yes
USE_GMAKE=		Yes
USE_GROFF =		Yes
CONFIGURE_STYLE=	gnu
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"
	
.include <bsd.port.mk>
