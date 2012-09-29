# $OpenBSD$

COMMENT =	backup mysql database directly from drupal
MAINTAINER =	Marc Espie <espie@openbsd.org>

DISTNAME = 	backup_migrate-6.x-2.6
PKGNAME =	drupal6-backup-migrate-2.6

post-install:
		${INSTALL_DATA_DIR} ${PREFIX}/${DRUPAL_ROOT}/files/backup_migrate
.include <bsd.port.mk>
