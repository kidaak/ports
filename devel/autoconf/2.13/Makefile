# $OpenBSD$

VERSION =	2.13
REVISION =	2

CONFIGURE_STYLE = gnu dest

MAKE_FLAGS = 	acdatadir=${PREFIX}/share/autoconf${SUFFIX}
FAKE_FLAGS = 	acdatadir=${WRKINST}${PREFIX}/share/autoconf${SUFFIX}

post-install:
	cd ${PREFIX}/info && mv autoconf.info autoconf${SUFFIX}.info && rm standards.info

REGRESS_DEPENDS=devel/dejagnu

.include <bsd.port.mk>
