# $OpenBSD$

SHARED_ONLY ?=	Yes

MODKDE_VERSION ?=
MODULES +=	x11/qt3
MODQT_OVERRIDE_UIC ?=No

MODKDE_NODEBUG ?=No

.if !${MODKDE_NODEBUG:L} == "yes"
FLAVORS +=	debug
.endif
FLAVOR ?=

MODKDE_CONFIGURE_ARGS =${MODQT_CONFIGURE_ARGS}
MODKDE_CONFIGURE_ARGS +=	--with-extra-libs="${LOCALBASE}/lib/kde3:${LOCALBASE}/lib/db4:${LOCALBASE}/lib/samba:${LOCALBASE}/lib"
MODKDE_CONFIGURE_ARGS +=	--with-extra-includes="${LOCALBASE}/include/db4:${LOCALBASE}/include/libpng:${LOCALBASE}/include"
MODKDE_CONFIGURE_ARGS +=	--with-xdmdir=/var/X11/kdm
MODKDE_CONFIGURE_ARGS +=	--enable-mitshm
MODKDE_CONFIGURE_ARGS +=	--with-xinerama
.if ${FLAVOR:L:Mdebug}
MODKDE_CONFIGURE_ARGS +=	--enable-debug=yes
.else
MODKDE_CONFIGURE_ARGS +=	--disable-debug
MODKDE_CONFIGURE_ARGS +=	--disable-dependency-tracking
.endif
MODKDE_CONFIGURE_ARGS +=	--enable-final

MODKDE_CONFIG_GUESS_DIRS =	${WRKSRC} ${WRKSRC}/admin

MODKDE_CONFIGURE_ENV =		UIC_PATH="${MODQT_UIC}" UIC="${MODQT_UIC}"
MODKDE_CONFIGURE_ENV +=		RUN_KAPPFINDER=no KDEDIR=${LOCALBASE}
MODKDE_CONFIGURE_ENV +=		PTHREAD_LIBS=-pthread
MODKDE_MAKE_FLAGS =		CXXLD='--tag CXX ${CXX} -L${MODQT_LIBDIR}'
MODKDE_MAKE_FLAGS +=		LIBRESOLV=

MODKDE_post-patch =	find ${WRKDIST} -name Makefile.am -exec touch {}.in \;

KDE=lib/kde3
SUBST_VARS +=	KDE

SUP_PATCH_LIST ?=
.if ${MODKDE_VERSION} == "3.1"
PATCH_LIST =	${PORTSDIR}/x11/kde/patches-3.1/patch-* patch-* ${SUP_PATCH_LIST}
.elif ${MODKDE_VERSION} == "3.2"
PATCH_LIST =	${PORTSDIR}/x11/kde/patches-3.2/patch-* patch-* ${SUP_PATCH_LIST}
AUTOCONF ?=	/bin/sh ${WRKDIST}/admin/cvs.sh configure
WANTLIB +=	lib/qt3/qt-mt>=3.20
.elif ${MODKDE_VERSION} == "3.2.3"
PATCH_LIST =	${PORTSDIR}/x11/kde/patches-3.2.3/patch-* patch-* ${SUP_PATCH_LIST}
AUTOCONF ?=	/bin/sh ${WRKDIST}/admin/cvs.sh configure
WANTLIB +=	lib/qt3/qt-mt>=3.20
.elif ${MODKDE_VERSION} == "3.3.0"
PATCH_LIST =	${PORTSDIR}/x11/kde/patches-3.2.3/patch-* patch-* ${SUP_PATCH_LIST}
AUTOCONF ?=	/bin/sh ${WRKDIST}/admin/cvs.sh configure
WANTLIB +=	lib/qt3/qt-mt>=3.33
.elif ${MODKDE_VERSION} == "3.4"
PATCH_LIST =	${PORTSDIR}/x11/kde/patches-3.4/patch-* patch-* ${SUP_PATCH_LIST}
AUTOCONF ?=	/bin/sh ${WRKDIST}/admin/cvs.sh configure
WANTLIB +=	lib/qt3/qt-mt>=3.33
.elif ${MODKDE_VERSION} == "3.5"
PATCH_LIST =	${PORTSDIR}/x11/kde/patches-3.5/patch-* patch-* ${SUP_PATCH_LIST}
AUTOCONF ?=	/bin/sh ${WRKDIST}/admin/cvs.sh configure
WANTLIB +=	lib/qt3/qt-mt>=3.33
.elif ${MODKDE_VERSION} == "3.5.2"
PATCH_LIST =	${PORTSDIR}/x11/kde/patches-3.5.2/patch-* patch-* ${SUP_PATCH_LIST}
AUTOCONF ?=	/bin/sh ${WRKDIST}/admin/cvs.sh configure
WANTLIB +=	lib/qt3/qt-mt>=3.33
.elif ${MODKDE_VERSION} == "3.5.3"
PATCH_LIST =	${PORTSDIR}/x11/kde/patches-3.5.3/patch-* patch-* ${SUP_PATCH_LIST}
AUTOCONF ?=	/bin/sh ${WRKDIST}/admin/cvs.sh configure
WANTLIB +=	lib/qt3/qt-mt>=3.33
.elif ${MODKDE_VERSION} == "3.5.7" || ${MODKDE_VERSION} == "3.5.8"
PATCH_LIST =	${PORTSDIR}/x11/kde/patches-3.5.7/patch-* patch-* ${SUP_PATCH_LIST}
AUTOCONF ?=	/bin/sh ${WRKDIST}/admin/cvs.sh configure
WANTLIB +=	lib/qt3/qt-mt>=3.33
USE_LIBTOOL ?=	Yes
LIBTOOL_FLAGS =	--tag=disable-static
.endif
