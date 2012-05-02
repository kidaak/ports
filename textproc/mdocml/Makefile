# $OpenBSD$

COMMENT =		
DISTNAME =		mdocml-1.12.1
CATEGORIES =		textproc

HOMEPAGE =		http://mdocml.bsd.lv/

# ISC
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

#WANTLIB =		???

MASTER_SITES =		${HOMEPAGE}snapshots/

#MODULES =		???
#BUILD_DEPENDS =	???
#RUN_DEPENDS =		???
#LIB_DEPENDS =		???

MAKE_FLAGS =		PREFIX="${PREFIX}" \
			DBLIB=-ldb \
			LDFLAGS="${LDFLAGS}" \
			STATIC=
MAKE_ENV =		CC="${CC}"
#FAKE_FLAGS =		???

NO_REGRESS =		Yes

#CFLAGS =		???
#LDFLAGS =		???
#MAKE_FILE =		???
#PKG_ARCH =		??? (* for arch-independent packages)
#WRKDIST =		??? if other than ${WRKDIR}/${DISTNAME}
#WRKSRC =		??? if other than ${WRKDIST}
#WRKBUILD =		??? if other than ${WRKSRC}
#WRKCONF =		??? if other than ${WRKBUILD}

#ALL_TARGET =		???
#INSTALL_TARGET =	???
#REGRESS_TARGET =	???

# XXX
post-install:
	mv ${PREFIX}/bin/preconv ${PREFIX}/bin/preconv-mandoc

.include <bsd.port.mk>
