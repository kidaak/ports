# $OpenBSD$

COMMENT=		text editor widget for FLTK

V=			0.4.5
DISTNAME=		fl_editor-${V}
PKGNAME=		fleditor-${V}
REVISION=		3

SHARED_LIBS=		fleditor 3.0
CATEGORIES=		x11

HOMEPAGE=		http://www.robertk.com/source/

MAINTAINER=		Peter Stromberg <wilfried@openbsd.org>

# LPGL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB += m stdc++

MASTER_SITES=		http://www.robertk.com/source/fl_editor/
EXTRACT_SUFX=		.tgz

BUILD_DEPENDS=		${RUN_DEPENDS}
RUN_DEPENDS=		x11/fltk

REGRESS_TARGET=		test
CONFIGURE_STYLE=	gnu
CONFIGURE_ENV=		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"
CONFIGURE_ARGS+=	${CONFIGURE_SHARED} \
			--with-fltk=${LOCALBASE}
MAKE_ENV=		LIBfleditor_VERSION=${LIBfleditor_VERSION}

WRKDIST=		${WRKDIR}/fl_editor

REGRESS_IS_INTERACTIVE= x11

post-patch:
	@rmdir ${WRKSRC}/obj

do-install:
	@${install_shared_frag}
	${INSTALL_DATA} ${WRKBUILD}/libfleditor.a ${PREFIX}/lib
	${INSTALL_DATA_DIR} ${PREFIX}/include/FL
	${INSTALL_DATA} ${WRKSRC}/FL/*.[Hh] ${PREFIX}/include/FL

.include <bsd.port.mk>

.if defined(NO_SHARED_LIBS) && ${NO_SHARED_LIBS:L} == "yes"
install_shared_frag= :
.else
install_shared_frag=\
	${INSTALL_DATA} ${WRKBUILD}/libfleditor.so* ${PREFIX}/lib
.endif
