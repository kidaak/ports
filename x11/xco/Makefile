# $OpenBSD$

COMMENT=	display X11 color names and colors

DISTNAME=	xco
PKGNAME=	xco-1.3
REVISION=	0
CATEGORIES=	x11

MASTER_SITES=	ftp://ftp.cs.purdue.edu/pub/bingle/

# BSD-like, but "may not modify"
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB=	X11 Xau Xdmcp Xext c

USE_GROFF =	Yes
CONFIGURE_STYLE=	imake

NO_REGRESS=	Yes

post-install:
		${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xco
		${INSTALL_DATA} ${FILESDIR}/copyright ${PREFIX}/share/doc/xco

.include <bsd.port.mk>
