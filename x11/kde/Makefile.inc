# $OpenBSD$
DIST_SUBDIR ?=	kde
HOMEPAGE ?=	http://www.kde.org

MASTER_SITES ?=	${MASTER_SITE_KDE:S@$@stable/${VERSION}/src/@}
EXTRACT_SUFX ?=	.tar.bz2
MASTER_SITES0 =	${MASTER_SITE_KDE:=security_patches/}

# Parts of kde want shared libraries to work, as some symbols are
# duplicated over the place.
NOT_FOR_ARCHS ?=	${NO_SHARED_ARCHS}
SHARED_ONLY =		Yes
MODKDE_VERSION ?=	3.1
MODULES ?=		x11/kde

MODGNU_CONFIG_GUESS_DIR	?=	${MODKDE_CONFIG_GUESS_DIRS}

CONFIGURE_STYLE ?=	autoconf
.if defined(MODKDE_VERSION)
.  if ${MODKDE_VERSION} == "3.5.7"
AUTOCONF_VERSION ?=	2.60
.  endif
.  if ${MODKDE_VERSION} == "3.5.8"
AUTOCONF_VERSION ?=	2.61
.  endif
.endif
AUTOCONF_VERSION ?=	2.57
CONFIGURE_ARGS +=	${MODKDE_CONFIGURE_ARGS}
USE_GMAKE ?=		Yes

PORTHOME ?=		${WRKDIR}

CONFIGURE_ENV +=	${MODKDE_CONFIGURE_ENV}
MAKE_ENV =		${CONFIGURE_ENV}

MAKE_FLAGS +=		${MODKDE_MAKE_FLAGS}
FAKE_FLAGS ?=		TAR=tar 
# GPL
PERMIT_DISTFILES_CDROM ?=	Yes
PERMIT_DISTFILES_FTP ?=		Yes
PERMIT_PACKAGE_CDROM ?=		Yes
PERMIT_PACKAGE_FTP ?=		Yes

# let's do a sweet little dance for kde4's libs
post_install_libs = mkdir -p ${PREFIX}/lib/kde3; cd ${PREFIX}/lib/kde3
.for l v in ${SHARED_LIBS}
post_install_libs += ;test -e ../lib$l.so.$v && ln -sf ../lib$l.so.$v lib$l.so.$v
.endfor
.if !target(post-install)
post-install:
	@${post_install_libs}
.endif
