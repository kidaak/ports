# $OpenBSD$

COMMENT =	japanese input engine for ibus

DISTNAME =	ibus-anthy-1.2.6
REVISION=	1

CATEGORIES =	inputmethods japanese

HOMEPAGE =	http://code.google.com/p/ibus/

# GPLv2
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM = Yes
PERMIT_DISTFILES_FTP =	Yes

WANTLIB =	anthy anthydic m util ${MODPY_WANTLIB}

MASTER_SITES =	http://ibus.googlecode.com/files/

MODULES =	lang/python \
		textproc/intltool

BUILD_DEPENDS =	devel/swig
RUN_DEPENDS =	inputmethods/ibus
LIB_DEPENDS =	inputmethods/anthy \
		${MODPY_LIB_DEPENDS}

USE_GMAKE =	Yes
USE_LIBTOOL =	Yes
LIBTOOL_FLAGS =	--tag=disable-static

CONFIGURE_STYLE =	gnu
CONFIGURE_ENV =	CPPFLAGS="-I${LOCALBASE}/include"

.include <bsd.port.mk>
