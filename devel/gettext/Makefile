# $OpenBSD$

COMMENT=	GNU gettext

DISTNAME=	gettext-0.18.1
REVISION=	4
SHARED_LIBS +=  intl                 6.0      # .9.1
SHARED_LIBS +=  asprintf             1.0      # .0.0
SHARED_LIBS +=  gettextlib           3.0      # .0.0
SHARED_LIBS +=  gettextsrc           3.0      # .0.0
SHARED_LIBS +=  gettextpo            4.0      # .5.1

CATEGORIES=	devel
# DPB: parallel-safe, not worth it. Too much time in configure

MASTER_SITES=	${MASTER_SITE_GNU:=gettext/}

HOMEPAGE=	http://www.gnu.org/software/gettext/

MAINTAINER=	Christian Weisgerber <naddy@openbsd.org>

# LGPL, GPLv3
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MODULES=	converters/libiconv
WANTLIB=	c expat m ncurses stdc++

USE_LIBTOOL=	Yes
CONFIGURE_STYLE=gnu
CONFIGURE_ARGS=	${CONFIGURE_SHARED} \
		--disable-csharp \
		--disable-java \
		--with-libiconv-prefix="${LOCALBASE}" \
		--with-included-gettext \
		--with-included-glib \
		--with-included-libcroco \
		--with-included-libunistring \
		--with-included-libxml \
		--without-emacs \
		--without-git

MODGNU_CONFIG_GUESS_DIRS=${WRKSRC}/build-aux

EXTRA_LOCALES=	en he hr hu lv no

# avoid triggering autotools rebuild cascade
post-patch:
	touch -r ${WRKSRC}/gettext-runtime/m4/fcntl-o.m4.orig \
	    ${WRKSRC}/gettext-runtime/m4/fcntl-o.m4

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/emacs/site-lisp
	@for f in start-po.el po-mode.el po-compat.el; do \
		${INSTALL_DATA} ${WRKSRC}/gettext-tools/misc/$$f \
			${PREFIX}/share/emacs/site-lisp; \
	done
	@for l in ${EXTRA_LOCALES}; do \
		${INSTALL_DATA_DIR} ${PREFIX}/share/locale/$$l/LC_MESSAGES; \
	done

.include <bsd.port.mk>
