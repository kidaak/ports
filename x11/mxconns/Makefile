# $OpenBSD$

COMMENT=	interactive X11 proxy with selective X request replacement

DISTNAME=	mxconns-3.1.8
REVISION=	2
CATEGORIES=	x11 security

HOMEPAGE=	http://cern.ch/mxconns/
MASTER_SITES=	${HOMEPAGE}
EXTRACT_SUFX=	.tgz

# Restrictive
PERMIT_PACKAGE_CDROM=	No
PERMIT_PACKAGE_FTP=	No
PERMIT_DISTFILES_CDROM=	No
PERMIT_DISTFILES_FTP=	No
WANTLIB=		X11 Xau Xext Xpm Xt c m Xm

LIB_DEPENDS+=		x11/openmotif
USE_GROFF =	Yes
CONFIGURE_STYLE= simple
CONFIGURE_ARGS=	-optim "${CFLAGS}" -debug
MAKE_FLAGS =	MOTIF_LIB="${MOTIFLIB} -lm -lXm"

NO_REGRESS=	Yes

do-install:
	${INSTALL_PROGRAM} ${WRKBUILD}/mxconns ${PREFIX}/bin
	${INSTALL_MAN} ${WRKBUILD}/mxconns.man \
		${PREFIX}/man/man1/mxconns.1

.include <bsd.port.mk>
