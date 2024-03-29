# $OpenBSD$

COMMENT =	improved dynamic tiling window manager

DISTNAME =	i3-4.3
REVISION =	1
CATEGORIES =	x11

EXTRACT_SUFX =	.tar.bz2
HOMEPAGE =	http://i3wm.org/
MASTER_SITES =	${HOMEPAGE}/downloads/
MAINTAINER =	David Coppa <dcoppa@openbsd.org>

# BSD
PERMIT_PACKAGE_CDROM =   Yes
PERMIT_PACKAGE_FTP =     Yes
PERMIT_DISTFILES_CDROM = Yes
PERMIT_DISTFILES_FTP =   Yes

WANTLIB =	GL X11 Xcursor Xrender c cairo ev expat \
		fontconfig freetype glib-2.0 gobject-2.0 m \
		pango-1.0 pangocairo-1.0 pangoft2-1.0 pcre \
		pixman-1 png pthread pthread-stubs \
		startup-notification-1 xcb xcb-atom xcb-aux \
		xcb-event xcb-icccm xcb-keysyms xcb-property \
		xcb-randr xcb-render xcb-shm xcb-xinerama yajl z

MODULES =	converters/libiconv \
		devel/gettext

LIB_DEPENDS =	devel/libev \
		devel/libyajl>=2.0.0 \
		devel/pango \
		devel/pcre \
		devel/startup-notification

BUILD_DEPENDS =	devel/bison \
		devel/flex

RUN_DEPENDS =	devel/desktop-file-utils \
		x11/dmenu \
		x11/i3status

USE_GMAKE =	Yes

NO_REGRESS =	Yes

MAKE_FLAGS =	CC="${CC}" \
		BISON="${LOCALBASE}/bin/bison" \
		FLEX="${LOCALBASE}/bin/gflex" \
		SYSCONFDIR=${SYSCONFDIR} \
		V=1

.if defined(DEBUG)
MAKE_FLAGS +=	DEBUG=1
.endif

FAKE_FLAGS =	PREFIX=${PREFIX} \
		SYSCONFDIR=${PREFIX}/share/examples \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}"

post-configure:
	${SUBST_CMD} ${WRKSRC}/i3.config \
		${WRKSRC}/i3.config.keycodes \
		${WRKSRC}/src/cfgparse.y \
		${WRKSRC}/src/commands.c \
		${WRKSRC}/src/config.c \
		${WRKSRC}/src/key_press.c

post-install:
	${INSTALL_MAN} ${WRKBUILD}/man/*.1 ${PREFIX}/man/man1/
	${SUBST_CMD} -o ${SHAREOWN} -g ${SHAREGRP} \
		-c ${WRKBUILD}/man/i3-config-wizard.1 \
			${PREFIX}/man/man1/i3-config-wizard.1
	${SUBST_CMD} -o ${SHAREOWN} -g ${SHAREGRP} \
		-c ${WRKBUILD}/man/i3.1 \
			${PREFIX}/man/man1/i3.1
	@rm ${PREFIX}/man/man1/i3-dump-log.1 \
		${PREFIX}/man/man1/i3-sensible*.1

.include <bsd.port.mk>
