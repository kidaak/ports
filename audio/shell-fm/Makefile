# $OpenBSD$

COMMENT=		console based player for last.fm radio streams

DISTNAME=		shell-fm-0.20120417
REVISION=		0

CATEGORIES=		audio

HOMEPAGE=		http://nex.scrapping.cc/shell-fm/

MAINTAINER=		David Coppa <dcoppa@openbsd.org>

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB +=		ao c m mad stdc++ tag tag_c z

MASTER_SITES=		http://distfiles.nl/

LIB_DEPENDS=		audio/libao \
			audio/libmad \
			audio/taglib

USE_GMAKE=		Yes

MAKE_FLAGS=		CC="${CC}"

FAKE_FLAGS=		INSTALL_MAN="${INSTALL_MAN}" \
			INSTALL_PROGRAM="${INSTALL_PROGRAM}"

NO_REGRESS=		Yes

.include <bsd.port.mk>
