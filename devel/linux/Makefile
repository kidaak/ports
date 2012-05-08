# $OpenBSD$

# XXX: Remember to adjust INSTALL_HDR_PATH once PREFIX=/ 
#PREFIX =		/

COMMENT =		Linux kernel
DISTNAME =		linux-3.3.5
CATEGORIES =		devel

HOMEPAGE =		http://kernel.org/

# GPLv2, LGPL, Mozilla 1.0
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

MASTER_SITES =		${HOMEPAGE}pub/linux/kernel/v3.0/
EXTRACT_SUFX =		.tar.bz2

BUILD_DEPENDS =		lang/perl
REGRESS_DEPENDS =	lang/perl		\
			misc/findutils		\
			sysutils/binutils

MAKE_FLAGS +=		O=${WRKBUILD}/
MAKE_FLAGS +=		CC="${CC}"
MAKE_FLAGS +=		HOSTCC="${CC}"
MAKE_FLAGS +=		HOSTCXX="${CXX}"
MAKE_FLAGS +=		INSTALL_HDR_PATH="${DESTDIR}${PREFIX}" # XXX
MAKE_ENV +=		KBUILD_VERBOSE=1
MAKE_ENV +=		CONFIG_SHELL=/bin/sh
MAKE_ENV +=		INSTALL_MOD_PATH=${DESTDIR}${PREFIX}

SEPARATE_BUILD =	Yes
USE_GMAKE =		Yes

INSTALL_TARGET =	modules_install firmware_install headers_install
REGRESS_TARGET =	namespacecheck versioncheck includecheck headers_check headerdep

do-configure:
	cd ${WRKSRC} && \
		env -i ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} defconfig

post-install:
	${INSTALL_DATA_DIR} "${PREFIX}/boot"
	${INSTALL_DATA} \
		"${WRKBUILD}/arch/${MACHINE_ARCH}/boot/bzImage" \
		"${PREFIX}/boot"
	find ${PREFIX} -type f \( -name '..install.cmd' -o -name '.install' \) -print0 | \
		xargs -0r rm -f

.include <bsd.port.mk>
