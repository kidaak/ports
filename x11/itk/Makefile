# $OpenBSD$

COMMENT=	build mega-widgets using the Itcl object system

VERSION=	3.3
DISTNAME=	itk${VERSION}
PKGNAME=	itk-${VERSION}
REVISION=	3
SHARED_LIBS=	itk33	0.0

CATEGORIES=	x11 devel

HOMEPAGE=	http://incrtcl.sourceforge.net/itk/

# BSD style
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MODULES =	x11/tk
WANTLIB +=	X11 ${MODTK_WANTLIB} itcl34

MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=incrtcl/}

LIB_DEPENDS=	${MODTK_LIB_DEPENDS} \
		devel/itcl
RUN_DEPENDS=	${MODTK_RUN_DEPENDS} \
		devel/itcl

SUBST_VARS=	VERSION

CONFIGURE_STYLE=gnu

CONFIGURE_ARGS=	${CONFIGURE_SHARED} \
		--with-tcl=${MODTCL_LIBDIR} \
		--with-tk=${MODTK_LIBDIR} \
		--with-itcl=${MODTCL_TCLDIR}/itcl \
		--libdir=${MODTCL_TCLDIR}/itcl \
		--includedir=${LOCALBASE}/include/itk

CONFIGURE_ENV=	CPPFLAGS="-I${MODTCL_INCDIR}/generic \
		-I${MODTCL_INCDIR}/unix \
		-I${MODTK_INCDIR}/generic \
		-I${MODTK_INCDIR}/unix \
		-I${MODTK_INCDIR} \
		-I${MODTCL_INCDIR} \
		-I${LOCALBASE}/include/itcl" \
		LIBitk33_VERSION=${LIBitk33_VERSION}
FAKE_FLAGS =    libdir=${MODTCL_TCLDIR}/itk

# This regression test wants an X11 display
REGRESS_IS_INTERACTIVE=Yes

do-regress:
	@cd ${WRKSRC} && env ITK_LIBRARY=${WRKSRC}/library \
		${MODTK_BIN} tests/all.tcl -load \
		"load ./libitk33.so.${LIBitk33_VERSION}; package require Tk"

.include <bsd.port.mk>
