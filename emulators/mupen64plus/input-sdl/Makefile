# $OpenBSD$

COMMENT =		n64 emulator input plugin

# GPLv2+
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

WANTLIB =		SDL
LIB_DEPENDS =		devel/sdl

MUPEN64PLUS_MOD = 	input-sdl

# resolve 'no newline at end of file' warning
post-patch:
	echo >> ${WRKSRC}/src/osal_preproc.h

.include <bsd.port.mk>
