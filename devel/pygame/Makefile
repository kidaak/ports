# $OpenBSD$

SHARED_ONLY=	Yes

COMMENT=	set of Python modules designed for writing games

DISTNAME=	pygame-1.8.1release
PKGNAME=	${DISTNAME:S/release//}
REVISION =	4
CATEGORIES=	devel games

HOMEPAGE=	http://www.pygame.org/

# LGPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB += SDL X11 jpeg png pthread-stubs smpeg xcb SDL_ttf SDL_image SDL_mixer

MASTER_SITES=	${HOMEPAGE}ftp/

MODULES=	lang/python

BUILD_DEPENDS+=	math/py-Numeric

LIB_DEPENDS=	devel/sdl-ttf \
		devel/sdl-image \
		devel/sdl-mixer


MAKE_ENV+=	LOCALBASE="${LOCALBASE}" \
		SDL_CONFIG="${LOCALBASE}/bin/sdl-config"

EXAMPLESDIR=	${PREFIX}/share/examples/pygame
DOCDIR=		${PREFIX}/share/doc/pygame
DOCSUBDIRS=	ref tut tut/chimp tut/surfarray \
		tut/tom

REGRESS_IS_INTERACTIVE=	x11

# fix perms
post-extract:
	find ${WRKSRC} -type d | xargs chmod 755
	find ${WRKSRC} -type f | xargs chmod 644

do-configure:
	${SUBST_CMD} ${WRKSRC}/Setup.in
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MODPY_BIN} config.py

post-install:
	${INSTALL_DATA_DIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/*.py ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/readme.txt ${EXAMPLESDIR}
	${INSTALL_DATA_DIR} ${EXAMPLESDIR}/data
	${INSTALL_SCRIPT} ${WRKSRC}/examples/data/* ${EXAMPLESDIR}/data
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.{gif,html} ${DOCDIR}
.for i in ${DOCSUBDIRS}
	${INSTALL_DATA_DIR} ${DOCDIR}/$i
	${INSTALL_DATA} `find ${WRKSRC}/docs/$i -maxdepth 1 -type f` \
		${DOCDIR}/$i
.endfor
	@perl -pi -e 's,/usr/bin/env python,/usr/bin/env python${MODPY_VERSION},g' \
		${PREFIX}/share/examples/pygame/*.py

do-regress: fake
	@cd ${WRKSRC} && ${MAKE_ENV} \
		PYTHONPATH=${WRKINST}${MODPY_SITEPKG} \
			${MODPY_BIN} ./run_tests.py

.include <bsd.port.mk>
