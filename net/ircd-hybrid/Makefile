# $OpenBSD$

SHARED_ONLY =	Yes

COMMENT =	Internet Relay Chat server

DISTNAME =	ircd-hybrid-7.3.1
CATEGORIES =	net
MASTER_SITES =	${MASTER_SITE_SOURCEFORGE:=ircd-hybrid/}
EXTRACT_SUFX =	.tgz

HOMEPAGE =	http://ircd-hybrid.com/

# GPLv2
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM = Yes
PERMIT_DISTFILES_FTP =	Yes

WANTLIB =	c crypto ltdl pcre ssl z

LIB_DEPENDS =	devel/libtool,-ltdl \
		devel/pcre

USE_GROFF =	Yes
USE_LIBTOOL=	Yes
LIBTOOL_FLAGS=	--tag=disable-static
CONFIGURE_STYLE = gnu
CONFIGURE_ENV =	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

NO_REGRESS =	Yes

pre-configure:
	@${SUBST_CMD} ${WRKSRC}/etc/example.conf

.include <bsd.port.mk>
