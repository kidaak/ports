# $OpenBSD$

SHARED_ONLY =		Yes

ONLY_FOR_ARCHS =	${GCC4_ARCHS}

COMMENT =		music studio with tracking, sampling and MIDI
DISTNAME =		lmms-0.4.8
REVISION =		2

CATEGORIES =		audio
HOMEPAGE =		http://lmms.sourceforge.net/

MAINTAINER =		Jacob Meuser <jakemsr@openbsd.org>

# GPLv2
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM = Yes
PERMIT_DISTFILES_FTP =	Yes

WANTLIB =		ICE SM QtGui QtXml X11 Xext Xft Xinerama c fltk jack \
			fftw3f fluidsynth fontconfig freetype m ncurses ogg \
			pthread readline samplerate sndfile sndio vorbis \
			vorbisenc vorbisfile z stdc++

MASTER_SITES =		${MASTER_SITE_SOURCEFORGE:=lmms/}
EXTRACT_SUFX =		.tar.bz2

MODULES =		x11/qt4 devel/cmake

RUN_DEPENDS =		devel/desktop-file-utils \
			misc/shared-mime-info
LIB_DEPENDS =		audio/jack \
			math/fftw3,float \
			audio/fluidsynth \
			audio/libsamplerate \
			audio/libvorbis \
			x11/fltk

USE_X11 =		Yes

CONFIGURE_ENV =		CFLAGS="${CFLAGS} -I${X11BASE}/include" \
			CXXFLAGS="${CXXFLAGS} -I${X11BASE}/include" \
			LDFLAGS="${LDFLAGS} -L${X11BASE}/lib"
CONFIGURE_ARGS =	-DWANT_OSS=OFF -DWANT_SDL=OFF -DWANT_PULSEAUDIO=OFF

# these are all available as separate ports
CONFIGURE_ARGS +=	-DWANT_CALF=OFF -DWANT_CAPS=OFF -DWANT_CMT=OFF \
			-DWANT_SWH=OFF -DWANT_TAP=OFF

MAKE_FLAGS +=		VERBOSE=1

NO_REGRESS =		Yes

post-patch:
	cp ${FILESDIR}/FindSndio.cmake ${WRKSRC}/cmake/modules/
	cp ${FILESDIR}/{Audio,Midi}Sndio.h ${WRKSRC}/include/
	cp ${FILESDIR}/AudioSndio.cpp ${WRKSRC}/src/core/audio/
	cp ${FILESDIR}/MidiSndio.cpp ${WRKSRC}/src/core/midi/

.include <bsd.port.mk>
