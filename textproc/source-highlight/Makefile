# $OpenBSD$

COMMENT=	create a document with syntax highlighting

DISTNAME=	source-highlight-3.1.2
REVISION=	0
SHARED_LIBS +=  source-highlight     0.0         # .3.1
CATEGORIES=	textproc

HOMEPAGE=	http://www.gnu.org/software/src-highlite/source-highlight.html

# GPLv3
PERMIT_PACKAGE_CDROM=   Yes
PERMIT_PACKAGE_FTP=     Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=   Yes

WANTLIB=		c m stdc++ boost_regex

MASTER_SITES=	${MASTER_SITE_GNU:=src-highlite/}

LIB_DEPENDS=	devel/boost
BUILD_DEPENDS=	textproc/texi2html

USE_LIBTOOL=	Yes
USE_GROFF =	Yes

CONFIGURE_STYLE= gnu
CONFIGURE_ARGS+= ${CONFIGURE_SHARED} \
		--with-bash-completion="${PREFIX}/share/source-highlight/bash_completion.d/"
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		YACC="yacc"

REGRESS_TARGET=	check

post-extract:
	chmod +x ${WRKSRC}/build-aux/install-sh

.include <bsd.port.mk>
