# $OpenBSD$

COMMENT=	addressbook program with mutt support

DISTNAME=	abook-0.5.6
REVISION=	0
CATEGORIES=	mail

HOMEPAGE=	http://abook.sourceforge.net/

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes
WANTLIB=		c ncurses readline

MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=abook/}

MODULES=	devel/gettext

CONFIGURE_STYLE=gnu

EXAMPLESDIR=	${PREFIX}/share/examples/abook
WHITELIST=README abook2whitelist.sh mutt.whitelist whitelist.rc
USE_GROFF =	Yes

post-install:
	${INSTALL_DATA_DIR} ${EXAMPLESDIR}/whitelist
	${INSTALL_DATA} ${WRKSRC}/contrib/mail2abook.py ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/vcard2abook.pl ${EXAMPLESDIR}
	cd ${WRKSRC}/contrib/whitelist && \
		${INSTALL_DATA} ${WHITELIST} ${EXAMPLESDIR}/whitelist
	${INSTALL_DATA} ${WRKSRC}/sample.abookrc ${EXAMPLESDIR}

.include <bsd.port.mk>
