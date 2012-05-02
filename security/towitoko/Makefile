# $OpenBSD: ports/security/towitoko/Makefile,v 1.9 2011/01/14 22:50:56 jasper Exp $

COMMENT=		library and utilities for towitoko card readers

DISTNAME=		towitoko-2.0.7
REVISION =		1
CATEGORIES=		security
SHARED_LIBS=		towitoko	2.0
MODGNU_SHARED_LIBS=	towitoko	'-module'

HOMEPAGE=		http://www.geocities.com/cprados/

# LGPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=	Yes
WANTLIB=		c pthread

MASTER_SITES=		http://www.geocities.com/cprados/files/

USE_LIBTOOL=		Yes
USE_GROFF =		Yes

CONFIGURE_STYLE=	gnu
CONFIGURE_ARGS+=	${CONFIGURE_SHARED}	\
			--enable-static

EXAMPLES=		doc/reader.conf

post-install:
	@perl -pi -e "s,%%PREFIX%%,${TRUEPREFIX}," ${WRKSRC}/doc/reader.conf
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/towitoko
	cd ${WRKSRC} && ${INSTALL_DATA} ${EXAMPLES} \
	  ${PREFIX}/share/examples/towitoko

.include <bsd.port.mk>