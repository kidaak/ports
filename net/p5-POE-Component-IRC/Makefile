# $OpenBSD$

COMMENT=	event-driven IRC-client module

DISTNAME=	POE-Component-IRC-6.52
CATEGORIES=	net
USE_GROFF =	Yes

MAINTAINER=	Jasper Lievisse Adriaanse <jasper@openbsd.org>

# perl
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MODULES=		cpan
MODCPAN_EXAMPLES=	Yes

RUN_DEPENDS=	devel/p5-Object-Pluggable \
		devel/p5-POE>=1.287 \
		net/p5-POE-Component-Client-DNS>=0.99 \
		net/p5-POE-Filter-IRCD>=2.42 \
		archivers/p5-POE-Filter-Zlib

# Not listed in PREREQ_PM, but needed for SSL connections.
RUN_DEPENDS=	security/p5-POE-Component-SSLify
REGRESS_DEPENDS=${RUN_DEPENDS}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/p5-POE-Component-IRC
	${INSTALL_DATA} ${WRKSRC}/docs/* \
		${PREFIX}/share/doc/p5-POE-Component-IRC
	${MODCPAN_POST_INSTALL}

.include <bsd.port.mk>
