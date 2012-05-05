# $OpenBSD$

COMMENT =		Perl programming language
DISTNAME =		perl-5.14.2

#SHARED_LIBS =		???

CATEGORIES =		devel lang

HOMEPAGE =		http://www.perl.org/

# GPLv1+ or Artistic
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

#WANTLIB =		???

MASTER_SITES =		http://www.cpan.org/src/5.0/

#MODULES =		???
#BUILD_DEPENDS =	???
#RUN_DEPENDS =		???
#LIB_DEPENDS =		???
#REGRESS_DEPENDS =	???

#MAKE_FLAGS =		???
#MAKE_ENV =		???
#FAKE_FLAGS =		???
#REGRESS_FLAGS =	???

SEPARATE_BUILD =	Yes
#USE_GROFF =		Yes

CONFIGURE_SCRIPT =	${WRKSRC}/Configure
CONFIGURE_ARGS +=	-Dmksymlinks
CONFIGURE_ARGS +=	-dse
CONFIGURE_ARGS +=	-Dcc="${CC}"	
CONFIGURE_ARGS +=	-Dusethreads
CONFIGURE_ARGS +=	-Darchname=${ARCH}
CONFIGURE_ARGS +=	-DARCH=${ARCH}

#CFLAGS =		???
#LDFLAGS =		???

REGRESS_TARGET =	test

do-configure:
	cd ${WRKBUILD} && ${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}

.include <bsd.port.mk>
