# $OpenBSD$

COMMENT =	GNUstep dbus interface

CATEGORIES +=   x11/gnustep devel
VERSION =	0.1
DISTNAME =	dbuskit-${VERSION}
REVISION =	1
PKGNAME =	gnustep-dbuskit-${VERSION}
EXTRACT_SUFX =	.tar.bz2

SHARED_LIBS =	DBusKit	0.0

HOMEPAGE =	http://www.gnustep.org/
MASTER_SITES =	http://download.gna.org/gnustep/

MODULES +=		x11/gnustep
MODGNUSTEP_NEEDS_GUI =	No
WANTLIB += 		c dbus-1 m pthread gnustep-base objc2
BUILD_DEPENDS +=	print/texlive/base \
			textproc/texi2html

# Setting porthome is needed to successfully build the 
# documenation
PORTHOME =	${WRKDIST}
MAKE_FLAGS =	DBusKit_INTERFACE_VERSION=${LIBDBusKit_VERSION}

.include <bsd.port.mk>
