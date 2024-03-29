# $OpenBSD$

# version comes from the .spec file or setup.py for -full

COMMENT ?=	Mozilla sync server - ${PART}
DISTNAME =	server-${PART}-${MODPY_EGG_VERSION}.20120901
DIST_SUBDIR =	mozilla
PKGNAME ?=	mozilla-sync-${PART}-${MODPY_EGG_VERSION}.pre20120901
CATEGORIES=	www www/mozilla-sync
WRKDIST ?=	${WRKDIR}/server-${PART}
MASTER_SITES ?=	http://rhaalovely.net/stuff/

# MPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MODULES =	lang/python
MODPY_SETUPTOOLS =	Yes
