# $OpenBSD$

COMMENT-main=	driver for ZjStream wire protocol compatible printers
COMMENT-cups=	Konica-Minolta foo2zjs command filter for CUPS

VERSION=	20120601
DISTNAME=	foo2zjs-${VERSION}

PKGNAME-main=	${DISTNAME}
PKGNAME-cups=	foo2zjs-cup-${VERSION}

CATEGORIES=	print

HOMEPAGE=	http://foo2zjs.rkkda.com/

MAINTAINER=	Antoine Jacoutot <ajacoutot@openbsd.org>

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB += c

MASTER_SITES=	http://distfiles.bsdfrog.org/

MULTI_PACKAGES=	-main -cups

USE_GMAKE=	Yes
WRKDIST=	${WRKDIR}/foo2zjs

BUILD_DEPENDS=	print/ghostscript/gnu # ps2pdf

WANTLIB-main += ${WANTLIB} m

# share/foomatic/db/source/*/*.xml
RUN_DEPENDS-main +=	print/foomatic-db-engine

WANTLIB-cups += ${WANTLIB} cups pthread
RUN_DEPENDS-cups=${BASE_PKGPATH},-main
LIB_DEPENDS-cups=print/cups,-libs

MAKE_FLAGS+=	CUPS_SERVERBIN=`cups-config --serverbin`

USE_GROFF =	Yes
NO_REGRESS=	Yes

post-patch:
	ln -sf ${WRKSRC}/modify-ppd ${WRKDIR}/bin/modify-ppd

pre-configure:
	perl -pi -e 's,/usr/bin,${PREFIX}/bin,g' \
		${WRKSRC}/*.1in
	perl -pi -e 's,\$\(shell ,\$\(,g' ${WRKSRC}/{,icc2ps}/Makefile
	${SUBST_CMD} ${WRKSRC}/getweb.in

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/{getweb,msexpand} \
		${PREFIX}/share/doc/foo2zjs
	${INSTALL_DATA_DIR} ${PREFIX}/libexec/cups/filter
	ln -sf ${TRUEPREFIX}/bin/command2foo2lava-pjl \
		${WRKINST}/${LOCALBASE}/libexec/cups/filter/

.include <bsd.port.mk>
