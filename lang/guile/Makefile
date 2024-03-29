# $OpenBSD$

COMMENT=	GNU's Ubiquitous Intelligent Language for Extension

VERSION=	1.8.8
DISTNAME=	guile-${VERSION}
REVISION=	0
SHARED_LIBS=	guile 20.0 \
		guile-srfi-srfi-1-v-3 3.2 \
		guile-srfi-srfi-13-14-v-3 3.1 \
		guile-srfi-srfi-4-v-3 3.1 \
		guile-srfi-srfi-60-v-2 2.2 \
		guilereadline-v-17 17.3
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU:=guile/}

HOMEPAGE=	http://www.gnu.org/software/guile/

# LGPLv2.1
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes
WANTLIB=		c gmp>=6 ltdl m ncurses pthread readline

LIB_DEPENDS=	devel/gmp>=4.1 \
		devel/libtool,-ltdl
RUN_DEPENDS=	devel/slib

MODULES=	devel/gettext

SEPARATE_BUILD=		Yes
CONFIGURE_STYLE=	gnu
USE_LIBTOOL=		Yes
USE_GMAKE=		Yes

# Needed because otherwise regress tests won't build:
# warning: format '%ji' expects type 'intmax_t', but argument 4 has type 'scm_t_intmax'
CONFIGURE_ARGS+=	--disable-error-on-warning
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		PTHREAD_CFLAGS=-pthread \
		PTHREAD_LIBS=-pthread

V=		${VERSION:C,.[0-9]+$,,}
SUBST_VARS=	V

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/aclocal
	${INSTALL_DATA} ${WRKSRC}/guile-config/guile.m4 ${PREFIX}/share/aclocal
	# Create symlink from share/guile/slib to share/slib.
	# This allows other ports to find guile.init.
	@cd ${PREFIX}/share/guile && ln -s ../slib

.include <bsd.port.mk>
