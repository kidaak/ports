# $OpenBSD$

COMMENT =	real-time stats toolkit for Rack HTTP servers

DISTNAME =	raindrops-0.8.0
REVISION =	0
CATEGORIES =	www

MAINTAINER =	Jeremy Evans <jeremy@openbsd.org>

# LGPLv2.1/LGPLv3
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =	Yes
PERMIT_DISTFILES_FTP =	Yes

MODULES =	lang/ruby

CONFIGURE_STYLE =	ruby gem ext

# XXX only actually required for gcc2/3 arch
BUILD_DEPENDS +=	libatomic_ops-*:devel/boehm-gc,-atomic

REGRESS_DEPENDS =	devel/gmake \
			www/ruby-unicorn,${MODRUBY_FLAVOR} \
			${FULLPKGNAME}:${BUILD_PKGPATH}

do-regress:
	cd ${WRKSRC} && ${SETENV} RUBYOPT=-rubygems \
		RUBYLIB=${WRKSRC}/lib gmake test RUBY=${RUBY}

.include <bsd.port.mk>
