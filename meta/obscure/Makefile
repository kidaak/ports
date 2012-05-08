# $OpenBSD$

COMMENT =	Obscure Linux base packages

VERSION =	0
PKGNAME =	obscure-base-${VERSION}

# todo:
# cksum
# libcap
# glibc
# gcc
# perl
RUN_DEPENDS += \
		archivers/bzip2		\
		archivers/gtar		\
		archivers/gzip		\
		archivers/pax		\
		archivers/unzip		\
		archivers/xz		\
		databases/db/v4,-main	\
		devel/ccache		\
		devel/glibc		\
		devel/gmake		\
		devel/libbsd		\
		devel/libcap		\
		devel/linux		\
		devel/ncurses		\
		devel/ncursesw		\
		devel/make		\
		devel/make-templates	\
		editors/vim,no_x11	\
		lang/gcc/4.7,-main	\
		lang/perl		\
		misc/findutils		\
		net/wget		\
		shells/ksh		\
		sysutils/arch		\
		sysutils/binutils	\
		sysutils/cksum		\
		sysutils/coreutils	\
		sysutils/diffutils	\
		sysutils/file		\
		sysutils/ggrep		\
		sysutils/jot		\
		sysutils/mtree		\
		sysutils/pkg-config	\
		sysutils/sed		\
		textproc/man		\
		textproc/mdocml

.include <bsd.port.mk>
