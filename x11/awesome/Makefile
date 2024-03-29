# $OpenBSD$

COMMENT=		highly configurable framework window manager

DISTNAME=		awesome-3.4.13
REVISION=		2
EXTRACT_SUFX=		.tar.xz
CATEGORIES=		x11

HOMEPAGE=		http://awesome.naquadah.org/

MAINTAINER=		David Coppa <dcoppa@openbsd.org>

# GPLv2+
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB+=		GL Imlib2 X11 Xau Xdamage Xdmcp Xext Xfixes
WANTLIB+=		Xrender Xxf86vm c cairo dbus-1 drm ev
WANTLIB+=		execinfo expat fontconfig freetype glib-2.0
WANTLIB+=		gmodule-2.0 gobject-2.0 gthread-2.0
WANTLIB+=		${MODLUA_WANTLIB} m pango-1.0 pangocairo-1.0
WANTLIB+=		pangoft2-1.0 pixman-1 png pthread
WANTLIB+=		pthread-stubs startup-notification-1 xcb
WANTLIB+=		xcb-atom xcb-aux xcb-event xcb-icccm
WANTLIB+=		xcb-image xcb-keysyms xcb-property
WANTLIB+=		xcb-randr xcb-render xcb-shape xcb-shm
WANTLIB+=		xcb-xinerama xcb-xtest xdg-basedir z

MASTER_SITES=		${HOMEPAGE}download/

LIB_DEPENDS=		devel/libexecinfo \
			devel/pango \
			devel/libev \
			devel/startup-notification \
			graphics/imlib2 \
			${MODLUA_LIB_DEPENDS} \
			x11/dbus \
			x11/libxdg-basedir

BUILD_DEPENDS=		devel/gperf \
			devel/luadoc \
			textproc/asciidoc>=8.4.5 \
			textproc/xmlto \
			graphics/ImageMagick \
			devel/doxygen

RUN_DEPENDS=		graphics/feh \
			misc/rlwrap \
			shells/bash

MODULES=		devel/cmake \
			devel/gettext \
			lang/lua

CONFIGURE_ARGS=		-DCOMPRESS_MANPAGES=off

SEPARATE_BUILD=		No

NO_REGRESS=		Yes

pre-configure:
	${SUBST_CMD} ${WRKSRC}/lib/naughty.lua.in \
		${WRKSRC}/lib/awful/util.lua.in

post-install:
	@rm ${WRKINST}/${LOCALBASE}/share/awesome/lib/*.{beforesubst,orig}
	@rm ${WRKINST}/${LOCALBASE}/share/awesome/lib/awful/*.{beforesubst,orig}
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/awesome
	@mv ${WRKINST}/${SYSCONFDIR}/xdg/awesome/rc.lua \
		${PREFIX}/share/examples/awesome/

.include <bsd.port.mk>
