# $OpenBSD$

COMMENT =	HTML form creation, rendering and validation framework

MODULES =	cpan
DISTNAME =	HTML-FormFu-0.07003
CATEGORIES =	www textproc
USE_GROFF =	Yes

MAINTAINER =	Simon Bertrang <simon@openbsd.org>

# Perl
PERMIT_PACKAGE_CDROM =		Yes
PERMIT_PACKAGE_FTP =		Yes
PERMIT_DISTFILES_CDROM =	Yes
PERMIT_DISTFILES_FTP =		Yes

BUILD_DEPENDS =		devel/p5-Task-Weaken

RUN_DEPENDS =		devel/p5-Class-Accessor-Chained \
			devel/p5-Clone \
			devel/p5-Config-Any>=0.23 \
			devel/p5-Data-Visitor \
			devel/p5-Date-Calc \
			devel/p5-DateTime-Format-Builder \
			devel/p5-DateTime-Format-Natural \
			devel/p5-DateTime-Format-Strptime \
			devel/p5-DateTime-Locale \
			devel/p5-File-ShareDir \
			devel/p5-Hash-Flatten \
			devel/p5-List-MoreUtils \
			devel/p5-MRO-Compat \
			devel/p5-Path-Class \
			devel/p5-Readonly \
			devel/p5-YAML-XS \
			graphics/p5-Captcha-reCAPTCHA \
			mail/p5-Email-Valid \
			security/p5-Crypt-CBC \
			security/p5-Crypt-DES \
			textproc/p5-Number-Format \
			textproc/p5-Regexp-Common \
			textproc/p5-Template \
			www/p5-HTML-Scrubber \
			www/p5-HTML-TokeParser-Simple \
			www/p5-libwww

REGRESS_DEPENDS =	devel/p5-Test-NoWarnings

CONFIGURE_STYLE =	modinst

.include <bsd.port.mk>
