# $OpenBSD$

LIB=	camd

SRCS=	camd_global.c
.for s in ${CSRC}
SRCS+=	camd_i_${s}.c camd_l_${s}.c
.endfor

.include <bsd.lib.mk>
