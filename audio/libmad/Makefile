# $OpenBSD$

COMMENT=	high-quality MPEG audio decoder

DISTNAME=	libmad-0.15.1b
REVISION=	3
CATEGORIES=	audio
HOMEPAGE=	http://www.underbit.com/products/mad/
SHARED_LIBS +=	mad                  2.1      # .2.1

MAINTAINER=	Christian Weisgerber <naddy@openbsd.org>

# GPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=	ftp://ftp.mars.org/pub/mpeg/ \
		${MASTER_SITE_SOURCEFORGE:=mad/}

USE_LIBTOOL=	Yes
SEPARATE_BUILD=	Yes
CONFIGURE_STYLE=gnu
CONFIGURE_ARGS=	${CONFIGURE_SHARED}

post-patch:
	@cp ${FILESDIR}/mad.pc.in ${WRKSRC}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/pkgconfig
	${INSTALL_DATA} ${WRKBUILD}/mad.pc ${PREFIX}/lib/pkgconfig

.include <bsd.port.mk>
