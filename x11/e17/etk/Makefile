# $OpenBSD$

BROKEN =		needs an update

COMMENT=		toolkit based on the EFL
DISTNAME=		etk-20071211
REVISION=		5

SHARED_LIBS +=  etk                 0.0          # .1.0

# BSD
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB += edje

MODULES=		devel/gettext

LIB_DEPENDS=		x11/e17/edje

RUN_DEPENDS=		devel/desktop-file-utils

USE_LIBTOOL =		Yes
USE_GMAKE=		Yes

CONFIGURE_STYLE=	automake autoconf
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib" \
			E_CFLAGS="-I${LOCALBASE}/include/efreet" \
			E_LIBS="-lssl -lcrypto -leet -levas -lecore -lecore_ipc -ledje -lefreet -lefreet_mime"

REGRESS_TARGET=         etk_test
REGRESS_IS_INTERACTIVE= yes

.include <bsd.port.mk>
