# $OpenBSD$

PKG_ARCH=	*

COMMENT=	TrueType fonts for Indic scripts

VERSION=	2.5.0
PKGNAME=	lohit-fonts-${VERSION}
CATEGORIES=	fonts x11
HOMEPAGE=	https://fedorahosted.org/lohit/

MAINTAINER=	Christian Weisgerber <naddy@openbsd.org>

# SIL OFL 1.1
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=	https://fedorahosted.org/releases/l/o/lohit/
.for s in	assamese bengali devanagari gujarati kannada \
		malayalam oriya punjabi tamil telugu
DISTFILES+=	lohit-$s-ttf-${VERSION}.tar.gz
.endfor

NO_BUILD=	Yes
NO_REGRESS=	Yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/X11/fonts/lohit
	${INSTALL_DATA} ${WRKDIST}/*/*.ttf ${PREFIX}/lib/X11/fonts/lohit
	${INSTALL_DATA} ${WRKDIST}/lohit-devanagari-ttf-${VERSION}/OFL.txt \
	    ${PREFIX}/lib/X11/fonts/lohit

.include <bsd.port.mk>
