# $OpenBSD$

COMMENT=		base elements for GStreamer

V=			0.10.36
DISTNAME=		gst-plugins-base-${V}
PKGNAME=		gstreamer-plugins-base-${V}

REVISION=		2

SHARED_LIBS +=  gstinterfaces-0.10   2.6      # .25.0
SHARED_LIBS +=  gsttag-0.10          2.6      # .25.0
SHARED_LIBS +=  gstfft-0.10          2.6      # .25.0
SHARED_LIBS +=  gstnetbuffer-0.10    2.6      # .25.0
SHARED_LIBS +=  gstpbutils-0.10      2.6      # .25.0
SHARED_LIBS +=  gstrtp-0.10          2.6      # .25.0
SHARED_LIBS +=  gstsdp-0.10          2.6      # .25.0
SHARED_LIBS +=  gstvideo-0.10        2.6      # .25.0
SHARED_LIBS +=  gstapp-0.10          2.6      # .25.0
SHARED_LIBS +=  gstaudio-0.10        2.6      # .25.0
SHARED_LIBS +=  gstcdda-0.10         2.6      # .25.0
SHARED_LIBS +=  gstriff-0.10         2.6      # .25.0
SHARED_LIBS +=  gstrtsp-0.10         2.6      # .25.0

WANTLIB += GL ICE SM X11 Xau Xdamage Xdmcp Xext Xfixes Xrender
WANTLIB += Xv Xxf86vm c cairo cdda_interface cdda_paranoia drm
WANTLIB += expat ffi fontconfig freetype gio-2.0 glib-2.0 gmodule-2.0
WANTLIB += gobject-2.0 gstbase-0.10 gstcontroller-0.10 gstdataprotocol-0.10
WANTLIB += gstreamer-0.10 gthread-2.0 m ogg orc-0.4 orc-test-0.4
WANTLIB += pango-1.0 pangocairo-1.0 pangoft2-1.0 pcre pixman-1
WANTLIB += png pthread pthread-stubs stdc++ theoradec theoraenc
WANTLIB += vorbis vorbisenc vorbisidec xcb xcb-render xcb-shm
WANTLIB += xml2 z

MASTER_SITES=		${MASTER_SITE_GST:=gst-plugins-base/}

# needed for ${WRKSRC}/tests/
BUILD_DEPENDS=		x11/gtk+2

LIB_DEPENDS=		${P}/core \
			audio/cdparanoia \
			audio/libvorbis \
			audio/tremor \
			devel/orc \
			devel/pango \
			multimedia/libtheora

# needed for the gio plugin
RUN_DEPENDS-main +=	x11/gnome/gvfs

# XXX libvisual needs to be ported
CONFIGURE_ARGS=		--disable-libvisual \
			--disable-gnome_vfs

pre-configure:
	perl -pi -e 's,/dev/cdrom1,/dev/rcd1c,g' \
		${WRKSRC}/tests/check/libs/cddabasesrc.c
	perl -pi -e 's,/dev/cdrom,/dev/rcd0c,g' \
		${WRKSRC}/docs/plugins/gst-plugins-base-plugins.args \
		${WRKSRC}/ext/cdparanoia/gstcdparanoiasrc.c \
		${WRKSRC}/gst-libs/gst/cdda/gstcddabasesrc.c \
		${WRKSRC}/tests/check/libs/cddabasesrc.c

.include <bsd.port.mk>
