# $OpenBSD$

COMMENT =	simple AMQP driver for Ruby

DISTNAME =	amqp-0.6.7
REVISION =	4
CATEGORIES =	net

# Ruby license
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MODULES =	lang/ruby

CONFIGURE_STYLE = ruby gem

BUILD_DEPENDS =	${RUN_DEPENDS}
RUN_DEPENDS =	net/ruby-eventmachine,${MODRUBY_FLAVOR}

REGRESS_DEPENDS =	${FULLPKGNAME}:${BUILD_PKGPATH} \
			devel/ruby-bacon,${MODRUBY_FLAVOR} 
MODRUBY_REGRESS =	rake 
MODRUBY_REGRESS_TARGET = spec

.include <bsd.port.mk>
