# $OpenBSD$

# pinentry builds against it's own stripped version of libassuan
# I will see with upstream how to change this behavior

COMMENT-main = 	PIN or passphrase entry dialog (ncurses interface)
COMMENT-gtk2 = 	PIN or passphrase entry dialog (gtk2 interface)

VERSION = 	0.8.1
DISTNAME = 	pinentry-${VERSION}
CATEGORIES = 	security

REVISION-main = 0
REVISION-gtk2 = 0
PKGNAME-main = 	${DISTNAME}
PKGNAME-gtk2 = 	pinentry-gtk2-${VERSION}

MASTER_SITES = 	ftp://ftp.gnupg.org/gcrypt/pinentry/

HOMEPAGE = 	http://www.gnupg.org/related_software/pinentry/index.en.html

MAINTAINER = 	Pierre-Emmanuel Andre <pea@openbsd.org>

# GPLv2
PERMIT_PACKAGE_CDROM = 	Yes
PERMIT_PACKAGE_FTP = 	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP = 	Yes

MULTI_PACKAGES = 	-main -gtk2

WANTLIB-main = 		${WANTLIB} c ncurses
WANTLIB-gtk2 = 		${WANTLIB} c GL X11 Xcomposite Xcursor Xdamage \
			Xext Xfixes Xi Xinerama Xrandr Xrender atk-1.0 \
			cairo expat fontconfig freetype gdk-x11-2.0 \
			gdk_pixbuf-2.0 gio-2.0 glib-2.0 gmodule-2.0  \
			gobject-2.0 gthread-2.0 gtk-x11-2.0 intl m ncurses \
			pango-1.0 pangocairo-1.0 pangoft2-1.0 pixman-1 png \
			pthread pthread-stubs xcb xcb-render xcb-shm z
LIB_DEPENDS-gtk2 = 	x11/gtk+2

MODULES = 		converters/libiconv

CONFIGURE_STYLE = 	gnu
CONFIGURE_ENV = 	CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"	
CONFIGURE_ARGS = 	--enable-pinentry-curses \
			--disable-pinentry-qt \
			--disable-pinentry-qt4 \
			--disable-pinentry-gtk \
			--enable-pinentry-gtk2

# Change default 'pinentry' to pinentry-curses in the -main package.
# The shipped Makefiles insist on setting it to the gtk2 variant.
post-install:
	ln -sf pinentry-curses ${PREFIX}/bin/pinentry
	
.include <bsd.port.mk>
