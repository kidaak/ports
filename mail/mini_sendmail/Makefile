# $OpenBSD$

COMMENT-main=	accept email on behalf of real sendmail
COMMENT-chroot=	static mini_sendmail for chrooted apache

V=		1.3.6
DISTNAME=	mini_sendmail-${V}
PKGNAME-main=	mini_sendmail-${V}
REVISION-main=	3
PKGNAME-chroot=	mini_sendmail-chroot-${V}
REVISION-chroot=1
CATEGORIES=	mail www
MASTER_SITES=	${HOMEPAGE}

HOMEPAGE=	http://www.acme.com/software/mini_sendmail/

# BSD
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes

NO_REGRESS=	Yes

MAKE_ENV+=	LDFLAGS="${LDFLAGS}"

MULTI_PACKAGES=	-main -chroot

PREFIX-chroot=	/var/www
WANTLIB-main=	c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mini_sendmail ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mini_sendmail
	${INSTALL_MAN} ${WRKSRC}/mini_sendmail.8 ${PREFIX}/man/man8
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/mini_sendmail
	${INSTALL_PROGRAM_DIR} ${WRKINST}/var/www/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mini_sendmail-static \
		${WRKINST}/var/www/bin/mini_sendmail

.include <bsd.port.mk>
