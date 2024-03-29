# $OpenBSD$

MODFORTRAN_COMPILER ?= g77

.if empty(MODFORTRAN_COMPILER)
ERRORS += "Fatal: need to specify MODFORTRAN_COMPILER"
.endif

.if ${MODFORTRAN_COMPILER:L} == "g77"
.  if ${COMPILER_VERSION:L:Mgcc[34]*}
_MODFORTRAN_LIB_DEPENDS_G77 = devel/libf2c
_MODFORTRAN_WANTLIB_G77 = g2c
_MODFORTRAN_BUILD_DEPENDS_G77 = lang/g77 devel/libf2c
.  else
_MODFORTRAN_LIB_DEPENDS_G77 = devel/libf2c-old
_MODFORTRAN_WANTLIB_G77 += g2c
_MODFORTRAN_BUILD_DEPENDS_G77 = lang/g77-old devel/libf2c-old
.  endif
MODFORTRAN_LIB_DEPENDS += ${_MODFORTRAN_LIB_DEPENDS_G77}
MODFORTRAN_WANTLIB += ${_MODFORTRAN_WANTLIB_G77}
MODFORTRAN_BUILD_DEPENDS += ${_MODFORTRAN_BUILD_DEPENDS_G77}
MODFORTRAN_post-patch = \
if test -e /usr/bin/g77 -o -e /usr/bin/f77; then \
    echo "Error: remove old fortran compiler /usr/bin/f77 /usr/bin/g77"; \
    exit 1; \
fi
.elif ${MODFORTRAN_COMPILER:L} == "gfortran"
.  if ${COMPILER_VERSION:L:Mgcc4}
_MODFORTRAN_LIB_DEPENDS_GFORTRAN = lang/gfortran,-lib
_MODFORTRAN_WANTLIB_GFORTRAN = gfortran
_MODFORTRAN_BUILD_DEPENDS_GFORTRAN = lang/gfortran
.  else
MODULES += gcc4
MODGCC4_LANGS += fortran
.  endif
MODFORTRAN_LIB_DEPENDS += ${_MODFORTRAN_LIB_DEPENDS_GFORTRAN}
MODFORTRAN_WANTLIB += ${_MODFORTRAN_WANTLIB_GFORTRAN}
MODFORTRAN_BUILD_DEPENDS += ${_MODFORTRAN_BUILD_DEPENDS_GFORTRAN}
.else
ERRORS += "Fatal: MODFORTRAN_COMPILER must be one of: g77 gfortran"
.endif
