# $OpenBSD$

SHARED_ONLY=	Yes

COMMENT-main=	file archiver with high compression ratio
COMMENT-rar=	rar modules for p7zip

V=		9.20.1
DISTNAME=	p7zip_${V}_src_all
PKGNAME=	p7zip-${V}
PKGNAME-main=	p7zip-${V}
PKGNAME-rar=	p7zip-rar-${V}
REVISION-main=	0
REVISION-rar=	1
CATEGORIES=	archivers

HOMEPAGE=	http://sourceforge.net/projects/p7zip/

MAINTAINER=	Josh Grosse <josh@jggimi.homeip.net>

# LGPL, except unRar plugin which is licensed as Freeware
PERMIT_PACKAGE_CDROM-rar=	no fee
PERMIT_PACKAGE_CDROM=		Yes
PERMIT_PACKAGE_FTP=		Yes 
PERMIT_DISTFILES_CDROM=		no fee
PERMIT_DISTFILES_FTP=		Yes 

WANTLIB=	m pthread stdc++
WANTLIB-main=	${WANTLIB} c
WANTLIB-rar=	${WANTLIB}

MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=p7zip/}
EXTRACT_SUFX=	.tar.bz2

MULTI_PACKAGES=	-main -rar

RUN_DEPENDS-rar= ${BASE_PKGPATH},-main

WRKDIST=	${WRKDIR}/p7zip_${V}

USE_GMAKE=	Yes
MAKE_FILE=	makefile
MAKE_FLAGS=	MYCC="${CC}" MYCXX="${CXX}" \
		MYCFLAGS="${CFLAGS}" MYCXXFLAGS="${CXXFLAGS}"

ALL_TARGET=	all3
REGRESS_TARGET=	all_test

do-configure:
	cp ${WRKSRC}/makefile.openbsd ${WRKSRC}/makefile.machine

do-install:
	@cd ${WRKBUILD} && ${SETENV} ${MAKE_ENV} PREFIX=${TRUEPREFIX} \
		DESTDIR=${DESTDIR} /bin/sh install.sh

.include <bsd.port.mk>
