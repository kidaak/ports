# $OpenBSD$

COMMENT=	oxford advanced learners' dictiction of current english
DISTNAME=	festlex_OALD

PERMIT_DISTFILES_CDROM=	no fee
PERMIT_PACKAGE_CDROM=	no fee

do-install:
	${INSTALL_DATA_DIR} ${LEX_PRE}/dicts/oald
	${INSTALL_DATA} ${WRKDIST}/lib/dicts/oald/{COPYING,*.out,*.scm} \
		${LEX_PRE}/dicts/oald

.include <bsd.port.mk>
