# $OpenBSD$
SHARED_ONLY=	Yes

COMMENT=	determine the malware activity on a network

DISTNAME=	nepenthes-0.2.2 
EPOCH=		1
REVISION=	1

CATEGORIES=	net

HOMEPAGE=	http://nepenthes.mwcollect.org/

# GPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nepenthes/}

USE_LIBTOOL=	Yes
LIBTOOL_FLAGS+=	--tag=disable-static
USE_GROFF =	Yes

MODULES=	devel/gettext

LIB_DEPENDS=	net/adns \
		net/curl \
		devel/libmagic \
		devel/pcre

WANTLIB=	c crypto idn m ssl stdc++ pcap z \
		adns>=1 curl>=3 magic>=1 pcre>=1

FAKE_FLAGS+=	localstatedir='/var/nepenthes' \
		sysconfdir='${PREFIX}/share/examples'

LOCALSTATEDIR=	${BASELOCALSTATEDIR}/nepenthes

CONFIGURE_STYLE=gnu
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include \
		-I${LOCALBASE}/include/postgresql"
CONFIGURE_ARGS+=--enable-debug-logging \
		--disable-mysql \
		--enable-postgre \
		--disable-capabilities \
		--with-curl-lib=${PREFIX}/lib

LIB_DEPENDS+=	databases/postgresql
WANTLIB +=	pq>=4

pre-configure:
	@perl -pi -e "s,%%SYSCONFDIR%%,${SYSCONFDIR}," \
		${WRKBUILD}/conf/nepenthes.conf.dist
	@perl -pi -e "s,%%PREFIX%%,${PREFIX}," \
		${WRKBUILD}/conf/nepenthes.conf.dist
	@perl -pi -e 's:\"var\/log:\"\/var\/nepenthes\/log:g' \
		${WRKBUILD}/modules/log-download/log-download.conf.dist
	@perl -pi -e 's:\"var\/binaries:\"/var\/nepenthes\/binaries:g' \
		${WRKBUILD}/modules/submit-file/submit-file.conf.dist

.include <bsd.port.mk>
