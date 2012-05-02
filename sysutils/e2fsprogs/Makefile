# $OpenBSD: ports/sysutils/e2fsprogs/Makefile,v 1.24 2012/03/29 13:39:00 sthen Exp $
# $FreeBSD: ports/sysutils/e2fsprogs/Makefile,v 1.8 2003/02/20 19:00:47 knu Exp $

COMMENT=		utilities to manipulate ext2 filesystems

DISTNAME=		e2fsprogs-1.41.4
REVISION=		7
CATEGORIES=		sysutils devel
SHARED_LIBS=		blkid		0.0 \
			e2p		3.0 \
			ext2fs		3.0 \
			ext2fs_com_err	3.0 \
			ss		3.0 \
			e2fs-uuid	0.0

HOMEPAGE=		http://e2fsprogs.sourceforge.net/

# GPLv2/LGPLv2/BSD/MIT
PERMIT_PACKAGE_CDROM=   Yes
PERMIT_PACKAGE_FTP=     Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=   Yes

WANTLIB=		c

MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=e2fsprogs/}

MODULES=		devel/gettext

SEPARATE_BUILD= 	Yes
CONFIGURE_STYLE=	gnu
CONFIGURE_ARGS+=	--enable-elf-shlibs --disable-tls
USE_GMAKE=		Yes
USE_GROFF =		Yes

MAKE_FLAGS=		LIBblkid_VERSION=${LIBblkid_VERSION} \
			LIBe2p_VERSION=${LIBe2p_VERSION} \
			LIBext2fs_VERSION=${LIBext2fs_VERSION} \
			LIBext2fs_com_err_VERSION=${LIBext2fs_com_err_VERSION} \
			LIBss_VERSION=${LIBss_VERSION} \
			LIBe2fs-uuid_VERSION=${LIBe2fs-uuid_VERSION}

FAKE_FLAGS=		root_sysconfdir=${PREFIX}/share/examples/e2fsprogs

INSTALL_TARGET=		install install-libs
post-install:
	cd ${PREFIX}/sbin && mv fsck fsck_ext2fs
	cd ${PREFIX}/man/man8 && mv fsck.8 fsck_ext2fs.8
	cd ${PREFIX}/man/man3 && mv uuid.3 e2fs-uuid.3

.include <bsd.port.mk>