# $OpenBSD$

SHARED_ONLY=		Yes

COMMENT=		filesystem disk space information

DISTNAME=		Filesys-Df-0.92
REVISION=		3
CATEGORIES=		sysutils

# XXX Force dependency on libc; this doesn't actually use libc, but doing
#     this ensures that changes to syscalls alter the package signature.
WANTLIB += c

# Artistic
PERMIT_PACKAGE_CDROM=   Yes
PERMIT_PACKAGE_FTP=     Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=   Yes

MODULES=		cpan
USE_GROFF =		Yes

.include <bsd.port.mk>	
