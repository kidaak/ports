# $OpenBSD$

COMMENT-canna=		X input method for Japanese, canna support
COMMENT-canna-wnn=	X input method for Japanese, canna and wnn support
COMMENT-wnn=		X input method for Japanese, wnn support

DISTNAME=	kinput2-v3
PKGNAME=	ja-kinput2-3.0
REVISION=	6
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/x11/kinput2/
CATEGORIES=	japanese x11

# License: NOFEE
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB=	ICE SM X11 Xau Xaw Xdmcp Xext Xmu Xpm Xt c

MAINTAINER=	SUZUKI Hitoshi <sigh@kuzirabekon.econ.nagasaki-u.ac.jp>

CONFIGURE_STYLE=imake
FLAVORS=	canna wnn
FLAVOR?=	wnn

USE_GROFF =	Yes

.if ${FLAVOR:Mwnn}
BUILD_DEPENDS+=	japanese/Wnn
.endif
.if ${FLAVOR:Mcanna}
PERMIT_PACKAGE_CDROM=	Canna prevents it
WANTLIB += canna16
LIB_DEPENDS=	japanese/canna
.endif

PORT_DOCDIR=${PREFIX}/share/doc/kinput2

pre-configure:
	mv -f ${WRKSRC}/Kinput2.conf ${WRKSRC}/Kinput2.conf.org
	cp ${FILESDIR}/Kinput2.conf ${WRKSRC}/Kinput2.conf
.if ${FLAVOR:L:Mwnn}
	echo "#define UseWnn" >>${WRKSRC}/Kinput2.conf
.endif
.if ${FLAVOR:L:Mcanna}
	echo "#define UseCanna" >>${WRKSRC}/Kinput2.conf
.endif

NO_REGRESS=	Yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/kinput2
	cp ${WRKSRC}/README ${PORT_DOCDIR}
	cp ${WRKSRC}/NEWS ${PORT_DOCDIR}
	@(cd ${WRKSRC}/doc; tar -cf - . | \
		(cd ${PORT_DOCDIR}; tar -xf -))
	@chown -R ${SHAREOWN}:${SHAREGRP} ${PORT_DOCDIR}

.include <bsd.port.mk>
