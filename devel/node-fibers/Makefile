# $OpenBSD$

# Currently node itself is only for amd64 and i386, but
# the coroutine library this uses only works on amd64
# and i386, so even if other arches are supported by node
# later, this extension will only support these arches.
ONLY_FOR_ARCHS= amd64 i386

COMMENT =	fiber/coroutine support for Node.js

NPM_VERSION =	0.6.8
NPM_NAME =	fibers
REVISION =	0
CATEGORIES =	devel

MAINTAINER =	Jeremy Evans <jeremy@openbsd.org>

HOMEPAGE =	https://github.com/laverdet/node-fibers

# MIT
PERMIT_PACKAGE_CDROM = Yes
PERMIT_PACKAGE_FTP = Yes
PERMIT_DISTFILES_CDROM = Yes
PERMIT_DISTFILES_FTP = Yes

MODULES =		lang/node

CONFIGURE_STYLE =	npm ext
USE_GMAKE =		Yes
FIBERS_ARCH =		openbsd-${PKG_ARCH:S/amd64/x64/:S/i386/ia32/}
SUBST_VARS =		FIBERS_ARCH

MODNODE_DEPENDS ?= 	node-gyp
REGRESS_DEPENDS =	${BUILD_PKGPATH}

do-regress:
	cd ${WRKDIST} && node test.js

.include <bsd.port.mk>
