# $OpenBSD$

COMMENT=		enhanced, MIME capable Berkeley Mail

V=			12.4
REVISION=		2
DISTNAME=		mailx-${V}
PKGNAME=		nail-${V}
CATEGORIES=		mail
HOMEPAGE=		http://heirloom.sourceforge.net/mailx.html

# BSD
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes
WANTLIB=		c crypto ssl

MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=heirloom/}
EXTRACT_SUFX=		.tar.bz2

MODULES=		converters/libiconv

MAKE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib" \

MAKE_FLAGS=		SENDMAIL="/usr/sbin/sendmail" \
			LIBS="-liconv"
USE_GROFF =		Yes

NO_REGRESS=		Yes

do-install:
	${INSTALL_PROGRAM} ${WRKBUILD}/mailx ${PREFIX}/bin/nail
	${INSTALL_MAN} ${WRKSRC}/mailx.1 ${PREFIX}/man/man1/nail.1
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/nail
	${INSTALL_DATA} ${WRKSRC}/nail.rc ${PREFIX}/share/examples/nail/

.include <bsd.port.mk>
