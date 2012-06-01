# $OpenBSD$

COMMENT=	American English lexicon compiled from Moby and CMU lexicons
DISTNAME=	OGIlexicon-2.1

RUN_DEPENDS=	audio/festival/core,ogi

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/festival/dicts
	${INSTALL_DATA} ${WRKDIST}/lib/dicts/* ${PREFIX}/lib/festival/dicts

.include <bsd.port.mk>
