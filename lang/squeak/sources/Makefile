# $OpenBSD$


COMMENT =	smalltalk system, smalltalk sources

DISTFILES =	SqueakV39.sources.gz
EXTRACT_ONLY =
NO_BUILD =	Yes
DISTNAME =	squeak-sources-${SOURCEV}
PKG_ARCH = *
MASTER_SITES =	${SQUEAK_SITE}

do-install:
	${INSTALL_DATA_DIR} ${SQUEAK_DIR}
	${INSTALL_DATA} ${FULLDISTDIR}/${DISTFILES} ${SQUEAK_DIR}
	gunzip ${SQUEAK_DIR}/${DISTFILES}


.include <bsd.port.mk>
