# $RuOBSD: Makefile,v 1.3 2002/04/10 05:14:52 form Exp $
# $OpenBSD$

COMMENT=		Joe's Own Editor

DISTNAME=		joe-3.7
REVISION=		1
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=joe-editor/}

HOMEPAGE=		http://joe-editor.sourceforge.net/

# GPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB=		c ncurses m util

CONFIGURE_STYLE=	gnu

USE_GROFF =	Yes
FAKE_FLAGS=	sysconf_joedir=${PREFIX}/share/examples/joe \
		sysconf_docdir=${PREFIX}/share/doc/joe

.include <bsd.port.mk>
