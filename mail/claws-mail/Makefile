# $OpenBSD$

SHARED_ONLY=		Yes

COMMENT-main=		mail and news client
COMMENT-bogofilter=	bogofilter plugin
COMMENT-clamav=		clamav plugin
COMMENT-spamassassin=	spamassassin plugin

V=			3.8.1
DISTNAME=		claws-mail-${V}
PKGNAME-main=		${DISTNAME}
PKGNAME-bogofilter=	claws-mail-bogofilter-${V}
PKGNAME-spamassassin=	claws-mail-spamassassin-${V}
CATEGORIES=		mail news

HOMEPAGE=		http://www.claws-mail.org/

# GPLv3+
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=sylpheed-claws/}
EXTRACT_SUFX=		.tar.bz2

DIST_SUBDIR=		claws

MULTI_PACKAGES=		-main -bogofilter -spamassassin
FLAVORS=		jpilot compface ldap debug
FLAVOR?=

FLAVOR_STRING=		${FLAVOR_EXT:S/-/,/g}
SUBST_VARS=		FLAVOR_STRING

RUN_DEPENDS-bogofilter=	${BUILD_PKGPATH} \
			mail/bogofilter 
RUN_DEPENDS-spamassassin=${BUILD_PKGPATH} \
			mail/p5-Mail-SpamAssassin 

WANTLIB=		X11 Xau Xcomposite Xcursor Xdamage Xdmcp Xext Xfixes \
			Xi Xinerama Xrandr Xrender atk-1.0 cairo crypto curl \
			expat fontconfig freetype gio-2.0 glib-2.0 gthread-2.0 \
			gmodule-2.0 gobject-2.0 idn m pango-1.0 pangocairo-1.0 \
			pangoft2-1.0 pcre pixman-1 png pthread-stubs ssl \
			gcrypt gpg-error xcb z gdk_pixbuf-2.0 \
			gdk-x11-2.0 gtk-x11-2.0 execinfo etpan>=13 sasl2 \
			GL Xxf86vm drm xcb-render xcb-shm

WANTLIB-main=		${WANTLIB} ICE SM c dbus-1 gmp hogweed nettle \
			pthread stdc++ tasn1 xcb-atom xcb-aux xcb-event assuan \
			startup-notification-1 enchant gnutls gpgme dbus-glib-1

WANTLIB-docs=

LIB_DEPENDS=		x11/gtk+2 \
			devel/libexecinfo \
			mail/libetpan \
			security/cyrus-sasl2 \
			security/libgcrypt

RUN_DEPENDS-main=	${RUN_DEPENDS} \
			devel/desktop-file-utils \
			x11/gtk+2,-guic

LIB_DEPENDS-main=	${LIB_DEPENDS} \
			devel/startup-notification \
			textproc/enchant \
			security/gnutls>=2.2 \
			security/gpgme \
			x11/dbus-glib

CONFIGURE_ARGS+=	--disable-gnomeprint \
			--disable-networkmanager-support \
			--disable-dillo-viewer-plugin

MODULES=		devel/gettext
USE_GMAKE=		Yes
USE_LIBTOOL=		Yes
USE_GROFF =		Yes
LIBTOOL_FLAGS=		--tag=disable-static
CONFIGURE_STYLE=	autoconf

AUTOCONF_VERSION=	2.68
CONFIGURE_ENV+=		CPPFLAGS="-I${X11BASE}/include" \
			LDFLAGS="-L${X11BASE}/lib"

.if ${FLAVOR:Mjpilot}
LIB_DEPENDS-main+=	comms/pilot-link 
WANTLIB-main +=		pisock
RUN_DEPENDS-main+=	comms/jpilot
.else
CONFIGURE_ARGS+=	--disable-jpilot
.endif

.if ${FLAVOR:Mcompface}
PERMIT_PACKAGE_CDROM=   No Fee
PERMIT_DISTFILES_CDROM= No Fee
LIB_DEPENDS-main+=     	mail/faces
WANTLIB-main +=		compface>=1
.else
CONFIGURE_ARGS+=       --disable-compface
.endif

.if ${FLAVOR:Mldap}
WANTLIB-main+=		asn1 com_err gssapi krb5 lber ldap
LIB_DEPENDS-main+=	databases/openldap
.else
CONFIGURE_ARGS+=	--disable-ldap
.endif

.if ${FLAVOR:Mdebug}
CFLAGS+=	-O0 -g
INSTALL_STRIP=
.endif

TOOLS=		OOo2claws-mail.pl \
		acroread2claws-mail.pl \
		calypso_convert.pl \
		claws-mail-compose-insert-files.pl \
		convert_mbox.pl \
		csv2addressbook.pl \
		eud2gc.py \
		filter_conv.pl filter_conv_new.pl \
		fix_date.sh \
		freshmeat_search.pl \
		gif2xface.pl \
		google_msgid.pl google_search.pl \
		kmail-mailbox2claws-mail.pl \
		kmail2claws-mail.pl kmail2claws-mail_v2.pl \
		mairix.sh \
		mew2claws-mail.pl \
		multiwebsearch.conf multiwebsearch.pl \
		nautilus2claws-mail.sh \
		outlook2claws-mail.pl \
		popfile-link.sh \
		tb2claws-mail tbird2claws.py \
		textviewer.pl textviewer.sh \
		thunderbird-filters-convertor.pl \
		uudec uuooffice \
		vcard2xml.py \
		README \
		kdeservicemenu/claws-mail-attach-files.desktop.kde4template \
		kdeservicemenu/claws-mail-attach-files.desktop.template \
		kdeservicemenu/claws-mail-kdeservicemenu.pl \
		kdeservicemenu/install.sh \
		kdeservicemenu/README

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/icons/hicolor/48x48/apps
	${INSTALL_DATA} ${WRKSRC}/claws-mail.png ${PREFIX}/share/icons/hicolor/48x48/apps/claws-mail.png
	${INSTALL_DATA_DIR} ${PREFIX}/share/icons/hicolor/64x64/apps
	${INSTALL_DATA} ${WRKSRC}/claws-mail-64x64.png ${PREFIX}/share/icons/hicolor/64x64/apps/claws-mail.png
	${INSTALL_DATA_DIR} ${PREFIX}/share/icons/hicolor/128x128/apps
	${INSTALL_DATA} ${WRKSRC}/claws-mail-128x128.png ${PREFIX}/share/icons/hicolor/128x128/apps/claws-mail.png
	${INSTALL_DATA_DIR} ${PREFIX}/share/claws-mail/tools/kdeservicemenu
.for i in ${TOOLS}
	${INSTALL_DATA} ${WRKSRC}/tools/${i} \
	${PREFIX}/share/claws-mail/tools/${i}
.endfor

.include <bsd.port.mk>
