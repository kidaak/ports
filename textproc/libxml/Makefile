# $OpenBSD$

COMMENT-main=		XML parsing library
COMMENT-python=		Python bindings for libxml

VERSION=		2.7.8
DISTNAME=		libxml2-${VERSION}
PKGNAME-main=		libxml-${VERSION}
REVISION-main =		6
REVISION-python =	3
PKGNAME-python=		py-libxml-${VERSION}
SHARED_LIBS=		xml2	13.0
CATEGORIES=		textproc
MASTER_SITES=		http://fr.rpmfind.net/pub/libxml/ \
			http://gd.tuwien.ac.at/pub/libxml/ \
			ftp://xmlsoft.org/libxml/

HOMEPAGE=		http://xmlsoft.org/ 

# BSD-like
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB=		m z

MODULES=		converters/libiconv

USE_LIBTOOL=		Yes
CONFIGURE_STYLE=	autoconf
AUTOCONF_VERSION=	2.68 # should be 2.66
CONFIGURE_ARGS+=	${CONFIGURE_SHARED}
CONFIGURE_ARGS+=	--enable-static
CONFIGURE_ARGS+=	--with-html-dir="${PREFIX}/share/doc"
CONFIGURE_ARGS+=	--with-html-subdir="libxml2/html"
CONFIGURE_ARGS+=	--with-iconv="${DEPBASE}"
# only used to fetch data during regression test
CONFIGURE_ENV=		WGET=/usr/bin/ftp

PSEUDO_FLAVORS=		no_python
FLAVOR?=

MULTI_PACKAGES=		-main -python

WANTLIB-main=		${WANTLIB} c
RUN_DEPENDS-main=
NOT_FOR_ARCHS-python =	${NO_SHARED_ARCHS}

.include <bsd.port.arch.mk>

.if ${BUILD_PACKAGES:M-python}
MODULES+=		lang/python
LIB_DEPENDS-python=	textproc/libxml,-main \
			${MODPY_LIB_DEPENDS} \
			${MODLIBICONV_LIB_DEPENDS}
WANTLIB-python=		m z util xml2>=11 ${MODPY_WANTLIB} ${MODLIBICONV_WANTLIB}
FAKE_FLAGS=		EXAMPLE_DIR=${PREFIX}/share/examples/libxml2/
CONFIGURE_ARGS+=	--with-python
.else
CONFIGURE_ARGS+=	--without-python
.endif


CONFIGURE_ARGS+=	--without-threads
REGRESS_DEPENDS=	devel/gmake

post-configure:
	sed -e 's,@PREFIX@,${PREFIX},' <${FILESDIR}/rebuild >${WRKBUILD}/rebuild

post-install:
	${INSTALL_SCRIPT_DIR} ${PREFIX}/share/libxml2
	${INSTALL_SCRIPT} ${WRKBUILD}/rebuild ${PREFIX}/share/libxml2/
.if ${BUILD_PACKAGES:M-python}
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py ${WRKINST}${MODPY_SITEPKG}
.endif

do-regress:
	@cd ${WRKBUILD} && exec ${SETENV} ${MAKE_ENV} ${GMAKE} \
		${ALL_REGRESS_FLAGS} -f ${MAKE_FILE} ${REGRESS_TARGET}

.include <bsd.port.mk>
