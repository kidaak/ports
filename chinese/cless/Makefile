# New ports collection makefile for:    cless
# Version required:     2.90
# Date created:         Thu Jan 18, 2000
# Whom:                 Kevin Lo <kevlo@openbsd.org>
#
# $OpenBSD$
#

COMMENT=	pager utility that speaks Chinese

DISTNAME=       cless-290
PKGNAME=        zh-${DISTNAME}
CATEGORIES=     chinese misc
MASTER_SITES=   ftp://ftp.cuhk.hk/pub/chinese/ifcss/software/unix/c-utils/ 

MAINTAINER=     Kevin Lo <kevlo@openbsd.org>

PERMIT_PACKAGE_CDROM=   Yes
PERMIT_PACKAGE_FTP=     Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=   Yes

WANTLIB=		c curses termcap

CONFIGURE_STYLE= gnu dest old
CFLAGS+=        -DHANZI # LDFLAGS=-s datadir=/usr/local/lib/less
USE_GROFF =	Yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.CLESS ${PREFIX}/share/doc/cless 

.include <bsd.port.mk>
