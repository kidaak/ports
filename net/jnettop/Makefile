# $OpenBSD$

COMMENT=	capture network traffic, display streams sorted by bandwidth

DISTNAME=	jnettop-0.13.0
REVISION=	1

CATEGORIES=	net

HOMEPAGE=	http://jnettop.kubs.info/

MAINTAINER=	Stuart Henderson <sthen@openbsd.org>

# GPLv2+
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB += c glib-2.0 gthread-2.0 ncurses pcap pthread

MASTER_SITES=	${HOMEPAGE}dist/

MODULES+=	devel/gettext
LIB_DEPENDS=	devel/glib2

MAKE_FLAGS=	CFLAGS="${CFLAGS}"

SEPARATE_BUILD=	Yes
CONFIGURE_STYLE= gnu

post-install:
	${SUBST_CMD} ${PREFIX}/man/man8/jnettop.8
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/jnettop
	${INSTALL_DATA} ${WRKSRC}/README* ${PREFIX}/share/doc/jnettop/
	${SUBST_CMD} -o ${SHAREOWN} -g ${SHAREGRP} -c ${WRKSRC}/.jnettop \
	    ${PREFIX}/share/doc/jnettop/dot.jnettop

.include <bsd.port.mk>
