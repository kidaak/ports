# $OpenBSD$

# XXX: Remember to bump MODCLANG_VERSION in lang/clang/clang.port.mk when
# updating this port.

SHARED_LIBS +=  libclang                  0.0 # 3.0

COMMENT =	modular, fast C/C++/ObjC compiler, static analyzer and tools

LLVM_V =	3.1
DISTNAME =	llvm-${LLVM_V}.src
PKGNAME =	llvm-${LLVM_V}
REVISION =	8
CATEGORIES =	devel

# packager notes in http://llvm.org/docs/Packaging.html
HOMEPAGE =	http://www.llvm.org/

VMEM_WARNING =	Yes

.include <bsd.port.arch.mk>
ONLY_FOR_ARCHS = ${LLVM_ARCHS}
#
# there is some chance of building on other GCC4 arch, but is known to be
# broken on alpha/sparc.

# BSD
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

WANTLIB =	c m pthread stdc++

MASTER_SITES =	http://llvm.org/releases/${LLVM_V}/

DISTFILES =	${DISTNAME}${EXTRACT_SUFX} clang-${LLVM_V}.src${EXTRACT_SUFX}
WRKDIST =	${WRKDIR}/llvm-${LLVM_V}.src

post-extract:
	@mv ${WRKDIR}/clang-${LLVM_V}.src ${WRKDIST}/tools/clang

MODULES =	devel/cmake \
		lang/python

REGRESS_DEPENDS = devel/dejagnu

MAKE_FLAGS =	OPTIMIZE_OPTION="${CFLAGS}" \
		VERBOSE=Yes \
		INSTALL="install -c"

REGRESS_FLAGS =	RUNTESTFLAGS=

SEPARATE_BUILD =	Yes
USE_LIBTOOL =		Yes

CONFIGURE_STYLE =	cmake
CONFIGURE_ARGS =	-DLLVM_ENABLE_FFI:Bool=False \
			-DLLVM_REQUIRES_RTTI:Bool=True \
			-DCMAKE_BUILD_TYPE:String=Release

CLANG_INCLUDE_PATH =	lib/clang/${LLVM_V}/include
SUBST_VARS +=		CLANG_INCLUDE_PATH

pre-configure:
	@${SUBST_CMD} ${WRKSRC}/tools/clang/tools/scan-build/scan-build
	-@ln -s ${MODPY_BIN} ${WRKDIR}/bin/python

post-build:
	cd ${WRKSRC}/docs/CommandGuide && for i in *.pod; do \
	pod2man --release=CVS --center="LLVM Command Guide" \
	    $$i man/man1/$${i%.pod}.1; \
	done
	pod2man --release=CVS --center="LLVM Command Guide" \
	    ${WRKSRC}/tools/clang/docs/tools/clang.pod \
	    ${WRKSRC}/docs/CommandGuide/man/man1/clang.1

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tools/clang/tools/scan-build/ccc-analyzer \
	    ${WRKSRC}/tools/clang/tools/scan-build/c++-analyzer \
	    ${WRKSRC}/tools/clang/tools/scan-build/scan-build ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/tools/clang/tools/scan-build/sorttable.js \
	    ${WRKSRC}/tools/clang/tools/scan-build/scanview.css \
	    ${PREFIX}/share/llvm
	${INSTALL_DATA} ${WRKSRC}/docs/CommandGuide/man/man1/* \
	    ${PREFIX}/man/man1

.include <bsd.port.mk>
