# $OpenBSD$

COMMENT=		writes any log live onto the background
V=			0.6
DISTNAME=		xrootconsole-${V}
REVISION=		2
CATEGORIES=		x11

# GPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB=		X11 c util

MASTER_SITES=           ${MASTER_SITE_SOURCEFORGE:=xrootconsole/}

NO_REGRESS=		Yes
USE_GROFF =		Yes

CFLAGS+=		-I$(X11BASE)/include

OBJS = main.o util.o

do-build:
	cd ${WRKSRC} && \
	${CC} ${CFLAGS} -c main.c -DXROOTCONSOLE_VERSION=\"${V}\"; \
	${CC} ${CFLAGS} -c util.c -DXROOTCONSOLE_VERSION=\"${V}\"; \
	${CC} ${LDFLAGS} ${OBJS} -L$(X11BASE)/lib -lX11 -lutil -o xrootconsole

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xrootconsole ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xrootconsole.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
