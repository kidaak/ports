# $OpenBSD$

COMMENT =	streaming XML input/output for OCaml
CATEGORIES =	textproc

V =		1.1.0
DISTNAME =	xmlm-${V}
PKGNAME =	ocaml-${DISTNAME}
EXTRACT_SUFX =	.tbz
MASTER_SITES =	http://erratique.ch/software/xmlm/releases/

MAINTAINER =	Anil Madhavapeddy <avsm@openbsd.org>
HOMEPAGE =	http://erratique.ch/software/xmlm

# 3-clause BSD
PERMIT_PACKAGE_FTP =		Yes
PERMIT_PACKAGE_CDROM =		Yes
PERMIT_DISTFILES_FTP =		Yes
PERMIT_DISTFILES_CDROM =	Yes

MODULES =	lang/ocaml

WANTLIB =	c m
BUILD_DEPENDS =	sysutils/findlib

CONFIGURE_STYLE =	oasis
CONFIGURE_ARGS =	--enable-tests
ALL_TARGET =		-build

post-install:
	${INSTALL_DATA_DIR} \
		${PREFIX}/share/doc/ocaml-xmlm \
		${PREFIX}/share/examples/ocaml-xmlm
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/ocaml-xmlm/
	${INSTALL_DATA} ${WRKSRC}/test/* ${PREFIX}/share/examples/ocaml-xmlm/


.include <bsd.port.mk>
