# $OpenBSD$

COMMENT=		compiler for the GObject type system

GNOME_PROJECT=		vala
GNOME_VERSION=		0.18.0
API_V=			0.18

SHARED_LIBS +=  vala-0.18            0.0      # 0.0

CATEGORIES=		lang

HOMEPAGE=		http://live.gnome.org/Vala

MAINTAINER=		Jasper Lievisse Adriaanse <jasper@openbsd.org>, \
			Antoine Jacoutot <ajacoutot@openbsd.org>

# LGPLv2
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB += c pcre pthread ffi glib-2.0 gmodule-2.0 gobject-2.0 gthread-2.0

MODULES=		devel/gettext \
			x11/gnome

BUILD_DEPENDS=		${RUN_DEPENDS}
RUN_DEPENDS=		textproc/libxslt \
			textproc/p5-XML-LibXML
LIB_DEPENDS=		devel/glib2
REGRESS_DEPENDS=	shells/bash

USE_GROFF=		Yes

SUBST_VARS+=		API_V

CONFIGURE_STYLE=	gnu
CONFIGURE_ARGS+=	--enable-vapigen

pre-configure:
	perl -pi -e 's,/bin/bash,${LOCALBASE}/bin/bash,g' \
		${WRKSRC}/tests/testrunner.sh

.include <bsd.port.mk>
