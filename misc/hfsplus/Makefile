# $OpenBSD$

COMMENT=	hfsplus filesystem access tool

VERSION=	1.0.4
DISTNAME=	hfsplus_${VERSION}
PKGNAME=	hfsplus-${VERSION}
REVISION=	4
SHARED_LIBS=	hfsp	0.0

CATEGORIES=	misc 

# GPL
PERMIT_DISTFILES_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB=		c

MASTER_SITES=		http://distfiles.nl/
EXTRACT_SUFX=		.src.tar.bz2

USE_GMAKE=		Yes
USE_LIBTOOL=		Yes

AUTOCONF_VERSION=	2.59
AUTOMAKE_VERSION=	1.9
BUILD_DEPENDS=		${MODGNU_AUTOCONF_DEPENDS} \
			${MODGNU_AUTOMAKE_DEPENDS}
# needs the AM_PROG_LIBTOOL macro                                           
BUILD_DEPENDS+=		devel/libtool

CONFIGURE_STYLE=	gnu
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"
MODGNU_CONFIG_GUESS_DIRS= ${WRKSRC}

WRKDIST=		${WRKDIR}/hfsplus-${VERSION}

DOC=			bugs.html hfsp.html libhfsp.html

post-patch:
	@cd ${WRKDIST} && ln -s ${LOCALBASE}/share/libtool/config/ltmain.sh \
	@cd ${WRKDIST} && env AUTOCONF_VERSION=${AUTOCONF_VERSION} \
		AUTOMAKE_VERSION=${AUTOMAKE_VERSION} \
		${MAKE_PROGRAM} -f Makefile.cvs all

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/hfsplus/
.for h in ${DOC}
	${INSTALL_DATA} ${WRKSRC}/doc/${h} ${PREFIX}/share/doc/hfsplus/
.endfor

.include <bsd.port.mk>
