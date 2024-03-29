# $OpenBSD$

COMMENT-main=	fast, light and extensible chat client
COMMENT-lua=	Lua bindings for weechat
COMMENT-python=	Python bindings for weechat
COMMENT-ruby=	Ruby bindings for weechat
COMMENT-tcl=	Tcl bindings for weechat

V=		0.3.8
DISTNAME=	weechat-${V}

PKGNAME-main=	weechat-${V}
REVISION-main=	2
PKGNAME-lua=	weechat-lua-${V}
REVISION-lua=	1
PKGNAME-python=	weechat-python-${V}
REVISION-python=0
PKGNAME-ruby=	weechat-ruby-${V}
REVISION-ruby=	1
PKGNAME-tcl=	weechat-tcl-${V}
REVISION-tcl=	0

CATEGORIES=	net

HOMEPAGE=	http://www.weechat.org/

SHARED_ONLY=	Yes

# GPLv3
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=	${HOMEPAGE}/files/src/

MULTI_PACKAGES=	-main -lua -python -ruby -tcl

WANTLIB-main=	c curl m ncursesw perl pthread util \
		gcrypt gnutls gpg-error z ${MODGETTEXT_WANTLIB}

WANTLIB-lua=	${MODLUA_WANTLIB}
WANTLIB-python=	${MODPY_WANTLIB}
WANTLIB-ruby=	${MODRUBY_WANTLIB}
WANTLIB-tcl=	${MODTCL_WANTLIB}

MODULES=	devel/cmake \
		devel/gettext \
		lang/lua \
		lang/python \
		lang/ruby \
		lang/tcl

MODLUA_RUNDEP=	No
MODPY_RUNDEP=	No
MODRUBY_RUNDEP=	No
MODRUBY_REV=	1.9

LIB_DEPENDS=	security/libgcrypt \
		security/gnutls \
		net/curl

LIB_DEPENDS-lua=	${MODLUA_LIB_DEPENDS}
RUN_DEPENDS-lua=	${MODLUA_RUN_DEPENDS}

LIB_DEPENDS-python=	${MODPY_LIB_DEPENDS}
RUN_DEPENDS-python=	${MODPY_RUN_DEPENDS}

LIB_DEPENDS-ruby=	${MODRUBY_LIB_DEPENDS}
RUN_DEPENDS-ruby=	${MODRUBY_RUN_DEPENDS}

LIB_DEPENDS-tcl=	${MODTCL_LIB_DEPENDS}
RUN_DEPENDS-tcl=	${MODTCL_RUN_DEPENDS}

CONFIGURE_ARGS+=-DENABLE_ASPELL=no \
		-DENABLE_GUILE=no \
		-DENABLE_RUBY=yes \
		-DENABLE_LUA=yes \
		-DENABLE_TCL=yes \
		-DENABLE_PYTHON=yes \
		-DHAVE_BACKTRACE=no

post-install:
	$(INSTALL_DATA_DIR) ${PREFIX}/share/doc/weechat
	$(INSTALL_DATA) $(WRKSRC)/doc/en/*.en.txt ${PREFIX}/share/doc/weechat/

NO_REGRESS=	Yes

.include <bsd.port.mk>
