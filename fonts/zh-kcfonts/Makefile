# $OpenBSD$

COMMENT=	extra chinese fonts

DISTNAME=       zh-fonts-kc-1.05
REVISION=	0
CATEGORIES=     fonts chinese x11

MAINTAINER=     Kevin Lo <kevlo@openbsd.org>

PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=   Yes
PERMIT_PACKAGE_CDROM=   Yes
PERMIT_PACKAGE_FTP=     Yes

MASTER_SITES=	http://cle.linux.org.tw/fonts/bitmap/KCFONTS/
DIST_SUBDIR=    zh-kcfonts
DISTFILES=	${FONTS}

CONFIGURE_STYLE= imake

EXTRACT_ONLY=
NO_BUILD=	Yes
NO_REGRESS=	Yes
PKG_ARCH=	*

FONTS=		kc8x15.pcf.gz kc12x24.pcf.gz kc15f.pcf.gz kc24f.pcf.gz

FONTDIR=	${PREFIX}/lib/X11/fonts/chinese

post-extract:
	@mkdir -p ${WRKDIST}
	@cp ${FILESDIR}/Imakefile ${FILESDIR}/kc.alias ${WRKDIST}
	@for i in ${FONTS} ; do cp $(FULLDISTDIR)/$$i ${WRKDIST}; done

post-install:
	@cd ${FONTDIR} && mv fonts.alias fonts.alias-kc

.include <bsd.port.mk>
