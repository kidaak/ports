# $OpenBSD$

COMMENT =		SoundFont2 software synthesizer
DISTNAME =		fluidsynth-1.0.9
REVISION =		1

SHARED_LIBS =		fluidsynth	0.1

CATEGORIES =		audio
HOMEPAGE =		http://fluidsynth.resonance.org/trac

MAINTAINER =		Jacob Meuser <jakemsr@openbsd.org>

# LGPL
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM = Yes
PERMIT_DISTFILES_FTP =	Yes

WANTLIB =		c jack m ncurses pthread readline sndio

MASTER_SITES =		${MASTER_SITE_SAVANNAH:=fluid/}

LIB_DEPENDS =		audio/jack

AUTOCONF_VERSION =	2.61
AUTOMAKE_VERSION =	1.9

BUILD_DEPENDS +=	${MODGNU_AUTOCONF_DEPENDS} \
			${MODGNU_AUTOMAKE_DEPENDS}
# autogen.sh needs libtoolize
BUILD_DEPENDS +=        devel/libtool

USE_LIBTOOL =		Yes
CONFIGURE_STYLE =	gnu
CONFIGURE_ARGS +=	${CONFIGURE_SHARED} \
			--disable-lash \
			--disable-ladcca \
			--disable-oss-support \
			--disable-portaudio-support \
			--disable-pulse-support

post-patch:
	cp ${FILESDIR}/fluid_sndio.c ${WRKSRC}/src/

pre-configure:
	cd ${WRKSRC} && AUTOMAKE_VERSION=${AUTOMAKE_VERSION} \
	    AUTOCONF_VERSION=${AUTOCONF_VERSION} ./autogen.sh

.include <bsd.port.mk>
