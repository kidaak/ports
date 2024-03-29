# $OpenBSD$

COMMENT=	API for accessing scanners, backends

DISTNAME=	sane-backends-1.0.23

SHARED_LIBS=	sane 2.0 # .1.0
CATEGORIES=	graphics

HOMEPAGE=	http://www.sane-project.org/

MAINTAINER=	Antoine Jacoutot <ajacoutot@openbsd.org>

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB += asn1 c crypto cups gssapi jpeg krb5 m pthread ssl tiff
WANTLIB += usb usb-1.0 z

# XXX
# README.txt: Due to limitations in alioth's file upload software, the
# release has been divided into 3 parts. Download all three, and the
# .md5sum. Join them using the following command:
# cat sane-backends-1.0.23.tar.gz.[1-3] > sane-backends-1.0.23.tar.gz
# Then check the md5sum as follows:
# md5sum -c sane-backends-1.0.23.tar.gz.md5
# MASTER_SITES=	https://alioth.debian.org/frs/download.php/3752/ \
#		ftp://ftp.sane-project.org/pub/sane/${DISTNAME}/ \
#		ftp://ftp.sane-project.org/pub/sane/old-versions/${DISTNAME}/ \
#		ftp://ftp2.sane-project.org/pub/sane/${DISTNAME}/
MASTER_SITES=	http://distfiles.bsdfrog.org/

LIB_DEPENDS=	graphics/tiff \
		devel/libusb-compat \
		print/cups,-libs

FLAVORS=	snmp
FLAVOR?=

USE_LIBTOOL=	Yes
USE_GMAKE=	Yes
USE_GROFF=	Yes
NO_REGRESS=	Yes

LOCALSTATEDIR=	${BASELOCALSTATEDIR}/spool

CONFIGURE_STYLE=gnu
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	${CONFIGURE_SHARED} \
		--sbindir=${PREFIX}/libexec \
		--with-docdir=${PREFIX}/share/doc/sane-backends \
		--without-gphoto2 \
		--with-group=553 \
		--disable-latex

# XXX doesn't work
#CONFIGURE_ARGS+=--enable-avahi

.if ${FLAVOR:Msnmp}
LIB_DEPENDS +=	net/net-snmp
WANTLIB +=	crypto netsnmp
CONFIGURE_ARGS += --with-snmp
.else
CONFIGURE_ARGS += --without-snmp
.endif

FAKE_FLAGS=	configdir=${PREFIX}/share/examples/sane-backends/sane.d

pre-configure:
	${SUBST_CMD} ${WRKSRC}/configure

post-install:
	# removing the microtek2 backend which needs a Linux kernel module
	find ${PREFIX} -name \*microtek2\* | xargs rm
	cp -R ${WRKSRC}/tools/openbsd/ \
		${PREFIX}/share/examples/sane-backends/hotplug
	rm ${PREFIX}/share/examples/sane-backends/hotplug/{attach,detach}.orig

.include <bsd.port.mk>
