# $OpenBSD$

COMMENT =		fonts from the League of Moveable Type

PKGNAME =		league-fonts-0.1
REVISION =		1
PKG_ARCH =		*
EXTRACT_SUFX =		.zip
.for font in \
			blackout chunk flaminia-type-system goudy-bookletter-1911 junction \
			league-gothic league-script-1 linden-hill orbitron \
			prociono raleway sniglet sorts-mill-goudy
DISTFILES +=		${font}${EXTRACT_SUFX}
.endfor

CATEGORIES =		fonts x11

HOMEPAGE =		http://www.theleagueofmoveabletype.com/
MASTER_SITES =		http://s3.amazonaws.com/theleague-production/fonts/

MAINTAINER=		Ian Darwin <ian@openbsd.org>

# Custom "SIL OPEN FONT LICENSE Version 1.1":
# "Permission is hereby granted, free of charge, to any person obtaining
# a copy of the Font Software, to use, study, copy, merge, embed, modify,
# redistribute, and sell modified and unmodified copies of the Font Software..."
# Allows redistribution of unmodified fonts even if bundled for sale with other software.
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM = Yes
PERMIT_DISTFILES_FTP =	Yes

DIST_SUBDIR =		leaguefonts

NO_BUILD =		Yes
NO_REGRESS =		Yes

INST_DIR=       ${PREFIX}/lib/X11/fonts/league-fonts/

post-extract:
	rm -r ${WRKDIR}/__MACOSX/
	mv ${WRKDIR}/Orbitron/readme.txt ${WRKDIR}/Orbitron/Orbitron_readme.txt
	mv ${WRKDIR}/Blackout/please_read_me.txt ${WRKDIR}/Blackout_please_read_me.txt

do-install:
	${INSTALL_DATA_DIR} ${INST_DIR}
	${INSTALL_DATA} ${WRKDIR}/*.??f ${WRKDIR}/*/*.??f ${WRKDIR}/*/*.txt ${INST_DIR}

.include <bsd.port.mk>
