# $OpenBSD$

COMMENT=		HTML Abstraction Markup Language for Ruby

DISTNAME=		haml-2.2.2
REVISION =		4
CATEGORIES=		textproc

HOMEPAGE=		http://haml.hamptoncatlin.com/

# MIT
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MODULES=		lang/ruby

CONFIGURE_STYLE=	ruby gem

BUILD_DEPENDS=		${RUN_DEPENDS}
RUN_DEPENDS=		textproc/ruby-hpricot,${MODRUBY_FLAVOR}

REGRESS_DEPENDS=	devel/ruby-actionpack,${MODRUBY_FLAVOR}

MODRUBY_REGRESS=	rake

.include <bsd.port.mk>
