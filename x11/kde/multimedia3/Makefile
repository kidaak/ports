# $OpenBSD$

COMMENT = 		K Desktop Environment, multimedia applications
CATEGORIES =		x11 x11/kde
VERSION =		3.5.10
DISTNAME =		kdemultimedia-${VERSION}
MODKDE_VERSION =	3.5.8
SHARED_LIBS +=	artsbuilder          1.0      # .0.0
SHARED_LIBS +=	artsmidi_idl         1.0      # .0.0
SHARED_LIBS +=	artsmidi             1.0      # .0.0
SHARED_LIBS +=	artsgui_idl          1.0      # .0.0
SHARED_LIBS +=	artsgui              1.0      # .0.0
SHARED_LIBS +=	artsgui_kde          1.0      # .0.0
SHARED_LIBS +=	artsmodulessynth     1.0      # .0.0
SHARED_LIBS +=	artsmodulescommon    1.0      # .0.0
SHARED_LIBS +=	artsmoduleseffects   1.0      # .0.0
SHARED_LIBS +=	artsmodulesmixers    1.0      # .0.0
SHARED_LIBS +=	artsmodules          1.0      # .0.0
SHARED_LIBS +=	artscontrolsupport   2.0      # .1.0
SHARED_LIBS +=	artscontrolapplet    2.0      # .1.0
SHARED_LIBS +=	arts_audiofile       0.0      # .0.0
SHARED_LIBS +=	kmidlib              1.0      # .0.0
SHARED_LIBS +=	kcddb                2.0      # .1.0
SHARED_LIBS +=	yafcore              1.0      # .0.0
SHARED_LIBS +=	yafxplayer           1.0      # .0.0
SHARED_LIBS +=	arts_xine            0.0      # .0.0
SHARED_LIBS +=	arts_akode           0.0      # .0.0
SHARED_LIBS +=	noatun               4.0      # .3.0
SHARED_LIBS +=	noatuncontrols       4.0      # .3.0
SHARED_LIBS +=	noatuntags           4.0      # .3.0
SHARED_LIBS +=	audiocdplugins       2.0      # .1.0
SHARED_LIBS +=	arts_mpeglib         1.0      # .0.3
SHARED_LIBS +=	arts_splay           1.0      # .0.0
SHARED_LIBS +=	arts_mpeglib-0.3.0   1.0      # .0.3

FLAVORS =	debug

MODULES =	x11/kde devel/gettext

LIB_DEPENDS = 	x11/kde/libs3 \
		x11/kde/arts3 \
		audio/libogg \
		audio/flac \
		audio/libvorbis \
		audio/cdparanoia \
		audio/taglib \
		gstreamer->=0.10,<0.11:multimedia/gstreamer-0.10/core \
		devel/libtool,-ltdl \
		multimedia/libtheora \
		audio/akode \
		multimedia/xine-lib

EXTRA_CONFIG =	xdg/menus/applications-merged/kde-multimedia-music.menu 
SAMPLECONFDIR =	${PREFIX}/share/apps/kde-conf-sample

FAKE_FLAGS =	sysconfdir=${SAMPLECONFDIR}
RUN_DEPENDS =	graphics/xanim \
		devel/desktop-file-utils \
		x11/gtk+2,-guic

SEPARATE_BUILD =	flavored
CONFIGURE_ARGS +=	--without-lame
CONFIGURE_ENV +=	aktion_has_xanim=yes

REVISION =	10
WANTLIB = FLAC>=8 ICE SM X11 Xau Xdmcp Xext Xrender Xv Xxf86dga Xxf86vm akode \
	art_lgpl_2 audiofile c cdda_interface cdda_paranoia expat fam \
	fontconfig freetype glib-2.0 gmodule-2.0 gobject-2.0 gstreamer-0.10 \
	gthread-2.0 idn jpeg lib/kde3/DCOP lib/kde3/artsc lib/kde3/artsflow \
	lib/kde3/artsflow_idl lib/kde3/artskde lib/kde3/kdecore>=6 \
	lib/kde3/kdefakes lib/kde3/kdefx lib/kde3/kdeprint lib/kde3/kdesu \
	lib/kde3/kdeui lib/kde3/khtml lib/kde3/kio lib/kde3/kjs \
	lib/kde3/kmedia2_idl lib/kde3/kmediaplayer lib/kde3/kmid \
	lib/kde3/kparts lib/kde3/kutils lib/kde3/kwalletclient lib/kde3/mcop \
	lib/kde3/qtmcop lib/kde3/soundserver_idl ltdl m mad ogg ossaudio pcre \
	pcreposix png pthread pthread-stubs sndio stdc++ tag theora \
	util vorbis vorbisenc vorbisfile xcb xine xml2 z


post-extract:
	cp ${FILESDIR}/audioIO_sndio.cpp ${WRKSRC}/mpeglib/lib/util/audio

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/HTML/en/common
	@${post_install_libs}

.include <bsd.port.mk>
