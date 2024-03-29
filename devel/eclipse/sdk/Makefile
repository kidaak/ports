# $OpenBSD$

SHARED_ONLY=		Yes
ONLY_FOR_ARCHS=		amd64 i386

COMMENT-main=		general-purpose, extensible IDE for Java & other langs
COMMENT-swt=		widget toolkit for Java
COMMENT-gnome=		GNOME integration library for swt/eclipse
COMMENT-browser=	HTML Browser Widget library for swt/eclipse

ECLIPSE_VER=		3.2.2
DISTNAME=		eclipse-sourceBuild-srcIncluded-${ECLIPSE_VER}
PKGNAME=		eclipse-sdk-${ECLIPSE_VER}
PKGNAME-main=		eclipse-sdk-${ECLIPSE_VER}
REVISION-main=		19
PKGNAME-swt=		swt-${ECLIPSE_VER}
REVISION-swt=		4
PKGNAME-gnome=		swt-gnome-${ECLIPSE_VER}
REVISION-gnome=		4
PKGNAME-browser=	swt-browser-${ECLIPSE_VER}
REVISION-browser=	7
SHARED_LIBS=		swt-atk-gtk-3236	4.0 \
			swt-awt-gtk-3236	4.0 \
			swt-gtk-3236		4.0 \
			swt-pi-gtk-3236		4.0 \
			swt-cairo-gtk-3236	4.0 \
			swt-gnome-gtk-3236	4.0 \
			swt-mozilla-gtk-3236	4.0 \
			swt-glx-gtk-3236	4.0

CATEGORIES=		devel/eclipse 

HOMEPAGE=		http://www.eclipse.org/

MAINTAINER=		Kurt Miller <kurt@openbsd.org>

# Eclipse Public License Version 1.0 (http://www.eclipse.org/legal/epl-v10.html)
# Apache Software License 2.0 (http://www.apache.org/licenses/LICENSE-2.0)
# IBM Public License 1.0 (http://oss.software.ibm.com/developerworks/opensource/license10.html)
# Metro Link Public License 1.00 (http://www.opengroup.org/openmotif/supporters/metrolink/license.html)
# Mozilla Public License Version 1.1 (http://www.mozilla.org/MPL/MPL-1.1.html)
# LGPL 2.1 
PERMIT_PACKAGE_CDROM=	commercial distribution defend and indemnify clauses
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	commercial distribution defend and indemnify clauses
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITE_ECLIPSE+=	\
	http://archive.eclipse.org/eclipse/downloads/drops/
 
MASTER_SITES=		${MASTER_SITE_ECLIPSE:=R-3.2.2-200702121330/}
EXTRACT_SUFX=		.zip

VMEM_WARNING=		Yes

MODULES=		java devel/gettext
MODJAVA_VER=		1.5+

BUILD_DEPENDS=		devel/xulrunner/1.9,-devel>=1.9 \
			devel/apache-ant>=1.6.1

USE_GMAKE=		Yes

MULTI_PACKAGES=		-main -swt -gnome -browser

RUN_DEPENDS-main=	java/javaPathHelper \
			${MODJAVA_RUN_DEPENDS} \
			swt-browser-${ECLIPSE_VER}:devel/eclipse/sdk,-browser \
			devel/desktop-file-utils
LIB_DEPENDS-main=	x11/gtk+2

WANTLIB-main=		X11 Xau Xcursor Xdmcp Xext Xfixes Xi Xinerama \
			Xcomposite Xdamage gdk_pixbuf-2.0 \
			Xrandr Xrender c expat m z fontconfig \
			freetype atk-1.0 glib-2.0 gmodule-2.0 \
			gobject-2.0 png \
			pango-1.0 pangoft2-1.0 pangocairo-1.0 cairo \
			pixman-1 gio-2.0 pthread-stubs xcb \
			gthread-2.0 pthread xcb-render GL Xxf86vm drm xcb-shm \
			gdk-x11-2.0 gtk-x11-2.0 ${MODGETTEXT_WANTLIB}

LIB_DEPENDS-swt=	x11/gtk+2
WANTLIB-swt=		GL GLU Xtst m atk-1.0 cairo gthread-2.0 gtk-x11-2.0

RUN_DEPENDS-gnome=	swt-${ECLIPSE_VER}:devel/eclipse/sdk,-swt
LIB_DEPENDS-gnome=	x11/gnome/libgnomeui
WANTLIB-gnome=		gnome-2 gnomevfs-2 gnomeui-2

RUN_DEPENDS-browser=	swt-${ECLIPSE_VER}:devel/eclipse/sdk,-swt
LIB_DEPENDS-browser=	devel/xulrunner/1.9>=1.9
WANTLIB-browser=	xulrunner1.9/xpcom xulrunner1.9/xul c nspr4 plc4 plds4 m stdc++

MOZILLA_HOME=		${LOCALBASE}/xulrunner1.9
ECLIPSE_WS=		gtk
ECLIPSE_BUILD=		3236
ECLIPSE_OS=		openbsd
.if ${MACHINE_ARCH} == "i386"
ECLIPSE_ARCH=		x86
.else
ECLIPSE_ARCH=		x86_64
.endif

MAKE_ENV=		ECLIPSE_BUILD=${ECLIPSE_BUILD} \
			ECLIPSE_ARCH=${ECLIPSE_ARCH} \
			ECLIPSE_OS=${ECLIPSE_OS} \
			ECLIPSE_WS=${ECLIPSE_WS} \
			JAVA_HOME=${JAVA_HOME} \
			MOZILLA_HOME=${MOZILLA_HOME} \
			CC="${CC}" CXX="${CXX}" \
			LIBswt_atk_gtk_VERSION=${LIBswt-atk-gtk-3236_VERSION} \
			LIBswt_awt_gtk_VERSION=${LIBswt-awt-gtk-3236_VERSION} \
			LIBswt_gtk_VERSION=${LIBswt-gtk-3236_VERSION} \
			LIBswt_pi_gtk_VERSION=${LIBswt-pi-gtk-3236_VERSION} \
			LIBswt_cairo_gtk_VERSION=${LIBswt-cairo-gtk-3236_VERSION} \
			LIBswt_gnome_gtk_VERSION=${LIBswt-gnome-gtk-3236_VERSION} \
			LIBswt_mozilla_gtk_VERSION=${LIBswt-mozilla-gtk-3236_VERSION} \
			LIBswt_glx_gtk_VERSION=${LIBswt-glx-gtk-3236_VERSION}

FAKE_FLAGS=		${MAKE_ENV}

NO_REGRESS=		Yes

WRKDIST=		${WRKDIR}

SUBST_VARS=		ECLIPSE_ARCH

# Build out openbsd source from linux source
pre-patch:
	@${SETENV} WRKSRC=${WRKSRC} ECLIPSE_WS=${ECLIPSE_WS} \
		sh ${FILESDIR}/prepatch.sh

do-build:
	@cd ${WRKBUILD} && ${SETENV} ${MAKE_ENV} \
		./build -os ${ECLIPSE_OS} -ws ${ECLIPSE_WS} -arch ${ECLIPSE_ARCH} -java5home ${JAVA_HOME} -compilelibs

do-install:
	@tar xzf ${WRKBUILD}/result/openbsd-gtk-${ECLIPSE_ARCH}-sdk.tar.gz \
		-C ${PREFIX}
	@sed -e "s+%%ECLIPSE_HOME%%+${TRUEPREFIX}/eclipse+g" \
		-e "s+%%MOZILLA_FIVE_HOME%%+${TRUEPREFIX}/xulrunner1.9+g" \
		${WRKBUILD}/eclipse.in > ${WRKBUILD}/eclipse.tmp
	${INSTALL_SCRIPT} ${WRKBUILD}/eclipse.tmp ${PREFIX}/bin/eclipse
	${INSTALL_PROGRAM} ${WRKBUILD}/launchertmp/eclipse ${PREFIX}/eclipse/eclipse
	${INSTALL_DATA} ${WRKBUILD}/plugins/org.eclipse.swt.gtk.openbsd.${ECLIPSE_ARCH}/libswt-*.so.* \
		${PREFIX}/lib/
	${INSTALL_DATA_DIR} ${PREFIX}/share/java/classes/
	${INSTALL_DATA} ${WRKBUILD}/eclipse/plugins/org.eclipse.swt.gtk.openbsd.${ECLIPSE_ARCH}_${ECLIPSE_VER}.v${ECLIPSE_BUILD}.jar \
		${PREFIX}/share/java/classes/swt.jar
	@${INSTALL_DATA_DIR} ${PREFIX}/share/applications
	@sed -e 's+%%PREFIX%%+${TRUEPREFIX}+' ${FILESDIR}/eclipse.desktop > \
		${PREFIX}/share/applications/eclipse.desktop

.include <bsd.port.mk>
