# $OpenBSD$

COMMENT=	GNU privacy guard - a free PGP replacement

DISTNAME=	gnupg-1.4.11
CATEGORIES=	security
REVISION=	2

# restrict, not compatible with gnupg-2.
PKGSPEC =	gnupg-<2

MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/gnupg/ \
		ftp://gd.tuwien.ac.at/privacy/gnupg/gnupg/ \
		ftp://crypto.yashy.com/pub/cryptography/gnupg/ \
		ftp://ftp.planetmirror.com/pub/gnupg/gnupg/ \
		ftp://sunsite.dk/pub/security/gcrypt/gnupg/ \
		ftp://ftp.linux.it/pub/mirrors/gnupg/gnupg/ \
		ftp://pgp.iijlab.net/pub/pgp/gnupg/ \
		ftp://ring.aist.go.jp/pub/net/gnupg/gnupg/

MASTER_SITES0=	ftp://ftp.gnupg.dk/contrib-dk/

DISTFILES=	${DISTNAME}${EXTRACT_SUFX} idea.c.gz:0

HOMEPAGE=	http://www.gnupg.org/

# GPLv3
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MODULES= devel/gettext
LIB_DEPENDS=	archivers/bzip2 \
		net/curl
WANTLIB=	c z readline termcap ssl crypto idn bz2>=10 curl>=3

CONFIGURE_STYLE= autoconf
AUTOCONF_VERSION= 2.64
MODGNU_CONFIG_GUESS_DIRS=${WRKSRC}/scripts
CONFIGURE_ARGS+= --disable-gnupg-iconv
USE_GROFF =	Yes
.if ${MACHINE_ARCH} == "m68k"
CONFIGURE_ARGS+= --disable-asm
.endif
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
MAKE_FLAGS=	LIBINTL="-L${LOCALBASE}/lib -lintl -liconv" \
		LIBICONV="-L${LOCALBASE}/lib -liconv"

FLAVORS=	card ldap
FLAVOR?=

.if ${FLAVOR:L:Mcard}
LIB_DEPENDS+=		devel/libusb-compat
WANTLIB +=		usb pthread
.else
CONFIGURE_ARGS+=	--disable-card-support --without-libusb
.endif

.if ${FLAVOR:L:Mldap}
CONFIGURE_ARGS+=	--enable-ldap
LIB_DEPENDS+=		databases/openldap
WANTLIB +=		ldap>=8
.else
CONFIGURE_ARGS+=	--disable-ldap
.endif


GNUPGDOCFILES=	README AUTHORS COPYING THANKS TODO BUGS \
		doc/DETAILS doc/FAQ doc/OpenPGP doc/HACKING

post-extract:
	ln -s ${WRKDIR}/idea.c ${WRKSRC}/cipher/idea.c

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gnupg
	cd ${WRKSRC}; ${INSTALL_DATA} ${GNUPGDOCFILES} \
		${PREFIX}/share/doc/gnupg

do-regress:
	@cd ${WRKSRC}/checks && ${MAKE_PROGRAM} check

.include <bsd.port.mk>
