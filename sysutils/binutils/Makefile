# $OpenBSD$

COMMENT =		binary tools
VERSION =		2.22
DISTNAME =		binutils-${VERSION}
CATEGORIES =		sysutils

HOMEPAGE =		http://www.gnu.org/software/binutils/

# GPLv3
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

MASTER_SITES =		${MASTER_SITE_GNU:=binutils/}

#MODULES =		???
#BUILD_DEPENDS =	???
#RUN_DEPENDS =		???
#LIB_DEPENDS =		???
#REGRESS_DEPENDS =	???

#MAKE_FLAGS =		???
#MAKE_ENV =		???

SEPARATE_BUILD =	Yes
USE_LIBTOOL =		Yes

CONFIGURE_STYLE =	gnu
CONFIGURE_ARGS +=	--disable-shared	\
			--disable-nls
#CONFIGURE_ENV =	???

#CFLAGS =		???
LDFLAGS =		-all-static

# We don't version the libs here because they should only be used
# by the tools in this package, instead propagate VERSION
# so that PLIST doesn't need to be regenerated every time
# the software updates.
SUBST_VARS =		VERSION

post-extract:
	ln -s /usr/bin/core_perl/pod2man ${WRKDIR}/bin/pod2man

do-build:
	cd "${WRKBUILD}" && \
		env -i ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} \
			-f ${MAKE_FILE} configure-host && \
		env -i ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} \
			-f ${MAKE_FILE} LDFLAGS="${LDFLAGS}" ${ALL_TARGET}

post-install:
	rm -rf "${PREFIX}/${MACHINE_ARCH}-unknown-linux-gnu/"

.include <bsd.port.mk>
