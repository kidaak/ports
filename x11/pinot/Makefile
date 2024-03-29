# $OpenBSD$

SHARED_ONLY=	Yes

COMMENT=	personal search and metasearch

DISTNAME=	pinot-1.01

SHARED_LIBS +=  xapianbackend             0.0 # 1.0

CATEGORIES=	x11 misc

HOMEPAGE=	http://code.google.com/p/pinot-search/

# LGPLv2
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB += GL X11 Xau Xcomposite Xcursor Xdamage Xdmcp Xext Xfixes
WANTLIB += Xi Xinerama Xrandr Xrender Xxf86vm atk-1.0 atkmm-1.6
WANTLIB += c cairo cairo-gobject cairomm-1.0 crypto curl dbus-1
WANTLIB += dbus-glib-1 drm e2fs-uuid exiv2 expat ffi fontconfig
WANTLIB += freetype gdk-3 gdk_pixbuf-2.0 gdkmm-3.0 gio-2.0 giomm-2.4
WANTLIB += glib-2.0 glibmm-2.4 gmime-2.6 gmodule-2.0 gobject-2.0
WANTLIB += gthread-2.0 gtk-3 gtkmm-3.0 idn m pango-1.0 pangocairo-1.0
WANTLIB += pangoft2-1.0 pangomm-1.4 pcre pixman-1 png pthread
WANTLIB += pthread-stubs sigc-2.0 sqlite3 ssl stdc++ tag textcat
WANTLIB += xapian xcb xcb-render xcb-shm xml++-2.6 xml2 z

MASTER_SITES=	http://pinot-search.googlecode.com/files/

MODULES=	devel/gettext

BUILD_DEPENDS=	devel/boost \
		misc/shared-mime-info \
		devel/desktop-file-utils \
		devel/libexecinfo

# XXX catppt - catdvi
LIB_DEPENDS=	x11/gtk3mm \
		textproc/libxml++ \
		mail/gmime>=2.6.0 \
		net/curl \
		audio/taglib \
		x11/dbus-glib \
		graphics/exiv2 \
		devel/libidn

# port-lib-depends-check misses these ones because the depending lib
# is under lib/pinot/backends/
LIB_DEPENDS+=	textproc/libtextcat \
		databases/xapian-core

RUN_DEPENDS=	devel/desktop-file-utils \
		devel/xdg-utils \
		archivers/unzip \
		textproc/unrtf \
		textproc/antiword \
		misc/shared-mime-info \
		x11/gtk+2,-guic

# pdftotext(1)
RUN_DEPENDS +=	print/poppler,-utils

USE_LIBTOOL=	yes
USE_GROFF=	Yes

CONFIGURE_STYLE= gnu
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		MKDIR_P="mkdir -p --"
CONFIGURE_ARGS= ${CONFIGURE_SHARED} \
		--with-http=curl \
		--with-ssl=/usr \
		--enable-gtkmm3

# needs boost >= 1.48
#CONFIGURE_ARGS += --disable-mempool

.ifdef DEBUG
CONFIGURE_ARGS+= --enable-debug
.endif

FAKE_FLAGS=	sysconfdir=${PREFIX}/share/examples/pinot

BASH_SCRIPTS=pinot-enum-index.sh pinot-cd.sh pinot-check-file.sh

pre-configure:
	perl -pi -e 's,/usr/share,${LOCALBASE}/share,g' \
		${WRKSRC}/textcat3*_conf.txt
	${SUBST_CMD} \
		${WRKSRC}/{Makefile.in,README,textcat_conf.txt,Core/pinot-search.1,Utils/xdgmime/xdgmime.c}
	for i in ${BASH_SCRIPTS}; \
		do perl -pi -e 's,/bin/bash/,/bin/sh,g' ${WRKSRC}/scripts/bash/$${i}; done

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pinot
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/pinot/
	rm ${PREFIX}/lib/pinot/*.{a,la}

.include <bsd.port.mk>
