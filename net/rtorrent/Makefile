# $OpenBSD$

BROKEN-hppa =		undefined references to __sync atomic ops

COMMENT=		ncurses BitTorrent client based on libTorrent

DISTNAME=		rtorrent-0.8.9
EPOCH=			0
CATEGORIES=		net

HOMEPAGE=		http://libtorrent.rakshasa.no/

MAINTAINER=		David Coppa <dcoppa@openbsd.org>

# GPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB=		c crypto curl>=14 idn m ncursesw \
			pthread sigc-2.0 ssl stdc++ \
			torrent>=20 z

MASTER_SITES=		${HOMEPAGE}downloads/

MODULES=		gcc4 devel/gettext

# SIGBUS during startup on sparc64 when built using gcc 4.2.1
# https://github.com/rakshasa/rtorrent/issues/28
MODGCC4_ARCHS=		sparc64
MODGCC4_LANGS=		c++
MODGCC4_VERSION=	4.6

BUILD_DEPENDS=		devel/cppunit
LIB_DEPENDS=		net/libtorrent>=0.12.9 \
			net/curl

USE_LIBTOOL=		Yes
CONFIGURE_STYLE=	gnu
CONFIGURE_ENV +=	LDFLAGS=-pthread
CONFIGURE_ARGS=		${CONFIGURE_SHARED} \
			--disable-debug

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/rtorrent
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/rtorrent
	${INSTALL_DATA} ${WRKSRC}/doc/rtorrent.rc \
		${PREFIX}/share/examples/rtorrent/rtorrent.rc
	${INSTALL_MAN} ${WRKSRC}/doc/rtorrent.1 \
		${PREFIX}/man/man1/rtorrent.1

.include <bsd.port.mk>
