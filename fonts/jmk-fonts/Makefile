# $OpenBSD$

COMMENT=		nice fixed width fonts, easy on the eye

V=			3.0
DISTNAME=		jmk-x11-fonts-${V}
PKGNAME=		jmk-fonts-${V}
REVISION=		2

CATEGORIES=		fonts x11

HOMEPAGE=		http://www.jmknoble.net/fonts/

MAINTAINER=		Jon Olsson <jon@abc.se>

# GPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=		${HOMEPAGE}

CONFIGURE_STYLE=	imake


NO_REGRESS=		Yes

post-install:
	cd ${PREFIX}/lib/X11/fonts/jmk && mv fonts.alias fonts.alias-jmk

.include <bsd.port.mk>
