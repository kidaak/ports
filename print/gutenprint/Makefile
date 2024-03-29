# $OpenBSD$

COMMENT-main=		high quality print drivers
COMMENT-foomatic=	Foomatic data for gutenprint drivers

# XXX On major update:
# update the gutenprint-ijs.X.X substitution in print/foomatic-db + bump
# update the example in print/foomatic-db-engine README + bump
V=			5.2.8
DISTNAME=		gutenprint-${V}
PKGNAME-main=		${DISTNAME}
PKGNAME-foomatic=	foomatic-db-${DISTNAME}

REVISION-foomatic=	0

MAJOR_V=		${V:C/^([0-9]+\.[0-9]+).*/\1/}
SUBST_VARS=		MAJOR_V

CATEGORIES=		print

EXTRACT_SUFX=		.tar.bz2

SHARED_LIBS+=		gutenprint	1.0	# .2.3

HOMEPAGE=		http://gimp-print.sourceforge.net/

MAINTAINER=		Antoine Jacoutot <ajacoutot@openbsd.org>

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gimp-print/}

MULTI_PACKAGES=		-main -foomatic

MODULES=	devel/gettext

WANTLIB-main +=	c m ncurses readline ijs ${MODGETTEXT_WANTLIB}

BUILD_DEPENDS=		print/foomatic-db-engine

LIB_DEPENDS-main=	${MODGETTEXT_LIB_DEPENDS} \
			print/ijs

WANTLIB-foomatic += # empty
LIB_DEPENDS-foomatic=	# empty
RUN_DEPENDS-foomatic=	${BUILD_PKGPATH},-main
PKG_ARCH-foomatic=	*

# gutenprint needs xml drivers information from foomatic-db
RUN_DEPENDS-foomatic +=	print/foomatic-db

# share/foomatic/db/source/*/*.xml
RUN_DEPENDS-foomatic +=	print/foomatic-db-engine

USE_GMAKE=		Yes
USE_LIBTOOL=		Yes
USE_GROFF =		Yes

CONFIGURE_STYLE=	gnu
CONFIGURE_ARGS+=	${CONFIGURE_SHARED} \
			--enable-static \
			--enable-test \
			--enable-testpattern \
			--enable-escputil \
			--disable-libgutenprintui2 \
			--with-foomatic \
			--with-foomatic3 \
			--with-ghostscript \
			--with-cups=no \
			--without-gimp2
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib" \
			LIBS="-liconv -lintl" \
			am_cv_prog_tar_ustar=plaintar

.for i in DVIPS DB2PDF DVIPDF DB2PS DB2HTML DOXYGEN TEXI2HTML CONVERT
CONFIGURE_ENV+=		ac_cv_path_$i=""
.endfor

FAKE_FLAGS=		docdir=${PREFIX}/share/doc/gutenprint

pre-configure:
	${SUBST_CMD} ${WRKSRC}/src/gutenprintui2/plist.c

.include <bsd.port.mk>
