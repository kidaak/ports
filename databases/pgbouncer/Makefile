# $OpenBSD$

COMMENT = 	lightweight connection pooler for PostgreSQL

DISTNAME = 	pgbouncer-1.5.2

CATEGORIES = 	databases

HOMEPAGE = 	http://wiki.postgresql.org/wiki/PgBouncer

MAINTAINER = 	Pierre-Emmanuel Andre <pea@openbsd.org>

# BSD
PERMIT_PACKAGE_FTP = 	Yes
PERMIT_PACKAGE_CDROM = 	Yes
PERMIT_DISTFILES_FTP = 	Yes
PERMIT_DISTFILES_CDROM =Yes

WANTLIB = 	c event

MASTER_SITES = 	http://pgfoundry.org/frs/download.php/3293/

BUILD_DEPENDS =	devel/libeventextra

CONFIGURE_STYLE = 	gnu
#Disable the detection of asciidoc since docs are already included
CONFIGURE_ENV =         ASCIIDOC=' '
CONFIGURE_ARGS = 	--with-libevent=${LOCALBASE}
MAKE_FLAGS+=		V=1

USE_GMAKE = 		Yes
USE_GROFF =		Yes

# The actual regress tests are (cd ${WRKSRC}/test; ./test.sh)
# They want to create full postgres install and also play with 
# firewall (iptables)
NO_REGRESS = 		Yes

.include <bsd.port.mk>
