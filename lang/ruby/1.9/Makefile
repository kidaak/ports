# $OpenBSD$

COMMENT-main =		object oriented script language with threads
COMMENT-gdbm =		gdbm interface for ruby
COMMENT-dbm =		Berkley DB interface for ruby
COMMENT-tk =		tk interface for ruby
COMMENT-ri_docs =	ri documentation files for ruby

VERSION =		1.9.3
PATCHLEVEL =		194
RUBYLIBREV =		1.9.1

REVISION-dbm =		0
REVISION-gdbm =		0
REVISION-tk =		0
REVISION-ri_docs =	0

SHARED_LIBS =		ruby19 1.0
PKGNAME-main =		ruby-${VERSION}.${PATCHLEVEL}
PKGNAME-gdbm =		ruby-gdbm-${VERSION}.${PATCHLEVEL}
PKGNAME-dbm =		ruby-dbm-${VERSION}.${PATCHLEVEL}
PKGNAME-tk =		ruby-tk-${VERSION}.${PATCHLEVEL}
PKGNAME-ri_docs =	ruby-ri_docs-${VERSION}.${PATCHLEVEL}

PKG_ARCH-ri_docs =	*
WANTLIB-ri_docs =	# empty

PKGSPEC-main =		ruby->=1.9,<1.10

CONFIGURE_ARGS =	--program-suffix=19 \
			--with-soname=ruby19 \
			--enable-pthread \
			--enable-ipv6 \
			--disable-option-checking

CONFIGURE_ENV =		LIBruby19_VERSION=${LIBruby19_VERSION} \
			ac_cv_prog_DOXYGEN="" \
			ac_cv_prog_DOT=""

ALL_TARGET =		V=1 main
INSTALL_TARGET =	V=1 install-nodoc

MODULES =		converters/libiconv
USE_GROFF =		Yes

WANTLIB-main =		c crypto ffi m ncurses ncursesw pthread readline ssl \
			termcap util yaml z ${MODLIBICONV_WANTLIB}
LIB_DEPENDS-main =	${MODLIBICONV_LIB_DEPENDS} \
			devel/libyaml \
			devel/libffi
RUN_DEPENDS-main =	${MODLIBICONV_RUN_DEPENDS}

PSEUDO_FLAVORS=		no_x11 no_ri_docs
# Do not build the RI docs on slow arches
.if ${MACHINE_ARCH:Marm} || ${MACHINE_ARCH:Msparc} || ${MACHINE_ARCH:Mvax}
FLAVOR?=		no_ri_docs
.else
FLAVOR?=
.endif

MULTI_PACKAGES =	-main -gdbm -dbm

WANTLIB-gdbm =		c m gdbm pthread ruby19
LIB_DEPENDS-gdbm =	databases/gdbm \
			lang/ruby/${REV},-main>=${VERSION}.${PATCHLEVEL}
RUN_DEPENDS-gdbm =	

WANTLIB-dbm =		c m db pthread ruby19
LIB_DEPENDS-dbm =	databases/db/v4 \
			lang/ruby/${REV},-main>=${VERSION}.${PATCHLEVEL}
RUN_DEPENDS-dbm =	
 
.if !${FLAVOR:Mno_x11}
MULTI_PACKAGES+=	-tk
CONFIGURE_ARGS+=	--with-tcl-include=${PREFIX}/include/tcl8.5 \
			--with-tk-include=${PREFIX}/include/tk8.5 \
			--with-X11-dir=${X11BASE}
WANTLIB-tk =		X11 c m pthread ruby19 tcl85 tk85
LIB_DEPENDS-tk =	tk->=8.5,<8.6:x11/tk/8.5 \
			lang/ruby/${REV},-main>=${VERSION}.${PATCHLEVEL}
RUN_DEPENDS-tk =	
.endif

.if !${FLAVOR:Mno_ri_docs}
MULTI_PACKAGES +=	-ri_docs
ALL_TARGET +=		rdoc
INSTALL_TARGET +=	install-doc
VMEM_WARNING =		Yes
.endif

SUBST_VARS +=		RUBYLIBREV

REGRESS_DEPENDS =	${FULLPKGNAME-main}:${BUILD_PKGPATH}

do-regress:
	-cd ${WRKSRC} && make test-sample
	-cd ${WRKSRC} && make btest-ruby
	cd ${WRKSRC} && make test-all

.include <bsd.port.mk>
