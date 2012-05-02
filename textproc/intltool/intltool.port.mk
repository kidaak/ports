# $OpenBSD: ports/textproc/intltool/intltool.port.mk,v 1.4 2011/10/04 11:29:51 ajacoutot Exp $

BUILD_DEPENDS+=	textproc/intltool>=0.41.1p0

MODINTLTOOL_OVERRIDE=INTLTOOL_EXTRACT=${LOCALBASE}/bin/intltool-extract \
		INTLTOOL_MERGE=${LOCALBASE}/bin/intltool-merge \
		INTLTOOL_UPDATE=${LOCALBASE}/bin/intltool-update

CONFIGURE_ENV+=	${MODINTLTOOL_OVERRIDE}
MAKE_ENV+=	${MODINTLTOOL_OVERRIDE}
MAKE_FLAGS+=	${MODINTLTOOL_OVERRIDE}
