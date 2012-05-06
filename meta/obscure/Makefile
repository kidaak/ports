# $OpenBSD$

COMMENT =	Obscure Linux base packages

VERSION =	0.1
PKGNAME =	obscure-base-${VERSION}

# todo:
# cksum
# pkg-config
# sed
# libcap
# linux-api-headers
# glibc
# gcc
# perl
RUN_DEPENDS += \
		archivers/bzip2		\
		archivers/gtar		\
		archivers/gzip		\
		archivers/unzip		\
		archivers/xz		\
		databases/db/v4,-main	\
		devel/ccache		\
		devel/glibc		\
		devel/gmake		\
		devel/libbsd		\
		devel/libcap		\
		devel/linux,-headers	\
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
		sysutils/coreutils	\
		sysutils/diffutils	\
		sysutils/file		\
		sysutils/ggrep		\
		sysutils/jot		\
		sysutils/mtree		\
		sysutils/cksum		\
		sysutils/pkg-config	\
		textproc/man		\
		textproc/mdocml

.include <bsd.port.mk>
