# $OpenBSD$

COMMENT=	Catalyst FormBuilder Base Controller

MODULES=	cpan
DISTNAME=	Catalyst-Controller-FormBuilder-0.06
CATEGORIES=	www
USE_GROFF =	Yes

MAINTAINER=	Simon Bertrang <simon@openbsd.org>

# Perl
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

RUN_DEPENDS=	devel/p5-MRO-Compat \
		devel/p5-Test-WWW-Mechanize-Catalyst \
		devel/p5-Tie-IxHash \
		www/p5-CGI-FormBuilder \
		www/p5-Catalyst-Runtime \
		devel/p5-Class-Data-Inheritable>=0.04 \
		devel/p5-Class-Inspector>=1.13

CONFIGURE_STYLE =	modinst

.include <bsd.port.mk>
