# $OpenBSD$

COMMENT =		audio codec for lossless, lossy and hybrid compression

DISTNAME =		wavpack-4.60.1
REVISION =		0
CATEGORIES =		audio

HOMEPAGE =		http://www.wavpack.com/

SHARED_LIBS +=		wavpack		0.1	# .2.4

# BSD
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

WANTLIB =		c m

MASTER_SITES =		${HOMEPAGE}			
EXTRACT_SUFX =		.tar.bz2

MODULES =		converters/libiconv 

SEPARATE_BUILD=		Yes
USE_LIBTOOL =		Yes
CONFIGURE_STYLE =	gnu
CONFIGURE_ARGS =	${CONFIGURE_SHARED} \
			--with-libiconv-prefix="${LOCALBASE}"
CONFIGURE_ENV =		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"
USE_GROFF =		Yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/wavpack
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/wavpack

.include <bsd.port.mk>
