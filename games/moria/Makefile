# $OpenBSD$

COMMENT=	The Dungeons of Moria

V=		5.5.2
DISTNAME=	um$V
PKGNAME=	moria-$V
REVISION =	1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.funet.fi/pub/unix/games/moria/source/ \
		ftp://alge.anart.no/pub/games/RPG/moria/
EXTRACT_SUFX=	.tar.Z

HOMEPAGE=	http://www-math.bgsu.edu/~grabine/moria.html

PERMIT_PACKAGE_CDROM=	not-for-profit redistribution only
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	not-for-profit redistribution only
PERMIT_DISTFILES_FTP=	Yes
WANTLIB=		c curses termcap

NO_REGRESS=	Yes

WRKDIST=	${WRKDIR}/umoria
WRKSRC=		${WRKDIST}

SEPARATE_BUILD= Yes
MAKE_ENV=	CC="${CC}" CFLAGS="${CFLAGS}"

do-build:
	@cd ${WRKBUILD}; for i in ${WRKSRC}/source/*; do ln -sf $$i; done; \
	 for i in ${WRKSRC}/unix/*; do ln -sf $$i; done; \
	 ln -sf ${WRKSRC}/files; \
	 ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} PREFIX="${PREFIX}"

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/moria
	@cd ${WRKBUILD}; ${MAKE_PROGRAM} ${ALL_FAKE_FLAGS} install

.include <bsd.port.mk>
