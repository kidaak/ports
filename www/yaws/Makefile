# $OpenBSD$

COMMENT-main=		high performance webserver written in Erlang, libraries
COMMENT-web=		high performance webserver written in Erlang, docroot

VERSION=		1.90
DISTNAME=		yaws-${VERSION}
PKGNAME-main=		yaws-${VERSION}
REVISION-main=		2
PKGNAME-web=		yaws-web-${VERSION}
CATEGORIES=		www

MAINTAINER=		Jasper Lievisse Adriaanse <jasper@openbsd.org>

HOMEPAGE=		http://yaws.hyber.org/

# BSD-3
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=		${HOMEPAGE}/download/

MULTI_PACKAGES =	-main -web

BUILD_DEPENDS=		${RUN_DEPENDS} \
			textproc/latex2html
RUN_DEPENDS=		lang/erlang

CONFIGURE_STYLE=	gnu
CONFIGURE_ARGS+=	--disable-pam \
			--disable-sendfile
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib" \
# erl(1) needs $HOME to be set.
CONFIGURE_ENV+=		HOME="${WRKDIST}"

RUN_DEPENDS-main=	${BASE_PKGPATH},-web

USE_GMAKE=		Yes

NO_REGRESS=		Yes

PREFIX-web=		/var

ALL_TARGET=		all docs

# Remove left-over patch file.
pre-install:
	@rm -f ${WRKSRC}/www/doc.yaws.orig
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/yaws/munin/
	${INSTALL_DATA} ${WRKSRC}/munin/* ${PREFIX}/share/examples/yaws/munin/

.include <bsd.port.mk>
