# $OpenBSD$

COMMENT=		ruby interface to Berkeley DB
DISTNAME=		bdb-0.6.5
REVISION=		4
CATEGORIES=		databases

HOMEPAGE=		http://rubyforge.org/projects/bdb/

# GPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=		http://rubyforge.org/frs/download.php/56887/

MODULES= 		lang/ruby

FLAVORS=		ruby18
FLAVOR=			ruby18

WANTLIB=		lib/db4/db>=4
LIB_DEPENDS=		databases/db/v4

CONFIGURE_STYLE=	ruby extconf
CONFIGURE_ARGS=		--with-db-include="${PREFIX}/include/db4" \
			--with-db-version=""

INSTALL_TARGET= 	site-install

DOCS=			Changes README.en bdb.html bdb.rd
EXAMPLES=		basic.rb cats.rb clean.rb cursor.rb \
			func.rb join.rb lock.rb log.rb \
			queue.rb recno.rb record.rb txn.rb \
			zeroc.rb wordlist wordtest

DOC_DIR=		${MODRUBY_DOCDIR}/bdb
EXAMPLE_DIR=		${MODRUBY_EXAMPLEDIR}/bdb

pre-install:
		@perl -i -pe 's,/usr,${LOCALBASE},' ${WRKSRC}/examples/*.rb

do-regress:
		@cd ${WRKSRC} && make test

post-install:
		${INSTALL_DATA_DIR} ${DOC_DIR}
		${INSTALL_DATA} ${WRKSRC}/docs/* ${DOC_DIR}
.for d in ${DOCS}
		${INSTALL_DATA} ${WRKSRC}/$d ${DOC_DIR}/$d
.endfor
		${INSTALL_DATA_DIR} ${EXAMPLE_DIR}
.for e in ${EXAMPLES}
		${INSTALL_DATA} ${WRKSRC}/examples/$e ${EXAMPLE_DIR}/$e
.endfor

.include <bsd.port.mk>
