# $OpenBSD$

COMMENT=	implementation of Lotus Sametime Community Client protocol

DISTNAME=	meanwhile-1.0.2
REVISION=	3
SHARED_LIBS=	meanwhile 1.2
CATEGORIES=	devel net

HOMEPAGE=	http://meanwhile.sourceforge.net/

# GPL
PERMIT_PACKAGE_FTP=	Yes
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes

WANTLIB=	m pcre glib-2.0>=800

MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=meanwhile/}

CONFIGURE_STYLE=gnu
CONFIGURE_ARGS=	--enable-mailme=no \
		--enable-doxygen=no

MODULES=	devel/gettext
LIB_DEPENDS=	devel/glib2

USE_LIBTOOL=	Yes

.include <bsd.port.mk>
