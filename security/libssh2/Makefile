# $OpenBSD$

COMMENT =		library implementing the SSH2 protocol

DISTNAME =		libssh2-1.3.0
CATEGORIES =		security
SHARED_LIBS +=		ssh2	5.1	# .1.1

HOMEPAGE =              http://www.libssh2.org/

MAINTAINER =		Benoit Lecocq <benoit@openbsd.org>

# libssh2: BSD License
# libssh2 Documentation: Open Publication License 
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

WANTLIB =		crypto ssl z

MASTER_SITES =		http://www.libssh2.org/download/

CONFIGURE_STYLE =	gnu
USE_LIBTOOL =		Yes
USE_GROFF =		Yes

# The second test will only pass if public key auth is configured for ${USER}
REGRESS_IS_INTERACTIVE = Yes
REGRESS_FLAGS="USER=${USER}"

.include <bsd.port.mk>
