# $OpenBSD$

COMMENT=	modular log analyzer

DISTNAME=	modlogan-0.8.13
REVISION =	5
CATEGORIES=	sysutils www

HOMEPAGE=	http://jan.kneschke.de/projects/modlogan/

MASTER_SITES=	${HOMEPAGE}/download/

# GPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MODULES=	devel/gettext

WANTLIB=	c expat fontconfig freetype jpeg m png z \
		gd>=18 pcre adns>=1 bz2>=10
LIB_DEPENDS=	graphics/gd \
		devel/pcre \
		net/adns \
		archivers/bzip2

USE_LIBTOOL=	Yes
USE_GROFF =	Yes
CONFIGURE_STYLE= gnu
CONFIGURE_ARGS+= --libdir=${PREFIX}/lib/modlogan
CONFIGURE_ENV += LOCALBASE="${LOCALBASE}" \
		 CPPFLAGS="-I${X11BASE}/include" \
		 LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
MAKE_FLAGS=	INTLLIBS="-L${LOCALBASE}/lib -lintl -liconv"

NO_REGRESS=	Yes

EXAMPLES=	doc/*.conf doc/*-dist
DOCS=		doc/*.txt 

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/modlogan
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/modlogan
	cd ${WRKSRC} && ${INSTALL_DATA} ${EXAMPLES} \
	  ${PREFIX}/share/examples/modlogan
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} \
	  ${PREFIX}/share/doc/modlogan

.include <bsd.port.mk>
