# $OpenBSD$

COMMENT=		reduce the amount of SPAM/UCE (junk-mail)

DISTNAME=		tmda-1.0.3
REVISION =		7
CATEGORIES=		mail

HOMEPAGE=		http://tmda.net/
MAINTAINER=		Dave Steinberg <dave@redterror.net>

# BSD-style
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=		http://tmda.net/releases/stable/
EXTRACT_SUFX=		.tgz

MODULES=		lang/python

NO_REGRESS=		Yes

CONTRIB_FILES=		collectaddys printcdb sample.config sendit.sh \
			def2html printdbm tmda.el vadduser-tmda

do-build:
	@cd ${WRKSRC} && ${MODPY_BIN} ./compileall

do-install:
	@perl -pi -e 's:htdocs:${TRUEPREFIX}/share/doc/tmda:' ${WRKSRC}/INSTALL
	${INSTALL_DATA_DIR} ${DESTDIR}${MODPY_SITEPKG}/TMDA/pythonlib/email
	${INSTALL_SCRIPT} ${WRKSRC}/TMDA/*.py* ${DESTDIR}${MODPY_SITEPKG}/TMDA
	${INSTALL_SCRIPT} ${WRKSRC}/TMDA/pythonlib/email/*.py* \
		${DESTDIR}${MODPY_SITEPKG}/TMDA/pythonlib/email
	${INSTALL_DATA_DIR} ${PREFIX}/share/tmda
	${INSTALL_DATA} ${WRKSRC}/templates/*.txt ${PREFIX}/share/tmda
	${INSTALL_SCRIPT} ${WRKSRC}/bin/tmda-* ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tmda/contrib
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/tmda
	${INSTALL_DATA} ${WRKSRC}/contrib/sample.config \
		${PREFIX}/share/examples/tmda
	${INSTALL_DATA} ${WRKSRC}/htdocs/*.html ${PREFIX}/share/doc/tmda
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tmda/img
	${INSTALL_DATA} ${WRKSRC}/htdocs/img/*.png ${PREFIX}/share/doc/tmda/img
.for f in ${CONTRIB_FILES}
	${INSTALL_DATA} ${WRKSRC}/contrib/$f ${PREFIX}/share/doc/tmda/contrib
.endfor
.for f in CRYPTO INSTALL README UPGRADE
	${INSTALL_DATA} ${WRKSRC}/$f ${PREFIX}/share/doc/tmda
.endfor

.include <bsd.port.mk>
