# $OpenBSD$
COMMENT=	enhanced talk that allows for multiple parties

DISTNAME=	ytalk-3.1.1
REVISION=	1
CATEGORIES=	net

MASTER_SITES=	http://www.iagora.com/~espel/ytalk/ \
		ftp://quatramaran.ens.fr/pub/orabidoo/ytalk/

HOMEPAGE=	http://www.iagora.com/~espel/ytalk/ytalk.html

MAINTAINER=	Marc Espie <espie@openbsd.org>

PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes
WANTLIB=		c ncurses 

CONFIGURE_STYLE= gnu dest
USE_GROFF =	Yes

FLAVORS=	no_x11
FLAVOR?=

.if ${FLAVOR:L:Mno_x11}
CONFIGURE_ARGS+= --without-x
.else
WANTLIB+=	ICE SM X11 pthread-stubs xcb
.endif

NO_REGRESS=	Yes

INSTALL_TARGET=	install.bin install.man

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/ytalk
	${INSTALL_DATA} ${WRKBUILD}/ytalkrc ${PREFIX}/share/examples/ytalk/ytalkrc-sample

.include <bsd.port.mk>
