# $OpenBSD$

COMMENT=		convert OpenDocument Text to plain text

DISTNAME=		odt2txt-0.4
REVISION =		0
CATEGORIES=		textproc

HOMEPAGE=		http://stosberg.net/odt2txt/

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=	${HOMEPAGE}

MODULES=	converters/libiconv

WANTLIB += c z

USE_GMAKE=	Yes
USE_GROFF =	Yes

NO_REGRESS=	Yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/odt2txt ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/odt2txt.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
