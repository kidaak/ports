# $OpenBSD$

COMMENT=		neat theme manager for Window Maker

DISTNAME=		wmthemeinstall-0.62
CATEGORIES=		x11 x11/windowmaker

REVISION=		1

MAINTAINER=		Peter Stromberg <wilfried@openbsd.org>

# GPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB=		X11 Xext Xi c glib gmodule gdk m z gtk

MODULES=		devel/gettext

RUN_DEPENDS=		x11/windowmaker
LIB_DEPENDS=		x11/gtk+

SEPARATE_BUILD=		Yes
USE_GMAKE=		Yes
NO_REGRESS=		Yes
CONFIGURE_STYLE=	gnu

pre-build:
	@perl -pi -e "s:/usr/local:${PREFIX}:g" ${WRKSRC}/wmOptions.c

do-install:
	${INSTALL_PROGRAM} ${WRKBUILD}/wmthemeinstall ${PREFIX}/bin

.include <bsd.port.mk>
