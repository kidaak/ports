# $OpenBSD$

# The RUN_DEPENDS entry is to ensure libiconv is installed. This is
# necessary so that we have charset.alias installed on static archs.
# Typically installed in PREFIX/lib.
MODLIBICONV_LIB_DEPENDS =	converters/libiconv
MODLIBICONV_RUN_DEPENDS =	converters/libiconv

MODLIBICONV_WANTLIB =		iconv>=2

LIB_DEPENDS +=			${MODLIBICONV_LIB_DEPENDS}
RUN_DEPENDS +=			${MODLIBICONV_RUN_DEPENDS}
WANTLIB +=			${MODLIBICONV_WANTLIB}
