# $OpenBSD$

COMMENT=	tty-based e-mail client, development version

DISTNAME=	mutt-1.5.21
EPOCH=		0
REVISION=	0
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mutt/} \
		${MASTER_SITES_MUTT:=devel/}

WANTLIB=	qdbm>=14 z

FLAVORS=	idn sasl sidebar
FLAVOR?=

AUTOCONF_VERSION= 2.65
CONFIGURE_ARGS= --enable-hcache \
		--enable-smtp \
		--without-gdbm

LIB_DEPENDS=	databases/qdbm
BUILD_DEPENDS+=	textproc/docbook-xsl

.if ${FLAVOR:L:Msasl}
CONFIGURE_ARGS+= --with-sasl=${LOCALBASE}
LIB_DEPENDS+=	security/cyrus-sasl2
WANTLIB+=	sasl2
.endif

MUTTRCDIR=	doc/

DIST_COMPRESSED=compressed-5302767aa6aa.gz:2
DIST_SIDEBAR=	sidebar-5302767aa6aa.gz:2

.if ${FLAVOR:L:Msidebar}
PATCHFILES+=		${DIST_SIDEBAR}
PATCH_DIST_STRIP=	-p1
.else
SUPDISTFILES+=		${DIST_SIDEBAR}
.endif

AUTOMAKE_VERSION= 1.9
CONFIGURE_STYLE= gnu
USE_GROFF =	Yes
BUILD_DEPENDS+=	${MODGNU_AUTOCONF_DEPENDS} \
		${MODGNU_AUTOMAKE_DEPENDS}
post-patch:
	cd ${WRKSRC}; \
	    AUTOCONF_VERSION=${AUTOCONF_VERSION} \
	    AUTOMAKE_VERSION=${AUTOMAKE_VERSION} \
	    autoreconf --install

.include <bsd.port.mk>
