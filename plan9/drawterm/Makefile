# $OpenBSD$

ONLY_FOR_ARCHS=	i386 amd64 powerpc sparc64 mips64 mips64el

COMMENT=	Plan9 terminal emulator

DISTNAME=	drawterm-20110221
CATEGORIES=	plan9

HOMEPAGE=	http://swtch.com/drawterm/

MASTER_SITES=	${HOMEPAGE} \
		http://openbsd.stanleylieber.com/drawterm/
EXTRACT_SUFX=	.tgz

MAINTAINER=	Stanley Lieber <stanley.lieber@gmail.com>

# Lucent Public License Version 1.02
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB =	X11 c pthread

NO_REGRESS=	Yes
MAKE_FLAGS=	CONF=unix AUDIO=none

WRKDIST=	${WRKDIR}/drawterm/

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/drawterm/drawterm ${PREFIX}/bin

.include <bsd.port.mk>
