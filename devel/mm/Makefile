# $OpenBSD$

# XXX This will panic any vax
NOT_FOR_ARCHS=	vax

COMMENT=	shared memory lib for apps with pre-forked process model

DISTNAME=	mm-1.3.1
REVISION =	0
SHARED_LIBS=	mm 13.21

CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.ossp.org/pkg/lib/mm/

HOMEPAGE=	http://www.ossp.org/pkg/lib/mm/

# BSD
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

USE_LIBTOOL=	 Yes
USE_GROFF =	Yes
CONFIGURE_STYLE= gnu
CONFIGURE_ARGS+= ${CONFIGURE_SHARED}
CONFIGURE_ARGS+= --enable-static

REGRESS_TARGET=	test

.include <bsd.port.mk>
