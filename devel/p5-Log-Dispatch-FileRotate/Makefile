# $OpenBSD$

COMMENT=	log to files that archive/rotate themselves

MODULES=	cpan
DISTNAME=	Log-Dispatch-FileRotate-1.19
REVISION=	0
CATEGORIES=	devel
USE_GROFF =	Yes

# Perl
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

RUN_DEPENDS=		converters/p5-DateManip \
			devel/p5-Log-Dispatch \
			devel/p5-Params-Validate \
			devel/p5-Log-Log4perl

.include <bsd.port.mk>
