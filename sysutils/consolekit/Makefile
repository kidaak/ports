# $OpenBSD$

COMMENT=	framework for defining and tracking users

DISTNAME=	ConsoleKit-0.4.5
PKGNAME=	${DISTNAME:L}
REVISION=	6

CATEGORIES=	sysutils	

EXTRACT_SUFX=	.tar.bz2

SHARED_LIBS+=	ck-connector	1.0

HOMEPAGE=	http://www.freedesktop.org/wiki/Software/ConsoleKit

MANTAINER=	Antoine Jacoutot <ajacoutot@openbsd.org>

# GPLv2+
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes

WANTLIB += X11 c dbus-1 dbus-glib-1 ffi gio-2.0 glib-2.0 gmodule-2.0
WANTLIB += gobject-2.0 gthread-2.0 kvm pcre polkit-gobject-1 pthread
WANTLIB += xcb z

MASTER_SITES=	http://www.freedesktop.org/software/ConsoleKit/dist/

MODULES=	devel/gettext

LIB_DEPENDS=	sysutils/polkit>=0.101 \
		x11/dbus-glib

AUTOCONF_VERSION= 2.68
CONFIGURE_STYLE= autoconf
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	${CONFIGURE_SHARED} \
		--with-pid-file=/var/run/ConsoleKit/pid \
		--enable-pam-module=no

USE_LIBTOOL=	Yes
USE_GMAKE=	Yes

FAKE_FLAGS=	DBUS_SYS_DIR=${TRUEPREFIX}/share/examples/consolekit/dbus-1 \
		sysconfdir=${TRUEPREFIX}/share/examples/consolekit

pre-patch:
	@cd ${WRKSRC}/tools && \
		cp -R freebsd openbsd && \
		perl -pi -e "s,freebsd,openbsd,g" openbsd/Makefile.in

# from Slackware Linux
post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/pam-foreground-compat.ck \
		${PREFIX}/lib/ConsoleKit/run-session.d/pam-foreground-compat.ck

.include <bsd.port.mk>
