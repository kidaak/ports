# $OpenBSD$

COMMENT=	library and toolset to operate arrays of data

DISTNAME=	orc-0.4.16
REVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://code.entropywave.com/download/orc/

SHARED_LIBS=	orc-0.4		4.0 \
		orc-test-0.4	3.0

HOMEPAGE=	http://code.entropywave.com/projects/orc/

MAINTAINER=	Brad Smith <brad@comstyle.com>

# BSD
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB=	c m pthread

USE_GMAKE=	Yes
USE_LIBTOOL=	Yes
CONFIGURE_STYLE= autoconf
AUTOCONF_VERSION= 2.67

# XXX segfault in orc_audio_convert_unpack_float_32() with Altivec when
# playing a video.
.if ${MACHINE_ARCH} == "powerpc"
CONFIGURE_ARGS=	--enable-backend=none
.endif

.include <bsd.port.mk>
