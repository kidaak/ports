# $OpenBSD$

SHARED_ONLY=		Yes

COMMENT-main=		SMB and CIFS client and server for UNIX
COMMENT-docs=		additional documentation and examples for Samba

DISTNAME=		samba-3.6.8
PKGNAME-main=		${DISTNAME}
FULLPKGNAME-docs=	${DISTNAME:S/-/-docs-/}
FULLPKGPATH-docs=	net/samba,-docs

SHARED_LIBS=		smbclient	3.0 \
			smbsharemodes	1.0 \
			netapi		1.0 \
			wbclient	1.0

CATEGORIES=		net

HOMEPAGE=		http://www.samba.org/

MAINTAINER=		Ian McWilliam <kaosagnt@tpg.com.au>

# GPLv3+
PERMIT_PACKAGE_CDROM=		Yes
PERMIT_PACKAGE_FTP=		Yes
PERMIT_DISTFILES_CDROM=		Yes
PERMIT_DISTFILES_FTP=		Yes

WANTLIB += asn1 c crypto cups execinfo gssapi krb5 m ncurses popt
WANTLIB += pthread readline ssl talloc tdb z

MASTER_SITES=	http://download.samba.org/samba/ftp/ \
		http://us2.samba.org/samba/ftp/ \
		http://ftp.samba.org/samba/ftp/old-versions/

MODULES=	converters/libiconv

BUILD_DEPENDS=	${MODGNU_AUTOCONF_DEPENDS} \
		sysutils/e2fsprogs
LIB_DEPENDS=	databases/tdb>=1.2.7 \
		devel/popt \
		devel/libexecinfo \
		devel/libtalloc \
		print/cups,-libs

MAKE_FLAGS+=	PASSWD_PROGRAM="/usr/bin/passwd" \
		LIBSMBCLIENT_SHARED_TARGET_SONAME="bin/libsmbclient.so.${LIBsmbclient_VERSION}" \
		LIBSMBSHAREMODES_SHARED_TARGET_SONAME="bin/libsmbsharemodes.so.${LIBsmbsharemodes_VERSION}" \
		LIBNETAPI_SHARED_TARGET_SONAME="bin/libnetapi.so.${LIBnetapi_VERSION}" \
		LIBADDNS_SHARED_TARGET_SONAME="bin/libaddns.so.${LIBaddns_VERSION}" \
		LIBWBCLIENT_SHARED_TARGET_SONAME="bin/libwbclient.so.${LIBwbclient_VERSION}"

CONFDIR=		${SYSCONFDIR}/samba
SAMBA_LOGDIR=		/var/log/samba
SUBST_VARS=		CONFDIR

USE_GMAKE=		Yes
USE_GROFF=		Yes
#SEPARATE_BUILD=		Yes
CONFIGURE_STYLE=	gnu
AUTOCONF_VERSION=	2.68

CONFIGURE_ARGS=		--disable-fam \
			--libdir="${PREFIX}/lib/samba" \
			--sbindir="${PREFIX}/libexec" \
			--with-configdir="${CONFDIR}" \
			--with-modulesdir="${PREFIX}/lib/samba" \
			--with-lockdir="/var/spool/samba" \
			--with-piddir="/var/run" \
			--with-logfilebase="${SAMBA_LOGDIR}" \
			--with-privatedir="${CONFDIR}" \
			--with-libsmbclient \
			--with-swatdir="${PREFIX}/share/swat" \
			--with-syslog \
			--with-utmp \
			--with-winbind \
			--with-wbclient \
			--enable-avahi=no \
			--enable-external-libtdb=yes \
			--enable-external-libtalloc=yes \
			--enable-pthreadpool

# Uncomment to enable debugging symbols.
#CONFIGURE_ARGS+=	--enable-debug

CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"

FLAVORS=		ldap ads
FLAVOR?=

MULTI_PACKAGES=		-main -docs

.if ${FLAVOR:L:Mldap} && ${FLAVOR:L:Mads}
ERRORS+= "Fatal: ldap and ads flavors conflict"
.endif

.if ${FLAVOR:L:Mldap} || ${FLAVOR:L:Mads}
LIB_DEPENDS+=	databases/openldap
WANTLIB +=	ldap lber
.else
CONFIGURE_ARGS+=	--without-ldap
.endif

.if ${FLAVOR:L:Mads}
CONFIGURE_ARGS+=	--with-krb5="${WRKDIR}/usr"

# Merged build cruft needs loads of work. Disable until ready.
#SEPERATE_BUILD=	simple
#CONFIGURE_ARGS+=	--enable-merged-build
#MODULES+=		lang/python
#MODPY_RUNDEP=		No

WANTLIB+=		com_err
.else
CONFIGURE_ARGS+=	--without-ads
.endif

PKG_ARCH-docs=		*
LIB_DEPENDS-docs=
WANTLIB-docs=
RUN_DEPENDS-docs=

# REGRESSION testing is currently borked. Builds, runs
# tests fail. Fix one day.
NO_REGRESS=		Yes
#REGRESS_TARGET=	test
#.ifmake regress
#CONFIGURE_ARGS+=	--enable-socket-wrapper \
#			--enable-nss-wrapper
#.endif

WRKSRC=		${WRKDIR}/${DISTNAME}/source3

SAMBA_DOCS=	${WRKDIST}/README \
		${WRKDIST}/docs/history \
		${WRKDIST}/docs/registry/*.reg

SAMPLE_CONFIG=	${PREFIX}/share/examples/samba/smb.conf.default

SAMBA_MANPAGES= ${WRKDIST}/docs/manpages

post-patch:
	@cd ${WRKSRC}; \
	    AUTOCONF_VERSION=${AUTOCONF_VERSION} \
	    ./autogen.sh

pre-configure:
	@${SUBST_CMD} ${SAMBA_MANPAGES}/swat.8

post-extract:
	@cp ${FILESDIR}/krb5-config ${WRKDIR}/bin
	@chmod a+x ${WRKDIR}/bin/krb5-config

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/samba/pdf
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/samba/htmldocs
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/samba
	@cp -R ${WRKDIST}/examples/* ${PREFIX}/share/examples/samba
	@chown -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/examples/samba
	@find ${PREFIX}/share/examples/samba -type f | \
	    xargs chmod ${SHAREMODE}
	@find ${PREFIX}/share/examples/samba -type d | \
	    xargs chmod ${DIRMODE}
	@for i in ${SAMBA_DOCS}; do \
	 ${INSTALL_DATA} $$i ${PREFIX}/share/doc/samba ;	\
	done
	@for i in ${WRKDIST}/docs/*.pdf ; do \
	 ${INSTALL_DATA} $$i ${PREFIX}/share/doc/samba/pdf ; \
	done
	@for i in ${WRKDIST}/docs/htmldocs/* ; do \
	 if [ -f $$i ]; then \
	  ${INSTALL_DATA} $$i ${PREFIX}/share/doc/samba/htmldocs ;\
	 fi \
	done
	@sed -e 's:/usr/spool/samba:/var/spool/samba:g' \
	 -e 's:/usr/local/samba/var/log:${SAMBA_LOGDIR}/smbd:g' \
	 -e 's:MYGROUP:WORKGROUP:' \
	 ${WRKDIST}/examples/smb.conf.default > ${SAMPLE_CONFIG}
	${INSTALL_SCRIPT} ${WRKSRC}/script/mksmbpasswd.sh \
	 ${PREFIX}/bin/mksmbpasswd
	@chown ${BINOWN}:${BINGRP} ${PREFIX}/bin/smbpasswd
	@ln -s samba/libsmbclient.so.${LIBsmbclient_VERSION} \
	 ${PREFIX}/lib/libsmbclient.so.${LIBsmbclient_VERSION}
	@ln -s samba/libsmbsharemodes.so.${LIBsmbsharemodes_VERSION} \
	 ${PREFIX}/lib/libsmbsharemodes.so.${LIBsmbsharemodes_VERSION}
	@ln -s samba/libnetapi.so.${LIBnetapi_VERSION} \
	 ${PREFIX}/lib/libnetapi.so.${LIBnetapi_VERSION}
	@ln -s samba/libwbclient.so.${LIBwbclient_VERSION} \
	 ${PREFIX}/lib/libwbclient.so.${LIBwbclient_VERSION}
	@rmdir ${WRKINST}${SYSCONFDIR}/samba
	@rmdir ${WRKINST}/var/spool/samba

.include <bsd.port.mk>
