# $OpenBSD$

SHARED_LIBS +=  ft                   0.0      # .0.0

COMMENT=	cisco NetFlow utilities

DISTNAME=	flow-tools-0.68.5.1
EXTRACT_SUFX=	.tar.bz2
REVISION=	2
CATEGORIES=	net

MAINTAINER=	Stuart Henderson <sthen@openbsd.org>

# forked from:  http://www.splintered.net/sw/flow-tools/
HOMEPAGE=	http://code.google.com/p/flow-tools/

MASTER_SITES=	http://flow-tools.googlecode.com/files/

PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

FLAVORS=		pgsql
FLAVOR?=

WANTLIB=		c z

MODULES=		lang/python

LOCALSTATEDIR=		${BASELOCALSTATEDIR}/flow-tools

CONFIGURE_STYLE=	gnu
SEPARATE_BUILD=		Yes
SYSCONFDIR=		${BASESYSCONFDIR}/flow-tools

.if !${FLAVOR:L:Mpgsql}
CONFIGURE_ARGS+=	--without-postgresql
.else
WANTLIB +=		pq
LIB_DEPENDS+=		databases/postgresql,-main
.endif

MAKE_FLAGS+=		SUBDIRS="lib src bin configs docs"
FAKE_FLAGS+=		sysconfdir=${PREFIX}/share/examples/flow-tools

USE_GMAKE=		Yes
USE_LIBTOOL=		Yes
USE_GROFF=		Yes

# let configure generate a new ftconfig.h, the supplied one has
# problems with libwrap
pre-configure:
	rm -f ${WRKSRC}/lib/ftconfig.h
	cd ${WRKSRC}/bin; perl -pi -e 's,/bin/env python,${MODPY_BIN},;' \
	    -e 's,/usr/local/netflow/var/sym/,${SYSCONFDIR}/sym/,;' \
	    flow-log2rrd flow-rpt2rrd flow-rptfmt

.include <bsd.port.mk>
