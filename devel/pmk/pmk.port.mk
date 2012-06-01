# $OpenBSD$
# Pre Make Kit support
# public domain

BUILD_DEPENDS+=		devel/pmk
CONFIGURE_SCRIPT=	${LOCALBASE}/bin/pmk
CONFIGURE_ARGS=		BIN_CC=${CC}
MODPMK_configure=	${MODSIMPLE_configure}
