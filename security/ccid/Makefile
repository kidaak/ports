# $OpenBSD$

SHARED_ONLY =	Yes

COMMENT =	USB Chip/Smart Card Interface Devices driver

DISTNAME =	ccid-1.4.7

CATEGORIES =	security

HOMEPAGE =	http://pcsclite.alioth.debian.org/ccid.html

MASTER_SITES =	https://alioth.debian.org/frs/download.php/3730/

EXTRACT_SUFX =	.tar.bz2

MAINTAINER =	David Coppa <dcoppa@openbsd.org>

# LGPLv2.1+ and GPLv2+
PERMIT_PACKAGE_CDROM=   Yes
PERMIT_PACKAGE_FTP=     Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=   Yes

WANTLIB =	pcsclite usb-1.0

LIB_DEPENDS =	devel/libusb1 \
		security/pcsc-lite>=1.8.3

USE_LIBTOOL =	Yes

CONFIGURE_STYLE = gnu

CONFIGURE_ARGS = --enable-twinserial

CONFIGURE_ENV =	ac_cv_lib_lex='none needed'

NO_REGRESS =	Yes

.include <bsd.port.mk>
