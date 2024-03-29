# $OpenBSD$

COMMENT-main=		subversion revision control system
COMMENT-perl=		perl interface to subversion
COMMENT-python=		python interface to subversion
COMMENT-ruby=		ruby interface to subversion
COMMENT-ap2=		apache2 subversion modules
COMMENT-gnome-keyring=	GNOME keyring support for subversion

VERSION=		1.7.6
DISTNAME=		subversion-${VERSION}
PKGNAME-main=		${DISTNAME}
FULLPKGNAME-perl=	p5-SVN-${VERSION}
FULLPKGPATH-perl=	devel/subversion,-perl
FULLPKGNAME-python=	py-subversion-${VERSION}
FULLPKGPATH-python=	devel/subversion,-python
FULLPKGNAME-ruby=	ruby-subversion-${VERSION}
FULLPKGPATH-ruby=	devel/subversion,-ruby
FULLPKGNAME-ap2=	ap2-subversion-${VERSION}
FULLPKGPATH-ap2=	devel/subversion,-ap2
FULLPKGNAME-gnome-keyring= gnome-keyring-subversion-${VERSION}
FULLPKGPATH-gnome-keyring= devel/subversion,-gnome-keyring

SO_VERSION=	1.3
SVN_LIBS=	svn_client-1 svn_delta-1 svn_diff-1 svn_fs-1 \
		svn_fs_base-1 svn_fs_fs-1 svn_fs_util-1 svn_ra-1 \
		svn_ra_neon-1 svn_ra_local-1 svn_ra_neon-1 \
		svn_ra_svn-1 svn_repos-1 svn_subr-1 svn_wc-1
SVN_EXT_LIBS=	svn_swig_perl-1 svn_swig_py-1 svn_swig_ruby-1 \
		svn_auth_gnome_keyring-1
.for _lib in ${SVN_LIBS} ${SVN_EXT_LIBS}
SHARED_LIBS+=	${_lib} ${SO_VERSION}
.endfor

CATEGORIES=	devel

HOMEPAGE=	http://subversion.apache.org

MAINTAINER=	Stefan Sperling <stsp@openbsd.org>

# BSD alike + Apache License 2.0
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=	${MASTER_SITE_APACHE:=subversion/}
EXTRACT_SUFX=	.tar.bz2

PSEUDO_FLAVORS=	no_bindings no_ap2 no_perl no_python no_ruby
FLAVORS=	maintainer_mode
FLAVOR?=
.if ${FLAVOR:Mno_bindings}
FLAVOR += no_perl no_python no_ruby
.endif

MODULES=	devel/gettext lang/python

WANTLIB=	expat magic pthread z

# autogen.sh checks for libtoolize
BUILD_DEPENDS=	${MODGNU_AUTOCONF_DEPENDS} \
		devel/libtool

MULTI_PACKAGES = -main -ap2 -perl -python -ruby -gnome-keyring

MAINSPEC =	${PKGNAME}:devel/subversion,-main
LIB_DEPENDS-main = ${LIB_DEPENDS} \
		net/neon>=0.26.2 \
		devel/apr \
		devel/apr-util \
		security/cyrus-sasl2 \
		devel/libmagic

WANTLIB-main=	${WANTLIB} asn1 c crypto db gssapi krb5 ssl \
		neon>=26 apr-1 aprutil-1 sasl2>=2 sqlite3 \
		m proxy stdc++
RUN_DEPENDS-main= ${MODGETTEXT_RUN_DEPENDS}

TOOLS_HOOK_SCRIPTS=	commit-access-control.cfg.example \
	commit-access-control.pl commit-email.rb \
	log-police.py svn2feed.py svnperms.conf.example \
	svnperms.py verify-po.py
# There's also 'mailer', but we handle it separately, see post-install

TOOLS_CLIENT_SIDE_SCRIPTS=	bash_completion change-svn-wc-format.py \
	server-version.py showchange.pl svn-graph.pl

WANTLIB-ap2=		${WANTLIB} apr-1 aprutil-1 db sqlite3
LIB_DEPENDS-ap2=	${MODGETTEXT_LIB_DEPENDS} ${MAINSPEC}
.for _lib in svn_delta-1 svn_fs-1 svn_fs_base-1 svn_fs_fs-1 \
	svn_fs_util-1 svn_repos-1 svn_subr-1
WANTLIB-ap2 +=	${_lib}>=${SO_VERSION}
.endfor
RUN_DEPENDS-ap2=	www/apache-httpd

NOT_FOR_ARCHS-perl = ${NO_SHARED_ARCHS}
NOT_FOR_ARCHS-python = ${NO_SHARED_ARCHS}
NOT_FOR_ARCHS-ruby = ${NO_SHARED_ARCHS}

WANTLIB-perl=		${WANTLIB} apr-1 aprutil-1 sqlite3 
RUN_DEPENDS-perl=	${MODGETTEXT_RUN_DEPENDS}
LIB_DEPENDS-perl=	${MODGETTEXT_LIB_DEPENDS} ${MAINSPEC}
.for _lib in svn_diff-1 svn_ra-1 svn_delta-1 svn_subr-1 svn_fs-1 \
	svn_repos-1 svn_wc-1 svn_client-1
WANTLIB-perl +=	${_lib}>=${SO_VERSION}
.endfor

WANTLIB-python=		${WANTLIB} apr-1 aprutil-1 asn1 crypto gssapi db \
			krb5 neon proxy sasl2 sqlite3 ssl ${MODPY_WANTLIB}
RUN_DEPENDS-python=	${MODPY_RUN_DEPENDS}
LIB_DEPENDS-python=	${MODPY_LIB_DEPENDS} ${MODGETTEXT_LIB_DEPENDS} \
			${MAINSPEC}
.for _lib in ${SVN_LIBS}
WANTLIB-python +=	${_lib}>=${SO_VERSION}
.endfor

WANTLIB-ruby=		${WANTLIB} apr-1 aprutil-1 asn1 crypto gssapi db \
			krb5 m neon proxy sasl2 sqlite3 ssl ${MODRUBY_WANTLIB}
RUN_DEPENDS-ruby=	${MODRUBY_RUN_DEPENDS}
LIB_DEPENDS-ruby=	${MODRUBY_LIB_DEPENDS} \
			${MODGETTEXT_LIB_DEPENDS} ${MAINSPEC}
.for _lib in ${SVN_LIBS}
WANTLIB-ruby +=	${_lib}>=${SO_VERSION}
.endfor

WANTLIB-gnome-keyring=	${WANTLIB} apr-1 aprutil-1 gcrypt gpg-error \
		dbus-1>=7 glib-2.0 gnome-keyring>=6 pcre>=2 sqlite3 \
		svn_subr-1>=${SO_VERSION} ffi gmodule-2.0 gobject-2.0 \
		gthread-2.0
LIB_DEPENDS-gnome-keyring= ${MAINSPEC} \
		${MODGETTEXT_LIB_DEPENDS} \
		x11/gnome/libgnome-keyring

RUN_DEPENDS-gnome-keyring=	${MODGETTEXT_RUN_DEPENDS}

MAKE_FLAGS=	MAKE=${MAKE_PROGRAM}
USE_LIBTOOL=	Yes
AUTOCONF_VERSION=2.64
CONFIGURE_STYLE=gnu
CONFIGURE_ENV=	PYTHON2=${MODPY_BIN} MKDIR="/bin/mkdir -p"
CONFIGURE_ARGS+=${CONFIGURE_SHARED} \
		--with-sasl=${LOCALBASE} \
		--with-gnome-keyring \
		--without-jikes \
		--without-jdk \
		--with-libmagic=${LOCALBASE}

# Maintainer mode shows files and line numbers for every error raised
# by Subversion. It is useful for debugging problems with Subversion
# but is not required for normal operation.
.if ${FLAVOR:Mmaintainer_mode}
CONFIGURE_ARGS+=--enable-maintainer-mode
.endif

.include <bsd.port.arch.mk>

.if ${BUILD_PACKAGES:M-ruby} || ${BUILD_PACKAGES:M-perl} || ${BUILD_PACKAGES:M-python}

BUILD_DEPENDS+=	devel/swig>=1.3.36
CONFIGURE_ARGS+=--with-swig
.else
CONFIGURE_ARGS+=--without-swig
.endif

.if ${BUILD_PACKAGES:M-ruby}
MODULES+=	lang/ruby
CONFIGURE_ENV+=	RUBY=ruby${MODRUBY_BINREV} RDOC=rdoc${MODRUBY_BINREV}
.endif

.if ${BUILD_PACKAGES:M-ap2}
CONFIGURE_ARGS+=--with-apxs=${LOCALBASE}/sbin/apxs2 \
		--disable-mod-activation
BUILD_DEPENDS+=		www/apache-httpd
.else
CONFIGURE_ARGS+=--without-apxs
.endif

REGRESS_DEPENDS=${MODPY_RUN_DEPENDS}
SUBST_VARS+=	LOCALBASE SO_VERSION

pre-patch:
	@ln -s ${MODPY_BIN} ${WRKDIR}/bin/python

pre-configure:
	@${SUBST_CMD} ${WRKSRC}/Makefile.in ${WRKSRC}/configure.ac \
		${WRKSRC}/subversion/libsvn_subr/auth.c
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		AUTOCONF_VERSION=${AUTOCONF_VERSION} ./autogen.sh

.if ${BUILD_PACKAGES:M-python}
REGRESS_DEPENDS+=	${FULLPKGNAME-python}:${BUILD_PKGPATH},-python

.if ${BUILD_PACKAGES:M-ruby}
REGRESS_DEPENDS+=	${FULLPKGNAME-ruby}:${BUILD_PKGPATH},-ruby
.endif

pre-build:
	@cd ${WRKBUILD} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} \
		${MAKE_FLAGS} clean-swig
.endif

post-build:
.if ${BUILD_PACKAGES:M-python}
	@cd ${WRKBUILD} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} \
		${MAKE_FLAGS} swig-py
.endif
.if ${BUILD_PACKAGES:M-perl}
	@cd ${WRKBUILD} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} \
		${MAKE_FLAGS} swig-pl
.endif
.if ${BUILD_PACKAGES:M-ruby}
	@cd ${WRKBUILD} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} \
		${MAKE_FLAGS} swig-rb
.endif
	@cd ${WRKBUILD} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} \
		${MAKE_FLAGS} svnmucc
	@cd ${WRKBUILD} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} \
		${MAKE_FLAGS} svnauthz-validate
	@cd ${WRKBUILD} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} \
		${MAKE_FLAGS} svn-populate-node-origins-index

do-regress:
	@cd ${WRKBUILD} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} \
		${ALL_REGRESS_FLAGS} check FS_TYPE=bdb
	@cd ${WRKBUILD} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} \
		${ALL_REGRESS_FLAGS} check FS_TYPE=fsfs
.if ${BUILD_PACKAGES:M-perl}
	@cd ${WRKBUILD} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} \
		${ALL_REGRESS_FLAGS} TMPDIR=${WRKBUILD} check-swig-pl
.endif
.if ${BUILD_PACKAGES:M-python}
	@cd ${WRKBUILD} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} \
		${ALL_REGRESS_FLAGS} check-swig-py
.endif
.if ${BUILD_PACKAGES:M-ruby}
	@cd ${WRKBUILD} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} \
		${ALL_REGRESS_FLAGS} check-swig-rb
.endif

post-install:
.if ${BUILD_PACKAGES:M-python}
	@cd ${WRKBUILD} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} \
		${ALL_FAKE_FLAGS} install-swig-py
.endif
.if ${BUILD_PACKAGES:M-perl}
	@cd ${WRKBUILD} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} \
		${ALL_FAKE_FLAGS} install-swig-pl
.endif
.if ${BUILD_PACKAGES:M-ruby}
	@cd ${WRKBUILD} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} \
		${ALL_FAKE_FLAGS} install-swig-rb
.endif
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/subversion/
	${INSTALL_DATA} ${FILESDIR}/servers \
			${PREFIX}/share/examples/subversion/servers
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/subversion/client-side
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/subversion/server-side
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/subversion/hook-scripts
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/subversion/cgi
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/subversion/client-side/emacs
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/subversion/client-side/svn2cl
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/subversion/client-side/svn_load_dirs
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/subversion/hook-scripts/mailer
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/subversion/hook-scripts/mailer/tests
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/subversion/hook-scripts/enforcer
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/subversion/server-side/mod_dontdothat
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/subversion/xslt
	@cd ${WRKBUILD} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} \
		${ALL_FAKE_FLAGS} install-tools
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/subversion/backup
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/subversion/bdb
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/subversion/xslt
	${INSTALL_DATA} ${WRKBUILD}/tools/backup/hot-backup.py \
			${PREFIX}/share/examples/subversion/backup
	${INSTALL_DATA} ${WRKSRC}/tools/bdb/* \
		${PREFIX}/share/examples/subversion/bdb
	${INSTALL_DATA} ${WRKSRC}/tools/examples/* \
		${PREFIX}/share/examples/subversion
.for _script in ${TOOLS_CLIENT_SIDE_SCRIPTS}
	${INSTALL_DATA} ${WRKSRC}/tools/client-side/${_script} \
			${PREFIX}/share/examples/subversion/client-side
.endfor
	${INSTALL_DATA} ${WRKSRC}/tools/server-side/fsfs-reshard.py \
			${PREFIX}/share/examples/subversion/server-side
	${INSTALL_DATA} ${WRKSRC}/tools/server-side/svn-backup-dumps.py \
			${PREFIX}/share/examples/subversion/server-side
	${INSTALL_PROGRAM} ${WRKSRC}/tools/server-side/svn-populate-node-origins-index.c \
		${PREFIX}/share/examples/subversion/server-side
	${INSTALL_DATA} ${WRKSRC}/tools/xslt/* \
		${PREFIX}/share/examples/subversion/xslt
.for _hook_script in ${TOOLS_HOOK_SCRIPTS}
	${INSTALL_DATA} ${WRKSRC}/tools/hook-scripts/${_hook_script} \
			${PREFIX}/share/examples/subversion/hook-scripts/
.endfor
	${INSTALL_DATA} ${WRKSRC}/tools/hook-scripts/mailer/mailer.conf.example \
			${PREFIX}/share/examples/subversion/hook-scripts/mailer
	${INSTALL_DATA} ${WRKSRC}/tools/hook-scripts/mailer/mailer.conf.example \
			${PREFIX}/share/examples/subversion/hook-scripts/mailer
	${INSTALL_DATA} ${WRKSRC}/tools/hook-scripts/mailer/mailer.py \
			${PREFIX}/share/examples/subversion/hook-scripts/mailer
	${INSTALL_DATA} ${WRKSRC}/tools/hook-scripts/mailer/tests/* \
			${PREFIX}/share/examples/subversion/hook-scripts/mailer/tests
	find ${PREFIX}/share/examples/subversion -type f | xargs perl -pi \
		-e "s,.*/usr/bin/python.*,#!${MODPY_BIN},;" \
		-e "s,.*env python.*,#!${MODPY_BIN},;"
	find ${PREFIX}/share/examples/subversion -type f -name '*\.orig' \
		-exec rm -f {} \;

.include <bsd.port.mk>
