# $OpenBSD$

ONLY_FOR_ARCHS-mono=	${MONO_ARCHS}

COMMENT-main=	MIME messages creation and parsing library
COMMENT-mono=	mono bindings for gmime

GNOME_PROJECT=	gmime
GNOME_VERSION=	2.6.10

PKGNAME-main=	${DISTNAME}
PKGNAME-mono=	gmime-sharp-${GNOME_VERSION}

REVISION=	0

SHARED_LIBS +=  gmime-2.6            0.0    # 600.0

CATEGORIES=	mail devel

HOMEPAGE=	http://spruce.sourceforge.net/gmime/

# LGPLv2
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB-main += ${MODGETTEXT_WANTLIB}
WANTLIB-main += ffi gio-2.0 glib-2.0 gmodule-2.0 gobject-2.0 gthread-2.0
WANTLIB-main += pcre z

MULTI_PACKAGES=	-main -mono

MODULES +=	devel/gettext \
		x11/gnome

# needed to build the tests
BUILD_DEPENDS += security/libgpg-error

LIB_DEPENDS-main= ${MODGETTEXT_LIB_DEPENDS} \
		devel/glib2

CONFIGURE_STYLE= gnu
CONFIGURE_ENV=	DOLT_BASH="/bin/ksh"

### mono subpackage
PSEUDO_FLAVORS=	no_mono
# XXX disable mono unconditionally, lang/mono is often problematic to build
# and nothing needs gmime-sharp in the tree
#FLAVOR ?=
FLAVOR=	no_mono

MODMONO_DEPS=   No
DLLMAP_FILES=	mono/gmime-sharp.dll.config

.include <bsd.port.arch.mk>

.if ${BUILD_PACKAGES:M-mono}
MODULES+=	lang/mono
BUILD_DEPENDS+= ${MODMONO_BUILD_DEPENDS} \
		x11/mono-gtk2
RUN_DEPENDS-mono= ${MODMONO_RUN_DEPENDS} \
		x11/mono-gtk2
LIB_DEPENDS-mono= # empty
WANTLIB-mono=	# empty
.else
CONFIGURE_ARGS+= --disable-mono
.endif
### end of mono subpackage

.include <bsd.port.mk>
