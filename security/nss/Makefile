# $OpenBSD$

SHARED_ONLY=		Yes

COMMENT=		libraries to support development of security-enabled apps

VERSION=		3.13.6
DISTNAME=		nss-${VERSION}
SO_VERSION=		31.0
.for _lib in freebl3 nss3 nssckbi nssdbm3 nssutil3 smime3 softokn3 ssl3
SHARED_LIBS+=		${_lib} ${SO_VERSION}
.endfor
CATEGORIES=		security

HOMEPAGE=		http://www.mozilla.org/projects/security/pki/nss/

MAINTAINER=		Martynas Venckus <martynas@openbsd.org>

# mozilla public license
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes
WANTLIB += c pthread z nspr4 plc4 plds4 sqlite3

#for regular releases
MASTER_SITES=		http://ftp.eu.mozilla.org/pub/mozilla.org/security/nss/releases/${DISTNAME:U:C/[-.]/_/g}_RTM/src/ \
			http://ftp.mozilla.org/pub/mozilla.org/security/nss/releases/${DISTNAME:U:C/[-.]/_/g}_RTM/src/

LIB_DEPENDS=		devel/nspr>=4.9

MAKE_ENV=		BUILD_OPT=1 \
			LOCALBASE="${LOCALBASE}" \
			NSS_ENABLE_ECC=1 \
			NSS_USE_SYSTEM_SQLITE=1 \
			SO_VERSION="${SO_VERSION}" \
			XCFLAGS="-I${LOCALBASE}/include ${CFLAGS}" \
			NSPR_INCLUDE_DIR="${LOCALBASE}/include/nspr" \
			NSPR_LIB_DIR="${LOCALBASE}/lib"

USE_GMAKE=		Yes

WRKSRC=			${WRKDIST}/mozilla/security/nss
NSSDIST=		${WRKDIST}/mozilla/dist
NSSOBJ=			${NSSDIST}/OpenBSD`uname -r`${OBJ64}_OPT.OBJ

ALL_TARGET=		nss_build_all

# Don't forget to sync these with http://wiki.mozilla.org/NSS:ToolsToShip
MAIN_TOOLS=		certutil modutil pk12util signtool ssltap crlutil \
			cmsutil signver

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/nss
	${INSTALL_DATA_DIR} ${PREFIX}/lib/pkgconfig
	${INSTALL_DATA} ${NSSDIST}/public/nss/*.{h,api} ${PREFIX}/include/nss/
	${INSTALL_DATA} ${NSSOBJ}/lib/*.so.${SO_VERSION} ${PREFIX}/lib/
	${INSTALL_DATA} ${NSSOBJ}/lib/{libcrmf.a,*.chk} ${PREFIX}/lib/
	cd ${NSSOBJ}/bin && ${INSTALL_PROGRAM} ${MAIN_TOOLS} ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${FILESDIR}/nss-config ${PREFIX}/bin/
	${INSTALL_DATA} ${FILESDIR}/nss.pc ${PREFIX}/lib/pkgconfig/
	@perl -pi -e 's|!!PREFIX!!|${TRUEPREFIX}|g; s|!!VERSION!!|${VERSION}|g' \
		${PREFIX}/bin/nss-config ${PREFIX}/lib/pkgconfig/nss.pc

do-regress:
	cd ${WRKSRC}/tests && ${SETENV} ${MAKE_ENV} \
		PATH="${NSSOBJ}/bin:${PATH}" \
		LD_LIBRARY_PATH="${NSSOBJ}/lib" /bin/sh ./all.sh

.include <bsd.port.mk>

.for _m in ${MACHINE_ARCH}
. if !empty(LP64_ARCHS:M${_m})
MAKE_ENV+=		USE_64=1
OBJ64=			_64
. endif
.endfor
