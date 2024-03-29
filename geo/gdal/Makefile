# $OpenBSD$

COMMENT-main =	translator library for geospatial data formats
COMMENT-python =python bindings and utilities for GDAL
COMMENT-perl =	perl bindings for GDAL

V =		1.8.1
DISTNAME =	gdal-${V}

PKGNAME-main =	${DISTNAME}
PKGNAME-python =py-${DISTNAME}
PKGNAME-perl =	p5-Geo-GDAL-${V}
REVISION-perl = 0

SHARED_LIBS =	gdal 18.0 #16.1
CATEGORIES =	geo devel

HOMEPAGE =	http://www.gdal.org/

MAINTAINER =	Landry Breuil <landry@openbsd.org>

# MIT/X
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES =	http://download.osgeo.org/gdal/

MODULES =	perl lang/python devel/gettext

MULTI_PACKAGES =	-main -python -perl

LIB_DEPENDS-main =	${LIB_DEPENDS} \
			graphics/tiff \
			net/curl \
			databases/postgresql \
			geo/geos \
			devel/libidn \
			graphics/png \
			graphics/libungif \
			graphics/jpeg \
			graphics/jasper \
			devel/geotiff

WANTLIB-main =		${WANTLIB} c crypto expat m ssl stdc++ z tiff \
			curl pq geos geos_c idn png gif jpeg jasper geotiff \
			com_err proj pthread

LIB_DEPENDS-python =	${PKGNAME}:${BASE_PKGPATH},-main
WANTLIB-python =	${MODPY_WANTLIB} gdal m stdc++

LIB_DEPENDS-perl =	${PKGNAME}:${BASE_PKGPATH},-main
WANTLIB-perl =		c gdal crypto curl expat geos_c geotiff gif idn \
			jasper jpeg m png pq ssl tiff z pthread \
			${MODGETTEXT_WANTLIB}

RUN_DEPENDS +=		math/py-numpy
BUILD_DEPENDS +=	${RUN_DEPENDS} devel/swig

MODPY_SETUPTOOLS =	Yes
MODPY_EGG_VERSION =	${V}
MODPY_ADJ_FILES =	swig/python/scripts/*.py

MAKE_FILE =	GNUmakefile
MAKE_FLAGS =	LIBTOOL_FINISH=:
USE_GMAKE =	Yes
USE_LIBTOOL =	Yes
NO_REGRESS =	Yes
CONFIGURE_STYLE =	gnu
CONFIGURE_ENV =	CPPFLAGS="-I${LOCALBASE}/include \
			  -I${LOCALBASE}/include/libpng" \
		LDFLAGS="-L${LOCALBASE}/lib -pthread"

CONFIGURE_ARGS =	${CONFIGURE_SHARED} \
		--without-cfitsio \
		--without-netcdf \
		--without-xerces \
		--without-mysql \
		--without-sqlite3 \
		--without-odbc \
		--without-oci \
		--without-grass \
		--without-idb \
		--without-sde \
		--without-libgrass \
		--without-php \
		--without-ruby \
		--with-pg=${LOCALBASE}/bin/pg_config \
		--with-python \
		--with-perl \
		--with-geos \
		--with-png=${LOCALBASE} \
		--with-geotiff=${LOCALBASE} \
		--with-libtiff=${LOCALBASE} \
		--with-curl=${LOCALBASE} \
		--with-gif=${LOCALBASE} \
		--with-jpeg=${LOCALBASE} \
		--with-jasper=${LOCALBASE}

pre-configure:
	${SUBST_CMD} ${WRKSRC}/configure

.include <bsd.port.mk>
