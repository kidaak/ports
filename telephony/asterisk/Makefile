# $OpenBSD$

SHARED_ONLY=		Yes
COMMENT-main=		open source multi-protocol PBX and telephony toolkit

VER=			10.8.0
DISTNAME=		asterisk-${VER:S/beta/-beta/:S/rc/-rc/}
PKGNAME-main=		asterisk-${VER}

CATEGORIES=		telephony

HOMEPAGE=		http://www.asterisk.org/

MAINTAINER=		Stuart Henderson <sthen@openbsd.org>

# Mostly GPL v2 (only). "Specific permission is also granted to link
# Asterisk with OpenSSL and OpenH323 and distribute the resulting binary
# files." iLBC codec has BSD-like license terms, but also see patent
# notes in codecs/ilbc/LICENSE_ADDENDUM.
PERMIT_PACKAGE_CDROM=	patent licensing clauses
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM= patent licensing clauses
PERMIT_DISTFILES_FTP=	Yes

WANTLIB-main +=	c crypto curl execinfo gsm idn iksemel
WANTLIB-main += m ogg pthread spandsp sqlite3 ssl stdc++ termcap
WANTLIB-main += tiff vorbis vorbisenc vorbisfile xml2 z
WANTLIB-main += ${MODGETTEXT_WANTLIB}

MODULES=		devel/gettext

MULTI_PACKAGES=		-main -calendar -http_post -ldap -odbc \
			-pgsql -snmp -speex
PSEUDO_FLAVORS=		no_calendar no_http_post no_ldap no_odbc \
			no_pgsql no_snmp no_speex

LIB_DEPENDS-main=	audio/gsm \
			audio/libogg \
			audio/libvorbis \
			devel/libexecinfo \
			graphics/tiff \
			net/curl \
			telephony/spandsp \
			textproc/iksemel \
			textproc/libxml \
			${MODGETTEXT_LIB_DEPENDS}
RUN_DEPENDS-main=	${MODGETTEXT_RUN_DEPENDS} \
			telephony/asterisk-sounds/core-sounds/en,gsm \
			telephony/asterisk-sounds/moh-opsound,wav
BUILD_DEPENDS=		security/libsrtp>=1.4.4 # statically linked

MASTER_SITES=	http://downloads.asterisk.org/pub/telephony/asterisk/releases/ \
		http://downloads.asterisk.org/pub/telephony/asterisk/old-releases/

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

USE_GMAKE=		Yes
USE_LIBTOOL=		Yes

CONFIGURE_STYLE=	gnu
AUTOCONF_VERSION=	2.68
AUTOMAKE_VERSION=	1.10
BUILD_DEPENDS+=		${MODGNU_AUTOCONF_DEPENDS} \
			${MODGNU_AUTOMAKE_DEPENDS} \
			devel/libtool,-ltdl # bogus dependencies in menuselect

CPPFLAGS+=		-I${X11BASE}/include -I${LOCALBASE}/include
LDFLAGS+=		-L${X11BASE}/lib -L${LOCALBASE}/lib
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}" \
			CFLAGS="${CFLAGS}" \
			LDFLAGS="${LDFLAGS}" \
			LIBS="-pthread"
MAKE_FLAGS+=		ASTCFLAGS="${CFLAGS}" \
			ASTLDFLAGS="${LDFLAGS}" \
			NOISY_BUILD="Yes" \
			OPTIMIZE=

CONFIGURE_ARGS+=	--localstatedir=/var

CONFIGURE_ARGS+=	--with-asound=no \
			--with-avcodec=no \
			--with-cap=no \
			--with-dahdi=no \
			--with-gtk2=no \
			--with-h323=no \
			--with-isdnnet=no \
			--with-misdn=no \
			--with-nbs=no \
			--with-newt=no \
			--with-osptk=no \
			--with-oss=no \
			--with-pri=no \
			--with-pwlib=no \
			--with-SDL_image=no \
			--with-sdl=no \
			--with-sqlite=no \
			--with-ss7=no \
			--with-suppserv=no \
			--with-tinfo=no \
			--with-tonezone=no \
			--with-vpb=no

CONFIGURE_ARGS+=	--with-jack=no \
			--with-lua=no \
			--with-portaudio=no \
			--with-radius=no \
			--with-resample=no \
			--with-tds=no

# Some build options (including a useful malloc debug) are available
# via menuselect. They may be enabled by running 'make configure', cd
# to WRKSRC, 'gmake menuselect', then 'cd -' back to the port directory
# and 'make'.

FLAVOR?=
FLAVORS=		imap

## flavours:

.if ${FLAVOR:Mimap}
CONFIGURE_ARGS+=	--with-imap=yes
MAKE_FLAGS+=		MENUSELECT_OPTS_app_voicemail=IMAP_STORAGE
CPPFLAGS+=		-I${LOCALBASE}/include/c-client
LIB_DEPENDS-main+=	mail/imap-uw,-c-client
WANTLIB-main+=		c-client gssapi krb5
.else
CONFIGURE_ARGS+=	--with-imap=no
.endif

## multipackages:
.include <bsd.port.arch.mk>

# calendar
COMMENT-calendar=	calendar support for Asterisk
WANTLIB-calendar=	${MODGETTEXT_WANTLIB} asn1 crypto expat gssapi \
			ical iksemel krb5 m neon proxy ssl xml2 z
LIB_DEPENDS-calendar=	net/neon \
			textproc/libical \
			${MODGETTEXT_LIB_DEPENDS}
.if !${BUILD_PACKAGES:M-calendar}
CONFIGURE_ARGS+=	--with-ical=no
.endif

# http_post
COMMENT-http_post=	HTTP POST support for Asterisk
LIB_DEPENDS-http_post=	mail/gmime ${MODGETTEXT_LIB_DEPENDS}
WANTLIB-http_post=	gio-2.0 glib-2.0 gmime-2.6 gobject-2.0 \
			${MODGETTEXT_WANTLIB}
.if !${BUILD_PACKAGES:M-http_post}
CONFIGURE_ARGS+=	--with-gmime=no
.endif

# ldap
COMMENT-ldap=		LDAP support for Asterisk
LIB_DEPENDS-ldap=	databases/openldap,-main
WANTLIB-ldap=		ldap
.if !${BUILD_PACKAGES:M-ldap}
CONFIGURE_ARGS+=	--with-ldap=no
.endif

# mysql				need to handle building addons/ first XXX
# up above .include <bsd.port.arch.mk>
#PSEUDO_FLAVORS+=	no_mysql
#MULTI_PACKAGES+=	-mysql
#
#COMMENT-mysql=		MySQL support for Asterisk
#WANTLIB-mysql=		mysqlclient
#LIB_DEPENDS-mysql=	databases/mysql
#.if !${BUILD_PACKAGES:M-mysql}
#CONFIGURE_ARGS+=	--with-mysqlclient=no
#.endif

# odbc
COMMENT-odbc=		ODBC support for Asterisk
LIB_DEPENDS-odbc=	databases/iodbc
WANTLIB-odbc=		iodbc pthread
.if !${BUILD_PACKAGES:M-odbc}
CONFIGURE_ARGS+=	--with-iodbc=no \
			--with-ltdl=no
.endif

# postgresql
COMMENT-pgsql=		PostgreSQL support for Asterisk
WANTLIB-pgsql=		pq z
LIB_DEPENDS-pgsql=	databases/postgresql
.if !${BUILD_PACKAGES:M-pgsql}
CONFIGURE_ARGS+=	--with-postgres=no
.endif

# snmp
COMMENT-snmp=		Net-SNMP support for Asterisk
WANTLIB-snmp=		m netsnmp netsnmpagent netsnmpmibs crypto kvm wrap
LIB_DEPENDS-snmp=	net/net-snmp
.if !${BUILD_PACKAGES:M-snmp}
CONFIGURE_ARGS+=	--with-snmp=no
.endif

# speex
COMMENT-speex=		Speex codec for Asterisk
WANTLIB-speex=		m speex speexdsp
LIB_DEPENDS-speex=	audio/speex>=1.2rc1
.if !${BUILD_PACKAGES:M-speex}
CONFIGURE_ARGS+=	--with-speex=no
.endif

NO_REGRESS=		Yes
INSTALL_TARGET=		install samples
EXAMPLEDIR=		${PREFIX}/share/examples/asterisk
EXAMPLEFILES=		cdr.conf extensions.ael extensions.conf logger.conf \
			modules.conf musiconhold.conf sip.conf voicemail.conf

.for i in ${MULTI_PACKAGES:N-main}
# subpackages aren't flavoured, so overwrite the default name/path
FULLPKGNAME$i ?=	asterisk$i-${VER}
FULLPKGPATH$i ?=	${PKGPATH},$i
RUN_DEPENDS$i +=	asterisk-${VER}:${BUILD_PKGPATH}
.endfor

post-patch:
	cd ${WRKSRC}; \
	    AUTOMAKE_VERSION=${AUTOMAKE_VERSION} \
	    AUTOCONF_VERSION=${AUTOCONF_VERSION} \
	    ./bootstrap.sh

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/asterisk
	${INSTALL_DATA} ${WRKSRC}/{BUGS,CHANGES,COPYING,CREDITS} \
		${WRKSRC}/{ChangeLog,LICENSE,README*,UPGRADE*.txt} \
		${PREFIX}/share/doc/asterisk
	${INSTALL_DATA} ${WRKSRC}/doc/*.{pdf,txt,odt} \
		${PREFIX}/share/doc/asterisk
	${INSTALL_DATA_DIR} ${EXAMPLEDIR}/openbsd
.for i in ${EXAMPLEFILES}
	@${SUBST_CMD} -c ${FILESDIR}/$i.sample \
	    ${EXAMPLEDIR}/openbsd/$i.sample
.endfor
	${INSTALL_DATA} ${WRKSRC}/contrib/scripts/asterisk.ldif \
		${WRKSRC}/contrib/scripts/asterisk.ldap-schema \
		${PREFIX}/share/examples/asterisk/
	@mv ${WRKINST}/${SYSCONFDIR}/asterisk ${EXAMPLEDIR}/default
	@chown -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLEDIR}
	@rm -rf ${WRKINST}/{etc,var/{log,run,spool}}/asterisk

.include <bsd.port.mk>
