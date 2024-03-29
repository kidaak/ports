# $OpenBSD$

SHARED_ONLY=	Yes

COMMENT=	Open Phone Abstraction Library

DISTNAME=	opal-3.10.7

SHARED_LIBS=	opal	2.0	# 3.10.3

EXTRACT_SUFX=	.tar.bz2

CATEGORIES=	net devel telephony

HOMEPAGE=	http://www.opalvoip.org/

MAINTAINER=	Antoine Jacoutot <ajacoutot@openbsd.org>

# MPL 1.0
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB += c celt0>=1 crypto gsm m ogg pt pthread spandsp speex
WANTLIB += speexdsp stdc++ theora tiff x264

MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=opalvoip/}

LIB_DEPENDS=	devel/ptlib>=2.10.7 \
		audio/celt \
		telephony/spandsp

# dlopen(3) libavcodec.so.X.Y; shows as "Extra:" in check-lib-depends
# but we want to be sure we track ABI and shared lib version changes
WANTLIB+=	avcodec
LIB_DEPENDS+=	graphics/ffmpeg>=20110306

ALL_TARGET=	default_target

MAKE_ENV=	CC=${CC} CPLUS=${CXX} VERBOSE=1
MAKE_FLAGS=	RELEASE_LIB_NAME=libopal.so.${LIBopal_VERSION} \
		RELEASE_LIB_FILENAME_SHARED_PAT=libopal.so.${LIBopal_VERSION}

USE_GMAKE=	Yes
NO_REGRESS=	Yes

MODGNU_CONFIG_GUESS_DIRS= ${WRKSRC} ${WRKSRC}/plugins

CONFIGURE_STYLE=gnu
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include -I${LOCALBASE}/include" \
		LDFLAGS="-L${X11BASE}/lib -L${LOCALBASE}/lib" \
		ac_cv_path_SWIG= # ruby, java
# internal ilbc (port libilbc?)
CONFIGURE_ARGS=	--disable-sbc \
		--enable-plugins \
		--with-plugin-installdir=opal

# plugins/audio/SILK/ReadMe.txt; not for commercial
# http://developer.skype.com/silk
CONFIGURE_ARGS+= --disable-silk

# XXX
# ekiga:/usr/local/lib/opal-3.6.6/lid/vpb_lid_pwplugin.so:
# undefined symbol '_Z18vpb_set_event_maskit'
# <...>
CONFIGURE_ARGS+= --disable-vpb

pre-configure:
	${SUBST_CMD} ${WRKSRC}/plugins/configure
	perl -pi -e 's,SUBDIRS\+=\",SUBDIRS=\"\$${SUBDIRS},g' \
		${WRKSRC}/plugins/configure

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/opal
	${INSTALL_DATA} ${WRKSRC}/opal_inc.mak ${PREFIX}/share/opal
	${INSTALL_DATA} ${WRKSRC}/version.h ${PREFIX}/share/opal

.include <bsd.port.mk>
