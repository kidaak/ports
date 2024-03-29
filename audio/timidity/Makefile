# $OpenBSD$

COMMENT=	MIDI to WAV renderer and player

V=		2.13.2
DISTNAME=	TiMidity++-${V}
PKGNAME=	timidity-${V}
REVISION=	4
CATEGORIES=	audio

MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=timidity/}
MASTER_SITES0=	http://www.anime.net/~goemon/timidity/
TIINS=		goemon.tgz
DISTFILES=	${TIINS}:0 ${DISTNAME}.tar.gz

HOMEPAGE=	http://timidity.sourceforge.net/

# GPL, copyrighted patches in goemon patchset
PERMIT_PACKAGE_CDROM=   copyrighted patches
PERMIT_PACKAGE_FTP=     copyrighted patches
PERMIT_DISTFILES_CDROM= copyrighted patches
PERMIT_DISTFILES_FTP=   copyrighted patches

WANTLIB=		c m ncurses sndio

CONFIGURE_STYLE=autoconf automake
AUTOCONF_VERSION = 2.59
AUTOMAKE_VERSION = 1.9
CONFIGURE_ARGS= --enable-audio=sndio \
		--with-default-output=sndio \
		--enable-vt100 \
		--enable-ncurses \
		--enable-server \
		--with-default-path=${SYSCONFDIR}

USE_GROFF =	Yes
FLAVORS=	gtk2 xaw
FLAVOR?=

.if ${FLAVOR:Mgtk2}
CONFIGURE_ARGS+=--enable-gtk
MODULES=	devel/gettext
LIB_DEPENDS+=	x11/gtk+2
WANTLIB+=	X11 Xau Xcomposite Xcursor Xdamage Xdmcp Xext Xfixes \
		Xi Xinerama Xrandr Xrender atk-1.0 cairo expat \
		fontconfig freetype gdk-x11-2.0 gdk_pixbuf-2.0 \
		glib-2.0 gio-2.0 gmodule-2.0 gobject-2.0 \
		gtk-x11-2.0 gthread-2.0 pango-1.0 pangocairo-1.0 \
		pangoft2-1.0 pixman-1 png pthread pthread-stubs xcb \
		xcb-render xcb-render-util z
.endif

.if ${FLAVOR:Mxaw}
CONFIGURE_ARGS+=--enable-xaw
WANTLIB+=	ICE SM X11 Xaw Xext Xmu Xt
.endif

.if ! ${FLAVOR:Mgtk2} && ! ${FLAVOR:Mxaw}
CONFIGURE_ARGS+=--without-x
.endif

USE_GMAKE=	Yes
NO_REGRESS=	Yes

WRKDIST=	${WRKDIR}
WRKSRC=		${WRKDIR}/${DISTNAME}
DATA_DIRS=	gsdrum00 gsdrum08 gsdrum40

post-patch:
	cp ${FILESDIR}/sndio_a.c \
		${WRKSRC}/timidity/sndio_a.c
	cd ${WRKSRC} && AUTOCONF_VERSION=${AUTOCONF_VERSION} \
		AUTOMAKE_VERSION=${AUTOMAKE_VERSION} aclocal -I autoconf

pre-configure:
	cd ${WRKSRC}; AUTOCONF_VERSION=${AUTOCONF_VERSION} \
		AUTOMAKE_VERSION=${AUTOMAKE_VERSION} automake \
		--foreign --add-missing --copy

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/timidity/goemon
	${INSTALL_DATA} ${WRKDIST}/goemon/*.* ${PREFIX}/share/timidity/goemon
.for DDIR in ${DATA_DIRS}
	${INSTALL_DATA_DIR} ${PREFIX}/share/timidity/goemon/${DDIR}
	${INSTALL_DATA} ${WRKDIST}/goemon/${DDIR}/*.* \
	    ${PREFIX}/share/timidity/goemon/${DDIR}
.endfor
	${INSTALL_DATA} ${WRKDIST}/goemon.cfg ${PREFIX}/share/timidity/goemon
	@echo -e "dir ${TRUEPREFIX}/share/timidity/goemon\nsource goemon.cfg" \
	    >> ${WRKDIR}/timidity.cfg
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/timidity
	${INSTALL_DATA} ${WRKDIR}/timidity.cfg ${PREFIX}/share/examples/timidity

.include <bsd.port.mk>
