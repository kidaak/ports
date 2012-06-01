# $OpenBSD$

COMMENT =	tool for inspecting compressed archvies

DISTNAME =	Zipper-1.3
REVISION=	0

HOMEPAGE =	http://xanthippe.dyndns.org/Zipper/
MASTER_SITES =	${HOMEPAGE}

MODULES =	x11/gnustep
WANTLIB += 	c m pthread Renaissance
LIB_DEPENDS +=	x11/gnustep/renaissance
RUN_DEPENDS +=  archivers/lha \
		archivers/p7zip \
		archivers/unrar \
		archivers/unzip

WRKDIST =	${WRKDIR}/Zipper

.include <bsd.port.mk>
