# $OpenBSD$

COMMENT=	Objective Caml bindings for calendar functions
CATEGORIES=	devel

V=		2.03.2
DISTNAME=	calendar-${V}
PKGNAME=	ocaml-calendar-${V}
REVISION=	1
# You need to update MASTER_SITES too, when changing the version number.
MASTER_SITES=	https://forge.ocamlcore.org/frs/download.php/915/

MAINTAINER=	Anil Madhavapeddy <avsm@openbsd.org>
HOMEPAGE=	http://www.lri.fr/~signoles/prog.en.html

PERMIT_PACKAGE_FTP=	Yes
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes

MODULES=	lang/ocaml
NO_REGRESS= 	Yes
ALL_TARGET=	all
CONFIGURE_STYLE= gnu
USE_GMAKE=	yes
BUILD_DEPENDS=  sysutils/findlib


pre-fake:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/ocaml

.include <bsd.port.mk>
