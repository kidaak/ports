# $OpenBSD$

COMMENT=	library for Chinese language processing

DISTNAME=	libtabe-0.2.6
PKGNAME=	zh-${DISTNAME}
REVISION=	4
CATEGORIES=	chinese
SHARED_LIBS +=	tabe                 2.1      # .0.0
SHARED_LIBS +=	bims                 2.1      # .0.0

HOMEPAGE=	http://libtabe.sourceforge.net/

MAINTAINER=     Kevin Lo <kevlo@openbsd.org>

PERMIT_PACKAGE_CDROM=   Yes
PERMIT_PACKAGE_FTP=     Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=   Yes

WANTLIB += c lib/db/db=3

MASTER_SITES=	http://www.kpvs.tp.edu.tw/

LIB_DEPENDS=	databases/db/v3

USE_LIBTOOL=	Yes
CONFIGURE_STYLE= gnu dest
CONFIGURE_ARGS=	--with-db-inc=${LOCALBASE}/include/db \
		--with-db-lib=${LOCALBASE}/lib/db \
		${CONFIGURE_SHARED}
MODGNU_CONFIG_GUESS_DIRS=${WRKSRC}/script

WRKDIST=	${WRKDIR}/libtabe

NO_REGRESS=	Yes

.include <bsd.port.mk>
