# $OpenBSD$

COMMENT=	a ruby timer based on SIGALRM

DISTNAME=	SystemTimer-1.2.3
PKGNAME=	${DISTNAME:L}
REVISION=	1
CATEGORIES=	devel

# ruby or gpl
PERMIT_PACKAGE_CDROM=	yes
PERMIT_PACKAGE_FTP=	yes
PERMIT_DISTFILES_CDROM=	yes
PERMIT_DISTFILES_FTP=	yes

MODULES=	lang/ruby

CONFIGURE_STYLE=ruby gem ext

FLAVORS=	ruby18
FLAVOR=		ruby18

# Regress tests not enabled, as they depend on ruby-dust,
# which is dead upstream and won't be imported.  You can
# manually install the gem if you want to run the regress
# tests.
#REGRESS_DEPENDS =	${FULLPKGNAME}:${BUILD_PKGPATH} \
#			devel/ruby-mocha,${MODRUBY_FLAVOR}
#MODRUBY_REGRESS =	ruby
#MODRUBY_REGRESS_TARGET = -rubygems test/all_tests.rb

.include <bsd.port.mk>
