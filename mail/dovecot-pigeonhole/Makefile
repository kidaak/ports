# $OpenBSD$

SHARED_ONLY=	Yes

COMMENT=	Sieve mail filtering for Dovecot

V_SIEVE=	0.3.3
V_DOVECOT=	2.1
V_DOVECOT_FULL=	2.1.10

DISTNAME=	dovecot-${V_DOVECOT}-pigeonhole-${V_SIEVE}
EPOCH=		0
CATEGORIES=	mail
PKGNAME=	dovecot-pigeonhole-${V_SIEVE}
MASTER_SITES=	http://www.rename-it.nl/dovecot/${V_DOVECOT}/

SHARED_LIBS=	dovecot-sieve	1.0

HOMEPAGE=	http://pigeonhole.dovecot.org/

MAINTAINER=	Brad Smith <brad@comstyle.com>

# LGPLv2.1
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB=	${MODLIBICONV_WANTLIB} c crypto ssl \
		lib/dovecot/dovecot-lda lib/dovecot/dovecot-login \
		lib/dovecot/dovecot-storage lib/dovecot/dovecot

MODULES=	converters/libiconv
LIB_DEPENDS=	mail/dovecot=${V_DOVECOT_FULL}

USE_LIBTOOL=	Yes
CONFIGURE_STYLE= gnu
CONFIGURE_ARGS=	--docdir=${PREFIX}/share/doc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-install:
	@find ${PREFIX}/lib/dovecot -name '*.a' -print | xargs rm
	@find ${PREFIX}/lib/dovecot -name '*.la' -print | xargs rm

.include <bsd.port.mk>
