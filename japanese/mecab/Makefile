# $OpenBSD$

COMMENT-main =	japanese morphological analyzer engine
COMMENT-ipadic = IPA japanese dictionary for mecab

DISTNAME =	mecab-0.994
REVISION-main =	0
REVISION-ipadic = 0
PKGNAME-main =	${DISTNAME}
PKGNAME-ipadic = mecab-ipadic-2.7.0

SHARED_LIBS =	mecab	0.0 # 2.0

CATEGORIES =	japanese

HOMEPAGE =	http://code.google.com/p/mecab/

# BSD + IPADIC
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM = Yes
PERMIT_DISTFILES_FTP =	Yes

MULTI_PACKAGES = -main -ipadic

WANTLIB-main =	c m pthread stdc++ ${MODLIBICONV_WANTLIB}
WANTLIB-ipadic =

MASTER_SITES =	http://mecab.googlecode.com/files/

DISTFILES =	${DISTNAME}${EXTRACT_SUFX} \
		${PKGNAME-ipadic}-${IPADIC_VER}.tar.gz

MODULES =	converters/libiconv

LIB_DEPENDS-main = ${MODLIBICONV_LIB_DEPENDS}
RUN_DEPENDS-main = mecab-ipadic-*:japanese/mecab,-ipadic
RUN_DEPENDS-ipadic =

USE_LIBTOOL =	Yes

CONFIGURE_STYLE = gnu
CONFIGURE_ENV =	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		LIBS="-liconv"

IPADIC_VER =	20070801
IPADIC_FILES =	char.bin dicrc left-id.def matrix.bin pos-id.def \
		rewrite.def right-id.def sys.dic unk.dic

post-build:
	cd ${WRKDIR}/${PKGNAME-ipadic}-${IPADIC_VER} && \
	    ${WRKSRC}/src/mecab-dict-index -t utf-8

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/mecab
	${INSTALL_DATA} ${WRKSRC}/mecabrc ${PREFIX}/share/examples/mecab
	${INSTALL_DATA_DIR} ${PREFIX}/share/mecab/dic/ipadic
	cd ${WRKDIR}/${PKGNAME-ipadic}-${IPADIC_VER} && \
	    ${INSTALL_DATA} ${IPADIC_FILES} ${PREFIX}/share/mecab/dic/ipadic

.include <bsd.port.mk>
