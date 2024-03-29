# $OpenBSD$

SHARED_ONLY=		Yes

COMMENT=		C++ database API

DISTNAME=		deepfryed-dbicpp-v0.6.0
PKGNAME=		dbic++-0.6.0
REVISION =		2
CATEGORIES=		databases
HOMEPAGE=		https://github.com/deepfryed/dbicpp

SHARED_LIBS +=  dbdmysql                  2.0 # 1.0
SHARED_LIBS +=  dbdpg                     2.0 # 1.0
SHARED_LIBS +=  dbdsqlite3                1.0 # 1.0

# MIT
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

# port-lib-depends-check says that e2fs-uuid and pcrecpp are
# Extra, but they are used in a .a file that doesn't have a
# .so shared library equivalent.
WANTLIB =		e2fs-uuid m mysqlclient pcrecpp pq stdc++ sqlite3

MASTER_SITES=		http://distfiles.bsdfrog.org/

MODULES =		devel/cmake

LIB_DEPENDS=		mysql-client->=5:databases/mysql \
			postgresql-client->=8.4:databases/postgresql \
			devel/pcre \
			sysutils/e2fsprogs

CONFIGURE_ARGS+=	-DCMAKE_MYSQL_VERSION=${LIBdbdmysql_VERSION} \
			-DCMAKE_PG_VERSION=${LIBdbdpg_VERSION} \
			-DCMAKE_SQLITE3_VERSION=${LIBdbdsqlite3_VERSION}

WRKDIST=		${WRKDIR}/deepfryed-dbicpp

NO_REGRESS=		Yes

post-extract:
	mv ${WRKDIR}/deepfryed-dbicpp-* ${WRKDIR}/deepfryed-dbicpp

pre-configure:
	${SUBST_CMD} ${WRKSRC}/{inc/dbic++.h,src/dbic++.cc,pkgconfig/dbic++.pc}

.include <bsd.port.mk>
