# $OpenBSD$

COMMENT=	Linux libc5

PKGNAME=	redhat_libc5-6.2
REVISION=	2

MASTER_SITES=	${MASTER_SITE_REDHAT:=redhat/linux/6.2/en/os/i386/RedHat/RPMS/}
MASTER_SITES0=	${MASTER_SITE_REDHAT:=redhat/linux/updates/6.2/en/os/i386/}

DISTFILES=	${RPMS}

RPMDIR=		${FULLDISTDIR}

RPMS=		libc-5.3.12-31.i386.rpm \
		ld.so-1.9.5-13.i386.rpm 

RUN_DEPENDS=	emulators/fedora/base

NO_BUILD=	Yes
NO_REGRESS=	Yes
USE_GROFF =	Yes

PREFIX=		${LOCALBASE}/emul/fedora

pre-install:
	@${INSTALL_DATA_DIR} ${PREFIX}

do-install:
.for rpm in ${RPMS:S/:0//}
	@cd ${PREFIX}; ${LOCALBASE}/bin/rpm2cpio ${RPMDIR}/${rpm} | cpio -id
.endfor

.include <bsd.port.mk>
