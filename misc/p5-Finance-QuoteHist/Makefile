# $OpenBSD$

COMMENT=	module to obtain historical financial quotes from exchanges

MODULES=	cpan
DISTNAME=	Finance-QuoteHist-0.32
REVISION=	2
CATEGORIES=	misc
USE_GROFF =	Yes

# GPL/Artistic License
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	converters/p5-DateManip \
		www/p5-HTML-TableExtract \
		www/p5-libwww

pre-configure:
	@rm -f ${WRKSRC}/lib/Finance/QuoteHist/*.orig

.include <bsd.port.mk>
