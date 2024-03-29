# $OpenBSD$

COMMENT=	administration and development platform for PostgreSQL

V=		1.14.0
DISTNAME=	pgadmin3-$V
CATEGORIES=	databases devel

HOMEPAGE=	http://www.pgadmin.org/

MAINTAINER=	Pierre-Emmanuel Andre <pea@openbsd.org>

# Artistic license
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MODULES=	converters/libiconv

WANTLIB=	c m pthread stdc++ z

MASTER_SITES=	ftp://ftp2.uk.postgresql.org/sites/ftp.postgresql.org/pgadmin3/release/v$V/src/ \
    ftp://ftp5.us.postgresql.org/pub/PostgreSQL/pgadmin3/release/v$V/src/ \
    ftp://ftp5.es.postgresql.org/mirror/postgresql/pgadmin3/release/v$V/src/ \
    ftp://ftp.postgresql.org/pub/pgadmin3/release/v$V/src/

LIB_DEPENDS=	x11/wxWidgets>=2.8.7 \
		databases/postgresql \
		textproc/libxml>=2.4.8 \
		textproc/libxslt
WANTLIB +=      wx_base_xml wx_base_odbc wx_gtk2_html wx_gtk2_richtext \
		wx_gtk2_stc wx_gtk2_ogl wx_gtk2_adv wx_gtk2_aui wx_gtk2_xrc \
		wx_base_net wx_gtk2_dbgrid wx_gtk2_qa wx_base wx_gtk2_core \
		pq>=4 xml2>=6 xslt>=3

BUILD_DEPENDS +=	databases/postgresql,-server

CONFIGURE_STYLE=gnu
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS}"
CONFIGURE_ARGS=	--with-pgsql=${LOCALBASE} 

USE_GMAKE=	Yes

.include <bsd.port.mk>
