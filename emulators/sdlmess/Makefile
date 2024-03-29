# $OpenBSD$

# Other archs have not been tested
ONLY_FOR_ARCHS =	amd64 i386

COMMENT =		emulates game consoles and old home computers

V =			0.132
DISTNAME =		sdlmess${V:S/.//}
PKGNAME =		sdlmess-${V}
REVISION=		8

CATEGORIES =		emulators games

HOMEPAGE =		http://rbelmont.mameworld.info/?page_id=163

# MAME Distribution License, see http://mamedev.org/license.html
PERMIT_PACKAGE_CDROM =		may not sell
PERMIT_PACKAGE_FTP =		Yes
PERMIT_DISTFILES_CDROM =	may not sell
PERMIT_DISTFILES_FTP =		Yes

WANTLIB +=	X11 Xau Xcomposite Xcursor Xdamage Xdmcp Xext
WANTLIB +=	Xfixes Xi Xinerama Xrandr Xrender atk-1.0 c cairo dbus-1
WANTLIB +=	expat fontconfig freetype gio-2.0 glib-2.0 gmodule-2.0
WANTLIB +=	gobject-2.0 gthread-2.0 m pango-1.0 pangocairo-1.0
WANTLIB +=	pangoft2-1.0 pixman-1 png pthread pthread-stubs xcb z
WANTLIB +=	xcb-render xcb-render-util gdk_pixbuf-2.0 SDL
WANTLIB +=	gdk-x11-2.0 gtk-x11-2.0 gconf-2>=5

MASTER_SITES =		http://rbelmont.mameworld.info/
EXTRACT_SUFX =		.zip

MODULES =		devel/gettext

LIB_DEPENDS =		devel/sdl devel/gconf2 x11/gtk+2

USE_GMAKE =		Yes

NO_REGRESS =		Yes

MAKE_FLAGS =		OPT_FLAGS='-DINI_PATH="\"${SYSCONFDIR}/mess;\""'
MAKE_ENV =		ARCH=$(ARCH) CC=$(CC) CFLAGS="$(CFLAGS)" LD=$(CC) \
			TARGETOS=openbsd
.if ${MACHINE_ARCH} == "amd64"
MAKE_ENV+=		PTR64=1
.endif
MAKE_FILE =		makefile.sdl

MESS_EXTBIN=		dat2html imgtool
MESS_DOC=		config.txt credits.htm faq.htm imgtool.txt \
				license.txt mame.txt messnew.txt newvideo.txt
MESS_DATA_DIR =		roms hash samples artwork ctrlr cheat keymaps

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mess ${PREFIX}/bin/sdlmess
.for i in ${MESS_EXTBIN}
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${PREFIX}/bin/
.endfor
.for i in ${MESS_DATA_DIR}
	${INSTALL_DATA_DIR} ${PREFIX}/share/sdlmess/${i}
.endfor
	${INSTALL_DATA} ${WRKSRC}/keymaps/km[-_]??.txt \
		${PREFIX}/share/sdlmess/keymaps/
	${INSTALL_DATA} ${WRKSRC}/ui.bdf ${PREFIX}/share/sdlmess
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/sdlmess
.for i in ${MESS_DOC}
	${INSTALL_DATA} ${WRKSRC}/docs/${i} ${PREFIX}/share/doc/sdlmess/
.endfor
	${INSTALL_DATA} $(WRKSRC)/SDLMESS.txt ${PREFIX}/share/doc/sdlmess/
	${INSTALL_DATA} $(WRKSRC)/sysinfo.dat ${PREFIX}/share/doc/sdlmess/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/sdlmess
	${SUBST_CMD} -c ${FILESDIR}/mess.ini \
		${PREFIX}/share/examples/sdlmess/mess.ini
	chown ${SHAREOWN}:${SHAREGRP} \
		${PREFIX}/share/examples/sdlmess/mess.ini
 
.include <bsd.port.mk>
