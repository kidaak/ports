# $OpenBSD$

COMMENT =	Mozilla mobile web browser

MOZILLA_VERSION =	10.0.5esr
MOZILLA_BRANCH =	esr10
MOZILLA_PROJECT =	fennec
MOZILLA_CODENAME =	mobile
PKGNAME =	${MOZILLA_PROJECT}-${MOZILLA_VERSION:S/esr//}
REVISION =	2

SO_VERSION =	6.0
# NOTE: Must bump minor version if any shlib's are removed from the
# components dir to avoid pkg_add -r issues.
MOZILLA_LIBS =	mozalloc xpcom xul

CATEGORIES =	www

# mozilla public license
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES =	http://releases.mozilla.org/pub/mozilla.org/mobile/releases/${MOZILLA_VERSION}/source/ \
		https://ftp.mozilla.org/pub/mozilla.org/mobile/releases/${MOZILLA_VERSION}/source/ \
		ftp://ftp.mozilla.org/pub/mozilla.org/mobile/releases/${MOZILLA_VERSION}/source/
HOMEPAGE =	http://www.mozilla.com/en-US/mobile/

# lots of logic in mozilla.port.mk
MODULES =	www/mozilla devel/gettext lang/python

MODPY_RUNDEP =	No

# Regression tests are too hard to adapt to run here
NO_REGRESS =	Yes

CONFIGURE_STYLE =	autoconf no-autoheader
CONFIGURE_ARGS +=	--enable-official-branding
CONFIGURE_ARGS +=	--disable-gconf
CONFIGURE_ARGS +=	--with-system-libevent=/usr/
CONFIGURE_ARGS +=	--with-system-zlib=/usr/ --with-system-bz2=${LOCALBASE}
WANTLIB +=	event

.if ${MACHINE_ARCH:Msparc64}
CONFIGURE_ARGS +=	--disable-tracejit --disable-methodjit
.endif

# ensure we depend on cairo with tee backend enabled
LIB_DEPENDS =	graphics/cairo>=1.10.2p0
# --with-system-png=${LOCALBASE}
# no system png : apng support not bundled in

MOZILLA_AUTOCONF_DIRS +=	js/src
MOZILLA_SUBST_FILES +=		config/autoconf.mk.in services/crypto/modules/WeaveCrypto.js

SUBST_VARS +=	MOZILLA_VERSION NSS_SO_VERSION

# package target uses gtar options
BUILD_DEPENDS +=	archivers/gtar
INSTALL_TARGET =	package

# unzip used during install
BUILD_DEPENDS +=	archivers/unzip

post-configure:
	rm -f ${WRKSRC}/services/crypto/modules/WeaveCrypto.js.{orig,beforesubst}

post-install:
	cd ${WRKSRC} && tar -C ${PREFIX}/lib/ -xjf dist/fennec*.tar.bz2
	mv ${PREFIX}/lib/${MOZILLA_PROJECT}{,-${MOZILLA_VERSION}}/
	echo '#!/bin/sh\ncd ${TRUEPREFIX}/lib/${MOZILLA_PROJECT}-${MOZILLA_VERSION} ; LD_LIBRARY_PATH=. ./fennec "$$@"' \
		 > ${PREFIX}/bin/fennec
	chmod +x ${PREFIX}/bin/fennec
	${INSTALL_DATA} ${WRKSRC}/mobile/branding/nightly/content/fennec_72x72.png \
		${PREFIX}/lib/${MOZILLA_PROJECT}-${MOZILLA_VERSION}/fennec_icon.png
	# install desktop file
	${INSTALL_DATA_DIR} ${PREFIX}/share/applications/ ; \
	${SUBST_CMD} -o ${SHAREOWN} -g ${SHAREGRP} -c ${FILESDIR}/${MOZILLA_PROJECT}.desktop \
		${PREFIX}/share/applications/${MOZILLA_PROJECT}.desktop ; \

.include <bsd.port.mk>
