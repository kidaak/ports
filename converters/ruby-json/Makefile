# $OpenBSD$

COMMENT=		JSON implementation for Ruby

DISTNAME=		json-1.5.3
CATEGORIES=		converters
REVISION =		2

HOMEPAGE=		http://json.rubyforge.org/

# Ruby license
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MODULES=		lang/ruby

CONFIGURE_STYLE=	ruby gem ext

MODRUBY_REGRESS=	rake
REGRESS_DEPENDS =	${FULLPKGNAME}:${BUILD_PKGPATH} \
			${MODRUBY_ICONV_DEPENDS}

do-regress:
	cd ${WRKSRC} && /usr/bin/env -i ${MAKE_ENV} RUBYOPT=-rubygems \
		JSON=ext ${MODRUBY_BIN_TESTRB} tests/*.rb

.include <bsd.port.mk>
