# $OpenBSD$

COMMENT=	alpha-release readers for reading SOUP and QWK packets

DISTNAME=	plor-0.3.2
CATEGORIES=	news

# License: GPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes
WANTLIB=		c

MASTER_SITES=	ftp://linux.psy.unipd.it/pub/pluto/developers/utils/

CONFIGURE_STYLE=	gnu dest

DOCFILES=	plor.html plor-1.html plor-2.html plor.txt
USE_GROFF =	Yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/plor
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/docs/${f} ${PREFIX}/share/doc/plor
.endfor
	${INSTALL_MAN} ${FILESDIR}/plor.1 ${PREFIX}/man/man1/plor.1
	perl -pi -e '$$a = '\''${PREFIX}/share/doc/plor/'\''; $$a =~ s/([^\w\/])/\\$$1/g; s/FUNKYTOKENHERE/$$a/' ${PREFIX}/man/man1/plor.1

.include <bsd.port.mk>
