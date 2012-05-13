# $OpenBSD$

COMMENT =		GNU C library
DISTNAME =		glibc-2.15

SHARED_LIBS +=		ld		0.0
SHARED_LIBS +=		BrokenLocale	0.0
SHARED_LIBS +=		SegFault	0.0
SHARED_LIBS +=		anl		0.0
SHARED_LIBS +=		c		0.0
SHARED_LIBS +=		cidn		0.0
SHARED_LIBS +=		crypt		0.0
SHARED_LIBS +=		dl		0.0
SHARED_LIBS +=		m		0.0
SHARED_LIBS +=		memusage	0.0
SHARED_LIBS +=		nsl		0.0
### These must match NSS_SHLIB_REVISION
SHARED_LIBS +=		nss_compat	0.0
SHARED_LIBS +=		nss_db		0.0
SHARED_LIBS +=		nss_dns		0.0
SHARED_LIBS +=		nss_files	0.0
SHARED_LIBS +=		nss_hesiod	0.0
SHARED_LIBS +=		nss_nis		0.0
SHARED_LIBS +=		nss_nisplus	0.0
###
SHARED_LIBS +=		pcprofile	0.0
SHARED_LIBS +=		pthread		0.0
SHARED_LIBS +=		pthread		0.0
SHARED_LIBS +=		rlv		0.0
SHARED_LIBS +=		rt		0.0
SHARED_LIBS +=		thread_db	0.0
SHARED_LIBS +=		util		0.0


CATEGORIES =		devel

HOMEPAGE =		http://www.gnu.org/software/libc/

# LGPL 2.1 
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

#WANTLIB =		???

MASTER_SITES =		${MASTER_SITE_GNU:=glibc/}
EXTRACT_SUFX =		.tar.xz

#MODULES =		???
#BUILD_DEPENDS =	???
#RUN_DEPENDS =		???
#LIB_DEPENDS =		???
#REGRESS_DEPENDS =	???

#MAKE_FLAGS =		???
#MAKE_ENV =		???
#FAKE_FLAGS =		???
#REGRESS_FLAGS =	???

SEPARATE_BUILD =	Yes
USE_GMAKE =		Yes
#USE_GROFF =		Yes
CONFIGURE_STYLE =	gnu
# --disable-sanity-checks can probably be removed once
# PREFIX is correctly set
CONFIGURE_ARGS +=	${CONFIGURE_SHARED}			\
			--disable-sanity-checks			\
			--enable-stackguard-randomization	\
#CONFIGURE_ENV =	???

#AUTOCONF_VERSION =	??? (defaults to 2.13)
#AUTOMAKE_VERSION =	??? (defaults to 1.4)

#CFLAGS =		???
#LDFLAGS =		???

pre-configure:
.for _N _V in ${SHARED_LIBS}
	perl -pi -e 's,\$$\{LIB${_N}_VERSION\},${_V},' '${WRKSRC}/shlib-versions'
.endfor

post-install:
.for _N _V in ${SHARED_LIBS}
	rm -f "${PREFIX}/lib/${_N}.${_V}"
	mv "${PREFIX}/lib/lib${_N}-"*.so "${PREFIX}/lib/lib${_LIB}.so.${_VER}"
.endfor

.include <bsd.port.mk>
