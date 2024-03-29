# $OpenBSD$

COMMENT=	client for Cisco AnyConnect SSL VPN

DISTNAME=	openconnect-4.07
DIST_SUBDIR=	openconnect
VPNC_SCRIPT=	vpnc-script
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${VPNC_SCRIPT}:0
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

SHARED_LIBS +=  openconnect               1.0 # 2.0

CATEGORIES=	net

HOMEPAGE=	http://www.infradead.org/openconnect/

MAINTAINER=	Stuart Henderson <sthen@openbsd.org>

# LGPLv2.1 only
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB += c gmp gnutls hogweed m nettle p11-kit proxy pthread
WANTLIB += stdc++ tasn1 xml2 z

MASTER_SITES=	ftp://ftp.infradead.org/pub/openconnect/
MASTER_SITES0=	http://git.infradead.org/users/dwmw2/vpnc-scripts.git/blob_plain/d19a327c74f824114c5c72101104891fe881a7da:/

# used to format html during build, USE_GROFF not needed
BUILD_DEPENDS=		textproc/groff
MODULES=		devel/gettext \
			lang/python
MODPY_RUNDEP=		No

LIB_DEPENDS=		security/gnutls \
			textproc/libxml \
			net/libproxy>=0.4.6p7
FAKE_FLAGS=		pkgdatadir=${PREFIX}/share/doc/openconnect

SEPARATE_BUILD=		Yes
USE_LIBTOOL=		Yes
CONFIGURE_STYLE=	gnu
CONFIGURE_ARGS=		--with-vpnc-script=${SYSCONFDIR}/openconnect/vpnc-script \
			--with-gnutls

post-extract:
	cp ${FULLDISTDIR}/${VPNC_SCRIPT} ${WRKSRC}/vpnc-script

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/openconnect/
	${INSTALL_SCRIPT} ${WRKSRC}/vpnc-script \
	    ${PREFIX}/share/examples/openconnect/

.include <bsd.port.mk>
