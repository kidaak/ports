# $OpenBSD$

COMMENT=		daemontools alike replacement for init

DISTNAME=		runit-1.7.2
REVISION=		0
CATEGORIES=		sysutils

HOMEPAGE=		http://www.smarden.org/runit/

PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes
WANTLIB=		c 

MASTER_SITES=		${HOMEPAGE}
WRKDIST=		${WRKDIR}/admin/${DISTNAME}
WRKSRC=			${WRKDIST}/src
SBINPROGRAMS=		chpst runit runit-init runsv runsvchdir runsvdir \
			sv svlogd utmpset
MANPAGES=		chpst.8 runit.8 runit-init.8 runsv.8 runsvchdir.8 runsvdir.8 \
			sv.8 svlogd.8 utmpset.8
DOCS1=			benefits.html chpst.8.html dependencies.html faq.html \
			index.html install.html replaceinit.html runit-init.8.html \
			runit.8.html runlevels.html runscripts.html runsv.8.html \
			runsvchdir.8.html runsvdir.8.html sv.8.html svlogd.8.html \
			upgrade.html useinit.html index.html utmpset.8.html
DOCS2=			CHANGES README COPYING THANKS
EXAMPLES=		etc/2 etc/openbsd/1 etc/openbsd/3 etc/openbsd/ctrlaltdel
USE_GROFF =		Yes

pre-build:
	echo "${CC} ${CFLAGS} ${COPTS}" > ${WRKSRC}/conf-cc
	echo "${CC} ${LDFLAGS}" > ${WRKSRC}/conf-ld

do-build:
	cd ${WRKDIST} && package/compile

do-regress:
	cd ${WRKDIST}/compile && make check

do-install:
.for pgm in ${SBINPROGRAMS}
	${INSTALL_PROGRAM} ${WRKDIST}/command/${pgm} ${PREFIX}/sbin/
.endfor
	${INSTALL_SCRIPT} ${WRKDIST}/etc/2 ${PREFIX}/sbin/runsvdir-start
.for page in ${MANPAGES}
	${INSTALL_MAN} ${WRKDIST}/man/${page} ${PREFIX}/man/man8
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/runit
.for doc in ${DOCS1}
	${INSTALL_DATA} ${WRKDIST}/doc/${doc} ${PREFIX}/share/doc/runit/
.endfor
.for doc in ${DOCS2}
	${INSTALL_DATA} ${WRKDIST}/package/${doc} ${PREFIX}/share/doc/runit/
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/runit
	${INSTALL_DATA} ${FILESDIR}/rc.shutdown ${PREFIX}/share/examples/runit/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/runit/init
.for file in ${EXAMPLES}
	${INSTALL_DATA} ${WRKDIST}/${file} ${PREFIX}/share/examples/runit/init/
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/runit/init/getty-ttyC4
	${INSTALL_DATA} ${WRKDIST}/etc/openbsd/getty-ttyC4/run \
		${PREFIX}/share/examples/runit/init/getty-ttyC4/run
	${INSTALL_DATA} ${WRKDIST}/etc/openbsd/getty-ttyC4/finish \
		${PREFIX}/share/examples/runit/init/getty-ttyC4/finish

.include <bsd.port.mk>
