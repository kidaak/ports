# $OpenBSD$

COMMENT =	clone of backtrace facility found in the GNU libc

V =		0.2
DISTNAME =	backtrace-$V
PKGNAME =	libexecinfo-$V
REVISION =	2
EPOCH =		0
CATEGORIES =	devel

SHARED_LIBS =	execinfo	2.0

HOMEPAGE =	http://opensource.conformal.com/wiki/Backtrace
MASTER_SITES =	http://opensource.conformal.com/snapshots/backtrace/
EXTRACT_SUFX =	.tgz

# BSD
PERMIT_PACKAGE_CDROM =		Yes
PERMIT_PACKAGE_FTP =		Yes
PERMIT_DISTFILES_CDROM =	Yes
PERMIT_DISTFILES_FTP =		Yes

WANTLIB=	c
CFLAGS+=	-Wl,--export-dynamic
LDFLAGS+=	-Wl,--export-dynamic

MAKE_FLAGS =	LIB=execinfo
FAKE_FLAGS =	PREFIX=${WRKINST}/${TRUEPREFIX} \
		MANDIR=${PREFIX}/man/man

.if ${MACHINE_ARCH:Mmips64*} || ${MACHINE_ARCH:Mhppa} || ${MACHINE_ARCH:Marm}
CFLAGS+=	-D__BUILTIN_HACK
.endif

do-configure:
	printf "major=${LIBexecinfo_VERSION:R}\nminor=${LIBexecinfo_VERSION:E}\n" \
	    > ${WRKSRC}/libbacktrace/shlib_version

post-install:
	mv ${PREFIX}/include/backtrace.h ${PREFIX}/include/execinfo.h
	${INSTALL_PROGRAM} ${WRKDIST}/examples/backtrace_test \
		${PREFIX}/bin/backtrace_test

.include <bsd.port.mk>
