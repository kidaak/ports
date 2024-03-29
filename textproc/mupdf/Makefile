# $OpenBSD$

COMMENT =	graphic library, pdf parser, viewer and utilities

V =		1.1
REVISION =	1
DISTNAME =	mupdf-$V-source
PKGNAME =	mupdf-${V:S/-rc/rc/}

CATEGORIES =	textproc x11

HOMEPAGE =	http://mupdf.com/

MAINTAINER =	Stuart Henderson <sthen@openbsd.org>

# code: GPLv3. font maps: Adobe (redist ok, see headers). droid font: Apache.
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

WANTLIB =	X11 Xext c freetype jbig2dec jpeg>=62 m openjpeg z

# http://git.ghostscript.com/?p=mupdf.git;a=summary
MASTER_SITES =	${HOMEPAGE}download/ \
		${HOMEPAGE}download/archive/

RUN_DEPENDS =	devel/desktop-file-utils
LIB_DEPENDS =	graphics/jbig2dec \
		graphics/jpeg \
		graphics/openjpeg>=1.5.0

USE_GMAKE =	Yes
NO_REGRESS =	Yes

# -I flags prepend mupdf's own, to allow building with previous ver installed
MAKE_ENV +=	CFLAGS="${CFLAGS} -I$(WRKSRC)/fitz -I$(WRKSRC)/pdf -I$(WRKSRC)/xps" \
		LDFLAGS="${LDFLAGS}" CC=${CC} CXX=${CXX} \
		MANDIR="${WRKINST}${PREFIX}/man/man1" build= verbose=1

FAKE_FLAGS =	prefix=${WRKINST}${PREFIX} mandir=${WRKINST}${PREFIX}/man

pre-configure:
	${SUBST_CMD} ${WRKSRC}/debian/mupdf.pc

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/applications/ \
	    ${PREFIX}/share/application-registry/ ${PREFIX}/share/pixmaps \
	    ${PREFIX}/lib/pkgconfig/
	${INSTALL_DATA} ${WRKSRC}/debian/mupdf.xpm ${PREFIX}/share/pixmaps/
	${INSTALL_DATA} ${WRKSRC}/debian/mupdf.applications \
	    ${PREFIX}/share/application-registry/
	${INSTALL_DATA} ${WRKSRC}/debian/mupdf.desktop \
	    ${PREFIX}/share/applications/
	${INSTALL_DATA} ${WRKSRC}/debian/mupdf.pc \
	    ${PREFIX}/lib/pkgconfig/mupdf.pc

.include <bsd.port.mk>
