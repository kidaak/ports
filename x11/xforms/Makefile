# $OpenBSD$

COMMENT=	GUI toolkit for X11

DISTNAME=	xforms-1.0
REVISION=	2
SHARED_LIBS=	flimage	1.0 \
		forms	1.0 \
		formsGL	1.0
CATEGORIES=	x11

HOMEPAGE=	http://xforms-toolkit.org/

MASTER_SITES=	${MASTER_SITE_SAVANNAH:=xforms/}

# LGPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB=		GL X11 Xau Xdmcp Xext Xpm c jpeg m tiff

USE_GROFF =		Yes
CONFIGURE_STYLE=	imake
MAKE_FLAGS=		LIBflimage_VERSION=${LIBflimage_VERSION} \
			LIBforms_VERSION=${LIBforms_VERSION} \
			LIBformsGL_VERSION=${LIBformsGL_VERSION} \
			OPTIMIZER="${CFLAGS}"

BUILD_DEPENDS=		graphics/jpeg

LIB_DEPENDS=		graphics/tiff

NO_REGRESS=		Yes

# crud confuses update-plist
post-extract:
	@find ${WRKDIST} -name \*.orig -print0 | xargs -0 rm

.include <bsd.port.mk>
