# $OpenBSD$

COMMENT=		Python bindings for GStreamer

V=			0.10.22
DISTNAME=		gst-python-${V}
PKGNAME=		py-gstreamer-${V}
REVISION=		2

HOMEPAGE=		http://gstreamer.freedesktop.org/modules/gst-python.html

MASTER_SITES =		${MASTER_SITE_GST:=gst-python/}

WANTLIB += ffi glib-2.0 gmodule-2.0 gobject-2.0 gstaudio-0.10
WANTLIB += gstbase-0.10 gstcontroller-0.10 gstdataprotocol-0.10
WANTLIB += gstinterfaces-0.10 gstnet-0.10 gstpbutils-0.10 gstreamer-0.10
WANTLIB += gsttag-0.10 gstvideo-0.10 gthread-2.0 m orc-0.4 pcre
WANTLIB += pthread xml2 z

# check-lib-depends(1) list them as extra, but they are dlopened
WANTLIB += ${MODPY_WANTLIB} util

MODULES=		lang/python

BUILD_DEPENDS=		x11/py-gtk2
RUN_DEPENDS=		x11/py-gtk2 \
			textproc/libxml,-python
LIB_DEPENDS=		${P}/plugins-base

REGRESS_DEPENDS=	${P}/plugins-good

CONFIGURE_STYLE=	gnu
CONFIGURE_ARGS=		--disable-gcov \
			--disable-shave

post-install:
	@cd ${PREFIX}/lib/python${MODPY_VERSION}/site-packages/ && \
		${MODPY_BIN} -OOOO -c 'import pygst' && \
		${MODPY_BIN} -c 'import pygst'
	rm ${PREFIX}/lib/python${MODPY_VERSION}/site-packages/gst-${VERSION}/gst/*.la \
		${PREFIX}/lib/python${MODPY_VERSION}/site-packages/*.la \
		${PREFIX}/lib/gstreamer-${VERSION}/*.la

.include <bsd.port.mk>
