# $OpenBSD$

COMMENT=	event-driven I/O for Ruby using the Reactor pattern

DISTNAME=	eventmachine-0.12.8
REVISION =	5
CATEGORIES=	net devel

HOMEPAGE=	http://rubyeventmachine.com/

# ruby or gpl2
PERMIT_PACKAGE_CDROM=	yes
PERMIT_PACKAGE_FTP=	yes
PERMIT_DISTFILES_CDROM=	yes
PERMIT_DISTFILES_FTP=	yes

MODULES=	lang/ruby

WANTLIB=	crypto ssl stdc++

CONFIGURE_STYLE=ruby gem ext

MODRUBY_REGRESS =	rake

do-regress:
	cd ${WRKSRC} && RUBYOPT=-Ilib:. ${RAKE} default

.include <bsd.port.mk>
