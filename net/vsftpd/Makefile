# $OpenBSD$

COMMENT=		ftp daemon which aims to be secure

DISTNAME=		vsftpd-2.3.4
REVISION=		0
CATEGORIES=		net

HOMEPAGE =		http://vsftpd.beasts.org/

MAINTAINER =		Benoit Lecocq <benoit@openbsd.org>

# GPLv2+OpenSSL exemption
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB=		c crypto util ssl wrap

MASTER_SITES=		https://security.appspot.com/downloads/

ALL_TARGET=		vsftpd

MAKE_FLAGS=		CC="${CC}" \
			CFLAGS="${CFLAGS}"

USE_GROFF =		Yes
NO_REGRESS =		Yes

do-configure:
	@perl -pi -e "s,%%SYSCONFDIR%%,${SYSCONFDIR}," ${WRKSRC}/defs.h
	@perl -pi -e "s,/usr/share/ssl/certs/,/etc/ssl/private/,g" \
		${WRKSRC}/tunables.c \
		${WRKSRC}/README.ssl
	@perl -pi -e "s,/etc/vsftpd,${SYSCONFDIR}/vsftpd,g" \
		${WRKSRC}/vsftpd.conf.5 \
		${WRKSRC}/vsftpd.8

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/vsftpd
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/vsftpd
	${INSTALL_PROGRAM} ${WRKSRC}/vsftpd ${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/vsftpd.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/vsftpd.conf.5 ${PREFIX}/man/man5
	${INSTALL_DATA} ${WRKSRC}/vsftpd.conf ${PREFIX}/share/examples/vsftpd

.for d in FAQ INSTALL README README.ssl
	${INSTALL_DATA} ${WRKSRC}/$d ${PREFIX}/share/doc/vsftpd
.endfor

.include <bsd.port.mk>
