# $OpenBSD$

COMMENT=        validate user input from a constraint object

MODULES=	cpan
DISTNAME=	Data-FormValidator-4.63
REVISION=	0
CATEGORIES=     devel
USE_GROFF =	Yes

MAINTAINER=	Simon Bertrang <simon@openbsd.org>

# perl
PERMIT_PACKAGE_CDROM=   Yes
PERMIT_PACKAGE_FTP=     Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=   Yes

RUN_DEPENDS=	graphics/p5-Image-Size \
		devel/p5-Date-Calc \
		devel/p5-Perl6-Junction \
		misc/p5-File-MMagic \
		mail/p5-Email-Valid \
		mail/p5-MIME-Types \
		textproc/p5-Regexp-Common
REGRESS_DEPENDS=www/p5-CGI-Simple

CONFIGURE_STYLE=modbuild

.include <bsd.port.mk>
