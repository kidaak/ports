# $OpenBSD$

COMMENT=	open source clone of the game Transport Tycoon Deluxe

V=		1.1.5
DISTNAME=	openttd-${V}
EXTRACT_SUFX=	-source.tar.gz
REVISION=	1
GFX_V=		0.3.5
SFX_V=		0.2.3
MSX_V=		0.3.1
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		opengfx-${GFX_V}.zip:0 \
		opensfx-${SFX_V}.zip:1 \
		openmsx-${MSX_V}.zip:2

CATEGORIES=	games

HOMEPAGE=	http://www.openttd.org/

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB += SDL c expat fontconfig freetype icudata icui18n icuuc
WANTLIB += lzma lzo2 m png pthread stdc++ z

MASTER_SITES=		http://binaries.openttd.org/releases/${V}/
MASTER_SITES0=		http://bundles.openttdcoop.org/opengfx/releases/${GFX_V}/
MASTER_SITES1=		http://bundles.openttdcoop.org/opensfx/releases/${SFX_V}/
MASTER_SITES2=		http://bundles.openttdcoop.org/openmsx/releases/${MSX_V}/

LIB_DEPENDS=		archivers/lzo2 \
			devel/sdl \
			graphics/png \
			textproc/icu4c \
			archivers/xz

RUN_DEPENDS=            devel/desktop-file-utils \
			x11/gtk+2,-guic

CONFIGURE_STYLE=	simple
CONFIGURE_ARGS+=	--prefix-dir=${PREFIX} \
			--binary-dir=bin \
			--data-dir=share/openttd \
			--icon-dir=share/pixmaps \
			--man-dir=man/man6 \
			--personal-dir=.openttd \
			--install-dir=${WRKINST} \
			--with-png \
			--with-zlib \
			--without-allegro \
			--without-libtimidity

MAKE_ENV+=		VERBOSE=1

USE_GMAKE=		Yes
NO_REGRESS=		Yes

DOCSDIR=		${PREFIX}/share/doc/openttd
EXAMPLESDIR=		${PREFIX}/share/examples/openttd
GAMEDIR=		${PREFIX}/share/openttd

FAKE_FLAGS=BUNDLE_DIR=${WRKINST}/bundle BUNDLES_DIR=${WRKINST}/bundle

post-install:
	${INSTALL_DATA_DIR} ${GAMEDIR}/media
	cd ${WRKSRC}/media/ && umask 022 && pax -rw . ${GAMEDIR}/media
	${INSTALL_DATA_DIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/bin/scripts/* ${EXAMPLESDIR}
	${INSTALL_DATA_DIR} ${DOCSDIR}
	cd ${WRKSRC}/docs/ && umask 022 && pax -rw . ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/opengfx-${GFX_V}/*.{grf,obg} ${GAMEDIR}/data
	${INSTALL_DATA} ${WRKDIR}/opensfx-${SFX_V}/*.{cat,obs} ${GAMEDIR}/data
	${INSTALL_DATA} ${WRKDIR}/openmsx-${MSX_V}/*.{mid,obm} ${GAMEDIR}/gm
	rm -rf ${WRKINST}/bundle

.include <bsd.port.mk>
