# $OpenBSD$

COMMENT =	formular fu for catalyst

MODULES =	cpan
DISTNAME =	Catalyst-Controller-HTML-FormFu-0.06001
CATEGORIES =	www textproc
USE_GROFF =	Yes

MAINTAINER =	Simon Bertrang <simon@openbsd.org>

# Perl
PERMIT_PACKAGE_CDROM =		Yes
PERMIT_PACKAGE_FTP =		Yes
PERMIT_DISTFILES_CDROM =	Yes
PERMIT_DISTFILES_FTP =		Yes

BUILD_DEPENDS =		devel/p5-Task-Weaken

RUN_DEPENDS =		devel/p5-Config-Any>=0.23 \
			devel/p5-Moose \
			textproc/p5-Regexp-Assemble \
			www/p5-HTML-FormFu>=0.07003 \
			www/p5-Catalyst-Component-InstancePerContext \
			devel/p5-MRO-Compat \
			devel/p5-namespace-autoclean

REGRESS_DEPENDS =	devel/p5-Config-General \
			devel/p5-Test-WWW-Mechanize>=1.16 \
			devel/p5-Test-WWW-Mechanize-Catalyst \
			textproc/p5-Catalyst-View-TT \
			www/p5-Catalyst-Action-RenderView \
			www/p5-Catalyst-Plugin-ConfigLoader \
			www/p5-Catalyst-Plugin-Session \
			www/p5-Catalyst-Plugin-Session-State-Cookie \
			www/p5-Catalyst-Plugin-Session-Store-File

CONFIGURE_STYLE =	modinst

.include <bsd.port.mk>
