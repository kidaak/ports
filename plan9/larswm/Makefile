# $OpenBSD$

COMMENT=	9wm with automatic window tiling and virtual desktops

DISTNAME=	larswm-7.5.3
REVISION =	3
CATEGORIES=	plan9

HOMEPAGE =	http://larswm.sourceforge.net/
MASTER_SITES =	${MASTER_SITE_SOURCEFORGE:=larswm/} \
		http://spacehopper.org/mirrors/

MAINTAINER =	William Yodlowsky <william@openbsd.org>

# nonstandard license
PERMIT_PACKAGE_CDROM =	No
PERMIT_PACKAGE_FTP =	No
PERMIT_DISTFILES_CDROM = No
PERMIT_DISTFILES_FTP =	No

WANTLIB =	ICE SM X11 Xau Xdmcp Xext Xmu Xt c pthread-stubs xcb

CONFIGURE_STYLE=imake
USE_GROFF =	Yes
NO_REGRESS=	Yes

DOCS=   ChangeLog README README.9wm

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/larswm
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/larswm
	cd ${WRKSRC}; ${INSTALL_DATA} \
	    sample.larswmrc sample.xsession \
	    ${PREFIX}/share/examples/larswm
	cd ${WRKSRC}; ${INSTALL_DATA} ${DOCS} ${PREFIX}/share/doc/larswm

.include <bsd.port.mk>
