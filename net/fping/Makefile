# $OpenBSD$

COMMENT =		quickly ping N hosts w/o flooding the network

DISTNAME =		fping-2.4b2_to4-ipv6
PKGNAME =		${DISTNAME:S/_to4-ipv6//}
REVISION =		6

CATEGORIES =		net

HOMEPAGE =		http://fping.sf.net/

MAINTAINER =		Stuart Henderson <sthen@openbsd.org>

# BSD
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

WANTLIB =		c

MASTER_SITES =		http://oss.oetiker.ch/smokeping/pub/

CONFIGURE_STYLE =	gnu
SEPARATE_BUILD =	Yes
CONFIGURE_ARGS =	--bindir=${PREFIX}/sbin
COPTS +=		-DHAVE_PROGNAME
USE_GROFF =		Yes

pre-configure:
	perl -pi -e 's,/usr/local/bin/fping,${LOCALBASE}/sbin/fping,g' \
	    ${WRKSRC}/fping.8

post-build:
	cd ${WRKBUILD}; \
	    ${CC} -DHAVE_CONFIG_H -I. -I${WRKSRC} ${CFLAGS} -c \
		-DIPV6 -o fping6.o ${WRKSRC}/fping.c; \
	    ${CC} ${LDFLAGS} ${CFLAGS} -o fping6 fping6.o

do-install:
	${INSTALL_PROGRAM} ${WRKBUILD}/fping ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKBUILD}/fping6 ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/fping.8 ${PREFIX}/man/man8
	ln ${PREFIX}/man/man8/fping.8 ${PREFIX}/man/man8/fping6.8
	${INSTALL_MAN_DIR} ${PREFIX}/share/doc/fping
	${INSTALL_MAN} ${WRKSRC}/COPYING ${PREFIX}/share/doc/fping
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/fping

.include <bsd.port.mk>
