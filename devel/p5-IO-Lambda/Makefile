# $OpenBSD$

COMMENT=	non-blocking I/O as lambda calculus

DISTNAME=	IO-Lambda-1.20
REVISION=	0
CATEGORIES=	devel

# perl
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MODULES=	cpan

USE_GROFF=	Yes

MODCPAN_EXAMPLES=	Yes
MODCPAN_EXAMPLES_DIST=	eg

RUN_DEPENDS=	devel/p5-Sub-Name \
		net/p5-Net-DNS \
		security/p5-IO-Socket-SSL \
		www/p5-libwww
# Additionally these can be installed:
# 'SNMP'            => 0,     # for IO::Lambda::SNMP
# 'AnyEvent'        => 0,     # for alternative event loop
# 'Authen::NTLM'    => 1.05,  # for HTTP authentication
# 'DBI'             => 0,     # for IO::Lambda::DBI


.include <bsd.port.mk>
