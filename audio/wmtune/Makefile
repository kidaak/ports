# $OpenBSD$

COMMENT=	premier dockable radio tuner

DISTNAME=	wmtune-1.1c
REVISION=	4
CATEGORIES=	audio x11 x11/windowmaker

HOMEPAGE=	http://www.soren.org/linux/wmtune/

MAINTAINER=	Vladimir Popov <pva48@mail.ru>	

PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB=		X11 Xext Xpm c

MASTER_SITES=		${HOMEPAGE}dl/

MAKE_ENV=		CC="${CC}"
USE_GROFF =		Yes

FLAVORS=		zoltrix
FLAVOR?=

.if ${FLAVOR:Mzoltrix}
CFLAGS+=		-DZOLTRIX
BINMODE=		4555
ONLY_FOR_ARCHS=		i386
.endif

WRKDIST=		${WRKDIR}/wmtune-1.0.1-combined/

post-extract:
	@cp files/wmtune.1 ${WRKDIST}

NO_REGRESS=		Yes

.include <bsd.port.mk>
