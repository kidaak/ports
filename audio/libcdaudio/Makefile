# $OpenBSD$

COMMENT=	multi-platform cd player development library
DISTNAME=	libcdaudio-0.99.12
REVISION=	0
SHARED_LIBS +=	cdaudio              1.1      # .1.0
CATEGORIES=	audio

HOMEPAGE=	http://libcdaudio.sourceforge.net/

MAINTAINER=	Kevin Lo <kevlo@openbsd.org>

# LGPLv2+
PERMIT_PACKAGE_CDROM=   Yes
PERMIT_PACKAGE_FTP=     Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=   Yes

MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=libcdaudio/}

USE_LIBTOOL=	Yes
CONFIGURE_STYLE= gnu
CONFIGURE_ARGS+= ${CONFIGURE_SHARED}

.include <bsd.port.mk>
