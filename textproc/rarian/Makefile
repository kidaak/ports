# $OpenBSD$

COMMENT=		documentation metadata library

GNOME_PROJECT=		rarian
GNOME_VERSION=		0.8.1
SHARED_LIBS +=	rarian               0.0      # .0.0
CATEGORIES=		textproc

REVISION=		10

HOMEPAGE=		http://rarian.freedesktop.org/

# LGPLv2.1/GPLv2
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

EXTRACT_SUFX=		.tar.bz2

WANTLIB=		c m stdc++

MODULES=		x11/gnome

RUN_DEPENDS=		shells/bash \
			textproc/docbook \
			textproc/libxslt
BUILD_DEPENDS=		${RUN_DEPENDS}

CONFIGURE_STYLE=	gnu
CONFIGURE_ARGS+=	--with-convert-dir=${PREFIX}/share/omf \
			--enable-installed \
			--enable-scrollkeeper-compat \
			--enable-omf-read \
			--disable-skdb-update

# The .in files in ${WRKSRC}/util/ don't have a newline at the end
# of the file, which causes diff(1) to puke.
post-extract:
	@echo "" >> ${WRKSRC}/util/rarian-sk-*.in

pre-configure:
	${SUBST_CMD} ${WRKSRC}/librarian/rarian-main.c \
		${WRKSRC}/librarian/rarian-man.c \
		${WRKSRC}/librarian/rarian-info.c

.include <bsd.port.mk>
