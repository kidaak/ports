# $OpenBSD$

FW_DRIVER=	bwi
FW_VER=		1.4
DISTNAME=	bwi-firmware-${FW_VER}
REVISION=	2

MAINTAINER=	Marcus Glocker <mglocker@openbsd.org>

HOMEPAGE=	http://www.nazgul.ch/bwi/

FIRMWARE=	airforce info

do-install:
.for i in ${FIRMWARE}
	 ${INSTALL_DATA} ${WRKSRC}/bwi-$i ${PREFIX}/firmware/bwi-$i
.endfor

.include <bsd.port.mk>
