# $OpenBSD$

COMMENT=	rip shoutcast streams to local mp3s

DISTNAME=	streamripper-1.64.6
REVISION=	1
CATEGORIES=	audio

HOMEPAGE=	http://streamripper.sourceforge.net/

MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=streamripper/}

MODULES=	devel/gettext

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB += c glib-2.0 iberty m mad>=2 ogg>=5.2 pthread vorbis>=3.0

LIB_DEPENDS=	audio/libmad \
		audio/libogg \
		audio/libvorbis \
		devel/glib2

AUTOCONF_VERSION=2.63
CONFIGURE_STYLE= autoconf
CONFIGURE_ARGS += ac_cv_lib_faad_NeAACDecDecode2=no
CONFIGURE_ENV=	CPPLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_GROFF =	Yes

.include <bsd.port.mk>
