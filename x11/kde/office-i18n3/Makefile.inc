# $OpenBSD$

LANGS= ca cs cy da de el en_GB es et eu fi fr \
	hu it ja lv ms nb nl pl pt pt_BR ru sk sl sr sr@Latn \
	sv tr uk zh_CN zh_TW

REVISION =	2

.for i in ${LANGS}
SUPDISTFILES += koffice-l10n-$i-${VERSION}.tar.bz2
.endfor

DISTFILES = koffice-l10n-$L-${VERSION}.tar.bz2
WRKDIST = ${WRKDIR}/koffice-l10n-$L-${VERSION}
DISTNAME = koffice-i18n-$L-${VERSION:S/-//g}
COMMENT = $L translations for KDE
DOC=share/doc/HTML/$L/
LOC=share/locale/$L/LC_MESSAGES/
I=index.docbook
C=index.cache.bz2

SUBST_VARS = I C DOC LOC


CATEGORIES=		x11 x11/kde
VERSION=		1.6.2
MODGNU_CONFIG_GUESS_DIRS=	${WRKSRC}
MASTER_SITES=	${MASTER_SITE_KDE:=stable/koffice-${VERSION}/src/koffice-l10n/}

BUILD_DEPENDS = x11/kde/libs3
RUN_DEPENDS += x11/kde/libs3

MODKDE_VERSION =
CONFIGURE_STYLE = gnu

MAKE_FLAGS += MEINPROC=
CONFIGURE_ARGS += -C

PKGDIR = ${.CURDIR}/../pkg
DESCR = ${PKGDIR}/DESCR
PLIST = ${PKGDIR}/PLIST-$L
CHECKSUM_FILE = ${.CURDIR}/../distinfo

MODKDE_NODEBUG=Yes


# kdgantt.mo is already in kde-i18n
post-install:
	@find ${PREFIX}/${LOC} -name kdgantt.mo | xargs -r rm -f

# XXX have to do this manually here...
.include "${.CURDIR}/../../Makefile.inc"
