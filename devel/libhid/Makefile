# $OpenBSD$

COMMENT =	user-space USB HID access library written in C

DISTNAME =	libhid-0.2.16
REVISION =	0

SHARED_LIBS =	hid	0.0

CATEGORIES =	devel

HOMEPAGE =	http://libhid.alioth.debian.org/

MAINTAINER =	Jonathan Armani <armani@openbsd.org>

# GPLv2
PERMIT_PACKAGE_CDROM=   Yes
PERMIT_PACKAGE_FTP=     Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=   Yes

MASTER_SITES=	https://alioth.debian.org/frs/download.php/1958/

WANTLIB += 	c usb pthread usb-1.0

LIB_DEPENDS = 	devel/libusb-compat

USE_GMAKE = 		Yes
USE_LIBTOOL =		Yes
USE_GROFF =		Yes
SEPARATE_BUILD =	Yes
CONFIGURE_STYLE = 	gnu
CONFIGURE_ARGS +=	--disable-swig

.include <bsd.port.mk>
