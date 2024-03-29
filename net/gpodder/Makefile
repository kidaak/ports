# $OpenBSD$

COMMENT=		media aggregator and podcast client

MODPY_EGG_VERSION=	3.1.0
DISTNAME=		gpodder-${MODPY_EGG_VERSION}
REVISION=		0
CATEGORIES=		net www

HOMEPAGE=		http://gpodder.org/

# GPLv3+
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

# upstream's master site doesn't play nice with ftp/DISTNAME, so just
# mirror the distfile instead.
MASTER_SITES=		http://distfiles.nl/

MODULES=		devel/gettext \
			lang/python \
			textproc/intltool

RUN_DEPENDS=		devel/desktop-file-utils \
			devel/py-minimock \
			net/mygpoclient \
			textproc/py-feedparser \
			x11/dbus-python \
			x11/py-gtk2
REGRESS_DEPENDS=	devel/py-minimock \
			net/mygpoclient \
			textproc/py-feedparser

USE_GMAKE=		Yes
MAKE_FILE=		makefile
MAKE_ENV=		PYTHON=${MODPY_BIN}

REGRESS_TARGET=		unittest

# Additional targets
post-build:
	cd ${WRKSRC} && ${SETENV} -i ${MAKE_ENV} ${MAKE_PROGRAM} \
		-f ${MAKE_FILE} messages

do-install:
	cd ${WRKSRC} && ${SETENV} -i ${MAKE_ENV} ${MAKE_PROGRAM} \
		-f ${MAKE_FILE} install
	# Move manpages to the right place..darn you setup.py
	mv ${PREFIX}/share/man/man1/*.1 ${PREFIX}/man/man1/ && \
		rm -fr ${PREFIX}/share/man

.include <bsd.port.mk>
