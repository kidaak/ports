# $OpenBSD$

COMMENT-main =	japanese input method
COMMENT-emacs =	emacs files for anthy

V =		9100h
DISTNAME =	anthy-$V
PKGNAME-main =	anthy-$V
PKGNAME-emacs =	emacs-anthy-$V

SHARED_LIBS +=	anthydic             1.0      # .1.0
SHARED_LIBS +=	anthy                1.0      # .1.0
SHARED_LIBS +=	anthyinput           1.0      # .0.0

CATEGORIES =	inputmethods japanese

HOMEPAGE = 	http://anthy.sourceforge.jp/

# GPL, part LGPL
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM = Yes
PERMIT_DISTFILES_FTP =	Yes

WANTLIB-main =	c m

MASTER_SITES =	${MASTER_SITE_SOURCEFORGE_JP:=anthy/37536/}

FAKE_FLAGS =	sysconfdir=$(PREFIX)/share/examples/anthy

USE_LIBTOOL =	Yes
CONFIGURE_STYLE = gnu
CONFIGURE_ENV =	CPPFLAGS='-I${LOCALBASE}/include' \
		LDFLAGS='-L${LOCALBASE}/lib' \
		SWIG=no

PSEUDO_FLAVORS = no_emacs
FLAVOR ?=

MULTI_PACKAGES = -main
.if !${FLAVOR:Mno_emacs}
MULTI_PACKAGES += -emacs
BUILD_DEPENDS =	editors/emacs21
.endif

# can't make sense of any of these tests
NO_REGRESS =	Yes

.include <bsd.port.mk>
