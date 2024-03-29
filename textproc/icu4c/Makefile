# $OpenBSD$

COMMENT=		International Components for Unicode

VERSION=		49.1.2
DISTNAME=		icu4c-${VERSION:S/./_/g}-src
PKGNAME=		icu4c-${VERSION}
REVISION =		2
SO_VERSION=		5.0
.for _lib in icudata icui18n icuio icule iculx icutest icutu icuuc
SHARED_LIBS+=		${_lib} ${SO_VERSION}
.endfor
SUBST_VARS+=		VERSION
CATEGORIES=		textproc devel
DPB_PROPERTIES=		parallel

HOMEPAGE=		http://www.icu-project.org

MAINTAINER=		Antoine Jacoutot <ajacoutot@openbsd.org>

# ICU
# http://source.icu-project.org/repos/icu/icu/trunk/license.html
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB=		c m pthread stdc++

MASTER_SITES=		http://download.icu-project.org/files/icu4c/${VERSION}/ \
			${MASTER_SITE_SOURCEFORGE:=icu/}
EXTRACT_SUFX=		.tgz

USE_GMAKE=		Yes
USE_GROFF=		Yes
CONFIGURE_STYLE=	gnu
CONFIGURE_ARGS+=	${CONFIGURE_SHARED} \
			--enable-static \
			--disable-extras \
			--disable-samples

SEPARATE_BUILD=		Yes

WRKDIST=		${WRKDIR}/icu
WRKSRC=			${WRKDIST}/source

MAKE_FLAGS+=		SO_TARGET_VERSION=${SO_VERSION} \
			SO_TARGET_VERSION_MAJOR=${SO_VERSION:R} \
			PKGDATA_INVOKE_OPTS="SO_TARGET_VERSION=${SO_VERSION} SO_TARGET_VERSION_MAJOR=${SO_VERSION:R}"

# XXX U_IS_BIG_ENDIAN is not propagated to the C/C++ files
# http://comments.gmane.org/gmane.comp.tex.texlive.build/1705
.include <bsd.port.arch.mk>
.if ${PROPERTIES:Mbe}
CONFIGURE_ENV +=	CPPFLAGS="-DU_IS_BIG_ENDIAN"
.endif

post-install:
# Bug #7506, #7567 and #7574, libicutest is not installed
	${INSTALL_DATA} ${WRKBUILD}/tools/ctestfw/libicutest.a ${PREFIX}/lib/
	${INSTALL_DATA} \
		${WRKBUILD}/tools/ctestfw/libicutest.so.${LIBicutest_VERSION} \
		 ${PREFIX}/lib/
# who needs those annoying symlinks ?
	find ${PREFIX}/lib -type l -name 'libicu*.so*' -exec rm '{}' \;

.include <bsd.port.mk>
