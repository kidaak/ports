# $OpenBSD$

SHARED_ONLY=	Yes

COMMENT=	Python interface to the Sybase relational database system

DISTNAME=	sybase-0.36
PKGNAME=	py-${DISTNAME}
REVISION =	8
CATEGORIES=	databases

HOMEPAGE=	http://www.object-craft.com.au/projects/sybase/
MASTER_SITES=	${HOMEPAGE}download/

# BSD 
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MODULES=	lang/python \
		devel/gettext

MODPY_DISTUTILS_BUILD=		build_ext
MODPY_DISTUTILS_BUILDARGS=	-DHAVE_FREETDS=61

LIB_DEPENDS =	databases/freetds
WANTLIB +=	ct>=1 ${MODPY_WANTLIB}

MAKE_ENV+=	SYBASE="${LOCALBASE}"
NO_REGRESS=	Yes

EXAMPLESDIR=	${PREFIX}/share/examples/py-sybase

post-install:
	${INSTALL_DATA_DIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/README ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/timeout.readme ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.{py,sql} ${EXAMPLESDIR}

.include <bsd.port.mk>
