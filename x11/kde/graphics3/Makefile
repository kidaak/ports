# $OpenBSD$

COMMENT-main =		K Desktop Environment, graphic applications
COMMENT-kamera =	KDE interface to digital cameras
COMMENT-kpov =		KDE modeller for povray
COMMENT-sane =		KDE interface to scanners
CATEGORIES =		x11 x11/kde
VERSION =		3.5.10
DISTNAME =		kdegraphics-${VERSION}
MODKDE_VERSION =	3.5.8

SEPARATE_BUILD =	flavored
MULTI_PACKAGES =	-main -kpov -kamera -sane

PKGNAME-main =		${DISTNAME}
PKGNAME-kamera =	kamera-${VERSION}
PKGNAME-kpov =		kpovmodeller-${VERSION}
PKGNAME-sane =		ksane-${VERSION}

SHARED_LIBS +=	kghostviewlib        1.0      # .0.0
SHARED_LIBS +=	kpovmodeler          1.0      # .0.0
SHARED_LIBS +=	text2path            1.0      # .0.0
SHARED_LIBS +=	ksvg                 1.0      # .0.1
SHARED_LIBS +=	kimageviewer         1.0      # .0.0
SHARED_LIBS +=	kmultipage           1.0      # .0.0
SHARED_LIBS +=	kscan                2.0      # .1.0

MODULES =		x11/kde devel/gettext

BUILD_DEPENDS =		print/texlive/base
WANTLIB = ICE SM X11 Xext art_lgpl_2 idn jpeg lib/kde3/DCOP \
	lib/kde3/kdecore>=6 lib/kde3/kdefx lib/kde3/kdesu lib/kde3/kdeui \
	lib/kde3/kio m png qt-mt stdc++ util xcb z
LIB_DEPENDS =		${MODGETTEXT_LIB_DEPENDS} \
			x11/kde/libs3

RUN_DEPENDS-main =	${RUN_DEPENDS} \
			print/ghostscript/gnu \
			devel/desktop-file-utils \
			x11/gtk+2,-guic
LIB_DEPENDS-main = 	${LIB_DEPENDS} \
			graphics/imlib \
			graphics/libungif \
			devel/fribidi>=0.19.2 \
			print/poppler, \
			print/poppler,,-qt
LIB_DEPENDS-kpov =	${LIB_DEPENDS}

RUN_DEPENDS-kpov =	graphics/povray \
			devel/desktop-file-utils 

LIB_DEPENDS-kamera = 	${LIB_DEPENDS} \
			graphics/libgphoto2

RUN_DEPENDS-sane =	devel/desktop-file-utils \
			x11/gtk+2,-guic
LIB_DEPENDS-sane =	${LIB_DEPENDS} \
			graphics/sane-backends

WANTLIB-main = 		${WANTLIB}
WANTLIB-kpov =		${WANTLIB}
WANTLIB-kamera =	${WANTLIB}
WANTLIB-sane =		${WANTLIB}

REVISION-main = 15
REVISION-kamera = 7
REVISION-kpov = 7
REVISION-sane = 11

WANTLIB-main +=	 GL Half ICE Iex IlmImf IlmThread Imath Imlib SM \
	Xcursor Xdamage Xext Xfixes Xft Xi Xinerama Xmu Xrandr Xrender Xt \
	Xxf86vm c drm expat fontconfig freetype fribidi lcms lib/kde3/kdeprint \
	lib/kde3/khtml lib/kde3/kjs lib/kde3/kparts lib/kde3/kutils \
	lib/kde3/kwalletclient mng openjpeg pcre pcreposix poppler \
	poppler-qt pthread tiff ungif

WANTLIB-kpov += GL GLU Xdamage Xfixes Xi Xmu Xrender Xt Xxf86vm c \
	drm freetype lib/kde3/kparts lib/kde3/kwalletclient pthread \
	expat fontconfig

WANTLIB-kamera +=  Xrender exif gphoto2 gphoto2_port pthread \
	lib/kde3/kwalletclient Xfixes Xt expat fontconfig freetype ltdl

WANTLIB-sane +=	c Xfixes Xrender Xt expat fontconfig freetype lib/kde3/kwalletclient \
	lib/kde3/kabc lib/kde3/kdeprint lib/kde3/kparts lib/kde3/kresources \
	lib/kde3/kspell lib/kde3/ktexteditor lib/kde3/vcard pthread sane \
	tiff usb usb-1.0

post-patch:
	@cp ${FILESDIR}/part_init.cpp ${WRKSRC}/kghostview

CONFIGURE_ENV +=	TIFF_LIBS='-L${LOCALBASE}/lib -ltiff -ljpeg -lz' \
			TIFF_CFLAGS='-I${LOCALBASE}/include'

# no need to depend on libpaper
CONFIGURE_ENV +=	ac_cv_header_paper_h=no

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/HTML/en/common
	@${post_install_libs}

.include <bsd.port.mk>
