# $OpenBSD$

COMMENT=	unique standard tape archiver

DISTNAME=	star-1.5.1
CATEGORIES=	archivers sysutils
HOMEPAGE=	http://cdrecord.berlios.de/old/private/star.html

# CDDL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=	ftp://ftp.berlios.de/pub/star/ \
		http://spacehopper.org/mirrors/berlios/star/

FLAVORS=	static
FLAVOR?=

USE_GMAKE=	Yes
USE_GROFF=	Yes
MAKE_FLAGS=	CCOM="${CC}" COPTOPT="${CFLAGS}" \
		CPPOPTX="-DDEFTAPE=\\\"/dev/rst0\\\" \
			 -DSYSCONFDIR=\\\"$(SYSCONFDIR)\\\"" \
		GMAKE_NOWARN=1

.if ${FLAVOR:Mstatic}
MAKE_ENV+=	LDOPTX=-static
.else
WANTLIB=	c
.endif

post-extract:
	@rm -f ${WRKSRC}/lib/libschily-mapvers.orig

post-patch:
	perl -pi -e 's,/etc/default/,${SYSCONFDIR}/default/,g' \
	    ${WRKSRC}/star/defaults.c ${WRKSRC}/star/suntar.c \
	    ${WRKSRC}/star/star.1 ${WRKSRC}/mt/smt.1 \
	    ${WRKSRC}/rmt/rmt.c ${WRKSRC}/rmt/rmt.1

do-configure:
.if ${MACHINE} != "i386" || ${CC} != "cc"
	cd ${WRKSRC}/RULES && \
	    ln -sf i386-openbsd-cc.rul ${MACHINE}-openbsd-${CC}.rul
.endif
.if ${CC} != "cc" && ${CC} != "gcc"
	cd ${WRKSRC}/RULES && ln -sf cc-gcc.rul cc-${CC}.rul
.endif

OBJ=	OBJ/${MACHINE_ARCH}-openbsd-${CC}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/star
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/star/default
	
	${INSTALL_PROGRAM} ${WRKBUILD}/star/${OBJ}/star ${PREFIX}/bin
	cd ${PREFIX}/bin; ln -s star scpio; ln -s star spax
	${INSTALL_MAN} ${WRKSRC}/star/star.1 ${WRKSRC}/star/scpio.1 \
	    ${WRKSRC}/star/spax.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/star/star.4 ${PREFIX}/man/man5/star.5
	${INSTALL_DATA} ${WRKSRC}/star/star.dfl \
	    ${PREFIX}/share/examples/star/default/star
	
	${INSTALL_PROGRAM} ${WRKBUILD}/star_sym/${OBJ}/star_sym ${PREFIX}/bin
	
	${INSTALL_PROGRAM} ${WRKBUILD}/mt/${OBJ}/smt ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mt/smt.1 ${PREFIX}/man/man1
	
	${INSTALL_PROGRAM} ${WRKBUILD}/rmt/${OBJ}/rmt ${PREFIX}/libexec/srmt
	${INSTALL_MAN} ${WRKSRC}/rmt/rmt.1 ${PREFIX}/man/man8/srmt.8
	${INSTALL_DATA} ${WRKSRC}/rmt/rmt.dfl \
	    ${PREFIX}/share/examples/star/default/rmt
	
	${INSTALL_PROGRAM} ${WRKBUILD}/tartest/${OBJ}/tartest ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tartest/tartest.1 ${PREFIX}/man/man1

NO_REGRESS=	Yes

.include <bsd.port.mk>
