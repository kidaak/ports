#$OpenBSD$

COMMENT=	open source MSN Messenger clone

V=		0.98.9
DISTNAME=	amsn-$V-src
PKGNAME=	${DISTNAME:S/-src//}
REVISION=	1
CATEGORIES=	net

HOMEPAGE=	http://www.amsn-project.net/

MAINTAINER=	Azwaw OUSADOU <bsdmaniak@gmail.com>

# GPLv2
PERMIT_PACKAGE_CDROM=   Yes
PERMIT_PACKAGE_FTP=     Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=   Yes

MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=project/amsn/amsn/${V}/}
EXTRACT_SUFX=	.tar.bz2

WANTLIB=	ICE SM X11 m stdc++ z glib-2.0 gmodule-2.0 gobject-2.0 \
		gthread-2.0 gstbase-0.10 gstreamer-0.10 xml2 jpeg png

LIB_DEPENDS=	graphics/jpeg \
		graphics/png
RUN_DEPENDS+=	${MODTK_RUN_DEPENDS} \
		security/tcltls \
		x11/bwidget \
		devel/desktop-file-utils
BUILD_DEPENDS=	${MODTK_BUILD_DEPENDS} \
		security/tcltls

MODTK_THREADED= Yes
MODULES=	devel/gettext \
		x11/tk

USE_GMAKE=	Yes
MAKE_FLAGS=	verbose=yes
CONFIGURE_STYLE=gnu
CONFIGURE_ARGS+=--disable-libv4l \
		--disable-upnp \
		--with-tcl="${MODTCL_LIBDIR}" \
		--with-tk="${MODTK_LIBDIR}"

CONFIGURE_ENV+=	CPPFLAGS="-I${X11BASE}/include -I${LOCALBASE}/include \
		    -I${LOCALBASE}/include/libpng" \
		LDFLAGS="-lm -L${LOCALBASE}/lib" \
		TK_INC_SPEC="${MODTK_INCDIR}/generic" \
		TCLSH="${MODTCL_BIN}"

WRKDIST=	${WRKDIR}/amsn-$V/

NO_REGRESS=	Yes # Generic tcl/tk tests.

pre-configure:
	@${SUBST_CMD} ${WRKSRC}/amsn*
	@${MODTCL_WISH_ADJ} ${WRKSRC}/amsn

post-install:
.for a in amsn amsn-remote amsn-remote-CLI
	cd ${PREFIX}/bin && ln -s ../share/amsn/$a
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/amsn
	${INSTALL_DATA} ${WRKSRC}/{FAQ,README} ${PREFIX}/share/doc/amsn
	${INSTALL_DATA} ${WRKSRC}/docs/{FAQ,README}* ${PREFIX}/share/doc/amsn

.include <bsd.port.mk>
