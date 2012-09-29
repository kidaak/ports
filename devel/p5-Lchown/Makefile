# $OpenBSD$

SHARED_ONLY=	Yes

COMMENT=	perl interface to the lchown(2) system call

DISTNAME=	Lchown-1.01
REVISION=	2

CATEGORIES=	devel

MAINTAINER=	Alexander Bluhm <bluhm@openbsd.org>

# perl
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB += c

MODULES=		cpan
CPAN_AUTHOR=		NCLEATON
USE_GROFF =		Yes

CONFIGURE_STYLE=	modbuild

.include <bsd.port.mk>
