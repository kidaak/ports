# $OpenBSD$

TOOL=			binutils
TOOL_V=			2.21.1a

REVISION=		0

GNU_TOOL=		Yes

MASTER_SITES=		${MASTER_SITE_GNU:=binutils/}

WANTLIB=		c z

CONFIGURE_ARGS+=	--enable-commonbfdlib=no

WRKDIST=		${WRKDIR}/${DISTNAME:S/a$//}

NO_REGRESS=		No

.include <bsd.port.mk>
