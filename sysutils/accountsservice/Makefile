# $OpenBSD: ports/sysutils/accountsservice/Makefile,v 1.22 2012/03/28 09:05:54 ajacoutot Exp $

COMMENT=	D-Bus interface for user account query and manipulation

DISTNAME=	accountsservice-0.6.17
EXTRACT_SUFX=	.tar.xz

SHARED_LIBS +=  accountsservice           0.0 # 0.0

CATEGORIES=	sysutils

HOMEPAGE=	http://cgit.freedesktop.org/accountsservice/

MAINTAINER=	Antoine Jacoutot <ajacoutot@openbsd.org>

# GPLv3
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB += c ffi gio-2.0 glib-2.0 gmodule-2.0 gobject-2.0 gthread-2.0
WANTLIB += kvm pcre polkit-gobject-1 pthread z

MASTER_SITES=	http://www.freedesktop.org/software/accountsservice/

MODULES=	devel/gettext \
		textproc/intltool

BUILD_DEPENDS=	devel/gobject-introspection \
		lang/vala

LIB_DEPENDS=	sysutils/polkit

RUN_DEPENDS=	sysutils/consolekit

USE_GMAKE=	Yes
USE_LIBTOOL=	Yes

CONFIGURE_STYLE=gnu
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	${CONFIGURE_SHARED} \
		--localstatedir=/var \
		--enable-introspection \
		--disable-docbook-docs

FAKE_FLAGS=	sysconfdir=${PREFIX}/share/examples/accountsservice

pre-configure:
	${SUBST_CMD} ${WRKSRC}/src/daemon.c

# XXX
post-configure:
	echo '#undef WITH_SYSTEMD' >> ${WRKBUILD}/config.h

.include <bsd.port.mk>