# $OpenBSD$

COMMENT=	command-line MPEG audio decoder and player

DISTNAME=	madplay-0.15.2b
REVISION=	3
CATEGORIES=	audio
HOMEPAGE=	http://mad.sourceforge.net/

MAINTAINER=	Christian Weisgerber <naddy@openbsd.org>

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=	ftp://ftp.mars.org/pub/mpeg/ \
		${MASTER_SITE_SOURCEFORGE:=mad/}

MODULES=	devel/gettext
LIB_DEPENDS=	audio/libid3tag \
		audio/libmad
WANTLIB=	c id3tag>=3 m mad>=2 sndio z

USE_LIBTOOL=	Yes
SEPARATE_BUILD=	Yes
AUTOCONF_VERSION=2.59
CONFIGURE_STYLE= autoconf
CONFIGURE_ARGS=	--without-esd
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-extract:
	@cp -f ${FILESDIR}/audio_sndio.c ${WRKSRC}/

.include <bsd.port.mk>
