# $OpenBSD$

COMMENT=		wm-dockapp; xeyes clone using South Park characters

DISTNAME=		speyes-1.2.0
REVISION =		1
CATEGORIES=		games x11 x11/windowmaker

HOMEPAGE=		http://www.okb-1.org/speyes/speyes.html

MAINTAINER=		Peter Stromberg <wilfried@openbsd.org>

# GPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB=		ICE SM X11 Xau Xdmcp Xext Xmu Xpm Xt c m \
			pthread-stubs xcb

MASTER_SITES=		http://www.okb-1.org/speyes/

NO_REGRESS=		Yes
CONFIGURE_STYLE=	imake noman

.include <bsd.port.mk>
