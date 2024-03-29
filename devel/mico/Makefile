# $OpenBSD$

COMMENT=	free and complete CORBA-compliant implementation

V=		2.3.13
DISTNAME=	mico-${V}
CATEGORIES=	devel

# The build framework accommodates only a single shared lib extension.
SHARED_LIBS=	mico${V}	${LIB_VERSION} \
		micoaux${V}	${LIB_VERSION} \
		micocoss${V}	${LIB_VERSION} \
		micoir${V}	${LIB_VERSION} \
		micox${V}	${LIB_VERSION}
LIB_VERSION=	0.0

HOMEPAGE=	http://www.mico.org/
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mico/}

# LGPL/GPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB=		c m ncurses readline stdc++
WANTLIB+=		crypto ssl ICE SM X11 Xt pthread

USE_GMAKE=		Yes
USE_GROFF =		Yes
CONFIGURE_STYLE=	gnu
CONFIGURE_ENV=		LIB_VERSION=${LIB_VERSION}
CONFIGURE_ARGS+=	--disable-optimize
CONFIGURE_ARGS+=	--with-ssl

SUBST_VARS+=		V
MODGNU_CONFIG_GUESS_DIRS=	${WRKSRC}/admin

FAKE_FLAGS=		INSTDIR=${WRKINST}${PREFIX} \
			SHARED_INSTDIR=${DESTDIR}${PREFIX}/share

WRKDIST=		${WRKDIR}/mico

pre-build:
	cd ${WRKSRC}/idl && ${GMAKE} generate

pre-regress:
	cd ${WRKSRC}/test && ${GMAKE} prg

.include <bsd.port.mk>
