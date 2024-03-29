# $OpenBSD$

COMMENT=		shared mime database for desktops

DISTNAME=		shared-mime-info-1.0
CATEGORIES=		misc
REVISION=		2

HOMEPAGE=		http://www.freedesktop.org/wiki/Software/shared-mime-info

MAINTAINER=		Antoine Jacoutot <ajacoutot@openbsd.org>

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB += c glib-2.0 pthread xml2

MASTER_SITES=		http://people.freedesktop.org/~hadess/
EXTRACT_SUFX=		.tar.xz

MODULES=		devel/gettext \
			textproc/intltool

LIB_DEPENDS=		devel/glib2 \
			textproc/libxml

USE_GMAKE=		Yes
USE_GROFF=		Yes
CONFIGURE_STYLE=	gnu
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"

pre-configure:
	@perl -pi -e 's|/usr/local|${PREFIX}|g' \
		${WRKSRC}/update-mime-database.c \
		${WRKSRC}/shared-mime-info-spec.xml

# Hack to get a minimal set of files and directories. We could just
# configure with `--disable-update-mimedb' but then we don't get
# the (mostly empty) bookkeeping files.
post-install:
	cd ${PREFIX}/share/mime && \
	mv packages/freedesktop.org.xml{,~} && \
	${PREFIX}/bin/update-mime-database $$(pwd) && \
	mv packages/freedesktop.org.xml{~,}

.include <bsd.port.mk>
