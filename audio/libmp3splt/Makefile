# $OpenBSD$

COMMENT=	library to split mp3/ogg files without decoding

DISTNAME=	libmp3splt-0.5.4

SHARED_LIBS +=  mp3splt 	0.0   # .0.5

CATEGORIES=	audio

HOMEPAGE=	http://mp3splt.sourceforge.net/

MAINTAINER=	Kevin Lo <kevlo@cvs.openbsd.org>

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB=	id3tag m mad ltdl ogg vorbis vorbisfile z

MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mp3splt/}

LIB_DEPENDS=	audio/libmad \
		devel/libtool,-ltdl \
		audio/libvorbis \
		audio/libid3tag

USE_LIBTOOL=	Yes
CONFIGURE_STYLE=gnu
CONFIGURE_ARGS= ${CONFIGURE_SHARED} \
		--with-ogg="${LOCALBASE}" \
		--with-vorbis="${LOCALBASE}" 
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
