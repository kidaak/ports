# $OpenBSD$

SHARED_ONLY=		Yes

# This architecture lacks fast mutexes...
NOT_FOR_ARCHS=		mips64 mips64el

COMMENT=		source code search engine
DISTNAME=		gonzui-1.2
REVISION=		21
CATEGORIES=		textproc www

HOMEPAGE=		http://gonzui.sourceforge.net/

MAINTAINER=		Jasper Lievisse Adriaanse <jasper@openbsd.org>

# GPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes
WANTLIB=		m

MODULES=		lang/ruby lang/ocaml

MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gonzui/}

BUILD_DEPENDS=		databases/db/v4 \
			databases/ruby-bdb,${MODRUBY_FLAVOR} \
			${MODRUBY_ICONV_DEPENDS}
RUN_DEPENDS=		archivers/bzip2 \
			archivers/unzip \
			archivers/xz \
			databases/db/v4 \
			databases/ruby-bdb,${MODRUBY_FLAVOR} \
			${MODRUBY_ICONV_DEPENDS} \
			textproc/p5-PPI

MODRUBY_ADJ_FILES=	gonzui-db \
			gonzui-import \
			gonzui-remove \
			gonzui-search \
			gonzui-server \
			gonzui-update

CONFIGURE_STYLE=	gnu
CONFIGURE_ARGS=		--with-user="_gonzui" \
			--with-group="_gonzui" \
			--with-rundir="/var/run/gonzui" \
			--with-logdir="/var/log"

# Tests want to do cvs checkouts, apt-get, etc.
NO_REGRESS=		Yes

# XXX: Bad, but saves a metric buttload of patches.
pre-configure:
	ln -sf ${RUBY} ${WRKDIR}/bin/ruby
	${MODRUBY_ADJ_REPLACE}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/gonzui/
	${INSTALL_DATA} ${WRKSRC}/gonzuirc.sample \
		${PREFIX}/share/examples/gonzui/

.include <bsd.port.mk>
