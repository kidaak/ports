# $OpenBSD$

COMMENT=	Ruby library to create and parse MIME messages

DISTNAME=	rmail-1.0.0
REVISION =	6
CATEGORIES=	mail

HOMEPAGE=	http://github.com/matta/rubymail

MAINTAINER=	Lawrence Teo <lteo.openbsd1@calyptix.com>

# BSD
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MODULES=	lang/ruby

CONFIGURE_STYLE=ruby gem

do-regress:
	@cd ${WRKBUILD} && ${RUBY} test/runtests.rb

.include <bsd.port.mk>
