# $OpenBSD$

ONLY_FOR_ARCHS=		i386 amd64 m68k sparc

COMMENT=		official distributed.net client

A-i386=			x86-elf
V-i386=			2.9013
SV-i386=		498
S-i386=			0

A-amd64=		amd64-elf
V-amd64=		2.9011
SV-amd64=		496
S-amd64=		3

A-m68k=			m68k
V-m68k=			2.9005
SV-m68k=		483
S-m68k=			1

A-sparc=		sparc-aout
V-sparc=		2.9002
SV-sparc=		479
S-sparc=		2

V=			${V-${MACHINE_ARCH}}
A=			${A-${MACHINE_ARCH}}
SV=			${SV-${MACHINE_ARCH}}
S=			${S-${MACHINE_ARCH}}

DISTFILES=
.for m in ${ONLY_FOR_ARCHS}
.  if ${MACHINE_ARCH} == "$m"
DISTFILES+=		dnetc${SV}-openbsd-$A${EXTRACT_SUFX}:$S
.  else
SUPDISTFILES+=		dnetc${SV-$m}-openbsd-${A-$m}${EXTRACT_SUFX}:${S-$m}
.  endif
MASTER_SITES${S-$m}=	http://http.distributed.net/pub/dcti/v${V-$m}/
.endfor

PKGNAME=		dnetc-${V}.${SV}
DISTNAME=              	dnetc${SV}-openbsd-${A}

CATEGORIES=		misc

HOMEPAGE=		http://www.distributed.net/


MAINTAINER=		Sico Bruins <openbsd@msh.xs4all.nl>

PERMIT_PACKAGE_CDROM=	no redistribution
PERMIT_PACKAGE_FTP=	no redistribution
PERMIT_DISTFILES_CDROM=	no redistribution
PERMIT_DISTFILES_FTP=	no redistribution

NO_BUILD=		Yes
NO_REGRESS=		Yes
USE_GROFF =		Yes

WRKSRC=			${WRKDIR}/dnetc${SV}-openbsd-${A}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dnetc ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/dnetc.1 ${PREFIX}/man/man1/

.include <bsd.port.mk>
