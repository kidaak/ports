# $OpenBSD$

COMMENT=	Simple regular expression library from Plan 9

VERSION=	2.0
DISTNAME=	libregexp9-${VERSION}
CATEGORIES=	devel plan9
MASTER_SITES=	${HOMEPAGE}
HOMEPAGE=	http://pdos.lcs.mit.edu/~rsc/software/
MAINTAINER=	Markus Friedl <markus@openbsd.org>
EXTRACT_SUFX=	.tgz

BUILD_DEPENDS=	devel/libutf \
		devel/libfmt

PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

FAKE_FLAGS=	PREFIX=${WRKINST}${PREFIX}
USE_GROFF =	Yes
REGRESS_TARGET=	test

pre-build:
	@cp ${FILESDIR}/Make.OpenBSD ${WRKSRC}

.include <bsd.port.mk>
