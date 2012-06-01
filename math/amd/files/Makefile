# $OpenBSD$

LIB=	amd

SRCS=	amd_global.c
.for s in ${CSRC}
SRCS+=	amd_i_${s}.c amd_l_${s}.c
.endfor

.include <bsd.lib.mk>
