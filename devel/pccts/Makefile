# $OpenBSD$

COMMENT=	Purdue Compiler Construction Tool Set 

DISTNAME=	pccts133mr33
PKGNAME=	pccts-1.33r33
CATEGORIES=	devel lang
MASTER_SITES=	http://www.polhode.com/
EXTRACT_SUFX=	.zip

HOMEPAGE=	http://www.polhode.com/pccts.html

PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes
WANTLIB=		c

MAKE_FILE=	makefile
MAKE_FLAGS=	CC="${CC}" COPT="${CFLAGS}"

ALL_TARGET=

WRKDIST=	${WRKDIR}/pccts

NO_REGRESS=	Yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/pccts
	cd ${WRKSRC}/bin; ${INSTALL_PROGRAM} antlr dlg genmk sor \
	  ${PREFIX}/bin 
	${INSTALL_DATA} ${WRKSRC}/h/* ${PREFIX}/include/pccts

.include <bsd.port.mk>
