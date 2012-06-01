# $OpenBSD$

COMMENT =		PHP support for retrieving info about files

DISTNAME =		Fileinfo-1.0.4
REVISION =		3
CATEGORIES =		sysutils
MAINTAINER =		Johan Huldtgren <jhuldtgren@gmail.com>

# PHP
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

WANTLIB +=		z magic

MODULES=		lang/php/pecl
CONFIGURE_STYLE=	gnu

LIB_DEPENDS =		devel/libmagic

.include <bsd.port.mk>
