# $OpenBSD$

SHARED_ONLY=	Yes
COMMENT=	G.729a voice codec for Asterisk
DISTNAME=	asterisk-g72x-1.1-beta4
PKGNAME=	asterisk-g729-1.1beta4
EXTRACT_SUFX=	.tar.bz2
CATEGORIES=	telephony
MASTER_SITES=	http://asterisk.hosting.lv/src/

HOMEPAGE=	http://asterisk.hosting.lv/

# GPL frontend to patented algorithm; free to use for non-commercial purposes
PERMIT_DISTFILES_CDROM=	contains non-compiled proprietary Intel code
PERMIT_DISTFILES_FTP=	contains non-compiled proprietary Intel code
PERMIT_PACKAGE_CDROM=	patents
PERMIT_PACKAGE_FTP=	Yes

WANTLIB += c

NO_REGRESS=	Yes

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	telephony/asterisk>=10.0,<=11.0
CONFIGURE_STYLE=gnu
CONFIGURE_ARGS+=--with-asterisk100 \
		--with-asterisk-includes=${LOCALBASE}/include \
		--with-itu

.include <bsd.port.mk>
