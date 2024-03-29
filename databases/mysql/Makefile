# $OpenBSD$

SHARED_ONLY=	Yes

COMMENT-main=	multithreaded SQL database (client)
COMMENT-server=	multithreaded SQL database (server)
COMMENT-tests=	multithreaded SQL database (regression test suite/benchmark)

VERSION=	5.1.65
DISTNAME=	mysql-${VERSION}
PKGNAME-main=	mysql-client-${VERSION}
PKGNAME-server=	mysql-server-${VERSION}
PKGNAME-tests= 	mysql-tests-${VERSION}
CATEGORIES=	databases
V=		MySQL-5.1
MASTER_SITES=	${MASTER_SITE_MYSQL:=Downloads/$V/}

SHARED_LIBS=	mysqlclient_r	21.0 \
		mysqlclient	21.0

HOMEPAGE=	http://www.mysql.com/

MAINTAINER=	Brad Smith <brad@comstyle.com>

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes
WANTLIB=		c m pthread

LOCALSTATEDIR=	${BASELOCALSTATEDIR}/mysql
SOCKET_DIR=	/var/run/mysql
SUBST_VARS=	SOCKET_DIR

MULTI_PACKAGES=		-main -server -tests

# Suggested flags for the C compiler, needed for
# high load servers otherwise MySQL will crash.
CXX=		${CC}
CXXFLAGS=	${CFLAGS} -felide-constructors -fno-exceptions -fno-rtti

VMEM_WARNING=	Yes

USE_LIBTOOL=	Yes
USE_GROFF=	Yes
CONFIGURE_STYLE= autoconf
AUTOCONF_VERSION= 2.63
CONFIGURE_ARGS+= ${CONFIGURE_SHARED}
CONFIGURE_ARGS+= --with-big-tables \
		 --with-comment='OpenBSD port: ${FULLPKGNAME-server}' \
		 --with-libwrap \
		 --with-low-memory \
		 --with-mysqld-user="_mysql" \
		 --with-plugins=max-no-ndb \
		 --with-ssl=/usr \
		 --with-unix-socket-path="${SOCKET_DIR}/mysql.sock" \
		 --without-docs \
		 --without-readline

.include <bsd.port.arch.mk>

.if ${PROPERTIES:Mgcc[34]}
CONFIGURE_ARGS+= --with-client-ldflags=-lsupc++ \
		 --with-mysqld-ldflags=-lsupc++
.endif

. if ${MACHINE_ARCH} == "i386"
CONFIGURE_ARGS+= --enable-assembler
.endif

RUN_DEPENDS-server=	${BASE_PKGPATH}>=5.1,<5.2 \
			databases/p5-DBD-mysql
LIB_DEPENDS-server=	${BASE_PKGPATH}>=5.1,<5.2

WANTLIB-server=		${WANTLIB} crypto mysqlclient ssl wrap z
WANTLIB-main=		${WANTLIB} crypto ncursesw readline ssl z
WANTLIB-tests=		${WANTLIB}

REGRESS_TARGET=		test-force

post-install:
	cd ${PREFIX}/lib && \
		ln -sf mysql/libmysqlclient.so.${LIBmysqlclient_VERSION} . && \
		ln -sf mysql/libmysqlclient_r.so.${LIBmysqlclient_r_VERSION} .
	${INSTALL_DATA} ${WRKSRC}/Docs/mysql.info ${PREFIX}/info

.include <bsd.port.mk>
