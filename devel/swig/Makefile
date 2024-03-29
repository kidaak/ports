# $OpenBSD$

COMMENT=	simplified wrapper and interface generator

SUBST_VARS=	VERSION
VERSION=	1.3.36

DISTNAME=	swig-${VERSION}
REVISION=	6
CATEGORIES=	devel
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=swig/}

HOMEPAGE=       http://www.swig.org/

# BSD
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes
WANTLIB=		c m stdc++

MODULES=	lang/python lang/tcl lang/ruby
MODRUBY_RUNDEP=	No
MODPY_RUNDEP=	No
BUILD_DEPENDS=	${MODTCL_BUILD_DEPENDS} \
		lang/guile


USE_GMAKE=	Yes
CONFIGURE_STYLE= gnu
CONFIGURE_ARGS+= --with-tclincl=${MODTCL_INCDIR} \
		 --with-tcllib=${MODTCL_LIBDIR} \
		 --with-guilelib=${LOCALBASE}/lib \
		 --with-python=${MODPY_BIN} \
		 --with-ruby=${RUBY} \
		 --without-mzscheme \
		 --without-php4 \
		 --without-ocaml
MODGNU_CONFIG_GUESS_DIRS=${WRKSRC}/Tools/config

ALL_TARGET=	swig

SWIG_EXAMPLES=	${PREFIX}/share/examples/swig
SWIG_DOCS=	${PREFIX}/share/doc/swig

post-install:
	${INSTALL_DATA_DIR} ${SWIG_EXAMPLES}
	${INSTALL_DATA_DIR} ${SWIG_DOCS}
	cp -R ${WRKSRC}/Examples/* ${SWIG_EXAMPLES}
	cp -R ${WRKSRC}/Doc/* ${SWIG_DOCS}
	
.include <bsd.port.mk>
