# $OpenBSD$
# PHP PECL module

MODULES +=	lang/php

SHARED_ONLY ?=	Yes
CATEGORIES +=	www

PKGNAME ?=	pecl-${DISTNAME:S/pecl-//:S/_/-/:L}
_PECLMOD ?=	${DISTNAME:S/pecl-//:C/-[0-9].*//:L}

.if !defined(MASTER_SITES)
MASTER_SITES ?=	http://pecl.php.net/get/
HOMEPAGE ?=	http://pecl.php.net/package/${_PECLMOD}
EXTRACT_SUFX ?=	.tgz
.endif

# XXX CONFIGURE_STYLE would be nice but it can't be set here
AUTOCONF_VERSION ?= 2.62
AUTOMAKE_VERSION ?= 1.9

USE_LIBTOOL ?=	Yes
LIBTOOL_FLAGS += --tag=disable-static

DESTDIRNAME ?=	INSTALL_ROOT

BUILD_DEPENDS += www/pear \
	${MODGNU_AUTOCONF_DEPENDS} \
	${MODGNU_AUTOMAKE_DEPENDS}

MODPHP_DO_SAMPLE ?= ${_PECLMOD}
MODPHP_DO_PHPIZE ?= Yes

.if !target(do-regress) && ${NO_REGRESS:L:Mno}
REGRESS_TARGET = test
REGRESS_FLAGS =  NO_INTERACTION=1
.endif

.if ${SHARED_ONLY:L} == "yes"
WANTLIB += c
.endif
