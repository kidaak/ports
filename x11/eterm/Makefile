# $OpenBSD$

COMMENT=	color X11 terminal emulator with transparency support
COMMENT-kanji=	color japanese terminal emulator with transparency support

V=		0.9.5
DISTNAME=	Eterm-$V
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
PKGNAME=	eterm-$V		# also see below
SHARED_LIBS +=	Eterm                1.0      # .0.0
CATEGORIES=	x11
REVISION=	1

HOMEPAGE=	http://www.eterm.org/

# GPL with some custom licenses
PERMIT_PACKAGE_CDROM=	may not sell
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	may not sell
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=	${HOMEPAGE}/download/ \
		${MASTER_SITE_SOURCEFORGE:=eterm/}

WANTLIB += ICE Imlib2 SM X11 XRes Xau Xdmcp Xext Xmu Xt c freetype
WANTLIB += m pthread-stubs util xcb z ast ttf

MODULES+=	converters/libiconv

LIB_DEPENDS=	devel/libast \
		print/freetype

USE_LIBTOOL=	Yes
USE_GROFF =	Yes

CONFIGURE_STYLE=gnu
CONFIGURE_ARGS=	${CONFIGURE_SHARED} \
		--enable-trans \
		--enable-utmp \
		--enable-xim \
		--with-theme-update \
		--with-backspace=bs \
		--without-terminfo
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

FLAVORS=	kanji
FLAVOR?=

.if ${FLAVOR:L:Mkanji}
FULLPKGNAME=	ja-eterm-$V
CATEGORIES+=	japanese
CONFIGURE_ARGS+=--enable-multi-charset=kanji
.else
CONFIGURE_ARGS+=--enable-multi-charset
.endif

pre-extract:
	ln -sf ${WRKSRC} ${WRKDIR}/Eterm

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/Eterm
	${INSTALL_DATA} ${WRKSRC}/ReleaseNotes ${PREFIX}/share/doc/Eterm
	${INSTALL_DATA} ${WRKSRC}/doc/Eterm.tcap ${PREFIX}/share/doc/Eterm
	${INSTALL_DATA} ${WRKSRC}/doc/Eterm.ti ${PREFIX}/share/doc/Eterm

.include <bsd.port.mk>
