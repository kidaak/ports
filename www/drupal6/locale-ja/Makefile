# $OpenBSD$

COMMENT =	japanese translation
DRUPAL_LANG =		ja
EXTRACT_ONLY =

DISTNAME =	${DRUPAL_LANG}-6.x-1.2
PKGNAME =	drupal6-${DRUPAL_LANG}-1.2
REVISION =	3

post-extract:
	mkdir -p ${WRKDIST}
	cd ${WRKDIST} && tar zxf ${FULLDISTDIR}/${DISTFILES}

.include <bsd.port.mk>
