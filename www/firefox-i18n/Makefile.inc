# $OpenBSD$

# keep in sync with working archs.. sigh
ONLY_FOR_ARCHS =	amd64 i386 powerpc

PKG_ARCH =	*

FV =		15.0.1
V =		${FV:C/b.$//}
NAME =		firefox-i18n

CATEGORIES =	www

HOMEPAGE =	https://wiki.mozilla.org/L10n:Home_Page

MAINTAINER =	Landry Breuil <landry@openbsd.org>

# Mozilla public license
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

MASTER_SITES =	https://ftp.mozilla.org/pub/mozilla.org/firefox/releases/${FV}/linux-i686/xpi/ \
		http://releases.mozilla.org/pub/mozilla.org/firefox/releases/${FV}/linux-i686/xpi/ \
		ftp://ftp.mozilla.org/pub/mozilla.org/firefox/releases/${FV}/linux-i686/xpi/

LANGUAGES =	af ak ar ast be bg bn-BD bn-IN br bs ca cs cy da de el en-GB en-US en-ZA eo \
		es-AR es-CL es-ES es-MX et eu fa fi fr fy-NL ga-IE gd gl gu-IN he \
		hi-IN hr hu hy-AM id \
		is it ja kk kn ko ku lg lt lv mai mk ml mr nb-NO nl nn-NO nso \
		or pa-IN pl pt-BR pt-PT rm ro ru si sk sl son sq sr sv-SE \
		ta-LK ta te th tr uk vi zh-CN zh-TW zu

BUILD_DEPENDS =	archivers/unzip
RUN_DEPENDS =	firefox-${FV:S/b/beta/}:www/mozilla-firefox

DIST_SUBDIR =	mozilla/${NAME}-${FV}
NO_BUILD =	Yes
NO_REGRESS =	Yes
EXTRACT_ONLY =

.for i in ${LANGUAGES}
SUPDISTFILES +=	$i.xpi
.endfor

PKGNAME =	${NAME}-$L-${FV:S/b/beta/}
COMMENT =	$L language pack for Firefox
DISTFILES =	$L.xpi

# use the same for all subpackages
PKGDIR =	${.CURDIR}/../pkg
PLIST =		${PKGDIR}/PLIST
DESCR =		${PKGDIR}/DESCR
CHECKSUM_FILE =	${.CURDIR}/../distinfo
MESSAGE=	${PKGDIR}/MESSAGE
SUBST_VARS =	V L

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/firefox-$V/extensions
	${INSTALL_DATA} ${FULLDISTDIR}/$L.xpi ${PREFIX}/lib/firefox-$V/extensions/langpack-$L@firefox.mozilla.org.xpi
