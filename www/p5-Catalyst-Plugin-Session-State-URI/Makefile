# $OpenBSD$

COMMENT=	catalyst session IDs as URI extensions

MODULES=	cpan
DISTNAME=	Catalyst-Plugin-Session-State-URI-0.15
CATEGORIES=	www
USE_GROFF =	Yes

MAINTAINER=	Simon Bertrang <simon@openbsd.org>

# Perl
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

RUN_DEPENDS=	devel/p5-Class-Data-Inheritable \
		devel/p5-Moose \
		devel/p5-MooseX-Emulate-Class-Accessor-Fast \
		devel/p5-MRO-Compat \
		devel/p5-namespace-clean \
		mail/p5-MIME-Types \
		www/p5-HTML-TokeParser-Simple \
		www/p5-URI \
		www/p5-Catalyst-Plugin-Session>=0.27 \
		www/p5-URI-Find
REGRESS_DEPENDS=devel/p5-Test-MockObject \
		www/p5-Catalyst-Plugin-Session-State-Cookie

MAKE_ENV=	TEST_POD=Yes

CONFIGURE_STYLE =	modinst

.include <bsd.port.mk>
