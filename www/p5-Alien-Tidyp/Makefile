# $OpenBSD$

COMMENT=	building, finding and using tidyp librar

DISTNAME=	Alien-Tidyp-v1.4.6
PKGNAME=	p5-${DISTNAME:S/v//}
CATEGORIES=	www
MODULES=	cpan
USE_GROFF =	Yes

# Perl
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

CONFIGURE_STYLE=	modbuild
CONFIGURE_ENV+= 	TIDYP_DIR=${LOCALBASE}

BUILD_DEPENDS=		devel/p5-File-ShareDir \
			www/tidyp

.include <bsd.port.mk>
