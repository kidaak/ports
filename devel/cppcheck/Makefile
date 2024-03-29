# $OpenBSD$

COMMENT =		C/C++ static checker

DISTNAME =		cppcheck-1.56

CATEGORIES =		devel

HOMEPAGE =		http://cppcheck.sourceforge.net/

MAINTAINER =		Gleydson Soares <gsoares@openbsd.org>

# GPLv3
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

WANTLIB =		c m pcre stdc++

BUILD_DEPENDS =		textproc/docbook-xsl

LIB_DEPENDS =		devel/pcre

MASTER_SITES =		${MASTER_SITE_SOURCEFORGE:=cppcheck/}

ALL_TARGET =		cppcheck
REGRESS_TARGET = 	test
MAKE_FLAGS =		BIN=${PREFIX}/bin \
			CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" \
			CPPFLAGS="-DHAVE_RULES -I${PREFIX}/include" \
			LDFLAGS="-L${PREFIX}/lib -lpcre"

USE_GMAKE =		Yes

post-build:
	cd ${WRKSRC} && \
	${PREFIX}/bin/xsltproc --novalid --nonet --param man.charmap.use.subset "0" \
	${PREFIX}/share/xsl/docbook/manpages/docbook.xsl \
	${WRKSRC}/man/cppcheck.1.xml

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cppcheck ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/cppcheck.1 ${PREFIX}/man/man1/

.include <bsd.port.mk>
