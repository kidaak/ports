# $OpenBSD$

COMMENT = 	library to secure any kind of communication streams

DISTNAME = 	libperseus-1.0.2
CATEGORIES = 	security

SHARED_LIBS = 	perseus 0.0	

MASTER_SITES = 	${HOMEPAGE}/files/

HOMEPAGE = 	http://libperseus.googlecode.com/

MAINTAINER = 	Pierre-Emmanuel Andre <pea@openbsd.org>

# GPL/LGPL/MPL
PERMIT_PACKAGE_CDROM = 	Yes
PERMIT_PACKAGE_FTP = 	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP = 	Yes

WANTLIB = 	c m

EXTRACT_SUFX = 	.tgz

USE_LIBTOOL = 	Yes

WRKDIST = 	${WRKDIR}

CFLAGS += 	-fPIC

do-regress:
	@cd ${WRKBUILD} && ./perseus_test2

do-install:
	${INSTALL_DATA} ${WRKBUILD}/perseus.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKBUILD}/${FULLPKGNAME}.so ${PREFIX}/lib/libperseus.so.${LIBperseus_VERSION}
	${INSTALL_PROGRAM} ${WRKBUILD}/perseus_test ${PREFIX}/bin

.include <bsd.port.mk>
