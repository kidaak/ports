# $OpenBSD$

COMMENT =		minimalistic Mumble server 

DISTNAME =		umurmur-0.2.10

CATEGORIES =		audio

HOMEPAGE =		http://umurmur.googlecode.com/

MASTER_SITES =		${HOMEPAGE}/files/

MAINTAINER =		Jonathon Sisson <sisson.j@gmail.com>

# BSD
PERMIT_PACKAGE_CDROM =	Yes 
PERMIT_PACKAGE_FTP =	Yes 
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes 

WANTLIB = 		c config crypto protobuf-c ssl

LIB_DEPENDS =		devel/libconfig \
			devel/protobuf-c

CONFIGURE_STYLE =	gnu
CONFIGURE_ENV =		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS =	--with-ssl=openssl

NO_REGRESS =		Yes

post-configure:
	${SUBST_CMD} ${WRKSRC}/src/conf.c ${WRKSRC}/src/conf.h

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/umurmur
	${SUBST_CMD} -o ${SHAREOWN} -g ${SHAREGRP} \
		-c ${WRKBUILD}/umurmur.conf.example \
		${PREFIX}/share/examples/umurmur/umurmur.conf
	${INSTALL_MAN} ${FILESDIR}/umurmurd.1 \
		${PREFIX}/man/man1/
	${SUBST_CMD} -o ${SHAREOWN} -g ${SHAREGRP} \
		-c ${FILESDIR}/umurmur.conf.1 \
			${PREFIX}/man/man1/umurmur.conf.1

.include <bsd.port.mk>
