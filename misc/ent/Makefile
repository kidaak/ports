# $OpenBSD$
# Original from: John Walker http://www.fourmilab.ch/random/ 

CATEGORIES=		misc
COMMENT=		pseudo random number sequence test program

DISTNAME=	  	ent-1.0		
EXTRACT_SUFX=		.zip

HOMEPAGE=		http://www.fourmilab.ch/random/
MAINTAINER=		Brad Tilley <brad@16systems.com>
MASTER_SITES=		http://16s.us/ent/		

WRKSRC=			${WRKDIR}
ALL_TARGET=		ent

MAKE_FLAGS=		CFLAGS="${CFLAGS}" CC="${CC}"

# Public Domain; see ent.html
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB += c m

USE_GROFF =		Yes
NO_REGRESS=		Yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ent ${PREFIX}/bin
	${INSTALL_MAN} ${FILESDIR}/ent.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
