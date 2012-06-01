# $OpenBSD$


MODULES +=	www/drupal7

# GPL
PERMIT_DISTFILES_CDROM ?=Yes
PERMIT_DISTFILES_FTP ?=	Yes
PERMIT_PACKAGE_CDROM ?=	Yes
PERMIT_PACKAGE_FTP ?=	Yes

NO_BUILD ?=	Yes
NO_REGRESS ?=	Yes

.if !target(do-install)
do-install:
		${MODDRUPAL_INSTALL}
.endif
