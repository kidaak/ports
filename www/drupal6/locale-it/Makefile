# $OpenBSD$

COMMENT =	italian translation
DRUPAL_LANG =		it
EXTRACT_ONLY =

DISTNAME =	${DRUPAL_LANG}-6.x-1.4
PKGNAME =	drupal6-${DRUPAL_LANG}-1.4
REVISION =	3

post-extract:
	mkdir -p ${WRKDIST}
	cd ${WRKDIST} && tar zxf ${FULLDISTDIR}/${DISTFILES}

.include <bsd.port.mk>
