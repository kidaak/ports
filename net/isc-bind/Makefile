# $OpenBSD$

COMMENT=	Berkeley Internet Name Daemon

V=		9.9.1-P3
RV=		9.9.1-P2
DISTNAME=	bind-$V
PKGNAME=	isc-bind-${V:S/-P/pl/}

SHARED_LIBS +=  bind9                     0.0 # 60.4
SHARED_LIBS +=  dns                       0.0 # 70.2
SHARED_LIBS +=  isc                       0.0 # 63.1
SHARED_LIBS +=  isccc                     0.0 # 60.0
SHARED_LIBS +=  isccfg                    0.0 # 62.0
SHARED_LIBS +=  lwres                     0.0 # 60.1

CATEGORIES=	net

HOMEPAGE=	http://www.isc.org/software/bind

# ISC
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB += c crypto m pthread xml2 z

MASTER_SITES=	${MASTER_SITE_ISC:=bind9/$V/}
MASTER_SITES0=	http://ss.vix.com/~vixie/

FLAVORS=	ratelimit
FLAVOR?=

.if ${FLAVOR:L:Mratelimit}
PATCHFILES+=	rl-${RV}.patch:0
.else
SUPDISTFILES+=	rl-${RV}.patch:0
.endif

MODULES=	converters/libiconv
LIB_DEPENDS=	textproc/libxml
SUBST_VARS=	LOCALSTATEDIR

SEPARATE_BUILD=	Yes
USE_LIBTOOL=	Yes
CONFIGURE_STYLE= gnu
CONFIGURE_ARGS=	${CONFIGURE_SHARED} \
		--enable-threads \
		--with-libtool

FAKE_FLAGS=	sysconfdir=${PREFIX}/share/examples/bind9

.include <bsd.port.mk>
