# $OpenBSD$

SHARED_ONLY=	Yes

COMMENT=	LIVE555 streaming media library

DISTNAME=	live.2012.02.04
PKGNAME=	liveMedia-20120204
REVISION=	0
CATEGORIES=	net devel
MASTER_SITES=	http://comstyle.com/source/

HOMEPAGE=	http://www.live555.com/liveMedia/

# LGPLv2.1+
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB=	c m stdc++

CONFIGURE_STYLE=simple
CONFIGURE_SCRIPT=genMakefiles
CONFIGURE_ARGS=	fixed-openbsd

WRKDIST=	${WRKDIR}/live

NO_REGRESS=	Yes

CFLAGS+=	-fPIC -DXLOCALE_NOT_USED

post-extract:
	@cp -f ${FILESDIR}/config.fixed-openbsd ${WRKSRC}/

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/live
	${INSTALL_DATA_DIR} ${PREFIX}/live/groupsock
	${INSTALL_DATA_DIR} ${PREFIX}/live/liveMedia
	${INSTALL_DATA_DIR} ${PREFIX}/live/UsageEnvironment
	${INSTALL_DATA_DIR} ${PREFIX}/live/BasicUsageEnvironment
	${INSTALL_DATA_DIR} ${PREFIX}/live/groupsock/include
	${INSTALL_DATA_DIR} ${PREFIX}/live/liveMedia/include
	${INSTALL_DATA_DIR} ${PREFIX}/live/UsageEnvironment/include
	${INSTALL_DATA_DIR} ${PREFIX}/live/BasicUsageEnvironment/include
	${INSTALL_PROGRAM} ${WRKSRC}/testProgs/playSIP ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/testProgs/openRTSP ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/testProgs/sapWatch ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/BasicUsageEnvironment/libBasicUsageEnvironment.a \
	    ${PREFIX}/live/BasicUsageEnvironment/
	ln -sf libBasicUsageEnvironment.a \
	    ${PREFIX}/live/BasicUsageEnvironment/libBasicUsageEnvironment_pic.a
	${INSTALL_DATA} ${WRKSRC}/UsageEnvironment/libUsageEnvironment.a \
	    ${PREFIX}/live/UsageEnvironment/
	ln -sf libUsageEnvironment.a \
	    ${PREFIX}/live/UsageEnvironment/libUsageEnvironment_pic.a
	${INSTALL_DATA} ${WRKSRC}/groupsock/libgroupsock.a \
	    ${PREFIX}/live/groupsock/
	ln -sf libgroupsock.a \
	    ${PREFIX}/live/groupsock/libgroupsock_pic.a
	${INSTALL_DATA} ${WRKSRC}/liveMedia/libliveMedia.a \
	    ${PREFIX}/live/liveMedia/
	ln -sf libliveMedia.a \
	    ${PREFIX}/live/liveMedia/libliveMedia_pic.a
	cd ${WRKSRC}/BasicUsageEnvironment/include && \
	    ${INSTALL_DATA} *.hh ${PREFIX}/live/BasicUsageEnvironment/include/
	cd ${WRKSRC}/UsageEnvironment/include && \
	    ${INSTALL_DATA} *.hh ${PREFIX}/live/UsageEnvironment/include/
	cd ${WRKSRC}/groupsock/include && \
	    ${INSTALL_DATA} *.h *.hh ${PREFIX}/live/groupsock/include/
	cd ${WRKSRC}/liveMedia/include && \
	    ${INSTALL_DATA} *.hh ${PREFIX}/live/liveMedia/include/

.include <bsd.port.mk>
