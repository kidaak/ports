# $OpenBSD$

COMMENT-main=	scan ports and fingerprint stack of network hosts
COMMENT-zenmap=	graphical frontend for nmap

MODPY_EGG_VERSION=	6.01
DISTNAME=		nmap-${MODPY_EGG_VERSION}
PKGNAME-main=		${DISTNAME}
PKGNAME-zenmap=		nmap-zenmap-${MODPY_EGG_VERSION}

REVISION-main=	0
REVISION-zenmap=0

CATEGORIES=	net security
MASTER_SITES=	http://nmap.org/dist/
EXTRACT_SUFX=	.tgz

HOMEPAGE=	http://www.nmap.org/

MAINTAINER=	Giovanni Bechis <giovanni@openbsd.org>

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MULTI_PACKAGES=	-main -zenmap

USE_GMAKE=	yes
MODULES=	lang/python \
		lang/lua

CONFIGURE_STYLE=gnu
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		CXXFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-libpcap=/usr \
		--with-openssl=/usr \
		--with-liblua=${LOCALBASE} \
		--with-libpcre=${LOCALBASE} \
		--with-mandir=${LOCALBASE}/man \
		--without-nmap-update \
		--disable-nls

WANTLIB-main=		c crypto m pcap ssl stdc++ pcre pthread ${MODLUA_WANTLIB}
LIB_DEPENDS-main=	devel/pcre \
			${MODLUA_LIB_DEPENDS}

RUN_DEPENDS-main=

RUN_DEPENDS-zenmap=	x11/py-gtk2 \
			databases/py-sqlite2 \
			devel/desktop-file-utils \
			net/nmap

NO_REGRESS=		Yes

post-extract:
	@cd ${WRKSRC} && rm -rf libpcap/ liblua/ libpcre/

pre-configure:
	${SUBST_CMD} ${WRKSRC}/zenmap/install_scripts/unix/su-to-zenmap.sh \
		${WRKSRC}/zenmap/install_scripts/unix/zenmap.desktop \
		${WRKSRC}/zenmap/install_scripts/unix/zenmap-root.desktop

.include <bsd.port.mk>
