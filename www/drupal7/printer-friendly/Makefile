# $OpenBSD$

COMMENT =	printer-friendly pages in drupal
MAINTAINER =	Marc Espie <espie@openbsd.org>

DISTNAME = 	print-7.x-1.1
PKGNAME =	drupal7-printer-friendly-1.1

# Anticipatory symlinking to tcpdf.
post-install:
	@cd ${PREFIX}/${DRUPAL_MODS}print/lib &&\
	 ln -fs ../../../../../../../tcpdf

.include <bsd.port.mk>
