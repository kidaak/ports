# $OpenBSD$

COMMENT =	SDL port of the legendary 2D platform shooter

DISTNAME =	abuse-free-0.8
PKGNAME =	abuse-0.8
EPOCH =		0
ABUSE_SFX =	abuse-free-sounds-20120309
CATEGORIES =	games x11

HOMEPAGE =	http://abuse.zoy.org/

MAINTAINER =	Antti Harri <iku@openbsd.fi>

# Abuse: GPLv2 and public domain
# Abuse-free-sounds: various free licenses
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

WANTLIB += FLAC GL SDL SDL_mixer X11 Xdamage Xext Xfixes Xrandr
WANTLIB += Xrender Xxf86vm c drm iconv m mikmod ogg pthread smpeg
WANTLIB += sndio stdc++ usbhid vorbis vorbisfile xcb

MASTER_SITES =	${HOMEPAGE}raw-attachment/wiki/download/
MASTER_SITES0 =	http://openbsd.fi/dist/

MODULES =	converters/libiconv
# Needs AC_PROG_LIBTOOL
BUILD_DEPENDS =	devel/libtool \
		${MODGNU_AUTOCONF_DEPENDS} \
		${MODGNU_AUTOMAKE_DEPENDS}
RUN_DEPENDS = 	audio/timidity
LIB_DEPENDS =	devel/sdl-mixer \
		devel/smpeg \
		audio/flac \
		audio/libogg \
		audio/libmikmod \
		audio/libvorbis

DISTFILES = 	${DISTNAME}.tar.gz \
		${ABUSE_SFX}.tar.gz:0

SEPARATE_BUILD =Yes
USE_LIBTOOL =	Yes

CONFIGURE_STYLE =	gnu
CONFIGURE_ARGS =	--enable-release \
			--disable-nonfree \
			--with-assetdir=${PREFIX}/share/abuse \
			--datadir=${PREFIX}/share/abuse
AUTOMAKE_VERSION =	1.11
AUTOCONF_VERSION =	2.68

NO_REGRESS =	Yes

post-patch:
	cd "${WRKSRC}" && \
		find "${WRKDIR}/${ABUSE_SFX}/patches/" -name 'patch-*' \
		-exec patch -z .afs-orig -i {} \;

pre-configure:
	cd ${WRKSRC} && \
		AUTOMAKE_VERSION=${AUTOMAKE_VERSION} \
		AUTOCONF_VERSION=${AUTOCONF_VERSION} \
		autoreconf -fi

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/abuse/sfx
	cd ${WRKDIR}/${ABUSE_SFX}/sfx && find . -type f -exec \
		${INSTALL_DATA} {} ${PREFIX}/share/abuse/sfx/ \;

.include <bsd.port.mk>
