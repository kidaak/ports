# $OpenBSD$

COMMENT = 	X.509 library

DISTNAME = 	libksba-1.2.0
CATEGORIES = 	security

SHARED_LIBS = 	ksba 0.2	#19

MASTER_SITES = 	ftp://ftp.gnupg.org/gcrypt/libksba/ 

HOMEPAGE = 	http://www.gnupg.org/related_software/libksba

MAINTAINER = 	Pierre-Emmanuel Andre <pea@openbsd.org>

# GPLv3
PERMIT_PACKAGE_CDROM = 	Yes
PERMIT_PACKAGE_FTP = 	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP = 	Yes

EXTRACT_SUFX = 		.tar.bz2

USE_LIBTOOL = 		Yes
MODULES = 		devel/gettext

LIB_DEPENDS = 		security/libgpg-error
WANTLIB =		gpg-error>=1

CONFIGURE_STYLE = 	gnu
CONFIGURE_ARGS =	${CONFIGURE_SHARED}

.include <bsd.port.mk>
