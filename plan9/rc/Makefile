# $OpenBSD$

COMMENT=	shell (clone of plan9 shell)

DISTNAME=	rc-1.6
REVISION=	0
CATEGORIES=	plan9 shells
MASTER_SITES=	http://www.star.le.ac.uk/~tjg/rc/release/ \
		ftp://ftp.sys.toronto.edu/pub/rc/
MASTER_SITES0=	http://www.star.le.ac.uk/~tjg/rc/misc/
SUPDISTFILES=	editline-1.5.tar.gz:0

MAINTAINER=	Markus Friedl <markus@openbsd.org>

PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB=		c

SEPARATE_BUILD=	Yes
CONFIGURE_STYLE= gnu
CONFIGURE_ARGS=	--with-history

FLAVORS=	readline editline
FLAVOR?=

USE_GROFF =	Yes
REGRESS_TARGET= trip

.if defined(WITH_READLINE) && ${WITH_READLINE:U} == YES
FLAVOR+=readline
.elif defined(WITH_EDITLINE) && ${WITH_EDITLINE:U} == YES
FLAVOR+=editline
.endif

.if ${FLAVOR:L} == "readline"
CONFIGURE_ARGS+= --with-readline
WANTLIB+=		readline termcap
.elif ${FLAVOR:L} == "editline"
DISTFILES=	${DISTNAME}.tar.gz editline-1.5.tar.gz:0
EDITLINE=	${WRKSRC}/../editline
CONFIGURE_ARGS+= --with-editline
CONFIGURE_ENV=	LIBS="-L${EDITLINE}"
.endif

.if ${FLAVOR:L} == "editline"
pre-configure:
	@echo "===>  Compiling editline"
	@cd ${EDITLINE} && ${MAKE_PROGRAM}
.endif

.include <bsd.port.mk>
