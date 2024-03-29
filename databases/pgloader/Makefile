# $OpenBSD$

COMMENT=	import CSV data and Large Object to PostgreSQL

DISTNAME=	pgloader-2.3.2
REVISION =	2
CATEGORIES=	databases

HOMEPAGE=	http://pgfoundry.org/projects/pgloader/

MAINTAINER=	Pierre-Emmanuel Andre <pea@openbsd.org>

# BSD
PERMIT_PACKAGE_FTP=	Yes
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes

MASTER_SITES=	http://pgfoundry.org/frs/download.php/2294/

MODULES=	lang/python

RUN_DEPENDS=	databases/py-psycopg2

USE_GROFF =	Yes
NO_BUILD=	Yes
NO_REGRESS=	Yes

EGGDIRS=	allcols clob cluttered csv errors fixed parallel \
		partial reformat serial simple udc

pre-configure:
	@perl -pi -e 's,/usr/bin/env python,${MODPY_BIN},' \
		${WRKSRC}/pgloader.py
	@perl -pi -e 's,/usr/share/python-support,${MODPY_LIBDIR},' \
		${WRKSRC}/pgloader/options.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pgloader.py ${PREFIX}/bin/pgloader
	${INSTALL_MAN} ${WRKSRC}/pgloader.1 ${PREFIX}/man/man1/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pgloader
.for i in ${EGGDIRS}
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/pgloader/${i}
	${INSTALL_DATA} ${WRKSRC}/examples/${i}/* ${PREFIX}/share/examples/pgloader/${i}
.endfor
	${INSTALL_DATA_DIR} ${WRKINST}/${MODPY_LIBDIR}/pgloader
	${INSTALL_DATA_DIR} ${WRKINST}/${MODPY_LIBDIR}/pgloader/reformat
	${INSTALL_DATA} ${WRKSRC}/*.txt ${PREFIX}/share/doc/pgloader
	${INSTALL_DATA} ${WRKSRC}/examples/README ${PREFIX}/share/examples/pgloader/
	${INSTALL_DATA} ${WRKSRC}/examples/parallel.conf ${PREFIX}/share/examples/pgloader/
	${INSTALL_DATA} ${WRKSRC}/examples/parallel.sections.conf ${PREFIX}/share/examples/pgloader/
	${INSTALL_DATA} ${WRKSRC}/examples/pgloader.conf ${PREFIX}/share/examples/pgloader/
	${INSTALL_DATA} ${WRKSRC}/pgloader/* ${WRKINST}/${MODPY_LIBDIR}/pgloader
	${INSTALL_DATA} ${WRKSRC}/reformat/* ${WRKINST}/${MODPY_LIBDIR}/pgloader/reformat

.include <bsd.port.mk>
