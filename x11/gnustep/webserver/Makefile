# $OpenBSD$

COMMENT =	GNUstep webserver framework

VERSION =	1.4.6
DISTNAME =	WebServer-${VERSION}
REVISION =	1
PKGNAME =	gnustep-webserver-${VERSION}

SHARED_LIBS +=  WebServer	1.1

CATEGORIES =	www

HOMEPAGE =	http://wiki.gnustep.org/index.php/WebServer

MASTER_SITES =	${MASTER_SITE_GNUSTEP:=libs/}

MODULES =		x11/gnustep
MODGNUSTEP_NEEDS_GUI = 	No
WANTLIB +=		Performance
LIB_DEPENDS +=		x11/gnustep/performance

MAKE_FLAGS +=	WebServer_INTERFACE_VERSION=${LIBWebServer_VERSION}

.include <bsd.port.mk>
