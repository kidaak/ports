# $OpenBSD$

COMMENT= 		WWW quote retrieval tool

DISTNAME=		xquote-2.6.10
REVISION=		7
CATEGORIES=		productivity x11

MAINTAINER=		Martynas Venckus <martynas@openbsd.org>

# BSD
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB=	ICE SM X11 Xau Xdmcp Xext Xmu Xpm Xt c m Xbae Xm

MASTER_SITES=	http://distfiles.nl/

LIB_DEPENDS=	x11/xbae \
		x11/openmotif

CONFIGURE_STYLE= imake
INSTALL_MAN=	No	# no manual page
MAKE_ENV+=MOTIFLIB='-L${LOCALBASE}/lib -lXm'

NO_REGRESS=	Yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Xquote ${PREFIX}/bin/xquote
	${INSTALL_DATA} ${WRKSRC}/Xquote.ad ${PREFIX}/lib/X11/app-defaults/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xquote
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xquote

.include <bsd.port.mk>
