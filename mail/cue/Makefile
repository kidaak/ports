# $OpenBSD$

COMMENT=	mh-e like mail user agent

V=		20090209
DISTNAME=	cue-snap-$V
PKGNAME=	cue-$V
CATEGORIES=	mail

MASTER_SITES=	ftp://sh.wide.ad.jp/WIDE/free-ware/cue/snap/

# BSD
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB=	c crypto z

AUTOCONF_VERSION=	2.13
CONFIGURE_STYLE=	autoconf no-autoheader
CONFIGURE_ARGS=		--enable-ipv6 \
			--without-canna \
			--with-openssl=/usr \
			--disable-pgpmime

MAKE_FLAGS=		CC='${CC}'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cue ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/cue
	${INSTALL_DATA} ${WRKSRC}/sample.cuerc ${PREFIX}/share/examples/cue
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/cue
	${INSTALL_DATA} ${WRKSRC}/cue.hlp  ${PREFIX}/share/doc/cue

NO_REGRESS=		Yes

.include <bsd.port.mk>
