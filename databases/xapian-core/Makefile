# $OpenBSD$

COMMENT=	search engine library

V=		1.2.8
DISTNAME=	xapian-core-${V}

SHARED_LIBS +=  xapian               3.0      # .23.2

CATEGORIES=	databases textproc

HOMEPAGE=	http://xapian.org/

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB += c m stdc++ z e2fs-uuid

MASTER_SITES=	http://oligarchy.co.uk/xapian/${V}/

USE_LIBTOOL=	Yes
USE_GROFF =	Yes

# needs uuid_generate(3) which devel/uuid does not provide
LIB_DEPENDS=	sysutils/e2fsprogs

CONFIGURE_STYLE= gnu
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	${CONFIGURE_SHARED} \
		--disable-sse

pre-configure:
	perl -pi -e "s,for ac_lib in '' uuid,for ac_lib in '' e2fs-uuid," \
		${WRKSRC}/configure

.include <bsd.port.mk>
