# $OpenBSD$

COMMENT=	PostIt (R) messages onto your X11 screen

DISTNAME=	xpostit3.3.1
PKGNAME=	xpostit-3.3.1
REVISION=	1
CATEGORIES=	x11

# Not all servers archie could find actually still have it.  Alas, some
# servers only have the comp.sources.x version, with its distfile named
# `part01.gz'.
#
MASTER_SITES=	${MASTER_SITE_R5CONTRIB}
EXTRACT_SUFX=	.tar.Z

# BSD
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB=	ICE SM X11 Xau Xaw Xdmcp Xext Xmu Xpm Xt c

USE_GROFF =	Yes
CONFIGURE_STYLE=	imake
WRKDIST=	${WRKDIR}/xpostit

NO_REGRESS=	Yes

.include <bsd.port.mk>
