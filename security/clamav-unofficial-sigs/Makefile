# $OpenBSD$

COMMENT =	fetch and update unofficial signatures for ClamAV

DISTNAME =	clamav-unofficial-sigs-3.7.1
REVISION =	0

CATEGORIES =	security mail

MAINTAINER =	Stuart Henderson <sthen@openbsd.org>

# BSD
PERMIT_PACKAGE_CDROM =	 Yes
PERMIT_PACKAGE_FTP =	 Yes
PERMIT_DISTFILES_CDROM = Yes
PERMIT_DISTFILES_FTP =	 Yes

MASTER_SITES =	http://www.inetmsg.com/pub/ \
		http://www.inetmsg.com/pub/archive/

RUN_DEPENDS =	net/curl net/rsync security/gnupg

NO_BUILD =	Yes
NO_REGRESS =	Yes

PKG_ARCH =	*

do-configure:
	${SUBST_CMD} ${WRKSRC}/clamav-unofficial-sigs.conf
	perl -pi -e 's,/etc,${SYSCONFDIR},' ${WRKSRC}/clamav-unofficial-sigs.sh
# simple perl re replace; if we used SUBST_CMD for this one we'd need to
# patch a line next to a version number which makes updating a pain

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/clamav-unofficial-sigs
	cd ${WRKSRC}; \
	${INSTALL_SCRIPT} clamav-unofficial-sigs.sh ${PREFIX}/bin; \
	${INSTALL_DATA} clamav-unofficial-sigs.conf \
	    ${PREFIX}/share/examples/clamav-unofficial-sigs; \
	${INSTALL_MAN} clamav-unofficial-sigs.8 ${PREFIX}/man/man8

.include <bsd.port.mk>
