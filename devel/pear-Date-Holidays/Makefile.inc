# $OpenBSD$

CATEGORIES =	devel
MAINTAINER ?=	Johan Huldtgren <jhuldtgren@gmail.com>

# BSD
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

.if defined(HOLNAME)
DISTNAME =	Date_Holidays_${HOLNAME}
RUN_DEPENDS +=	devel/pear-Date-Holidays/pear-Date-Holidays
.endif

MODULES +=		www/pear
