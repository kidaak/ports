# $OpenBSD$

COMMENT =		C library for (embedded) Linux
DISTNAME =		uClibc-0.9.33.1
PKGNAME =		${DISTNAME:L}
CATEGORIES =		devel
HOMEPAGE =		http://www.uclibc.org/

MAJOR=0
MINOR=0
SHARED_LIBS +=		c	${MAJOR}.${MINOR}
SHARED_LIBS +=		crypt	${MAJOR}.${MINOR}
SHARED_LIBS +=		dl	${MAJOR}.${MINOR}
SHARED_LIBS +=		m	${MAJOR}.${MINOR}
SHARED_LIBS +=		pthread	${MAJOR}.${MINOR}
SHARED_LIBS +=		rt	${MAJOR}.${MINOR}

.for A B in ${SHARED_LIBS}
   MAKE_FLAGS +=	lib${A}_FULL_NAME=lib${A}.so.${MAJOR}.${MINOR}
.endfor

MAKE_FLAGS +=		UCLIBC_LDSO_NAME=ld
MAKE_FLAGS +=		ldso_FULL_NAME=ld.so.${MAJOR}.${MINOR}

# LGPL 2.1
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

MASTER_SITES =		${HOMEPAGE}downloads/
EXTRACT_SUFX =		.tar.xz

#MODULES =		???
BUILD_DEPENDS =		archivers/gtar
#RUN_DEPENDS =		???
#LIB_DEPENDS =		???
#REGRESS_DEPENDS =	???

MAKE_FLAGS +=		MAJOR_VERSION=${MAJOR}		\
			MINOR_VERSION=${MINOR}		\
			SUBLEVEL=0			\
			EXTRAVERSION=0			\
			VERSION=			\
			ABI_VERSION=0.0			\
			TAR=gtar			\
			PREFIX="${DESTDIR}"		\
			DEVEL_PREFIX="${PREFIX}/"	\
			RUNTIME_PREFIX="${PREFIX}/"	\
			MULTILIB_DIR=lib/		\
			MAKE_IS_SILENT=n		\
			SECHO=@echo			\
			VERBOSE=1			\
			CC="${CC}"
#MAKE_ENV =		???

USE_GMAKE =		Yes

#CFLAGS =		???
#LDFLAGS =		???

REGRESS_TARGET =	test

do-configure:
	cd "${WRKBUILD}" && \
		env -i ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} defconfig
	cd "${WRKBUILD}" && patch < "${FILESDIR}/config.patch"

post-install:
	ln -s "ld.so.${MAJOR}.${MINOR}" "${PREFIX}/lib/ld.so"
	${INSTALL_MAN} "${WRKBUILD}/docs/man/ldd.1" "${PREFIX}/man/man1/"
	${INSTALL_MAN} "${WRKBUILD}/docs/man/ldconfig.8" "${PREFIX}/man/man8/"

.include <bsd.port.mk>
