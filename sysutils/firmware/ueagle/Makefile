# $OpenBSD$

FW_DRIVER=	ueagle
FW_VER=		1.0
REVISION=	1

WRKDIST=	${WRKDIR}
EXTRACT_SUFX=	.tgz

do-install:
	${INSTALL_DATA} ${WRKSRC}/ueagle-dsp ${PREFIX}/firmware/
	${INSTALL_DATA} ${WRKSRC}/ueagleI ${PREFIX}/firmware/
	${INSTALL_DATA} ${WRKSRC}/ueagleII ${PREFIX}/firmware/
	${INSTALL_DATA} ${WRKSRC}/ueagleIII ${PREFIX}/firmware/

.include <bsd.port.mk>
