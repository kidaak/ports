# $OpenBSD$

COMMENT= 	combines WWW::Mechanize and HTML::TreeBuilder

MODULES=	cpan

DISTNAME=	WWW-Mechanize-TreeBuilder-1.10003
REVISION=	1
CATEGORIES=	www
USE_GROFF =	Yes

# Perl
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

RUN_DEPENDS=	devel/p5-MooseX-Role-Parameterized \
		www/p5-WWW-Mechanize \
		www/p5-HTML-Tree

REGRESS_DEPENDS=devel/p5-Test-WWW-Mechanize \
		www/p5-HTML-TreeBuilder-XPath

.include <bsd.port.mk>
